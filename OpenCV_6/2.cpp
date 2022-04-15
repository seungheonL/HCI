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

	CEdge cEdge;

	// canny edge detector 적용
	Mat stuff_color_canny = cEdge.GS_canny_edge_Canny(stuff_color_otzu);
	Mat rice_canny = cEdge.GS_canny_edge_Canny(rice_otzu);

	// 출력 후 저장
	imshow("result", stuff_color_canny);
	waitKey();
	imwrite("./result/6-1.png", stuff_color_canny);

	// 출력 후 저장
	imshow("result", rice_canny);
	waitKey();
	imwrite("./result/6-2.png", rice_canny);

	// sobel edge detector적용
	Mat stuff_color_sobel = cEdge.GS_sobel_edge_Sobel(stuff_color_otzu);
	Mat rice_sobel = cEdge.GS_sobel_edge_Sobel(rice_otzu);

	// 출력 후 저장
	imshow("result", stuff_color_sobel);
	waitKey();
	imwrite("./result/7-1.png", stuff_color_sobel);

	// 출력 후 저장
	imshow("result", rice_sobel);
	waitKey();
	imwrite("./result/7-2.png", rice_sobel);

	CMorph cMorph;

	// closing 적용
	Mat stuff_color_closing = cMorph.GS_closing(stuff_color_sobel, 1, MORPH_RECT);
	Mat rice_closing = cMorph.GS_closing(rice_sobel, 1, MORPH_RECT);

	// 출력 후 저장
	imshow("result", stuff_color_closing);
	waitKey();
	imwrite("./result/8-1.png", stuff_color_closing);

	// 출력 후 저장
	imshow("result", rice_closing);
	waitKey();
	imwrite("./result/8-2.png", rice_closing);

	// opening 적용
	Mat stuff_color_opening = cMorph.GS_opening(stuff_color_closing, 1, MORPH_RECT);
	Mat rice_opening = cMorph.GS_opening(rice_closing, 1, MORPH_RECT);

	// 출력 후 저장
	imshow("result", stuff_color_opening);
	waitKey();
	imwrite("./result/9-1.png", stuff_color_opening);

	// 출력 후 저장
	imshow("result", rice_opening);
	waitKey();
	imwrite("./result/9-2.png", rice_opening);

	return 0;
}