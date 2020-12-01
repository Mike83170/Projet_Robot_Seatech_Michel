/* 
 * File:   ADC.h
 * Author: TP-EO-5
 *
 * Created on 21 octobre 2020, 13:41
 */

#ifndef ADC_H
#define	ADC_H

void InitADC1();
void __attribute__((interrupt, no_auto_psv)) _AD1Interrupt();
void ADC1StartConversionSequence();
unsigned int * ADCGetResult();
unsigned char ADCIsConversionFinished();
void ADCClearConversionFinishedFlag();

#endif	/* ADC_H */

