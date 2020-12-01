/* 
 * File:   PWM.h
 * Author: Table2
 *
 * Created on 1 octobre 2020, 12:19
 */

#ifndef PWM_H
#define	PWM_H

#define MOTEUR_DROIT 0
#define MOTEUR_GAUCHE 1

void InitPWM(void);
void PWMSetSpeedConsigne(float vitesseEnPourcents, unsigned char numMoteur) ;
void PWMUpdateSpeed();

#endif	/* PWM_H */

