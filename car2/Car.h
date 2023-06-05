//
// Created by kurum on 西暦2023年4月12日.
//

#ifndef COLLISIONMODE_CAR_H
#define COLLISIONMODE_CAR_H
#include "Arduino.h"
#define C1 5
#define C2 16
#define C3 0
#define C4 4
enum car_command
{
    START =0x01,
    STOP=0x02,
    BRAKE=0x03,
    LEFT=0x04,
    RIGHT=0x05,
    BACK=0x06
};
void car_init();
void car_run(car_command mode );


#endif //COLLISIONMODE_CAR_H
