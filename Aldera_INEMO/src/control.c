/*
 * control.c
 *
 *  Created on: Jun 9, 2014
 *  Template: Callen Fisher
 *  Author: Roberto Aldera
 *
 */

#include "control.h"

void getEncoder(float*shaft_angle, float*shaft_revs,
		uint8_t*last_encoderA_state, uint8_t*last_encoderB_state) {
	uint8_t current_encoderA_state = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5);
	uint8_t current_encoderB_state = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4);

	if (current_encoderA_state != *last_encoderA_state) {
		//transition has occurred
		//now check if A was going up or down
		//and check if B was low or high
		//this will enable determination of direction
		if (current_encoderA_state != 0 && current_encoderB_state == 0) {
			//each increment is one tenth of a revolution
			*shaft_revs = *shaft_revs + 0.1;
			*last_encoderA_state = current_encoderA_state;
		} else if (current_encoderA_state == 0 && current_encoderB_state != 0) {
			*shaft_revs = *shaft_revs + 0.1;
			*last_encoderA_state = current_encoderA_state;
		} else if (current_encoderA_state != 0 && current_encoderB_state != 0) {
			*shaft_revs = *shaft_revs - 0.1;
			*last_encoderA_state = current_encoderA_state;
		} else if (current_encoderA_state == 0 && current_encoderB_state == 0) {
			*shaft_revs = *shaft_revs - 0.1;
			*last_encoderA_state = current_encoderA_state;
		}

	}
	if (*shaft_angle >= 360) {
		//*shaft_revs = *shaft_revs + 1;
		*shaft_angle = 0;
	}
}

void controlMethod(float*acc, float*mag, float*gyro, s8*temp, float*angles,
		float*PWMval) //perform all control in this method
{
	//read all the data
	//getAcc(acc8, acc); //send the floats as well
	//getMag(mag);
	//getGyro(gyro8, gyro);
	//getTemp(temp);

	//perform the control here
	//this is original code from Stacey's demo
	/*
	 angles[0] = 5;
	 angles[1] = 12.1;
	 angles[2] = -12.1;
	 *PWMval = 15;
	 setPWM(PWMval);
	 */
	//end of Stacey's code
	//debugging code
	//3 floats sent in angles (12 bytes total)
	angles[0] = 1.23;
	angles[1] = -1.23;
	angles[2] = 3.45;

	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0) {
		*PWMval = 35;
		setPWM(PWMval);
	} else {
		*PWMval = 0;
		setPWM(PWMval);
	}

}
