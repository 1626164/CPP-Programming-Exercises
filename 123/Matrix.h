#pragma once//�� ���α׷��� ���� ��� ������ �� ���� ����
#include <iostream>//�� ���α׷��� C++ ǥ�� ���̺귯�� iostream ��� ������ ����
#include <iomanip>//�� ���α׷��� C++ ǥ�� ���̺귯�� iomanip ��� ������ ����
using namespace std;//ǥ�� �̸������� ���

class Matrix {//Matrix Ŭ���� ����
	int rows, cols;//��� ���� ũ���� �ڷ��� ����
	int** mat;//���� ��� �������� �ڷ��� ����
public://���� ������ ����
	Matrix(int r = 0, int c = 0) : rows(r), cols(c), mat(NULL) {//����Ʈ �Ű������� ��� �ʱ�ȭ ����Ʈ�� ����� ������ ����
		mat = new int* [rows];//mat�� �޸� �Ҵ�
		for (int i = 0; i < rows; i++)//�ຸ�� ������ �ݺ�
			mat[i] = new int[cols];//mat[i]�� �޸� �Ҵ�
	}
	~Matrix() {//�Ҹ��� ����
		if (mat != NULL) {//mat�� NULL�� �ƴ��� Ȯ��
			for (int i = 0; i < rows; i++)//�ຸ�� ������ �ݺ�
				delete[] mat[i];//mat[i]�� �޸� ����
			delete[] mat;//mat�� �޸� ����
		}
	}
	int& elem(int x, int y) {//�Ű������� �ڷ��� ����� elem �Լ�
		return mat[y][x];//mat[y][x]�� ��ȯ
	}
	int Rows() {//Rows �Լ�
		return rows;//���� ��ȯ
	}
	int Cols() {//Cols �Լ�
		return cols;//���� ��ȯ
	}
	int** Data() {//Data �Լ�
		return mat;//mat�� ��ȯ
	};
	void print(const char* str = "Mat") {//����Ʈ �Ű����� ����� print �Լ�
		cout << str << " " << rows << "x" << cols << endl;//ȭ�鿡 ��İ� ������ ��� �� ��� ���۸� ���� ����
		for (int i = 0; i < rows; i++) {//�ຸ�� ������ �ݺ�
			for (int j = 0; j < cols; j++)//������ ������ �ݺ�
				cout << setw(4) << mat[i][j];//ȭ�鿡 ��� ���
			cout << "\n";//ȭ�鿡 ���� ��� �� ����
		}
	}
	void setRand(int val = 100) {//����Ʈ �Ű����� ����� setRand �Լ�
		if (mat != NULL) {//mat���� NULL�� �ƴ��� Ȯ��
			for (int i = 0; i < rows; i++)//�ຸ�� ������ �ݺ�
				for (int j = 0; j < cols; j++)//������ ������ �ݺ�
					mat[i][j] = (rand() % val);//������ ������ �ʱ�ȭ
		}
	}
};