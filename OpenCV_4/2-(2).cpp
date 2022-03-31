#include <opencv2/opencv.hpp>
#include "Pixel.h"
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase = imread("image/briefcase.jpg", 1); // briefcase.jpg 이미지 로드
	Mat briefcase_30_11 = imread("result/briefcase_30_11.png", 1); // briefcase_30_11.png 이미지 로드

	Mat result; // Output 이미지들을 저장하기 위한 Mat 변수

	CPixel cpixel; // 제공되는 여러 함수를 사용하기 위한 CPixel 객체 생성

	result = cpixel.GS_subtract_image(briefcase, briefcase_30_11); // 두 이미지를 서로 빼준다.

	imshow("result", result); // 이미지 출력
	imwrite("result/briefcase_30_11_subtracted.png", result); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}