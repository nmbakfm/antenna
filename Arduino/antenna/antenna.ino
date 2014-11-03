#include <CapacitiveSensor.h>
const int PINNUM = 7;
const int bufSize = 5;
int buf[PINNUM][bufSize] = {0};
int bufCounter = 0;

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
  unsigned long data = 0;
  
  int i = 0;
  for (i = 0; i < PINNUM; ++i) {
    buf[i][bufCounter] = capacitive_sensor[i].capacitiveSensor(30);
    
    float avg = 0;
    int j = 0;
    for(j = 0; j<bufSize; ++j){
      avg += buf[i][j];
    }
    avg = avg / bufSize;
    if(avg > 500){
      data += (1 << i);
    }
  }
  Serial.write(data);
  
  ++bufCounter;
  if(bufCounter > bufSize-1){
    bufCounter=0;
  }
  delay(10);
}
