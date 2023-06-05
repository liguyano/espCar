//
// Created by kurum on 西暦2023年4月12日.
//

#include "Transport.h"

Transport::Transport(unsigned char T, unsigned char R):TT(T),RT(R) {
    pinMode(TT,OUTPUT);
    digitalWrite(TT,HIGH);
    digitalWrite(RT,HIGH);
    pinMode(RT,INPUT);
}

void Transport::send(unsigned char dat) {
    int timer=0;
    erro=0;
    a:
    timer=0;
    digitalWrite(TT,HIGH);
    delay(10);
    digitalWrite(TT,LOW);
    delay(5);
   // Serial.println("wait anser");
    while (digitalRead(RT))
    {
        delay(5);
        timer++;
        if (timer%100==0)
        {
            digitalWrite(TT,HIGH);
            delay(10);
            digitalWrite(TT,LOW);
            delay(5);
        }

        if (timer>=2000)
        {
            erro=TRSNSPORT_ERRO_WAIT_ANS_TOO_LONG;
            goto end;
        }
    }
   // Serial.println("get answeer");
    for (int i = 0; i < 8; ++i) {
        timer=0;
        while (!digitalRead(RT))
        {
            timer++;
            if (timer>=2000)
            {erro=TRANSPORT_ERRO_TIME_OUT;
                goto end;}
            delay(1);
        }
        if (dat&(0x80>>i))
        {
            digitalWrite(TT,HIGH);
           // Serial.print(1);
        }
        else
        {
            digitalWrite(TT,LOW);
            //Serial.print(0);
        }
        while (digitalRead(RT))
        {
            timer++;
            if (timer>=2000)
            {
                erro=TRANSPORT_ERRO_TIME_OUT;
                goto end;
            }
            delay(1);
        }
    }
    end:
    digitalWrite(TT,HIGH);
    delay(10);
}

unsigned char Transport::recv() {
    erro=0;
    this->wait_send();
    if (this->getErro())
    {
        return this->getErro();
    }
   // Serial.println("ready to received");
    unsigned char re=0;
    digitalWrite(TT,LOW);
    delay(200);
    for (int i = 0; i < 8; ++i) {
        digitalWrite(TT,HIGH);
        delay(50);
        if (digitalRead(RT))
        {
            re |= (0x80>>i);
        }
        digitalWrite(TT,LOW);
        delay(50);
    }
    //Serial.println(' ');
    return re;
}

void Transport::wait_send() {
    int timer;
    erro=0;
    timer=0;
   // Serial.println("wait to be high");
    while (!digitalRead(RT)){
        timer++;
        if (timer>2000)
        {
            erro=TRSNSPORT_ERRO_WAIT_SEND;
            return;
        }

        delay(1);
    }
   // Serial.println("wait to be low");
    timer=0;
    while (digitalRead(RT)){
        timer++;
        if (timer>2000)
        {
            erro=TRSNSPORT_ERRO_WAIT_SEND;
            return;
        }
        delay(1);
    }

   // Serial.println("ready");
}

void Transport::init() {
    pinMode(TT,OUTPUT);
    digitalWrite(TT,HIGH);
    pinMode(RT,INPUT);
}

unsigned int Transport::getErro() const {
    return erro;
}


