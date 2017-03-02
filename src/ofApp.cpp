#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup()
{
  for(int i = 0; i < listLength; i++)
  {
	list[i] = (int) rand() % 100;
	std::cout << list[i] << ", ";
  }
}

//--------------------------------------------------------------
void ofApp::update()
{
//  for(int i = 0; i < listLength - 1; i++) // Bubble
//  {
//	if(list[i] > list[i+1])
//	{
//	  int temp = list[i];
//	  
//	  list[i] = list[i+1];
//	  list[i+1] = temp;
//	}
//  }
//
//	bool swapped = false;
//	for(int j = listLength - cycleCount - 2; j > cycleCount; j--) // Cocktail
//	{
//	  if(list[j] < list[j - 1])
//	  {
//		int temp = list[j];
//		list[j] = list[j-1];
//		list[j-1] = temp;
//		
//		swapped = true;
//	  }
//	}
//	
//	for(int j = cycleCount; j < listLength - cycleCount - 1; j++)
//	{
//	  if(list[j] > list[j + 1])
//	  {
//		int temp = list[j];
//		list[j] = list[j+1];
//		list[j+1] = temp;
//		
//		swapped = true;
//	  }
//	}
//	if(!swapped) break;
//
//  cycleCount++;
  for(int i = 0; i < listLength; i++)
  {
	int temp = list[i];
	list[0] = temp;
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  ofBackground(0, 255, 0);
  for(int i = 0; i < listLength; i++)
  {
	ofDrawBitmapString(list[i], i * 20, ofGetHeight()/2);
  }
  
  for(int i = 0; i < listLength; i++)
  {
	ofSetColor(255);
//	ofDrawCircle((ofGetWidth()/listLength)*i, ofGetHeight() - list[i]*2, list[i]);
	ofDrawRectangle((ofGetWidth()/listLength)*i, ofGetHeight()-list[i]*3, 144, list[i]*3);
	ofSetColor(0);
//  	ofDrawBitmapString(list[i], (ofGetWidth()/listLength)*i, ofGetHeight() - list[i]*2);
  }
}

