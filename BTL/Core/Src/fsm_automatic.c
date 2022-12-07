/*
 * fsm_automatic.c
 *
 *  Created on: Nov 29, 2022
 *      Author: PC
 */

#include "fsm_automatic.h"

void fsm1_automatic_run() {
	switch (status1) {
	case INIT:
		//TODO
		setRedLed1();
		status1 = AUTO_RED;
		lastState1 = status1;
		setTimer1(red_duration1);
		setTimer3(100);
		timeCountdown1 = red_duration1 / 100;
		mode = 1;
		break;

	case AUTO_RED:
		//TODO
		setRedLed1();
		mode = 1;
		if (isTimer3Expired()) {
			setTimer3(100);
			timeCountdown1--;
			writeMess(timeCountdown1);
		}
		if (isTimer1Expired() == 1) {
			setTimer1(green_duration1);
			status1 = AUTO_GREEN;
			setTimer3(100);
			timeCountdown1 = green_duration1 / 100;
		}

		if (isButtonPressed(0)) {
			clearAllLed();
			lastState1 = status1;
			lastState2 = status2;
			status1 = WAIT;
			status2 = WAIT;
			status3 = MODIFY_RED1;
			clearTimer1();
			clearTimer2();
			clearTimer3();
			clearTimer4();
			setTimer1(100);
		}
		break;

	case AUTO_GREEN:
		//TODO
		mode = 1;
		setGreenLed1();
		if (isTimer3Expired()) {
			setTimer3(100);
			timeCountdown1--;
			writeMess(timeCountdown1);
		}
		if (isTimer1Expired() == 1) {
			setTimer1(yellow_duration1);
			status1 = AUTO_YELLOW;
			setTimer3(100);
			timeCountdown1 = yellow_duration1 / 100;
		}

		if (isButtonPressed(0)) {
			clearAllLed();
			lastState1 = status1;
			lastState2 = status2;
			status1 = WAIT;
			status2 = WAIT;
			status3 = MODIFY_RED1;
			clearTimer1();
			clearTimer2();
			clearTimer3();
			clearTimer4();
			setTimer1(100);
		}
		break;

	case AUTO_YELLOW:
		//TODO
		mode = 1;
		setYellowLed1();
		if (isTimer3Expired()) {
			setTimer3(100);
			timeCountdown1--;
			writeMess(timeCountdown1);
		}
		if (isTimer1Expired() == 1) {
			setTimer1(red_duration1);
			status1 = AUTO_RED;
			setTimer3(100);
			timeCountdown1 = red_duration1 / 100;
		}

		if (isButtonPressed(0)) {
			clearAllLed();
			lastState1 = status1;
			lastState2 = status2;
			status1 = WAIT;
			status2 = WAIT;
			status3 = MODIFY_RED1;
			clearTimer1();
			clearTimer2();
			clearTimer3();
			clearTimer4();
			setTimer1(100);
		}
		break;

	case WAIT:
		if (lastState1 == AUTO_RED && returnFlag1) {
			clearAllLed();
			status1 = lastState1;
			returnFlag1 = 0;
			setTimer3(100);
			setTimer1(red_duration1);
			timeCountdown1 = red_duration1 / 100;
		}
		if (lastState1 == AUTO_GREEN && returnFlag1) {
			returnFlag1 = 0;
			status1 = lastState1;
			clearAllLed();
			setTimer3(100);
			setTimer1(green_duration1);
			timeCountdown1 = green_duration1 / 100;
		}
		if (lastState1 == AUTO_YELLOW && returnFlag1) {
			returnFlag1 = 0;
			status1 = lastState1;
			clearAllLed();
			setTimer3(100);
			setTimer1(yellow_duration1);
			timeCountdown1 = yellow_duration1 / 100;
		}
		break;
	default:
		break;
	}
}

void fsm2_automatic_run() {
	switch (status2) {
	case INIT:
		//TODO
		setGreenLed2();
		status2 = AUTO_GREEN;
		lastState2 = status2;
		setTimer2(green_duration2);
		setTimer4(100);
		timeCountdown2 = green_duration2 / 100;
		mode = 1;
		break;

	case AUTO_RED:
		//TODO
		setRedLed2();
		mode = 1;
		if (isTimer4Expired()) {
			setTimer4(100);
			timeCountdown2--;
		}
		if (isTimer2Expired() == 1) {
			setTimer2(green_duration2);
			status2 = AUTO_GREEN;
			setTimer4(100);
			timeCountdown2 = green_duration2 / 100;
		}

		if (isButtonPressed(0)) {
			clearAllLed();
			lastState1 = status1;
			lastState2 = status2;
			status1 = WAIT;
			status2 = WAIT;
			status3 = MODIFY_RED1;
			clearTimer1();
			clearTimer2();
			clearTimer3();
			clearTimer4();
			setTimer1(100);
		}
		break;

	case AUTO_GREEN:
		//TODO
		mode = 1;
		setGreenLed2();
		if (isTimer4Expired()) {
			setTimer4(100);
			timeCountdown2--;
		}
		if (isTimer2Expired() == 1) {
			setTimer2(yellow_duration2);
			status2 = AUTO_YELLOW;
			setTimer4(100);
			timeCountdown2 = yellow_duration2 / 100;
		}

		if (isButtonPressed(0)) {
			clearAllLed();
			lastState1 = status1;
			lastState2 = status2;
			status1 = WAIT;
			status2 = WAIT;
			status3 = MODIFY_RED1;
			clearTimer1();
			clearTimer2();
			clearTimer3();
			clearTimer4();
			setTimer1(100);
		}
		break;

	case AUTO_YELLOW:
		//TODO
		mode = 1;
		setYellowLed2();
		if (isTimer4Expired()) {
			setTimer4(100);
			timeCountdown2--;
		}
		if (isTimer2Expired() == 1) {
			setTimer2(red_duration2);
			status2 = AUTO_RED;
			setTimer4(100);
			timeCountdown2 = red_duration2 / 100;
		}

		if (isButtonPressed(0)) {
			clearAllLed();
			lastState1 = status1;
			lastState2 = status2;
			status1 = WAIT;
			status2 = WAIT;
			status3 = MODIFY_RED1;
			clearTimer1();
			clearTimer2();
			clearTimer3();
			clearTimer4();
			setTimer1(100);
		}
		break;

	case WAIT:
		if (lastState2 == AUTO_RED && returnFlag2) {
			clearAllLed();
			status2 = lastState2;
			returnFlag2 = 0;
			setTimer4(100);
			setTimer2(red_duration2);
			timeCountdown2 = red_duration2 / 100;
		}
		if (lastState2 == AUTO_GREEN && returnFlag2) {
			returnFlag2 = 0;
			status2 = lastState2;
			clearAllLed();
			setTimer4(100);
			setTimer2(green_duration2);
			timeCountdown2 = green_duration2 / 100;
		}
		if (lastState2 == AUTO_YELLOW && returnFlag2) {
			returnFlag2 = 0;
			status2 = lastState2;
			clearAllLed();
			setTimer4(100);
			setTimer2(yellow_duration2);
			timeCountdown2 = yellow_duration2 / 100;
		}
		break;
	default:
		break;
	}
}
