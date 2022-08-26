#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void pyramid_up(Mat &image, vector<Mat> &pyramid_images, int level);
void laplaian_demo(vector<Mat> &pyramid_images, Mat &image, vector<Mat> &pyramid_gabor_images);
//int main(int artc, char** argv) {
int main() {
	Mat src = imread("D:\\Desktop\\spot1.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input", WINDOW_AUTOSIZE);
	imshow("input", src);

	vector<Mat> p_images;
	vector<Mat> pyramid_gabor_images;
	pyramid_up(src, p_images, 3);
	laplaian_demo(p_images, src, pyramid_gabor_images);

	waitKey(0);
	return 0;
}

void pyramid_up(Mat &image, vector<Mat> &pyramid_images, int level) {
	Mat temp = image.clone();
	Mat dst;
	for (int i = 0; i < level; i++) {
		pyrDown(temp, dst);
		//imshow(format("pyramid_up_%d", i), dst);
		temp = dst.clone();
		pyramid_images.push_back(temp);
	}
}

void laplaian_demo(vector<Mat> &pyramid_images, Mat &image, vector<Mat> &pyramid_gabor_images) {
	double theta[4];

	// theta 法线方向
	theta[0] = 0;
	theta[1] = CV_PI / 4;
	theta[2] = CV_PI / 2;
	theta[3] = CV_PI - CV_PI / 4;

	int kernel_size = 3;
	double sigma = 1.0, lambd = CV_PI / 8, gamma = 0.5, psi = 0;
	Mat kernel[4];
	for (int ang = 0; ang < 4; ang++) {
		kernel[ang] = getGaborKernel(cv::Size(kernel_size, kernel_size), sigma, theta[ang], lambd, gamma, psi, CV_32F);
	}


	Mat temp;
	for (int t = pyramid_images.size() - 1; t > -1; t--) {
		Mat dst;
		if (t - 1 < 0) {
			pyrUp(pyramid_images[t], dst, image.size());
			subtract(image, dst, dst);
			dst = dst + Scalar(127, 127, 127);
			//imshow(format("laplaian_layer_%d", t), dst);
		}
		else {
			pyrUp(pyramid_images[t], dst, pyramid_images[t - 1].size());
			subtract(pyramid_images[t - 1], dst, dst);
			dst = dst + Scalar(127, 127, 127);
			//imshow(format("laplaian_layer_%d", t), dst);
		}

		for (int i = 0; i < 4; i++) {
			filter2D(dst, temp, CV_32F, kernel[i]);
			pyramid_gabor_images.push_back(temp);
			imshow(format("laplaian_layer_%d_d_%d", t, i), temp);
		}

	}
}

