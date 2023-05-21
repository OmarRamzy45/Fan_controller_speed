#include "adc.h"
#include "gpio.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "Motor.h"
#include "PWM.h"

int main (void)
{
	ADC_ConfigType ADC_Config = {Division_factor_8,INTERNAL};
	uint8 temp;

	LCD_init();
	ADC_init( &ADC_Config );
	DcMotor_Init();

	while (1)
	{
		temp = LM35_getTemperature();

		if (temp >= 120)
		{
			DcMotor_Rotate(CW, 100);
			LCD_displayStringRowColumn(0, 1, "Fan is  ON");
			LCD_displayStringRowColumn(1, 1, "Temp = ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
		}

		else if (temp >= 90)
		{
			DcMotor_Rotate(CW, 75);
			LCD_displayStringRowColumn(0, 1, "Fan is  ON");
			LCD_displayStringRowColumn(1, 1, "Temp = ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			if (temp <100)
			{
				LCD_moveCursor(1, 9);
				LCD_displayCharacter(' ');

			}
		}
		else if (temp >= 60)
		{
			DcMotor_Rotate(CW, 50);
			LCD_displayStringRowColumn(0, 1, "Fan is  ON");
			LCD_displayStringRowColumn(1, 1, "Temp = ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			LCD_moveCursor(1, 9);
			LCD_displayCharacter(' ');

		}


		else if (temp >= 30)
		{
			LCD_displayStringRowColumn(0, 1, "Fan is  ON");
			LCD_displayStringRowColumn(1, 1, "Temp = ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 25);
			LCD_moveCursor(1, 9);
			LCD_displayCharacter(' ');
		}

		else if (temp < 30)
		{
			DcMotor_Rotate(Stop,0);
			LCD_displayStringRowColumn(0, 1, "Fan is OFF");
			LCD_displayStringRowColumn(1, 1, "Temp = ");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			if (temp < 10)
			{
				LCD_moveCursor(1, 8);
				LCD_displayCharacter(' ');
			}
		}
	}

	return 0;
}
