#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat image = Mat(Size(300, 400), CV_8UC1, Scalar(255));
	image(Rect(0, 0, 300, 200)) = Scalar(1);

	putText(image, "2018112026", Point(50, 100), FONT_HERSHEY_PLAIN, 2, Scalar(255, 255, 255));
	putText(image, "LeeSeungHeon", Point(25, 300), FONT_HERSHEY_PLAIN, 2, Scalar(0, 0, 0));

	std::cout << "2018112026 ÀÌ½ÂÇå" << std::endl;
	imshow("image", image);

	waitKey();
	return 0;
}