//
// Created by kurum on 西暦2023年4月12日.
//

#include "Car.h"
void car_init()
{
    pinMode(C1,OUTPUT);
    pinMode(C2,OUTPUT);
    pinMode(C3,OUTPUT);
    pinMode(C4,OUTPUT);
    car_run(STOP);
}
void car_run(car_command mode )
{
    switch (mode) {
        case START:
            digitalWrite(C1,HIGH);
            digitalWrite(C3,HIGH);
            digitalWrite(C2,LOW);
            digitalWrite(C4,LOW);
            break;
        case BRAKE:
            digitalWrite(C1,HIGH);
            digitalWrite(C2,HIGH);
            digitalWrite(C3,HIGH);
            digitalWrite(C4,HIGH);
            break;
        case LEFT:
            digitalWrite(C1,LOW);
            digitalWrite(C2,HIGH);
            digitalWrite(C3,HIGH);
            digitalWrite(C4,LOW);
            break;
        case RIGHT:
            digitalWrite(C1,HIGH);
            digitalWrite(C3,LOW);
            digitalWrite(C2,LOW);
            digitalWrite(C4,HIGH);
            break;
        case BACK:
            digitalWrite(C1,LOW);
            digitalWrite(C3,LOW);
            digitalWrite(C2,HIGH);
            digitalWrite(C4,HIGH);
            break;
        case STOP:
            digitalWrite(C1,LOW);
            digitalWrite(C2,LOW);
            digitalWrite(C3,LOW);
            digitalWrite(C4,LOW);
            break;

    }
}