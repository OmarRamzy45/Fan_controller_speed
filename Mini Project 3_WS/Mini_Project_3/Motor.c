#include "Motor.h"

void DcMotor_Init(void)
{
	DCMotor_SetPinDirection();
	DCMotor_stop();
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if (state == Stop)
	{
		DCMotor_stop();
	}
	else if (state == CW)
	{
		DCMotor_CW(speed);
	}
	else
	{
		DCMotor_CCW(speed);
	}
}
