#ifndef TIM_PWM_H
#define TIM_PWM_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

#define SATURATE(v, _min, _max) (v > _max ? _max : v < _min ? _min : v)

typedef enum{
	PWM_CHANNEL_1 = 1,
	PWM_CHANNEL_2 = 2,
	PWM_CHANNEL_3 = 4,
	PWM_CHANNEL_4 = 8,
} PWMChannel_t;

void PWMSetDuty(TIM_HandleTypeDef* tim, PWMChannel_t channels, uint16_t duty);

void PWMSetDutyF(TIM_HandleTypeDef* tim, PWMChannel_t channels, float duty);

void PWMSetMotorDuty(TIM_HandleTypeDef* tim, PWMChannel_t channels, int16_t duty);

void PWMSetMotorDutyF(TIM_HandleTypeDef* tim, PWMChannel_t channels, float duty);

void PWMSetServoDuty(TIM_HandleTypeDef* tim, PWMChannel_t channels, int16_t duty);

void PWMSetServoDutyF(TIM_HandleTypeDef* tim, PWMChannel_t channels, float duty);

void PWMSetESCDuty(TIM_HandleTypeDef* tim, PWMChannel_t channels, int16_t duty);

void PWMSetESCDutyF(TIM_HandleTypeDef* tim, PWMChannel_t channels, float duty);

#endif