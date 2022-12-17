/*
 * TrafficLight.c
 *
 *  Created on: Nov 29, 2022
 *      Author: PC
 */


#include "TrafficLight.h"

// first traffic light
#define LED0_EN0_GPIO_Port L0_EN0_GPIO_Port
#define LED0_EN0_Pin       L0_EN0_Pin
#define LED0_EN1_GPIO_Port L0_EN1_GPIO_Port
#define LED0_EN1_Pin       L0_EN1_Pin

// second traffic light
#define LED1_EN0_GPIO_Port L1_EN0_GPIO_Port
#define LED1_EN0_Pin       L1_EN0_Pin
#define LED1_EN1_GPIO_Port L1_EN1_GPIO_Port
#define LED1_EN1_Pin       L1_EN1_Pin

void setGreenLed1(){
	HAL_GPIO_WritePin(LED0_EN0_GPIO_Port, LED0_EN0_Pin, RESET);
	HAL_GPIO_WritePin(LED0_EN1_GPIO_Port, LED0_EN1_Pin, SET);
}

void setYellowLed1(){
	HAL_GPIO_WritePin(LED0_EN1_GPIO_Port, LED0_EN1_Pin, SET);
	HAL_GPIO_WritePin(LED0_EN0_GPIO_Port, LED0_EN0_Pin, SET);
}

void setRedLed1(){
	HAL_GPIO_WritePin(LED0_EN1_GPIO_Port, LED0_EN1_Pin, RESET);
	HAL_GPIO_WritePin(LED0_EN0_GPIO_Port, LED0_EN0_Pin, SET);
}

void setGreenLed2(){
	HAL_GPIO_WritePin(LED1_EN0_GPIO_Port, LED1_EN0_Pin, RESET);
	HAL_GPIO_WritePin(LED1_EN1_GPIO_Port, LED1_EN1_Pin, SET);
}

void setYellowLed2(){
	HAL_GPIO_WritePin(LED1_EN1_GPIO_Port, LED1_EN1_Pin, SET);
	HAL_GPIO_WritePin(LED1_EN0_GPIO_Port, LED1_EN0_Pin, SET);
}

void setRedLed2(){
	HAL_GPIO_WritePin(LED1_EN1_GPIO_Port, LED1_EN1_Pin, RESET);
	HAL_GPIO_WritePin(LED1_EN0_GPIO_Port, LED1_EN0_Pin, SET);
}

void clearAllLed(){
	HAL_GPIO_WritePin(LED0_EN1_GPIO_Port, LED0_EN1_Pin, RESET);
	HAL_GPIO_WritePin(LED0_EN0_GPIO_Port, LED0_EN0_Pin, RESET);
	HAL_GPIO_WritePin(LED1_EN1_GPIO_Port, LED1_EN1_Pin, RESET);
	HAL_GPIO_WritePin(LED1_EN0_GPIO_Port, LED1_EN0_Pin, RESET);
}

void toggleRed1(){
	if(state == 1){
		setRedLed1();
		state = 0;
		return;
	}
	state = 1;
}
void toggleYellow1(){
	if(state == 1){
		setYellowLed1();
		state = 0;
		return;
	}
	state = 1;
}
void toggleGreen1(){
	if(state == 1){
		setGreenLed1();
		state = 0;
		return;
	}
	state = 1;
}

void toggleRed2(){
	if(state2 == 1){
		setRedLed2();
		state2 = 0;
		return;
	}
	state2 = 1;
}
void toggleYellow2(){
	if(state2 == 1){
		setYellowLed2();
		state2 = 0;
		return;
	}
	state2 = 1;
}
void toggleGreen2(){
	if(state2 == 1){
		setGreenLed2();
		state2 = 0;
		return;
	}
	state2 = 1;
}

