#include <avr/io.h>
#include "adc.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/




void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	switch(Config_Ptr->prescaler)
	{
	case TWO:
				ADCSRA= (1<<ADEN) | (1<<ADPS0);
				break;
	case FOUR:
				ADCSRA= (1<<ADEN) | (1<<ADPS1);
				break;
	case EIGHT:
				ADCSRA= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
				break;
	case SIXTEEN:
				ADCSRA= (1<<ADEN) | (1<<ADPS2);
				break;
	case THIRTY_TWO:
				ADCSRA= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);
				break;
	case SIXTY_FOUR:
				ADCSRA= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS2);
				break;
	case HUNDERD_TWENTY_EIGHT:
				ADCSRA= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0) | (1<<ADPS2);
				break;

	}
	switch(Config_Ptr->ref_volt)
	{
	case AREF:
			ADMUX=0x00;
			break;
	case AVCC:
			ADMUX =(1<<REFS0);
			break;
	case INTERNAL:
			ADMUX =(1<<REFS0) | (1<<REFS1);
			break;
	}
}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADCW; /* Read the digital value from the data register */
}
