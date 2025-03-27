
#include "motor.h"

void go_stop()
{
   gpio_put(MOTOR_RIGHT_DIR, FORWARD);
   gpio_put(MOTOR_LEFT_DIR, FORWARD);
   gen_pwm2(MOTOR_LEFT_PWM, 0);
   gen_pwm2(MOTOR_RIGHT_PWM, 0);
   //gen_pwm(MOTOR_LEFT_PWM, PWM_FREQUENCY, 100);
   //gen_pwm(MOTOR_RIGHT_PWM, PWM_FREQUENCY, 100);
}

void go_forward()
{
   gpio_put(MOTOR_RIGHT_DIR, FORWARD);
   gpio_put(MOTOR_LEFT_DIR, FORWARD);
   gen_pwm2(MOTOR_LEFT_PWM, 85);
   gen_pwm2(MOTOR_RIGHT_PWM, 95);
}

void go_backward()
{
   gpio_put(MOTOR_RIGHT_DIR, BACKWARD);
   gpio_put(MOTOR_LEFT_DIR, BACKWARD);
   gen_pwm2(MOTOR_LEFT_PWM, 85);
   gen_pwm2(MOTOR_RIGHT_PWM, 95);
}

void go_left()
{
   gpio_put(MOTOR_RIGHT_DIR, FORWARD);
   gpio_put(MOTOR_LEFT_DIR, BACKWARD);
   gen_pwm2(MOTOR_LEFT_PWM, 85);
   gen_pwm2(MOTOR_RIGHT_PWM, 95);
}

void go_right()
{
   gpio_put(MOTOR_RIGHT_DIR, BACKWARD);
   gpio_put(MOTOR_LEFT_DIR, FORWARD);
   gen_pwm2(MOTOR_LEFT_PWM, 85);
   gen_pwm2(MOTOR_RIGHT_PWM, 95);
}



/*
      // PWM test
      gen_pwm(MOTOR_LEFT_PWM, 5000, 0);
      sleep_ms(1000);  // 1 second delay

      gen_pwm(MOTOR_LEFT_PWM, 5000, 25.0);
      sleep_ms(1000);  // 1 second delay

      gen_pwm(MOTOR_LEFT_PWM, 5000, 50.0);
      sleep_ms(1000);  // 1 second delay

      gen_pwm(MOTOR_LEFT_PWM, 5000, 75.0);
      sleep_ms(1000);  // 1 second delay

      gen_pwm(MOTOR_LEFT_PWM, 5000, 100.0);
      sleep_ms(1000);  // 1 second delay

      // PWM test
      gen_pwm(MOTOR_RIGHT_PWM, 5000, 0);
      sleep_ms(1000);  // 1 second delay

      gen_pwm(MOTOR_RIGHT_PWM, 5000, 25.0);
      sleep_ms(1000);  // 1 second delay

      gen_pwm(MOTOR_RIGHT_PWM, 5000, 50.0);
      sleep_ms(1000);  // 1 second delay

      gen_pwm(MOTOR_RIGHT_PWM, 5000, 75.0);
      sleep_ms(1000);  // 1 second delay

      gen_pwm(MOTOR_RIGHT_PWM, 5000, 100.0);
      sleep_ms(1000);  // 1 second delay

   gpio_put(MOTOR_RIGHT_DIR, FORWARD);

   //gen_pwm(MOTOR_RIGHT_PWM, 5000, 60);
   //sleep_ms(1000);  // 1 second delay

   //gen_pwm(MOTOR_RIGHT_PWM, 5000, 50);
   //sleep_ms(1000);  // 1 second delay

   //gen_pwm(MOTOR_RIGHT_PWM, 5000, 45);
   //sleep_ms(1000);  // 1 second delay

   //gen_pwm(MOTOR_RIGHT_PWM, 5000, 40);
   //sleep_ms(1000);  // 1 second delay

   //gen_pwm(MOTOR_RIGHT_PWM, 5000, 35);
   //sleep_ms(1000);  // 1 second delay

   gen_pwm(MOTOR_RIGHT_PWM, 5000, 30);
   sleep_ms(1000);  // 1 second delay

   //gen_pwm(MOTOR_RIGHT_PWM, 5000, 25);
   //sleep_ms(1000);  // 1 second delay

   //gen_pwm(MOTOR_RIGHT_PWM, 5000, 20);
   //sleep_ms(1000);  // 1 second delay

   gen_pwm(MOTOR_RIGHT_PWM, 5000, 100);      // OFF

   gpio_put(MOTOR_LEFT_DIR, FORWARD);

   //gen_pwm(MOTOR_LEFT_PWM, 5000, 60);
   //sleep_ms(1000);  // 1 second delay

   gen_pwm(MOTOR_LEFT_PWM, 5000, 55);
   sleep_ms(1000);  // 1 second delay

   gen_pwm(MOTOR_LEFT_PWM, 5000, 50);
   sleep_ms(1000);  // 1 second delay

   gen_pwm(MOTOR_LEFT_PWM, 5000, 45);
   sleep_ms(1000);  // 1 second delay

   gen_pwm(MOTOR_LEFT_PWM, 5000, 40);
   sleep_ms(1000);  // 1 second delay

   gen_pwm(MOTOR_LEFT_PWM, 5000, 35);
   sleep_ms(1000);  // 1 second delay

   gen_pwm(MOTOR_LEFT_PWM, 5000, 30);
   sleep_ms(1000);  // 1 second delay

   gen_pwm(MOTOR_LEFT_PWM, 5000, 25);
   sleep_ms(1000);  // 1 second delay

   //gen_pwm(MOTOR_LEFT_PWM, 5000, 20);
   //sleep_ms(1000);  // 1 second delay


   gen_pwm(MOTOR_LEFT_PWM, 5000, 100);    // OFF
   sleep_ms(1000);  // 1 second delay

   */