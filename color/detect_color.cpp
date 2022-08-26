#include <iostream>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat image_RGB;
	image_RGB = imread("res.png");
	resize(image_RGB, image_RGB, Size(400, 300));
	Mat image_hsv;
	cvtColor(image_RGB, image_hsv, COLOR_BGR2HSV);
	namedWindow("image_hsv", WINDOW_AUTOSIZE);
	moveWindow("image_hsv", 400, 200);
	imshow("image_hsv", image_hsv);
	Mat mask;
	//将规定区间内的值置为255；必须使用Scalar()来赋值
	inRange(image_hsv, Scalar(35, 43, 46), Scalar(99, 255, 255), mask);
	//mask为二值图像，CV_8UC
	namedWindow("mask", WINDOW_AUTOSIZE);
	moveWindow("mask", 400, 200);
	imshow("mask", mask);
	Mat output;
	bitwise_and(image_RGB, image_RGB, output, mask);
	namedWindow("output", WINDOW_AUTOSIZE);
	moveWindow("output", 400, 200);
	imshow("output", output);
	waitKey(0);
}