#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase_1_5 = imread("result/briefcase_1.5.png", 1); // briefcase_1.5.png 이미지 로드

	CGeometry cgeometry; // 제공되는 여러 함수들을 사용하기 위한 CGeometry 객체 생성
	Mat result; // Output 이미지들을 저장하기 위한 Mat 변수

	result = cgeometry.GS_affineRotate(briefcase_1_5, -45, 1); // 원점을 중심으로 시계방향으로 45도 회전

	imshow("result", result); // 이미지 출력
	imwrite("result/briefcase_1.5_45.png", result); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}