#include "pico/stdlib.h"

#include "pin_definition.h"
#include "constant.h"
#include "genpwm.h"

#ifndef MOTOR_H
#define MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif

void go_stop();
void go_forward();
void go_backward();
void go_left();
void go_right();

#ifdef __cplusplus
}
#endif

#endif // MOTOR_H