#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase_45 = imread("result/briefcase_45.png", 1); // briefcase_45.png 이미지 로드

	CGeometry cgeometry; // 제공되는 여러 함수들을 사용하기 위한 CGeometry 객체 생성
	Mat result; // Output 이미지들을 저장하기 위한 Mat 변수

	result = cgeometry.GS_affineRotate(briefcase_45, 0, 1.5); // 1.5배 확대

	imshow("result", result); // 이미지 출력
	imwrite("result/briefcase_45_1.5.png", result); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}