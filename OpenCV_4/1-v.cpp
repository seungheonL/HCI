#include <opencv2/opencv.hpp>
#include "Filter.h"
#include "Edge.h"
#include "Pixel.h"

using namespace cv;

int main()
{
	Mat jenny_gray = imread("result/jenny_gray.png", 0); // jenny_gray.png 이미지 로드
	Mat rice_gray = imread("result/rice_gray.png", 0); // rice_gray.png 이미지 로드

	CFilter cfilter; // 제공되는 여러 함수를 사용하기 위한 CFilter 객체 생성
	CEdge cedge; // 제공되는 여러 함수를 사용하기 위한 CEdge 객체 생성

	Mat result; // Output 이미지들을 저장하기 위한 Mat 변수

	result = cfilter.GS_gaussian_smoothing_filtering(jenny_gray, 2); // 가우시안 필터링 적용
	result = cedge.GS_laplacian_edge_Laplacian(result); // 라플라시안 엣지 적용

	imshow("result", result); // 이미지 출력
	imwrite("result/jenny_laplacian_of_gaussian.png", result); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	result = cfilter.GS_gaussian_smoothing_filtering(rice_gray, 2); // 가우시안 필터링 적용
	result = cedge.GS_laplacian_edge_Laplacian(result); // 라플라시안 엣지 적용

	imshow("result", result); // 이미지 출력
	imwrite("result/rice_laplacian_of_gaussian.png", result); // 이미지 저장

	waitKey(); // Output 이미지를 관찰하기 위해 별도의 입력이 있을 때까지 기다린다.

	return 0;
}