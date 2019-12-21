#include "WorkOut.h"
void WorkOut::domask(cv::Scalar sc)
{
	const cv::Point* corner_list[1] = { &h.data[0] };
	int num_points = h.data.size();

	cv::Mat s(h.test.rows, h.test.cols, CV_8UC3, cv::Scalar(255, 255, 255));
	cv::fillPoly(s, corner_list, &num_points, 1, sc, 8);
	cv::Mat s1;
	cv::bitwise_and(h.test, s, s1);
	cv::imwrite("..\\Testers\\tut\\tut_v\\1.png", s1);
}

void WorkOut::doblur()
{
	cv::Mat dst;
	cv:: GaussianBlur(h.img, dst, cv::Size(5, 5), 0);
	cv::imwrite("..\\Testers\\tut\\tut_v\\blur.jpg", dst);
	h.img = dst;
}
void WorkOut::docut() {
	cv::Mat mask(h.img.rows, h.img.cols, CV_8UC3, cv::Scalar(0, 0, 0));
	int num_points = h.data.size();
	const cv::Point* corner_list[1] = { &h.data[0] };
	cv::fillPoly(mask, corner_list, &num_points, 1, cv::Scalar(255, 255, 255), 8);
	cv::Mat result;
	cv::bitwise_and(h.img, mask, result);
	h.img.copyTo(result, mask);
	cv::Mat mask1(h.img.rows, h.img.cols, CV_8UC3, cv::Scalar(0, 255, 0));
	h.img.copyTo(mask1, mask);
	cv::imwrite("..\\Testers\\tut\\tut_v\\mask.jpg", mask1);
	h.test= h.img;
	h.img = mask1;

}

void WorkOut::dofind() {
	Vec3b iCheck= h.img.at<Vec3b>(0, 0);
	Mat OutputImage;
	inRange(h.img, Scalar(h.RGB1_1, h.RGB1_2, h.RGB1_3), Scalar(h.RGB2_1,h.RGB2_2, h.RGB2_3), OutputImage);

	int i, j, k = h.img.size().height, w = h.img.size().width, counterW = 0, counterB = 0;
	for (i = 0; i < k; i++) {
		for (j = 0; j < w; j++) {
			if (h.img.at<Vec3b>(i, j) != iCheck)
				if (OutputImage.at<uchar>(i, j) == 255)
					counterW++;
				else { counterB += 1; OutputImage.at<uchar>(i, j) = 120; }
		}
	}
	cv::imwrite("..\\Testers\\tut\\tut_v\\test.png", OutputImage);
	

	double result = (double)counterB / (counterB + counterW);
	int resultOutput = result * 100;
	cout << "Result:" << resultOutput << "% damaged!\n" << endl; //גûגוסעט ג ְֳ
	h.GetData(resultOutput);

	cv::Mat s(h.test.rows, h.test.cols, CV_8UC3, cv::Scalar(255, 255, 255));
	if (resultOutput > 50) {
		domask (cv::Scalar(0, 20, 255));
	
	}
	else if (resultOutput < 30) {
		domask(cv::Scalar(0, 255, 0));

	}
	else {
		domask(cv::Scalar(0, 216, 255));
	}
	
}

