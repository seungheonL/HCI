#include <opencv2/opencv.hpp>
#include "Geometry.h"
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat briefcase_45_1_5 = imread("result/briefcase_45_1.5.png", 1); // briefcase_45_1.5.png 이미지 로드
	Mat briefcase_1_5_45 = imread("result/briefcase_1.5_45.png", 1); // briefcase_1.5_45.png 이미지 로드

	Mat result; // Output 이미지들을 저장하기 위한 Mat 변수

	CPixel cpixel; // 제공되는 여러 함수를 사용하기 위한 CPixel 객체 생성

	result = cpixel.GS_subtract_image(briefcase_45_1_5, briefcase_1_5_45); // 두 이미지를 빼준다.

	imshow("result", result); // 이미지 출력
	imwrite("result/briefcase_subtracted.png", result); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}