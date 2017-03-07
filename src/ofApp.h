#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void InsertSort();
		void BubbleSort();
		void CocktailSort();
		void MergeSort();
		void SinghalSort();

	private:
		int length = 10;
		int list[10];
		int cycleCount = 0;
		int mergeCycles = 0;
		int j;
};
