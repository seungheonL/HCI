#include <opencv2/opencv.hpp>
#include "Morph.h"
#include "Pixel.h"
#include "ImageAnalysis.h"
#include "Edge.h"
#include "Morph.h"

using namespace cv;

int main()
{
	Mat stuff_color_otzu = imread("./result/4-1.png", 0);
	Mat rice_otzu = imread("./result/4-2.png", 0);

	CImageAnalysis cImageAnalysis;

	// Hough Transomfrom 적용
	Mat stuff_color_hough = cImageAnalysis.GS_basicHoughTransformGray(stuff_color_otzu);
	Mat rice_hough = cImageAnalysis.GS_basicHoughTransformGray(rice_otzu);

	// 출력 후 저장
	imshow("result", stuff_color_hough);
	waitKey();
	imwrite("./result/10-1.png", stuff_color_hough);

	// 출력 후 저장
	imshow("result", rice_hough);
	waitKey();
	imwrite("./result/10-2.png", rice_hough);

	return 0;
}