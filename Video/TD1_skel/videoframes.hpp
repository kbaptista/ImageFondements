#ifndef VIDEOFRAMES_HPP
#define VIDEOFRAMES_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class VideoFrames
{
public:
	VideoFrames();
	VideoFrames( const std::string& filename );
	~VideoFrames();

	void open( const std::string& filename );
	void saveToPngSequence( const std::string& folderName ) const;

	const cv::Mat& frame( unsigned int index ) const;
	int nbFrames() const;

private:
	std::vector<cv::Mat> _frames;
};

#endif // VIDEOFRAMES_HPP