#include <Arduino.h>

#include <PMS.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(16, 17); //serial pins 16,17

PMS pms(mySerial);
PMS::DATA data;

void setup()
{
    Serial.begin(9600); // 1,3 - connected via usb

    mySerial.begin(9600);

}



void loop()
{
  
  if (pms.read(data))
  {
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);

    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);

    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);

    Serial.println();
  }
  
/*
   if (mySerial.available()) {
      Serial.println(mySerial.read());
    }
  */
}
