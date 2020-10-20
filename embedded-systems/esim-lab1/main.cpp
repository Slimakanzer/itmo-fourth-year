#include "hal.h"

enum btn_state
{
    STOP,
    START,
};

unsigned int read_sw();
void animate(unsigned int &animation_state);
void check_button(btn_state &state_btn);
void green_light();
void red_light();
void yellow_light();

unsigned int led_num[] = {GPIO_PIN_3, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6};
unsigned int sw_num[] = {GPIO_PIN_4, GPIO_PIN_8, GPIO_PIN_10, GPIO_PIN_12};
unsigned int led_state[8][2] = {
    {GPIO_PIN_3, GPIO_PIN_12},
    {GPIO_PIN_3, GPIO_PIN_4},
    {GPIO_PIN_4, GPIO_PIN_5},
    {GPIO_PIN_5, GPIO_PIN_6},
    {GPIO_PIN_6, GPIO_PIN_8},
    {GPIO_PIN_8, GPIO_PIN_9},
    {GPIO_PIN_9, GPIO_PIN_11},
    {GPIO_PIN_11, GPIO_PIN_12}};

int umain()
{
    unsigned int animation_state = 0;
    btn_state state_btn = START;
    while (1)
    {
        unsigned int state_sw = read_sw();
        if (state_sw == GPIO_PIN_4 /* 0x8 code */)
        {
            check_button(state_btn);
            if (state_btn == STOP)
            {
                // red light
                HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);

                for (int i = 0; i < 4; i++)
                {
                    HAL_GPIO_WritePin(GPIOD, led_num[i], GPIO_PIN_RESET);
                }
                continue;
            }

            // green light
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
            animate(animation_state);
        }
        else
        {
            // yellow light
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
            for (int i = 0; i < 4; i++)
            {
                if (state_sw & sw_num[i])
                    HAL_GPIO_WritePin(GPIOD, led_num[i], GPIO_PIN_SET);
                else
                    HAL_GPIO_WritePin(GPIOD, led_num[i], GPIO_PIN_RESET);
            }
        }
    }

    return 0;
}

unsigned int read_sw()
{
    unsigned int result = 0;
    for (int i = 0; i < 4; i++)
    {
        GPIO_PinState state = HAL_GPIO_ReadPin(GPIOE, sw_num[i]);
        if (state == GPIO_PIN_SET)
            result |= sw_num[i];
    }

    return result;
}

void animate(unsigned int &animation_state)
{
    if (animation_state == 8)
        animation_state = 0;

    unsigned int first_pin = led_state[animation_state][0];
    unsigned int second_pin = led_state[animation_state][1];
    animation_state++;

    HAL_GPIO_WritePin(GPIOD, first_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOD, second_pin, GPIO_PIN_SET);
    HAL_Delay(500); // delay 0.5s
    HAL_GPIO_WritePin(GPIOD, first_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOD, second_pin, GPIO_PIN_RESET);
}

void check_button(btn_state &state_btn)
{
    GPIO_PinState state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15);
    if (state == GPIO_PIN_RESET)
    {
        if (state_btn == START)
            state_btn = STOP;
        else if (state_btn == STOP)
            state_btn = START;

        // button tresholding
        while (state == GPIO_PIN_RESET)
        {
            state = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15);
        }
    }
}