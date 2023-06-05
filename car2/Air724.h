//
// Created by kurum on 西暦2023年6月4日.
//

#ifndef COLLISIONMODE_AIR724_H
#define COLLISIONMODE_AIR724_H

#include <Arduino.h>
class Air724 {
private:
    String a="";
    String tem="";
public:

    Air724();
    void init();
    int connectTOServe(String ip, int port);
    String send(String data);
    String recv();
    String sendToTcp(String messa);
    String recv_tcp();


};


#endif //COLLISIONMODE_AIR724_H
