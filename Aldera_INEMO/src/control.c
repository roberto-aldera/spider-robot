/*
 * control.c
 *
 *  Created on: Jun 9, 2014
 *      Author: Callen Fisher
 */

#include "control.h"

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
		*PWMval = 15;
		setPWM(PWMval);
	} else {
		*PWMval = 0;
		setPWM(PWMval);
	}
}
