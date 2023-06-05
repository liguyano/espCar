#include <Arduino.h>
#include "Air724.h"
#include "Transport.h"
Air724 air724;
#define password "wwpdsg"
void setup()
{
    Serial.begin(115200);
    air724.init();//connect to air724
    while (!air724.connectTOServe("43.136.94.231",7001));
    air724.sendToTcp(password);
    air724.sendToTcp(password);
    air724.sendToTcp(password);
}
Transport tr(16,5);
String mess="";
void loop()
{
    mess=air724.recv();
    if (mess.length()>0)
    {
        air724.sendToTcp(mess);
        if (mess.startsWith("CAR"))
        {
            switch (mess.charAt(3)) {
                case 'W':
                    tr.send(0xc1);
                    break;
                case 'S':
                    tr.send(0xc0);break;
                case 'B':
                    tr.send(0xc2);break;
                case 'L':
                    tr.send(0xc4);break;
                case 'R':
                    tr.send(0xc5);break;
            }
        } else if (mess.startsWith("TEM"))
        {
            tr.send('T');
            air724.sendToTcp("temp:"+String(tr.recv()*255+tr.recv()));
            tr.send('H');
            air724.sendToTcp("humi:"+String(tr.recv()*255+tr.recv()));
        }

    }
}