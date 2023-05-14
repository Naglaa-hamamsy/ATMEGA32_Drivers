#ifndef ULTRASONIC_H
#define ULTRASONIC_H




/*
 *  Description :1- Get Ultasonic Reading 
     Inputs      : Void
     Return      : u16 Reading (Distance)
 * */

/*Note that you don't need to configure any configuration in timer config */
u16 ULTRASONIC_GetDistance(void);

#endif