#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup()
{
  for(int i = 0; i < length; i++)
  {
	list[i] = (int) rand() % 100;
	std::cout << list[i] << ", ";
  }
}

//--------------------------------------------------------------
void ofApp::update()
{

MergeSort();
//BubbleSort();
//CocktailSort();
//InsertSort();

}



//--------------------------------------------------------------
void ofApp::draw()
{
  ofBackground(0, 255, 0);
  for(int i = 0; i < length; i++)
  {
	ofDrawBitmapString(list[i], i * 20, ofGetHeight()/2);
  }
  
  for(int i = 0; i < length; i++)
  {
	ofSetColor(255);
//	ofDrawCircle((ofGetWidth()/length)*i, ofGetHeight() - list[i]*2, list[i]);
	ofDrawRectangle((ofGetWidth()/length)*i, ofGetHeight()-list[i]*3, 144, list[i]*3);
	ofSetColor(0);
//  	ofDrawBitmapString(list[i], (ofGetWidth()/length)*i, ofGetHeight() - list[i]*2);
  }
}

void ofApp::MergeSort()
{
  if(list[0] > list[1])
  {
	  int temp = list[0];
	  
	  list[0] = list[1];
	  list[1] = temp;
  }
  
  if(list[2] > list[3])
  {
  	  int temp = list[2];
	  
	  list[2] = list[3];
	  list[2] = temp;
  }
}

void ofApp::InsertSort()
{
//  for(int i = 0; i < length; i++)
//  {
	int temp = list[cycleCount]; //Insertion Sort
	j = cycleCount - 1;
	
	while((temp < list[j]) && j >= 0)
	{
	  list[j + 1] = list[j];
	  j--;
	}
	 list[j+1]=temp;
//  }
  if(cycleCount < 100)
	cycleCount++;
}

void ofApp::BubbleSort()
{
  for(int i = 0; i < length - 1; i++) // Bubble
  {
	if(list[i] > list[i+1])
	{
	  int temp = list[i];
	  
	  list[i] = list[i+1];
	  list[i+1] = temp;
	}
  }
}

void ofApp::CocktailSort()
{
  	bool swapped = false;
	for(int j = length - cycleCount - 2; j > cycleCount; j--) // Cocktail
	{
	  if(list[j] < list[j - 1])
	  {
		int temp = list[j];
		list[j] = list[j-1];
		list[j-1] = temp;
		
		swapped = true;
	  }
	}


	for(int j = cycleCount; j < length - cycleCount - 1; j++)
	{
	  if(list[j] > list[j + 1])
	  {
		int temp = list[j];
		list[j] = list[j+1];
		list[j+1] = temp;
		
		swapped = true;
	  }
	}
	
  cycleCount++;
}
