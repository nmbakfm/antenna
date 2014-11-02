//
//  ArduinoSimulator.h
//  Antenna
//
//  Created by 南部 晃史 on 2014/11/02.
//
//

#ifndef __Antenna__ArduinoSimulator__
#define __Antenna__ArduinoSimulator__

#include "ofMain.h"

class ArduinoSimulator{
public:
    ArduinoSimulator();
    void update();
    unsigned long getData();
private:
    int current_count;
    const int max_count = 32;
};

#endif /* defined(__Antenna__ArduinoSimulator__) */
