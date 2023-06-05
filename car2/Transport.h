//
// Created by kurum on 西暦2023年4月12日.
//

#ifndef COLLISIONMODE_TRANSPORT_H
#define COLLISIONMODE_TRANSPORT_H

#include "Arduino.h"
#define TRANSPORT_ERRO_TIME_OUT 1
#define TRSNSPORT_ERRO_WAIT_ANS_TOO_LONG 2
#define TRSNSPORT_ERRO_WAIT_SEND 3
class Transport {
public:
    Transport(unsigned char T,unsigned char R);
    void wait_send();
    void send(unsigned char dat);
    unsigned char recv();
    void init();
private:
    unsigned int erro;
public:
    unsigned int getErro() const;

private:
    unsigned char TT;
    unsigned char RT;
};


#endif //COLLISIONMODE_TRANSPORT_H
