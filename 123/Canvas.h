#pragma once//�� ���α׷��� ���� ��� ������ �� ���� ����
#include <iostream>//�� ���α׷��� C++ ǥ�� ���̺귯�� iostream ��� ������ ����
#include <string>//�� ���α׷��� C++ ǥ�� ���̺귯�� string ��� ������ ����
#include "Point.h"//�� ���α׷��� Point.h ��� ������ ����
#define MAXLINES 100//���� �ִ� ���̸� 100���� ����
using namespace std;//ǥ�� �̸������� ���

class Canvas {//Canvas Ŭ���� ����
	string line[MAXLINES];//ȭ�� ����� ���� �ڷ��� ����
	int xMax, yMax;//���� �ʺ�� ������ �ڷ��� ����
public://���� ������ ����
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {//����Ʈ �Ű������� ��� �ʱ�ȭ ����Ʈ�� ����� ������ ����
		for (int y = 0; y < yMax; y++)//������ ĵ���� ���ο� ������ �ݺ�
			line[y] = string(xMax * 2, ' ');//�� ���ο� ���� string ��ü �ʱ�ȭ
	}
	void draw(int x, int y, string val) {//�Ű������� �ڷ��� ����� draw �Լ�
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)//������ ĵ���� ���ο� �ִ��� Ȯ��
			line[y].replace(x * 2, 2, val);//ĵ������ ��� ȭ�� ���� val�� ����
	}
	void draw(Point& p, string val) {//�Ű������� �ڷ��� ����� draw �Լ�
		draw(p.x, p.y, val);//�Ű������� Point�� string�� draw �Լ�
	}
	void clear(string val = ". ") {//����Ʈ �Ű����� ����� clear �Լ�
		for (int y = 0; y < yMax; y++)//������ ĵ���� ���ο� ������ �ݺ�
			for (int x = 0; x < xMax; x++)//������ ĵ���� ���ο� ������ �ݺ�
				draw(x, y, val);//ĵ������ ��� ȭ�� ���� val�� ���� 
	}
	void print(const char* title = "<My Canvas>") {//����Ʈ �Ű����� ����� print �Լ�
		system("cls");//ȭ�� ����
		cout << title << endl;//ȭ�鿡 ���� ��� �� ��� ���۸� ���� ����
		for (int y = 0; y < yMax; y++)//������ ĵ���� ���ο� ������ �ݺ�
			cout << line[y] << endl;//ȭ�鿡 �� ���� ��� �� ��� ���۸� ���� ����
		cout << endl;//ȭ�鿡 ���� ��� �� ��� ���۸� ���� ����
	}
};