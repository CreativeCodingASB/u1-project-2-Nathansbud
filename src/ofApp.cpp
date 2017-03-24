#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup()
{
  for(int i = 0; i < length; i++)
  {
	list[i] = (int) rand() % 100;
  }
}

//--------------------------------------------------------------
void ofApp::update()
{
//Merge();
//BubbleSort();
//CocktailSort();
//InsertSort();
//SinghalSort();
}



//-------------------------------------------------------------

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
	ofDrawRectangle((ofGetWidth()/length)*i, ofGetHeight()-list[i]*3, 1, list[i]*3);
	ofSetColor(0);
//  	ofDrawBitmapString(list[i], (ofGetWidth()/length)*i, ofGetHeight() - list[i]*2);
  }
  
  MergeSort(0, length);
}

void ofApp::MergeSort(int low, int high)
{
    int mid;
    
    if(low < high)
    {
        mid = (low + high)/2;
        MergeSort(low, mid);
        MergeSort(mid+1, high);
        Merge(low, mid, high);
    }
}

void ofApp::Merge(int low, int mid, int high)
{
    int h, i, j, b[2000];
    h = low;
    i = low;
    j = mid+1;
    
    while(h <= mid && j <= high)
    {
        if(list[h] <= list[j])
        {
            b[i] = list[h];
            h++;
        }
        else
        {
            b[i] = list[j];
            j++;
        }
    i++;
    }
    
    if(h > mid)
    {
        for(int k = j; k <= high; k++)
        {
            b[i] = list[k];
            i++;
        }
    }
    else
    {
        for(int k = h; k <= high; k++)
        {
            b[i] = list[k];
            i++;
        }
    }
    
    for(int k = low; k <= high; k++)
    {
        list[k] = b[k];
    }
}
void ofApp::RanaAttemptedSort()
{
  int temp[length];
  if(cycleCount<=length)
    {
        for(int j = 0; j<length; j+=cycleCount)
        {
            int k = 0, l = cycleCount/2;
            for(int m = 0; m < cycleCount; m++)
            {
                std::cout << list[j+k]<<" "<<list[j+l];
                if(l < cycleCount && k < cycleCount/2)
                {
                    if(list[j+l] > list[j+k])
                    {
                        std::cout<<"k:"<<j+k;
                        temp[j+m]=list[j+k];
                        k++;
                    } else
                    {
                        std::cout<<"l:"<<j+l;
                        temp[j+m]=list[j+l];
                        l++;
                    }
                } else if(k>=cycleCount/2)
                {
                    std::cout<<"l:"<<j+l;
                    temp[j+m]=list[j+l];
                    l++;
                } else if(l>= cycleCount)
                {
                    std::cout<<"k:"<<j+k;
                    temp[j+m]=list[j+k];
                    k++;
                }
            }
        }
        for(int i=0; i<length; i++)
        {
            std::cout<<temp[cycleCount];
            list[cycleCount]=temp[cycleCount];
        }
        cycleCount*=2;
    }
}

void ofApp::InsertSort()
{
  int temp = list[cycleCount]; //Insertion Sort
  index = cycleCount - 1;
	
  while((temp < list[index]) && index >= 0)
  {
	list[index + 1] = list[index];
	index--;
  }
  list[index+1]=temp;

  if(cycleCount < length)
  {
	cycleCount++;
  }
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

void ofApp::SinghalSort()
{
  for(int i = 1; i < length - 1 - cycleCount; i++)
  {
	if(list[i] > list[i+1])
	{
	  int temp = list[i];
	  list[i] = list[i+1];
	  list[i+1] = temp;
	}
	
	if(list[i] < list[i-1])
	{
	  int temp = list[i];
	  list[i] = list[i-1];
	  list[i-1] = temp;
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
