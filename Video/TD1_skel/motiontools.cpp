#include "motiontools.hpp"
#include <iostream>
#include "stdio.h"
#include <stdlib.h>

namespace MotionTools
{
	void 
	drawVectorFlow( cv::Mat& im, 
					const cv::Mat& vecFlowX, 
					const cv::Mat& vecFlowY, 
					int step, 
					const cv::Scalar& color )
	{
		for (int i = 0; i < im.cols-2 ; i+=step)
		{
			for (int j = 0; j < im.rows-2; j+=step)
			{
				cv::Point p1( i, j );
				cv::Point p2 = p1 + cv::Point( vecFlowX.at<float>(i), vecFlowY.at<float>(j) );
				cv::line(im, p1, p2, color, 2, 8, 0);
			}
		}
	}

	void 
	compenseFromVectorFlow( cv::Mat& imComp, 
							const cv::Mat& imRef, 
							const cv::Mat& vecFlowX, 
							const cv::Mat& vecFlowY )
	{
		for (int i = 0; i < imComp.cols ; i++)
		{
			for (int j = 0; j < imComp.rows; j++)
			{
				int new_i = i+(int)vecFlowX.at<float>(i);
				int new_j = j+(int)vecFlowY.at<float>(j);
				if (new_i<imComp.cols && new_j<imComp.rows)
				{
					/* code - erreur ici */
					imComp.at(i,j)=imRef.at(new_i, new_j);
				}
			}
		}
	}
	
	void errorImage( cv::Mat& imErr, const cv::Mat& imCurr, const cv::Mat& imComp )
	{

	}

	float computeEQM( const cv::Mat& imCurr, const cv::Mat& imComp )
	{

	}
}