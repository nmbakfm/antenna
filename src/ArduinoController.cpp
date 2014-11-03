//
//  ArduinoController.cpp
//  Antenna
//
//  Created by 南部 晃史 on 2014/11/02.
//
//

#include "ArduinoController.h"

ArduinoController::ArduinoController(){
    data = 0;
}

void ArduinoController::setup(string modem, int rate){
    
#if NO_ARDUINO
    
#else
    serial.setup(modem, rate);
#endif
}

void ArduinoController::update(){
    p_data = data;
#if NO_ARDUINO
    arduino_simulator.update();
    data = arduino_simulator.getData();
#else
    if(serial.isInitialized()){
        if(serial.available()){
            data = serial.readByte();
            cout << data << endl;
        }
    }
#endif
}

bool ArduinoController::isOn(int pin_id){
    return data & (1 << pin_id);
}

bool ArduinoController::isTurnedOn(int pin_id){
    return getStatus(pin_id) == TURN_ON;
}

bool ArduinoController::isTurnedOff(int pin_id){
    return getStatus(pin_id) == TURN_OFF;
}

int ArduinoController::getStatus(int pin_id){
    int current_state = (data & (1 << pin_id))>0 ? 1 << 0 : 0;
    int prev_state = (p_data & (1 << pin_id))>0 ? 1 << 1 : 0;
    switch(current_state + prev_state){
        case 0:
            return STAY_OFF;
        case 1:
            return TURN_ON;
        case 2:
            return TURN_OFF;
        case 3:
            return STAY_ON;
    }
}