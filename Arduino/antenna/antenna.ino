#include <CapacitiveSensor.h>

const int PINNUM = 7;
CapacitiveSensor capacitive_sensor[PINNUM] = { 
  CapacitiveSensor(13, 12), 
  CapacitiveSensor(13, 11), 
  CapacitiveSensor(13, 10), 
  CapacitiveSensor(13, 9), 
  CapacitiveSensor(13, 8), 
  CapacitiveSensor(13, 7), 
  CapacitiveSensor(13, 6) 
};

void setup() {

  capacitive_sensor[0].set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop() {
  unsigned char data = 0;
  
  int i = 0;
  for (i = 0; i < PINNUM; ++i) {
    if (capacitive_sensor[i].capacitiveSensor(30)>300) {
      data += (1 << i);
    }
  }
  Serial.write(data);

  delay(10);
  // put your main code here, to run repeatedly:

}
