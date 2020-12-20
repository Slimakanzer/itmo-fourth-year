/*
 * led.c
 *
 *  Created on: Dec 20, 2020
 *      Author: slimakanzer
 */
#include "led.h"
#include "trace.h"
#define T 300
uint8_t led = LED1;

uint8_t get_led()
{
	return led;
}

void set_led(uint8_t led_val)
{
	led = led_val;
}

void led_green()
{
	led = LED1;
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

void led_yellow()
{
	led = LED2;
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
}

void led_red()
{
	led = LED3;
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
}

void led_dash()
{
	led_green();

	SDK_TRACE_Timestamp(led, 1);
    HAL_Delay(2*T);
	SDK_TRACE_Timestamp(led, 0);
}

void led_dot()
{
	led_yellow();

	SDK_TRACE_Timestamp(led, 1);
    HAL_Delay(T);
	SDK_TRACE_Timestamp(led, 0);
}

void led_delay()
{
	led_red();

	SDK_TRACE_Timestamp(led, 1);
    HAL_Delay(T);
	SDK_TRACE_Timestamp(led, 0);
}
