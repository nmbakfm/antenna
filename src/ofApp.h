#pragma once


// set true when arduino unconnected
#define NO_ARDUINO TRUE
#define USB_MODEM "/dev/tty.usbmodem1411"

#include "ofMain.h"

#if NO_ARDUINO
#include "ArduinoSimulator.h"
#endif;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
#if NO_ARDUINO
    ArduinoSimulator arduino_simulator;
#else
    ofSerial serial;
#endif
		
};
