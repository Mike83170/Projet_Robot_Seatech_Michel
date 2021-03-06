#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "ChipConfig.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"
#include "ADC.h"
#include "Robot.h"
#include "main.h"
#include "UART.h"
unsigned char stateRobot;

void OperatingSystemLoop(void) {
//    switch (stateRobot) {
//        case STATE_ATTENTE:
//            timestamp = 0;
//            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
//            stateRobot = STATE_ATTENTE_EN_COURS;
//
//        case STATE_ATTENTE_EN_COURS:
//            if (timestamp > 1000)
//                stateRobot = STATE_AVANCE;
//            break;
//
//        case STATE_AVANCE:
//            PWMSetSpeedConsigne(20, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(20, MOTEUR_GAUCHE);
//            stateRobot = STATE_AVANCE_EN_COURS;
//            break;
//        case STATE_AVANCE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_GAUCHE:
//            PWMSetSpeedConsigne(20, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(0, MOTEUR_GAUCHE);
//            stateRobot = STATE_TOURNE_GAUCHE_EN_COURS;
//            break;
//        case STATE_TOURNE_GAUCHE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_DROITE:
//            PWMSetSpeedConsigne(0, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(20, MOTEUR_GAUCHE);
//            stateRobot = STATE_TOURNE_DROITE_EN_COURS;
//            break;
//        case STATE_TOURNE_DROITE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_SUR_PLACE_GAUCHE:
//            PWMSetSpeedConsigne(10, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(-10, MOTEUR_GAUCHE);
//            stateRobot = STATE_TOURNE_SUR_PLACE_GAUCHE_EN_COURS;
//            break;
//        case STATE_TOURNE_SUR_PLACE_GAUCHE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        case STATE_TOURNE_SUR_PLACE_DROITE:
//            PWMSetSpeedConsigne(-10, MOTEUR_DROIT);
//            PWMSetSpeedConsigne(10, MOTEUR_GAUCHE);
//            stateRobot = STATE_TOURNE_SUR_PLACE_DROITE_EN_COURS;
//            break;
//        case STATE_TOURNE_SUR_PLACE_DROITE_EN_COURS:
//            SetNextRobotStateInAutomaticMode();
//            break;
//
//        default:
//            stateRobot = STATE_ATTENTE;
//            break;
//    }
}

unsigned char nextStateRobot = 0;

void SetNextRobotStateInAutomaticMode() {
    unsigned char positionObstacle = PAS_D_OBSTACLE;

    //D�termination de la position des obstacles en fonction des t�l�m�tres
    if (robotState.distanceTelemetreDroit < 40 &&
            robotState.distanceTelemetreCentre > 30 &&
            robotState.distanceTelemetreGauche > 40) //Obstacle � droite
        positionObstacle = OBSTACLE_A_DROITE;
    else if (robotState.distanceTelemetreDroit > 40 &&
            robotState.distanceTelemetreCentre > 30 &&
            robotState.distanceTelemetreGauche < 40) //Obstacle � gauche
        positionObstacle = OBSTACLE_A_GAUCHE;
    else if (robotState.distanceTelemetreCentre < 30) //Obstacle en face
        positionObstacle = OBSTACLE_EN_FACE;
    else if (robotState.distanceTelemetreDroit > 40 &&
            robotState.distanceTelemetreCentre > 30 &&
            robotState.distanceTelemetreGauche > 40) //pas d?obstacle
        positionObstacle = PAS_D_OBSTACLE;

    //D�termination de l?�tat � venir du robot
    if (positionObstacle == PAS_D_OBSTACLE)
        nextStateRobot = STATE_AVANCE;
    else if (positionObstacle == OBSTACLE_A_DROITE)
        nextStateRobot = STATE_TOURNE_GAUCHE;
    else if (positionObstacle == OBSTACLE_A_GAUCHE)
        nextStateRobot = STATE_TOURNE_DROITE;
    else if (positionObstacle == OBSTACLE_EN_FACE)
        nextStateRobot = STATE_TOURNE_SUR_PLACE_GAUCHE;

    //Si l?on n?est pas dans la transition de l?�tape en cours
    if (nextStateRobot != stateRobot - 1)
        stateRobot = nextStateRobot;
}

int main(void) {
    /***************************************************************************************************/
    //Initialisation de l?oscillateur
    /****************************************************************************************************/
    InitOscillator();

    /****************************************************************************************************/
    // Configuration des entr�es sorties
    /****************************************************************************************************/
    InitIO();

    InitTimer23();

    InitTimer1();

    InitPWM();

    InitADC1();
    InitTimer4();
    InitUART();
    //    PWMUpdateSpeed() ;


    LED_BLANCHE = 1;
    LED_BLEUE = 1;
    LED_ORANGE = 1;

    /****************************************************************************************************/
    // Boucle Principale
    /****************************************************************************************************/
    while (1) {
        /* LED_BLANCHE = !LED_BLANCHE; */
        /*LED_ORANGE = !LED_ORANGE; */
        /*LED_BLEUE = !LED_BLEUE; */
        //        if (ADCIsConversionFinished() == 1) {
        //            ADCClearConversionFinishedFlag();
        //            unsigned int * result = ADCGetResult();
//        SendMessageDirect ((unsigned char *) "Bonjour" , 7 ) ;
//        __delay32 (40000000);
         //  int i;
//        for (i = 0; i < CB_RX1_GetDataSize(); i++) {
//            unsigned char c = CB_RX1_Get();
//            SendMessage(c,1);
//        }
       // __delay32(1000);
        if (ADCIsConversionFinished() == 1) {
            ADCClearConversionFinishedFlag();
            unsigned int * result = ADCGetResult();
            float volts = ((float) result [2])*3.3 / 4096 * 3.2;
            robotState.distanceTelemetreGauche = 34 / volts - 5;
            volts = ((float) result [1])*3.3 / 4096 * 3.2;
            robotState.distanceTelemetreCentre = 34 / volts - 5;
            volts = ((float) result [0])*3.3 / 4096 * 3.2;
            robotState.distanceTelemetreDroit = 34 / volts - 5;

            if (robotState.distanceTelemetreGauche > 30)
                LED_BLANCHE = 0;
            else
                LED_BLANCHE = 1;
            if (robotState.distanceTelemetreCentre > 30)
                LED_BLEUE = 0;
            else
                LED_BLEUE = 1;
            if (robotState.distanceTelemetreDroit > 30)
                LED_ORANGE = 0;
            else
                LED_ORANGE = 1;
        }
    } // fin main
}


//void PWMSetSpeed(float 50)
