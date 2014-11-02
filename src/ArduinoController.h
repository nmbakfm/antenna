//
//  ArduinoController.h
//  Antenna
//
//  Created by 南部 晃史 on 2014/11/02.
//
//

#ifndef __Antenna__ArduinoController__
#define __Antenna__ArduinoController__

#include "ofMain.h"

// set true when arduino unconnected
#define NO_ARDUINO TRUE

#if NO_ARDUINO
#include "ArduinoSimulator.h"
#endif

class ArduinoController{
public:
    ArduinoController();
    bool isOn(int pin_id);
    void setup(string modem, int rate);
    void update();
    
private:
#if NO_ARDUINO
    ArduinoSimulator arduino_simulator;
#else
    ofSerial serial;
#endif
    unsigned long data;
};

#endif /* defined(__Antenna__ArduinoController__) */
