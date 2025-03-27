
#include "genpwm.h"

// power : 0 is stopped and 100 is full power
void gen_pwm2(uint32_t gpio_pin, float power)
{
   float duty_cycle = 100 - power;
   gen_pwm(gpio_pin, PWM_FREQUENCY, duty_cycle);
}


// Frequency Parameter: The frequency is used to calculate wrap_value and adjust clkdiv as needed.
// Duty Cycle Parameter: The duty cycle is expected to be a float between 0.0 and 100.0 (representing a percentage).
// The level is calculated as (wrap_value * duty_cycle) / 100.0, which sets the PWM duty cycle accordingly.
void gen_pwm(uint32_t gpio_pin, uint32_t frequency, float duty_cycle)
{
   // Set GPIO function for PWM
   gpio_set_function(gpio_pin, GPIO_FUNC_PWM);

   // Get the slice number for the specified GPIO pin
   uint32_t slice_num = pwm_gpio_to_slice_num(gpio_pin);

   // Calculate the wrap value based on the desired frequency
   float clkdiv = 1.0;  // Set initial clock divider
   uint32_t pwm_clock = 125000000 / clkdiv;  // System clock divided by clkdiv

   // Calculate wrap value based on the desired frequency
   uint16_t wrap_value = pwm_clock / frequency - 1;

   // If wrap_value is too high, adjust clkdiv accordingly
   while (wrap_value > 65535) 
   {
      clkdiv *= 2.0;  // Increase the clock divider
      pwm_clock = 125000000 / clkdiv;
      wrap_value = pwm_clock / frequency - 1;
   }

   // Set the calculated wrap value and clock divider
   pwm_set_wrap(slice_num, wrap_value);
   pwm_set_clkdiv(slice_num, clkdiv);

   // Calculate and set the fractional duty cycle level
   uint16_t level = (uint16_t)((wrap_value * duty_cycle) / 100.0);
   pwm_set_gpio_level(gpio_pin, level);

   // Enable the PWM output
   pwm_set_enabled(slice_num, true);
}



