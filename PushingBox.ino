
// Add your PushingBox Scenario DeviceID here:
  char devid[] = "vC44A9599CFC24AA";

//String serverName[] = "api.pushingbox.com";
boolean DEBUG = true;
#include <Bridge.h>
#include <HttpClient.h>
#include <math.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int B = 4275;
int colorR = 60;
int colorG = 20;
int colorB = 255;
void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

      lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    lcd.print("Humidity");
  Serial.begin(9600);
  while (!Serial); // wait for a serial connection
}

void loop() {
  // Initialize the client library
  HttpClient client;

  //Setup sensorValue to read a value from Analog Port A0
  int sensorValue = analogRead(A0);
  float R = 1023.0/sensorValue-1.0;
    R = 100000*R;

    double temperature = 1.0/(log(R/100000)/B+1/298.15)-273.15+30;
  //Testing value - when sensor is not connected - comment out when sketch is shown to be working - and take value from A0 instead
  //sensorValue=1500;

  // Make a HTTP request:  
  String APIRequest;
  //APIRequest = String(serverName) + "/pushingbox?devid=" + String(devid)+ "&IDtag=100&TimeStamp=50&TempC="+sensorValue;
  APIRequest = "api.pushingbox.com/pushingbox?devid=" + String(devid)+"&TempC="+temperature;
  client.get (APIRequest);
  
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();

  }
  lcd.setCursor(0, 1);
    lcd.print(temperature);
  Serial.flush();
  String UploadMessage;
  Serial.print("\n Uploaded temp value: ");
  Serial.print(sensorValue);
  delay(5000);
}

