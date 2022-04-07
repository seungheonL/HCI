#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

	VideoCapture videoCapture(0); // 웹캠 촬영할 수 있는 객체

	Mat img;

	while (true)
	{
		videoCapture >> img; // 영상 스트림 생성

		imshow("camera", img); // 영상 출력

		if (waitKey(1) == 27) // ESC 누르면 종료
		{
			break;
		}
	}

	imshow("result", img); // 마지막으로 찍힌 프레임 출력
	imwrite("result/airpod.png", img); // 마지막으로 찍힌 프레임 저장

	waitKey();

	return 0;
}