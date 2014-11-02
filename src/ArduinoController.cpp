//
//  ArduinoController.cpp
//  Antenna
//
//  Created by 南部 晃史 on 2014/11/02.
//
//

#include "ArduinoController.h"

ArduinoController::ArduinoController(){
    
}

void ArduinoController::setup(string modem, int rate){
    
#if NO_ARDUINO
    
#else
    serial.setup(modem, rate);
#endif
}

void ArduinoController::update(){
#if NO_ARDUINO
    arduino_simulator.update();
    data = arduino_simulator.getData();
#else
    data = 0x0000006a; // dummy pin1,3,5,6 are on
#endif
}

bool ArduinoController::isOn(int pin_id){
    return data & (1 << pin_id);
}