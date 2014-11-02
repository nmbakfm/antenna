//
//  ArduinoSimulator.cpp
//  Antenna
//
//  Created by 南部 晃史 on 2014/11/02.
//
//

#include "ArduinoSimulator.h"

ArduinoSimulator::ArduinoSimulator(){
    current_count = 0;
}

void ArduinoSimulator::update(){
    if(ofGetFrameNum() % 45 == 0){
        current_count += 1;
        if(current_count == max_count) current_count = 0;
    }
}

unsigned long ArduinoSimulator::getData(){
    return 1 << current_count;
}


