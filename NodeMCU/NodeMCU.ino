#include <ESP8266WiFi.h>
#include "FirebaseArduino.h"
// Set these to run example.

#define FIREBASE_HOST "https://smart-lock-eb15c.firebaseio.com/"
#define FIREBASE_AUTH "s7GPVjDKFVRDhi2argaA24nmWIemzRXLhYP3uvLm"
#define WIFI_SSID "Mountain"
#define WIFI_PASSWORD "eouj8028"

#define LED 14

void setup() {

  pinMode(LED,OUTPUT);

  digitalWrite(LED,0);

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("connecting");

  while (WiFi.status() != WL_CONNECTED) {

    Serial.print(".");

    delay(500);

  }

  Serial.println();

  Serial.print("connected: ");

  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
  if (Firebase.success()) {
      Serial.println("streaming ok");
  }

//  Firebase.setInt("LED_STATUS",0);

  }

void loop() {
  String x= Firebase.getString("led");
  int l=x.length()+1;
  char y[l];
  x.toCharArray(y, l);
  int z= atoi(y);
  Serial.println(z);
  
  digitalWrite(LED,z); 
 
  /*int a = Firebase.getInt("led");
  
  Serial.println(a);
  
  if(a==1)

  {

    digitalWrite(LED,HIGH);

  }

  else

  {

    digitalWrite(LED,LOW);

 }*/
  delay(1000);
}
