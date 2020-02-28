#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main()
{
	//��ϰһ
	cv::Mat srcMat = imread("D:\\UpupooResource\\2000222879\\test.jpg");
	int height = srcMat.rows; //����
	int width = srcMat.cols; //ÿ��Ԫ�ص���Ԫ������
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			//-----------------��ʼ����ÿ������----------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2]) / 3;
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
			//-------------�������ش���-----------------------
		}
		//���д������ 
	}
	imshow("src", srcMat);
	//��ϰ��
	cv::Mat srcMat2 = imread("D:\\UpupooResource\\2000222879\\test.jpg", 0);
	imshow("src2", srcMat2);
	//��ϰ��
	cv::Mat srcMat3 = imread("D:\\UpupooResource\\2000222879\\test.jpg");
	uchar threshold = 100;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar average = (srcMat3.at<Vec3b>(j, i)[0] + srcMat3.at<Vec3b>(j, i)[1] + srcMat3.at<Vec3b>(j, i)[2]) / 3;
			//average��threshold�Ƚ�
			if (average > threshold)
				average = 255;
			else
				average = 0;
			//��ֵ�����ص�����ͨ��
			srcMat3.at<Vec3b>(j, i)[0] = average;
			srcMat3.at<Vec3b>(j, i)[1] = average;
			srcMat3.at<Vec3b>(j, i)[2] = average;
		}
	}
	imshow("src3", srcMat3);
	waitKey(0);
	return 0;
}

