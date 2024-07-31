#include"dc_motor.h"
#include"lcd.h"
#include "adc.h"
#include "PWM.h"
#include "lm35_sensor.h"
#include <util/delay.h>
int main()
{	uint8 value;
	ADC_ConfigType ADC_INPUT;
	ADC_INPUT.prescaler=EIGHT;
	ADC_INPUT.ref_volt=INTERNAL;
	ADC_ConfigType  const *ADC_POINTER;
	ADC_POINTER=&ADC_INPUT;
	LCD_init();
	_delay_ms(5);
	ADC_init(ADC_POINTER);
	DcMotor_Init();
while(1)
{
	value= LM35_getTemperature();
	if(value<30)
	{
		DcMotor_Rotate(STOP,0);
		LCD_displayStringRowColumn(0,0,"FAN IS OFF");
		LCD_displayStringRowColumn(1,0,"Temp=");
		LCD_intgerToString(value);
		LCD_displayStringRowColumn(1,7,"C");
	}
	else if((value>=30) && (value<60))
	{
		DcMotor_Rotate(CW,25);
		LCD_displayStringRowColumn(0,0,"FAN IS ON ");
		LCD_displayStringRowColumn(1,0,"Temp=");
		LCD_intgerToString(value);
		LCD_displayStringRowColumn(1,7,"C");
	}
	else if((value>=60) && (value<90))
	{
		DcMotor_Rotate(CW,50);
		LCD_displayStringRowColumn(0,0,"FAN IS ON ");
		LCD_displayStringRowColumn(1,0,"Temp=");
		LCD_intgerToString(value);
		LCD_displayStringRowColumn(1,7,"C");

	}
	else if((value>=90) && (value<120))
	{
		DcMotor_Rotate(CW,75);
		LCD_displayStringRowColumn(0,0,"FAN IS ON ");;
		LCD_displayStringRowColumn(1,0,"Temp=");
		LCD_intgerToString(value);
		LCD_displayStringRowColumn(1,8,"C");
	}
	else
	{
		DcMotor_Rotate(CW,100);
		LCD_displayStringRowColumn(0,0,"FAN IS ON ");
		LCD_displayStringRowColumn(1,0,"Temp=");
		LCD_intgerToString(value);
		LCD_displayStringRowColumn(1,8,"C");
	}
}
}
