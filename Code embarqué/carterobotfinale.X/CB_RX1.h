/* 
 * File:   CB_RX1.h
 * Author: Table2
 *
 * Created on 7 novembre 2019, 10:19
 */

#ifndef CB_RX1_H
#define	CB_RX1_H

void CB_RX1_Add(unsigned char value);
unsigned char CB_RX1_Get(void);
unsigned char CB_RX1_isDataAvailable(void);
int CB_RX1_GetRemainingSize(void);
int CB_RX1_GetDataSize(void);

#endif	/* CB_RX1_H */

