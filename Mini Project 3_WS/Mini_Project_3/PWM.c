#include "PWM.h"
#include <avr/io.h>

void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0; //Set Timer Initial value
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) |(1<<CS01);
	OCR0 = duty_cycle;
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

}
