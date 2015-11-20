#include "videoframes.hpp"
#include <iostream>
#include "stdio.h"

// Constructeur
VideoFrames::VideoFrames(){

}

VideoFrames::VideoFrames(const std::string & filename){
	VideoCapture cap(filename); // open the default camera
	int video_size = cap.get(CV_CAP_PROP_FRAME_COUNT);
	_frames.resize(video_size);
    if(cap.isOpened())  // check if we succeeded
    {
	    for(int i = 0 ; i < video_size ; i++)
	    {
	        cap >> _frames.at(i);
	        if(waitKey(30) >= 0) break;
	    }
	    // the camera will be deinitialized automatically in VideoCapture destructor
    }
}

// Destructeur
VideoFrames::~VideoFrames(){

}

void 
VideoFrames::open( const std::string& filename ){
	VideoCapture cap(filename); // open the default camera
	int video_size = cap.get(CV_CAP_PROP_FRAME_COUNT);
	_frames.resize(video_size);
    if(cap.isOpened())  // check if we succeeded
    {
	    for(int i = 0 ; i < video_size ; i++)
	    {
	        cap >> _frames.at(i);
	        if(waitKey(30) >= 0) break;
	    }
	    // the camera will be deinitialized automatically in VideoCapture destructor
    }

}

void 
VideoFrames::saveToPngSequence( const std::string& folderName ) const{
	int size = _frames.size();
	string name = "img_";
	string name_end = ".png";
	for (int i = 0; i < size; ++i)
	{
		/* code */
		char buffer[256]; sprintf(buffer, "%06d", i);
		string s(buffer);
		string full_name = folderName + "/" + name + s + name_end;
		imwrite(full_name, _frames.at(i));
	}
}

const cv::Mat& 
VideoFrames::frame( unsigned int index ) const{
	return _frames.at(index);
}

int
VideoFrames::nbFrames() const{
	return _frames.size();
}

