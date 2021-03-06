#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <Servo.h>
#include <ESP8266WiFi.h>


#define WIFI_SSID       "KAT"
#define WIFI_PASSWORD   "kathaleeya"

#define FIREBASE_HOST "testproject-abf8e.firebaseio.com"
#define FIREBASE_KEY "NGgVOJ4iKLlp5fM00v6m2cCaaQ3DqEkbBsyBY0RK"
#define D0 16
#define LED D0
Servo myservo;
void setup() {
  Serial.begin(9600);
  Serial.println(WiFi.localIP());
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  // Do something

   Firebase.begin(FIREBASE_HOST, FIREBASE_KEY);
  //pinMode(13, OUTPUT);
  myservo.attach(13);
}

void loop() {
  

   int name = Firebase.getInt("light/switch");
Serial.print("Switch : ");
// digitalWrite(13, name);
//  delay(500);
Serial.println(name);
if(name > 0){
  for(int i = 0;i<name;i++){
      myservo.write(90);
      delay(1500);
      myservo.write(0);
      delay(1000);
    }
Firebase.setInt("light/switch", 0);
myservo.writeMicroseconds(1500);
  }
}
