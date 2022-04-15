#include <opencv2/opencv.hpp>
#include "Morph.h"
#include "Pixel.h"
#include "ImageAnalysis.h"

using namespace cv;

int main()
{
	Mat stuff_color = imread("./stuff_color.png", 0);
	imwrite("./result/stuff_color_gray.png", stuff_color);

	Mat rice = imread("./rice.png", 0);

	Mat result;

	CMorph cMorph;

	// erosion 적용, GS_erode를 수정하여 커널 사이즈를 11*11, 중심점을 (5, 5)로 설정하였다.
	Mat stuff_color_erode = cMorph.GS_erode(stuff_color, MORPH_ELLIPSE, 1);
	imshow("result", stuff_color_erode);
	waitKey();
	imwrite("./result/1-1.png", stuff_color_erode);

	// erosion 적용, GS_erode를 수정하여 커널 사이즈를 11*11, 중심점을 (5, 5)로 설정하였다.
	Mat rice_erode = cMorph.GS_erode(rice, MORPH_ELLIPSE, 1);
	imshow("result", rice_erode);
	waitKey();
	imwrite("./result/1-2.png", rice_erode);

	// dilation 적용, GS_dilate를 수정하여 커널 사이즈를 11*11, 중심점을 (5, 5)로 설정하였다.
	Mat stuff_color_dilate = cMorph.GS_dilate(stuff_color_erode, MORPH_ELLIPSE, 1); // 
	imshow("result", stuff_color_dilate);
	waitKey();
	imwrite("./result/2-1.png", stuff_color_dilate);

	// dilation 적용, GS_dilate를 수정하여 커널 사이즈를 11*11, 중심점을 (5, 5)로 설정하였다.
	Mat rice_dilate = cMorph.GS_dilate(rice_erode, MORPH_ELLIPSE, 1);
	imshow("result", rice_dilate);
	waitKey();
	imwrite("./result/2-2.png", rice_dilate);

	CPixel cPixel;

	// 원본 이미지에서 erosion 후 dilation한 결과를 뺀다.
	Mat stuff_color_subtracted = cPixel.GS_subtract_image(stuff_color, stuff_color_dilate);
	imshow("result", stuff_color_subtracted);
	waitKey();
	imwrite("./result/3-1.png", stuff_color_subtracted);

	// 원본 이미지에서 erosion 후 dilation한 결과를 뺀다.
	Mat rice_subtracted = cPixel.GS_subtract_image(rice, rice_dilate);
	imshow("result", rice_subtracted);
	waitKey();
	imwrite("./result/3-2.png", rice_subtracted);

	// 뺀 결과를 otzu 알고리즘을 이용하여 이진화한다.
	Mat stuff_color_subtracted_otzu = cPixel.GS_threshold(stuff_color_subtracted, 0, THRESH_BINARY | THRESH_OTSU);
	imshow("result", stuff_color_subtracted_otzu);
	waitKey();
	imwrite("./result/4-1.png", stuff_color_subtracted_otzu);

	// 뺀 결과를 otzu 알고리즘을 이용하여 이진화한다.
	Mat rice_subtracted_otzu = cPixel.GS_threshold(rice_subtracted, 0, THRESH_BINARY | THRESH_OTSU);
	imshow("result", rice_subtracted_otzu);
	waitKey();
	imwrite("./result/4-2.png", rice_subtracted_otzu);

	CImageAnalysis cImageAnalysis;

	// 이진화한 결과를 labeling한다.
	Mat stuff_color_subtracted_otzu_labeled = cImageAnalysis.GS_findContours(stuff_color_subtracted_otzu);
	imshow("result", stuff_color_subtracted_otzu_labeled);
	waitKey();
	imwrite("./result/5-1.png", stuff_color_subtracted_otzu_labeled);

	// 이진화한 결과를 labeling한다.
	Mat rice_subtracted_otzu_labeled = cImageAnalysis.GS_findContours(rice_subtracted_otzu);
	imshow("result", rice_subtracted_otzu_labeled);
	waitKey();
	imwrite("./result/5-2.png", rice_subtracted_otzu_labeled);

	return 0;
}