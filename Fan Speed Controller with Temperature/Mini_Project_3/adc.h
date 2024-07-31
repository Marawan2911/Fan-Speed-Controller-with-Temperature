#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

typedef enum{INTERNAL,AREF,AVCC}ADC_ReferenceVolatge;
typedef enum{TWO=2,FOUR=4,EIGHT=8,SIXTEEN=16,THIRTY_TWO=32,SIXTY_FOUR=64,HUNDERD_TWENTY_EIGHT=128}ADC_Prescaler;

typedef struct{
      ADC_ReferenceVolatge ref_volt;
      ADC_Prescaler prescaler;
}ADC_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
