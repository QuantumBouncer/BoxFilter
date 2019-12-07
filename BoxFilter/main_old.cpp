#include <header.h>
#include <iostream>
#include <fstream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

void FileRead(char* _src, char* _dst) {
	size_t size;
	ifstream fsrc(_src, ios::in | ios::binary);
	if (!fsrc) {
		cout << _src << " <-- cannot open this file !!!" << endl;
	}
	
	fsrc.seekg(0, ios::end);	//���� ������ ������ �̵�
	size = fsrc.tellg();		//���� �����Ͱ� �̵��� �Ÿ��� ���� ũ��
	cout << "File size is: " << size << endl;
	fsrc.seekg(0, ios::beg);

	_dst = new char[size - 8 + 1];
	fsrc.seekg(8);
	fsrc.read(_dst, size - 8);
	_dst[size] = '\0';
	cout << "Data size is: " << fsrc.tellg() << endl;

}

void main() {
	cout << "���� �� �ʱ�ȭ" << endl;
	char* src = "lena_gray.png";
	char* dst = "lena_gray_Box.png";
	
	cout << "���� �б� ����" << endl;
	FileRead(src, dst);
	

	

	system("pause");
}
