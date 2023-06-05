//
// Created by kurum on 西暦2023年6月4日.
//

#include "Air724.h"

Air724::Air724() {


}

String Air724::recv() {

    return Serial.readString();
}
bool isAlphaNumeric(char ch) {
    if (isalnum(ch) || ch == '!' || ch == '"' || ch == '#' || ch == '$' || ch == '%' || ch == '&' || ch == '\'' || ch == '(' || ch == ')' || ch == '*' || ch == '+' || ch == ',' || ch == '-' || ch == '.' || ch == '/' || ch == ':' || ch == ';' || ch == '<' || ch == '=' || ch == '>' || ch == '?' || ch == '@' || ch == '[' || ch == '\\' || ch == ']' || ch == '^' || ch == '_' || ch == '`' || ch == '{' || ch == '|' || ch == '}' || ch == '~') {
        return true;
    } else {
        return false;
    }
}
String Air724::send(String data) {
    Serial.println(data);
    unsigned long start=millis();
    unsigned long end;
    while (!Serial.available())
    {
        delay(1);
        end= millis()-start;
        if (end>200)
        {
            Serial.println(data);
        }
    }
    String rc=Serial.readString();

    a="";
    for (auto ca:rc) {
        if (isAlphaNumeric(ca))
        {
            a+=ca;
        }
    }
    return a;
}

String Air724::sendToTcp(String messa) {
    tem="";
    tem="AT+CIPSEND="+String(messa.length());
    tem+="\r"+messa+"\r";
    return send(tem);
}

String Air724::recv_tcp() {
    return send("AT+CIPRECVMODE=1,1024");
}
