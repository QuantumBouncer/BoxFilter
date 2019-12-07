#include <header.h>
#include <iostream>
#include <fstream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	cout << "���� �� �ʱ�ȭ" << endl;
	char* src = "20171001_010357.jpg";
	char* dst = "20171001_010357_Box.jpg";
	int height = 1080;
	int width = 1920;
	/*char* src = "lena_gray.bmp";
	char* dst = "lena_gray_Box.bmp";
	int height = 512;
	int width = 512;*/

	// ���� ũ�� ã��
#if 0
	size_t size;
	ifstream fsrc(src, ios::in | ios::binary);
	if (!fsrc) {
		cout << src << " <-- cannot open this file !!!" << endl;
	}
	fsrc.seekg(0, ios::end);	//���� ������ ������ �̵�
	size = fsrc.tellg();		//���� �����Ͱ� �̵��� �Ÿ��� ���� ũ��
	cout << "File size is: " << size << endl;
	fsrc.seekg(0, ios::beg);
#endif

	cout << "���� �б� ����" << endl;
	Mat img = imread(src, IMREAD_GRAYSCALE);
	if (img.empty()) {
		cout << "�̹��� ���� ���µ�... �̸� Ʋ���� �ƴ�?" << endl;
		system("pause");
		return -1;
	}
	imshow("image", img);
	//waitKey();


	cout << "Filtering ����" << endl;
	Mat img_Box = Mat(height, width, CV_8UC1, Scalar(0));
	double mean = 0;
	//vector<vector<int>> mask;
	//for (int i = 0; i < 3; i++) {
	//	vector<int> row(3);
	//	mask.push_back(row);
	//}

	for (int y = 1; y < height-1; y++) {
		for (int x = 1; x < width-1; x++) {
			mean += img.at<uchar>(y - 1, x - 1);
			mean += img.at<uchar>(y - 1, x);
			mean += img.at<uchar>(y - 1, x + 1);
			mean += img.at<uchar>(y, x - 1);
			mean += img.at<uchar>(y, x);
			mean += img.at<uchar>(y, x + 1);
			mean += img.at<uchar>(y + 1, x - 1);
			mean += img.at<uchar>(y + 1, x);
			mean += img.at<uchar>(y + 1, x + 1);

			mean = mean / 9;
			img_Box.at<uchar>(y, x) = mean;
			mean = 0;
			//img_Box.at<uchar>(y,x) = 
			//int pixel = img.at<uchar>(y, x);
		}
	}

	//for (int i = 0; i < 3; i++) {
	//	mask.at(i).clear();
	//}
	//mask.clear();

	imshow("image_Box", img_Box);
	waitKey();

//	system("pause");
	return 0;

}
