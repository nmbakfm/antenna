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

enum PinStatus{
    STAY_ON, STAY_OFF, TURN_ON, TURN_OFF
};

class ArduinoController{
public:
    ArduinoController();
    bool isOn(int pin_id);
    bool isTurnedOn(int pin_id);
    bool isTurnedOff(int pin_id);
    void setup(string modem, int rate);
    void update();
    
private:
    
    int getStatus(int pin_id);
    
#if NO_ARDUINO
    ArduinoSimulator arduino_simulator;
#else
    ofSerial serial;
#endif
    unsigned long data;
    unsigned long p_data;
};

#endif /* defined(__Antenna__ArduinoController__) */
