
#include <stdio.h>

#include "hardware/uart.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

#include "pin_definition.h"
#include "constant.h"

#ifndef GENPWM_H
#define GENPWM_H

#ifdef __cplusplus
extern "C" {
#endif

void gen_pwm(uint32_t gpio_pin, uint32_t pwmFrequency_Hz, float duty_cycle);
void gen_pwm2(uint32_t gpio_pin, float power);

#ifdef __cplusplus
}
#endif

#endif // GENPWM_H