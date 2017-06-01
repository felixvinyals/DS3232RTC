
#include "FVlib_DS3232RTC_JChristensenFork.h"
#include <TimeLib.h>


DS3232RTC DS3231;
tmElements_t tm;

void setup() {
  Serial.begin(9600);

  tm.Hour = 13;             //set the tm structure to 23h31m30s on 13Feb2009
  tm.Minute = 53;
  tm.Second = 30;
  tm.Day = 19;
  tm.Month = 4;
  tm.Year = (2017 - 1970);    //tmElements_t.Year is the offset from 1970
  //DS3231.write(tm);
}

void loop() {

  delay(1000);
  
  DS3231.read(tm);
  Serial.println("===========");
  Serial.print(tm.Hour, DEC);
  Serial.print(':');
  Serial.print(tm.Minute,DEC);
  Serial.print(':');
  Serial.println(tm.Second,DEC);
  Serial.println("-");
  Serial.print(tm.Day, DEC);
  Serial.print('/');
  Serial.print(tm.Month,DEC);
  Serial.print('/');
  Serial.println((tm.Year + 1970),DEC);
  //
  int ttt = DS3231.temperature();
  float celsiust = ttt / 4.0;
  
  Serial.println(ttt);
  Serial.println(celsiust);
  Serial.println("===========");

}
