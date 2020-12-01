//#include <xc.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include "CB_RX1.h"
//#define CB_RX1_BUFFER_SIZE 128
//
//int cbRx1Head;
//int cbRx1Tail;
//unsigned char cbRx1Buffer[CB_RX1_BUFFER_SIZE];
//
//void CB_RX1_Add(unsigned char value)
//{
//    if(CB_RX1_GetRemainingSize()>0)
//    {
//        cbRx1Buffer[cbRx1Head++] = value;
//        
//        if (cbRx1Head > CB_RX1_BUFFER_SIZE)
//            cbRx1Head = 0;
//    }
//}
//
//unsigned char CB_RX1_Get(void)
//{
//    unsigned char value = cbRx1Buffer[cbRx1Tail++];
//    if (cbRx1Tail > CB_RX1_BUFFER_SIZE)
//        cbRx1Tail = 0;
//    return value;
//}
//
//unsigned char CB_RX1_isDataAvailable(void){
//    if(cbRx1Head != cbRx1Tail)
//        return 1;
//    else
//        return 0;
//}
//
//void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void)
//{
//    IFS0bits.U1RXIF = 0;//clearRX flag
//    
//    //check receive error
//    if(U1STAbits.FERR == 1)
//        U1STAbits.FERR = 0;
//    
//    //clear error to keep uart receiving
//    if (U1STAbits.OERR ==1)
//        U1STAbits.OERR = 0;
//    
//    while(U1STAbits.URXDA == 1){
//        CB_RX1_Add(U1RXREG);
//    }
//}
//
//int CB_RX1_GetRemainingSize(void)
//{
//    return CB_RX1_BUFFER_SIZE - CB_RX1_GetDataSize();
//}
//
//int CB_RX1_GetDataSize(void){
//    int dataSize;
//    if (cbRx1Head >= cbRx1Tail)
//        dataSize = cbRx1Head - cbRx1Tail;
//    else
//        dataSize = CB_RX1_BUFFER_SIZE  - (cbRx1Tail - cbRx1Head);
//    return dataSize;
//}
