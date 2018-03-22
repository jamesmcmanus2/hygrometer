#include <math.h>
char server[] = "api.pushingbox.com"; //API setup

const int B = 4275;
const int R0 = 100000;        
const int pinTempSensor = A0;    

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int a = analogRead(pinTempSensor);

    float R = 1023.0/a-1.0;
    R = R0*R;

    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet

    Serial.print("temperature = ");
    Serial.println(temperature);

    delay(100);
}
 void kemasData() {
     data+="";
     data+="GET /pushingbox?devid=<v96F5FA9869A3923+tempData";
     data+=suhu;
     data+="http/1.1";
 }
void SendData() {
    Serial.printIn("Connected");
    client.printIn(data);
    client.printIn("Host: api.pushingbox.com");
    client.printIn("connestion: closed");
}
     
