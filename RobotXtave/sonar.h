#include <stdio.h>

#include "pico/stdlib.h"

// Speed of sound in air (in cm/µs)
#define SPEED_OF_SOUND_CM_PER_US 0.0343

// Timeout in microseconds
#define ECHO_TIMEOUT_US 38000  // ~38ms corresponds to ~6.5m maximum distance

#define BLINK_DURATION_MS 500  // Total blinking time in milliseconds
#define BLINK_FREQUENCY_HZ 8    // Blinking frequency in Hz
#define BLINK_INTERVAL_MS (1000 / BLINK_FREQUENCY_HZ)  // Interval per blink in ms

#ifndef SONAR_H
#define SONAR_H

#ifdef __cplusplus
extern "C" {
#endif

float measure_distance();
void BlinkLedObstacle(uint32_t uLED);

#ifdef __cplusplus
}
#endif

#endif // SONAR_H




