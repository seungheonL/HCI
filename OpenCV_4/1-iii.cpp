#include <opencv2/opencv.hpp>
#include "Edge.h"

using namespace cv;

int main()
{
	Mat jenny_gray = imread("result/jenny_gray.png", 0); // jenny_gray.png 이미지 로드
	Mat rice_gray = imread("result/rice_gray.png", 0); // rice_gray.png 이미지 로드

	CEdge cedge; // 제공되는 여러 함수를 사용하기 위한 CEdge 객체 생성

	Mat result; // Output 이미지들을 저장하기 위한 Mat 변수

	result = cedge.GS_laplacian_edge_Laplacian(jenny_gray); // laplacian edge 적용

	imshow("result", result); // 이미지 출력
	imwrite("result/jenny_laplacian.png", result); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	result = cedge.GS_laplacian_edge_Laplacian(rice_gray); // laplacian edge 적용

	imshow("result", result); // 이미지 출력
	imwrite("result/rice_laplacian.png", result); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}