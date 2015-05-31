/*
 * tim_pwm.c
 *
 *  Created on: May 25, 2015
 *      Author: Bruno
 */

#include "tim_pwm.h"

#include <math.h>

#include "stm32f4xx_hal.h"
#include <stdint.h>

static void setTimCCR(TIM_HandleTypeDef* tim, PWMChannel_t channel, uint32_t value){
	if(channel & PWM_CHANNEL_1)
		tim->Instance->CCR1 = value;
	if(channel & PWM_CHANNEL_2)
		tim->Instance->CCR2 = value;
	if(channel & PWM_CHANNEL_3)
		tim->Instance->CCR3 = value;
	if(channel & PWM_CHANNEL_4)
		tim->Instance->CCR4 = value;
}

void PWMSetDuty(TIM_HandleTypeDef* tim, PWMChannel_t channels, uint16_t duty){
	uint64_t nv = ((uint64_t)SATURATE(duty, 0, 10000)*(tim->Instance->ARR+1))/10000-1;
	setTimCCR(tim, channels, nv);
}

void PWMSetDutyF(TIM_HandleTypeDef* tim, PWMChannel_t channels, float duty){
	float nv = ((float)SATURATE(duty, 0.0f, 1.0f)*(tim->Instance->ARR+1))-1;
	setTimCCR(tim, channels, roundf(nv));
}

void PWMSetMotorDuty(TIM_HandleTypeDef* tim, PWMChannel_t channels, int16_t duty){
	int32_t nv = (SATURATE(duty, -10000, 10000) + 10000)>>1;
	PWMSetDuty(tim, channels, nv);
}

void PWMSetMotorDutyF(TIM_HandleTypeDef* tim, PWMChannel_t channels, float duty){
	float nv = ((float)SATURATE(duty, -1.0f, 1.0f) + 1)/2;
	PWMSetDutyF(tim, channels, nv);
}

void PWMSetServoDuty(TIM_HandleTypeDef* tim, PWMChannel_t channels, int16_t duty){
	int32_t nv = (((SATURATE(duty, -10000, 10000) + 10000)>>1)*500)/10000 + 500;
	PWMSetDuty(tim, channels, nv);
}

void PWMSetServoDutyF(TIM_HandleTypeDef* tim, PWMChannel_t channels, float duty){
	float nv = ((((float)SATURATE(duty, -1.0f, 1.0f) + 1)/2)*0.05)+0.05;
	PWMSetDutyF(tim, channels, nv);
}

void PWMSetESCDuty(TIM_HandleTypeDef* tim, PWMChannel_t channels, int16_t duty){
	int32_t nv = (((SATURATE(duty, 0, 10000)))*4000)/10000 + 4000;
	PWMSetDuty(tim, channels, nv);
}

void PWMSetESCDutyF(TIM_HandleTypeDef* tim, PWMChannel_t channels, float duty){
	float nv = ((((float)SATURATE(duty, 0.0f, 1.0f)))*0.4)+0.4;
	PWMSetDutyF(tim, channels, nv);
}
