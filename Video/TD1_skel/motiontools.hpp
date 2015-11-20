#ifndef MOTIONTOOLS_HPP
#define MOTIONTOOLS_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

namespace MotionTools
{
	//valeur par défaut uniquement dans la déclaration 
	void drawVectorFlow( cv::Mat& im, const cv::Mat& vecFlowX, const cv::Mat& vecFlowY, int step = 1, const cv::Scalar& color = cv::Scalar(255,255,255) );
	void compenseFromVectorFlow( cv::Mat& imComp, const cv::Mat& imRef, const cv::Mat& vecFlowX, const cv::Mat& vecFlowY );
	void errorImage( cv::Mat& imErr, const cv::Mat& imCurr, const cv::Mat& imComp );
	float computeEQM( const cv::Mat& imCurr, const cv::Mat& imComp );
}

#endif // MOTIONTOOLS_HPP