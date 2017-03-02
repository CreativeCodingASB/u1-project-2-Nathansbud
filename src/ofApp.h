#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

	private:
		int listLength = 100;
		int list[100];
		int cycleCount = 0;
		int j;
};
