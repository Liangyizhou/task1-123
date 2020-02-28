#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main()
{
	//练习一
	cv::Mat srcMat = imread("D:\\UpupooResource\\2000222879\\test.jpg");
	int height = srcMat.rows; //行数
	int width = srcMat.cols; //每行元素的总元素数量
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			//-----------------开始处理每个像素----------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2]) / 3;
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
			//-------------结束像素处理-----------------------
		}
		//单行处理结束 
	}
	imshow("src", srcMat);
	//练习二
	cv::Mat srcMat2 = imread("D:\\UpupooResource\\2000222879\\test.jpg", 0);
	imshow("src2", srcMat2);
	//练习三
	cv::Mat srcMat3 = imread("D:\\UpupooResource\\2000222879\\test.jpg");
	uchar threshold = 100;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar average = (srcMat3.at<Vec3b>(j, i)[0] + srcMat3.at<Vec3b>(j, i)[1] + srcMat3.at<Vec3b>(j, i)[2]) / 3;
			//average和threshold比较
			if (average > threshold)
				average = 255;
			else
				average = 0;
			//赋值给像素的三个通道
			srcMat3.at<Vec3b>(j, i)[0] = average;
			srcMat3.at<Vec3b>(j, i)[1] = average;
			srcMat3.at<Vec3b>(j, i)[2] = average;
		}
	}
	imshow("src3", srcMat3);
	waitKey(0);
	return 0;
}

