#include <opencv2/opencv.hpp>
#include "Geometry.h"

using namespace cv;

int main()
{
	Mat briefcase_30 = imread("result/briefcase_30.png", 1); // briefcase_30.png 이미지 로드

	Mat result = briefcase_30; // Output 이미지들을 저장하기 위한 Mat 변수

	CGeometry cgeometry; // 제공되는 여러 함수들을 사용하기 위한 CGeometry 객체 생성

	for (int i = 0; i < 11; i++) // 11번 반복
	{
		result = cgeometry.GS_affineRotate(result, -30, 1); // 원점 중심으로 시계 방향으로 30도 회전
	}

	imshow("result", result); // 이미지 출력
	imwrite("result/briefcase_30_11.png", result); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}