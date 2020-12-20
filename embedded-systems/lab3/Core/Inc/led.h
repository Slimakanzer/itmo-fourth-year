/*
 * led.h
 *
 *  Created on: Dec 20, 2020
 *      Author: slimakanzer
 */

#ifndef INC_LED_H_
#define INC_LED_H_
#include <stdint.h>

uint8_t get_led();
void set_led(uint8_t val);

void led_green();
void led_yellow();
void led_red();
void led_dash();
void led_dot();
void led_delay();

#endif /* INC_LED_H_ */
