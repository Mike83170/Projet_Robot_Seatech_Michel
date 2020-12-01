/* 
 * File:   CB_TX1.h
 * Author: Table2
 *
 * Created on 7 novembre 2019, 09:07
 */

#ifndef CB_TX1_H
#define	CB_TX1_H

void CB_TX1_Add(unsigned char value);
unsigned char CB_TX1_Get(void);
void SendMessage(unsigned char* message, int length);
void SendOne();
unsigned char CB_TX1_IsTransmitting(void);
int CB_TX1_RemainingSize(void);


#endif	/* CB_TX1_H */

