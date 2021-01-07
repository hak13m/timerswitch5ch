//Arduino Promini
//RTC_DS3931 module
//Relay 4ch
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

//BEGIN PIN RELAY
int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
//END PIN RELAY

//DEFINE RELAY SIGNAL
int relayON = LOW; //relay nyala
int relayOFF = HIGH; //relay mati


char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () 
{
  Serial.begin(9600);
  delay(3000); // wait for console opening
  // Comment out below lines once you set the date & time.
    // Following line sets the RTC to the date & time this sketch was compiled
   //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
    // Following line sets the RTC with an explicit date & time
    // for example to set January 27 2017 at 12:56 you would call:
    //rtc.adjust(DateTime(2020, 10, 30, 17, 18, 0));
  
  
 //RELAY OUTPUT
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  
  digitalWrite(relay1, relayOFF);
  digitalWrite(relay2, relayOFF);
  digitalWrite(relay3, relayOFF);
  digitalWrite(relay4, relayOFF);
  //END RELAY OUTPUT
}

void loop () 
{
    DateTime now = rtc.now();
    char buf1[] = "hh:mm";
    //Serial.println(now.toString(buf1));
    String waktu = String(now.toString(buf1));
   Serial.println(waktu);
    
    
//RELAY1 pin2 lampu gerbang nyala jam 19 mati jam 22, nyala 4,30 mati 5,30
//      if(waktu=="19:00"){
//    digitalWrite(relay1, relayON);
//}
//     if(waktu=="05:30"){
//    digitalWrite(relay1, relayOFF);
  if ((now.hour() >= 19) || (now.hour() < 22)) {
     digitalWrite(relay1, relayON);
  }
  else if ((now.hour() >= 4 && now.minute() >=30) || (now.hour() < 5 && now.minute() >=30)) {
     digitalWrite(relay1, relayON);
  }
  else {
    digitalWrite(relay1, relayOFF);
  }



//RELAY2 pin3 lampu teras nyala jam 22 mati jam 5
  if ((now.hour() >= 22) || (now.hour() < 5)) {    
    digitalWrite(relay2, relayON);                   
  } else {
    digitalWrite(relay2, relayOFF);                   
  }


//RELAY3 pin4 lampu samping luar nyala jam 19 mati jam 5 
  if ((now.hour() >= 19) || (now.hour() < 5)) {    
    digitalWrite(relay3, relayON);                   
  } else {
    digitalWrite(relay3, relayOFF);                   
  }


//RELAY4 pin5 Lampu belakang nyala jam 18:30 mati jam 6
  if ((now.hour() >= 18 && now.minute() >=30 ) || (now.hour() < 6 )) {    
    digitalWrite(relay4, relayON);                   
  } else {
    digitalWrite(relay4, relayOFF);                   
  }

    delay(1000);
}
