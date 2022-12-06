/*
 * input_reading.c
 *
 *  Created on: Nov 29, 2022
 *      Author: PC
 */

#include "input_reading.h"

//int TimeOutForKeyPress = 500;
//int TimeOutForKeyHold = 500;

int buttonFlags[NO_OF_BUTTONS];

// we define 4-stage buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer4[NO_OF_BUTTONS];
// we define a flag for a button pressed more than 1 second .
static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];
// we define counter for automatically increasing the value
// after the button is pressed more than 1 second .
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];

//user definition input port and input pin
#define INPUT_PORT GPIOA
uint16_t buttonPin[NO_OF_BUTTONS] = { 0x2000, 0x4000, 0x8000 };

void initButton() {
	//clear all buffers, counters and flags
	for (unsigned char i = 0; i < NO_OF_BUTTONS; i++) {
		debounceButtonBuffer1[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer2[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer3[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer4[i] = BUTTON_IS_RELEASED;
		buttonFlags[i] = BUTTON_FLAG_CLEAR;
		flagForButtonPress1s[i] = BUTTON_FLAG_CLEAR;
		counterForButtonPress1s[i] = 0;
	}
}

void button_reading(void) {
	for (unsigned char i = 0; i < NO_OF_BUTTONS; i++) {
		//propagate buffer stage 2 to stage 3
		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		//propagate buffer stage 1 to stage 2
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		//update the lasted button state in buffer 1
		//debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(INPUT_PORT, buttonPin[i]);
		if (i == 0) {
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(Button0_GPIO_Port,
			Button0_Pin);
		} else if (i == 1) {
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(Button1_GPIO_Port,
			Button1_Pin);
		} else if (i == 2) {
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(Button2_GPIO_Port,
			Button2_Pin);
		} else if (i == 3) {
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(Button3_GPIO_Port,
			Button3_Pin);
		}
		if ((debounceButtonBuffer2[i] == debounceButtonBuffer1[i])
				&& (debounceButtonBuffer2[i] == debounceButtonBuffer3[i])) {
			if (debounceButtonBuffer3[i] != debounceButtonBuffer4[i]) {
				//state different, mean there's a transition in button state
				debounceButtonBuffer4[i] = debounceButtonBuffer3[i];
				if (debounceButtonBuffer4[i] == BUTTON_IS_PRESSED) {
					//on falling edge of transition
//					TimeOutForKeyPress = 500;   //additional feature
					buttonFlags[i] = BUTTON_FLAG_SET;
				} else {
					//rising eadge, which mean button is release;
//					TimeOutForKeyPress[i]--;
					counterForButtonPress1s[i] = 0;
					debounceButtonBuffer4[i] = BUTTON_IS_RELEASED;
				}
			} else {
				//buffer same state, which mean key is still hold, increase counter
				if (debounceButtonBuffer4[i] == BUTTON_IS_PRESSED) {
					if (counterForButtonPress1s[i]
							< DURATION_FOR_AUTO_INCREASING) {
						counterForButtonPress1s[i]++;
						if (counterForButtonPress1s[i]
								== DURATION_FOR_AUTO_INCREASING) {
							flagForButtonPress1s[i] = BUTTON_FLAG_SET;
						}
					}
				}
			}
		}
	}
}

unsigned char isButtonPressed(unsigned char index) {
	if (index >= NO_OF_BUTTONS)
		return 0;
	if (buttonFlags[index] == BUTTON_FLAG_SET) {
		//clear button flags and return
		buttonFlags[index] = BUTTON_FLAG_CLEAR;
		return 1;
	} else
		return 0;
}

unsigned char isButtonPressed1s(unsigned char index) {
	if (index >= NO_OF_BUTTONS)
		return 0;
	if (flagForButtonPress1s[index] == BUTTON_FLAG_SET) {
		//clear button hold more than 1s flags and return
		flagForButtonPress1s[index] = BUTTON_FLAG_CLEAR;
		//clear counter
		counterForButtonPress1s[index] = 0;
		return 1;
	} else
		return 0;
}
