#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"
#include "gpio.h"
#include <avr/io.h>
#include "PWM.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DCMotor_Port PORTB_ID

#define DCMotor_Input1_pin PB0
#define DCMotor_Input2_pin PB1
#define DCMotor_Enable_pin PB3

#define DCMotor_SetPinDirection() {\
	GPIO_setupPinDirection(DCMotor_Port, DCMotor_Input1_pin, PIN_OUTPUT);\
	GPIO_setupPinDirection(DCMotor_Port, DCMotor_Input2_pin, PIN_OUTPUT);\
}

#define DCMotor_stop() { \
	GPIO_writePin(DCMotor_Port , DCMotor_Input1_pin , LOGIC_LOW);\
	GPIO_writePin(DCMotor_Port,DCMotor_Input2_pin, LOGIC_LOW);\
}

#define DCMotor_CW(speed) { \
	GPIO_writePin(DCMotor_Port,DCMotor_Input1_pin, LOGIC_LOW);\
	GPIO_writePin(DCMotor_Port,DCMotor_Input2_pin, LOGIC_HIGH);\
	PWM_Timer0_Start((speed/100.00)*255);\
}

#define DCMotor_CCW(speed) { \
	GPIO_writePin(DCMotor_Port,DCMotor_Input1_pin, LOGIC_HIGH);\
	GPIO_writePin(DCMotor_Port,DCMotor_Input2_pin, LOGIC_LOW);\
	PWM_Timer0_Start((speed/100.00)*255);\
}

typedef enum
{
Stop, CW, CCW
}DcMotor_State;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* MOTOR_H_ */
