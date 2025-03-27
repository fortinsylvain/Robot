#include "sonar.h"
#include "pin_definition.h"

float measure_distance() 
{
   // Trigger the sonar with a pulse
   gpio_put(SONAR_TX_ENABLE, 1);
   sleep_us(600);
   gpio_put(SONAR_TX_ENABLE, 0);

   // Record the start time
   uint32_t start_time = time_us_32();

   // Wait for the echo signal
   while (gpio_get(SONAR_CAPTOR) == 1)    // Will go low when echo received
   {
      if (time_us_32() - start_time > ECHO_TIMEOUT_US) 
      {
         return -1;  // Timeout, no echo received
      }
   }

   // Record the time of echo arrival
   uint32_t echo_time = time_us_32();

   // Calculate pulse duration in microseconds
   float travel_duration_us = (float)(echo_time - start_time);

   // Calculate distance in centimeters
    float distance = (travel_duration_us * SPEED_OF_SOUND_CM_PER_US) / 2.0;

    return distance;

}

void BlinkLedObstacle(uint32_t uLED) 
{
   uint32_t start_time = to_ms_since_boot(get_absolute_time());
   uint32_t elapsed_time = 0;
   bool led_state = false;
   
   while (elapsed_time < BLINK_DURATION_MS) 
   {  
      // Toggle LED state
      led_state = !led_state;
      gpio_put(uLED, led_state);
      
      // Wait for half the blink interval (on/off cycle)
      sleep_ms(BLINK_INTERVAL_MS / 2);
      
      // Update elapsed time
      elapsed_time = to_ms_since_boot(get_absolute_time()) - start_time;
    }

    // Ensure LED is off at the end
    gpio_put(uLED, 0);
}