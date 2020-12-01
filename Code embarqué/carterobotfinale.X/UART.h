/* 
 * File:   UART.h
 * Author: utilisateur
 *
 * Created on 29 novembre 2020, 01:21
 */

#ifndef UART_H
#define	UART_H

void InitUART(void);
void SendMessageDirect();
void __attribute__ ((interrupt, no_auto_psv)) _U1RXInterrupt();

#endif	/* UART_H */

