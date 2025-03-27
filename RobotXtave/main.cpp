//------------------------------------------------------------------------------------
//--
//-- Radio Transmitter using 433 MHz
//--
//--
//------------------------------------------------------------------------------------

// Measured RF to Data time response 
//
//                 ON
//
// RF    -----/\/\/\/\/\/\/\/\/
//                  ___________
// DATA  ----------|
//
//           |-----|
//             60 us
//
//                 OFF
//
// RF    /\/\/\/\/\-------------
//       ___________________
// DATA                     |___
//                         
//                 |--------|
//                   230 us   
//
// If no signal transmitted after 45ms then the receiver start to generate garbage

#include <stdlib.h>

#include <stdbool.h>
#include "pico/stdlib.h"

#include "pin_definition.h"
#include "constant.h"
#include "RH_ASK.h"
#include "genpwm.h"
#include "motor.h"
#include "sonar.h"

//#define DATATX_GPIO 2          // DATATX  GP2 PCB pin<4>

// Onboard Led
#define LED_GPIO 25        // GP25 and don't have a pin on RP Pico board

#define Period_ms 1
#define Period2_ms 2

int main() 
{
   //gpio_init(DATATX_GPIO);

   // Configure generator outputs
   //gpio_set_dir(DATATX_GPIO, GPIO_OUT);

   // Configure onboard LED
   gpio_init(LED_GPIO);
   gpio_set_dir(LED_GPIO, GPIO_OUT);

   // Initialize LED state
   bool led_state = false;

   // Initialize motor
   gpio_init(MOTOR_RIGHT_DIR);               // Initialize the GPIO pin
   gpio_set_dir(MOTOR_RIGHT_DIR, GPIO_OUT);  // Set the pin as output
   gpio_put(MOTOR_RIGHT_DIR, FORWARD);

   gpio_init(MOTOR_RIGHT_PWM);               // Initialize the GPIO pin
   gpio_set_dir(MOTOR_RIGHT_PWM, GPIO_OUT);  // Set the pin as output
   gpio_put(MOTOR_RIGHT_PWM, 1);             

   gpio_init(MOTOR_LEFT_DIR);               // Initialize the GPIO pin
   gpio_set_dir(MOTOR_LEFT_DIR, GPIO_OUT);  // Set the pin as output
   gpio_put(MOTOR_LEFT_DIR, FORWARD);             // Set the pin to low (0)

   gpio_init(MOTOR_LEFT_PWM);               // Initialize the GPIO pin
   gpio_set_dir(MOTOR_LEFT_PWM, GPIO_OUT);  // Set the pin as output
   gpio_put(MOTOR_LEFT_PWM, 1);           

   gen_pwm(MOTOR_RIGHT_PWM, 5000, 100);
   gen_pwm(MOTOR_LEFT_PWM, 5000, 100);

   // Initialize Sonar
   gpio_init(SONAR_TX_ENABLE);               // Initialize the GPIO pin
   gpio_set_dir(SONAR_TX_ENABLE, GPIO_OUT);  // Set the pin as output
   gpio_put(SONAR_TX_ENABLE, 0);             // transmit OFF

   gpio_init(SONAR_CAPTOR);               // Initialize the GPIO pin
   gpio_set_dir(SONAR_CAPTOR, GPIO_IN);  // Set the pin as input

   // INIT LED SONAR
   gpio_init(SONAR_LED_RED);
   gpio_set_dir(SONAR_LED_RED, GPIO_OUT);
   gpio_put(SONAR_LED_RED, 0);

   gpio_init(SONAR_LED_YELLOW);
   gpio_set_dir(SONAR_LED_YELLOW, GPIO_OUT);
   gpio_put(SONAR_LED_YELLOW, 0);

   gpio_init(SONAR_LED_GREEN);
   gpio_set_dir(SONAR_LED_GREEN, GPIO_OUT);
   gpio_put(SONAR_LED_GREEN, 0);

   // RX on GPIO 3 pin<5>
   // TX on GPIO 2 pin<4> 
   // PTT on GPIO 4 pin<6>
   //RH_ASK driver(2000, 3, 2, 4);
  
   //driver.init();
   const char *msg1 = "hello";
   const char *msg2 = "Ca va bien ?";
   const char *msg3 = "Que faites vous aujourdhui?";
   const char *msg4 = "0123456789012345678901234567890123456789";

   //const char *msg1 = "a";
   //const char *msg2 = "b";
   //const char *msg3 = "c";
   //const char *msg4 = "d";

   while (true) 
   {
      //driver.send((uint8_t *)msg1, strlen(msg1));
      //driver.waitPacketSent();
      //sleep_ms(1000);
  
      //driver.send((uint8_t *)msg2, strlen(msg2));
      //driver.waitPacketSent();
      //sleep_ms(1000);

      //driver.send((uint8_t *)msg3, strlen(msg3));
      //driver.waitPacketSent();
      //sleep_ms(1000);

      //driver.send((uint8_t *)msg4, strlen(msg4));
      //driver.waitPacketSent();

      float distance;
      int choice = rand() % 5; // Generate a number between 0 et 5
      //choice = 0;
      switch (choice) 
      {
        case 0:      // Want to try to go foward
            go_stop();
            sleep_ms(500);
            distance = measure_distance();
            if((distance == -1) || (distance > 60))   // enough space to go forward
            {
               BlinkLedObstacle(SONAR_LED_GREEN);
               go_forward();
               sleep_ms(600);
               go_stop();
               sleep_ms(1500);
            }
            else if (distance > 40) // object around
            {
               BlinkLedObstacle(SONAR_LED_YELLOW);
               go_backward();
               sleep_ms(500);
               go_stop();
               sleep_ms(2000);
            }
            else  // need to avoid collision
            {
               go_stop();
               BlinkLedObstacle(SONAR_LED_RED);
               go_backward();
               sleep_ms(800);
               go_stop();
               sleep_ms(2000);
               // Turn around
               go_right();
               sleep_ms(900);
               go_stop();
               sleep_ms(2000);
            }
            break;
        case 1:
            //go_stop();
            //sleep_ms(500);
            break;
        case 2:
            //go_backward();
            //sleep_ms(1000);
            break;
        case 3:
            go_right();
            sleep_ms(350);
            go_stop();
            sleep_ms(1000);
            break;
         case 4:
            go_left();
            sleep_ms(350);
            go_stop();
            sleep_ms(1000);
            break;
         case 5:  // Do nothing
            sleep_ms(4000);
            break;
        default:
            break;
    }

      // Toggle the LED state
      led_state = !led_state;
      gpio_put(LED_GPIO, led_state);
   }
}
