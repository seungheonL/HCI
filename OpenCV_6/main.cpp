#include <opencv2/opencv.hpp>
#include "Morph.h"
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat stuff_color = imread("./stuff_color.png", 0);
	imwrite("./result/stuff_color_gray.png", stuff_color);

	Mat rice = imread("./rice.png", 0);

	Mat result;

	CMorph cMorph;

	Mat stuff_color_erode = cMorph.GS_erode(stuff_color, MORPH_ELLIPSE, 1);
	imshow("result", stuff_color_erode);
	waitKey();
	imwrite("./result/1-1.png", stuff_color_erode);

	Mat rice_erode = cMorph.GS_erode(rice, MORPH_ELLIPSE, 1);
	imshow("result", rice_erode);
	waitKey();
	imwrite("./result/1-2.png", rice_erode);

	Mat stuff_color_dilate = cMorph.GS_dilate(stuff_color_erode, MORPH_ELLIPSE, 1);
	imshow("result", stuff_color_dilate);
	waitKey();
	imwrite("./result/2-1.png", stuff_color_dilate);

	Mat rice_dilate = cMorph.GS_dilate(rice_erode, MORPH_ELLIPSE, 1);
	imshow("result", rice_dilate);
	waitKey();
	imwrite("./result/2-2.png", rice_dilate);

	CPixel cPixel;

	Mat stuff_color_subtracted = cPixel.GS_subtract_image(stuff_color, stuff_color_dilate);
	imshow("result", stuff_color_subtracted);
	waitKey();
	imwrite("./result/3-1.png", stuff_color_subtracted);

	Mat rice_subtracted = cPixel.GS_subtract_image(rice, rice_dilate);
	imshow("result", rice_subtracted);
	waitKey();
	imwrite("./result/3-2.png", rice_subtracted);

	return 0;
}