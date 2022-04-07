#include <opencv2/opencv.hpp>
#include "ImageAnalysis.h"

using namespace cv;
using namespace std;

int main() {
	cv::VideoCapture videoCapture(0); // 웹캠 촬영할 수 있는 객체

	CImageAnalysis cImageAnalysis; // template matching을 사용하기 위한 객체

	Mat templateImg = imread("result/template.png", 1); // 미리 만들어놓은 template을 읽어온다

	Mat img;
	Mat result;

	while (true)
	{
		videoCapture >> img; // 영상 스트림 생성

		result = cImageAnalysis.GS_templateMatching(img, templateImg); // 영상으로부터 template matching한다.

		imshow("result", result); // template matching한 결과 출력

		if (waitKey(1) == 27) // ESC 누르면 종료
		{
			break;
		}
	}

	imwrite("result/1_ii_original.png", img); // 원본 이미지 저장
	imwrite("result/1_ii_temMat.png", result); // template matching한 이미지 저장

	return 0;
}