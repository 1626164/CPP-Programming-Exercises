#pragma once//�� ���α׷��� ���� ��� ������ �� ���� ����
#include <iostream>//�� ���α׷��� C++ ǥ�� ���̺귯�� iostream ��� ������ ����
#include <cmath>//�� ���α׷��� C++ ǥ�� ���̺귯�� cmath ��� ������ ����
using namespace std;//ǥ�� �̸������� ���

class Point {//Point Ŭ���� ����
	int x, y;//��ǥ���� �ڷ��� ����
	friend class Monster;//Monster�� ģ�� Ŭ������ ���
	friend class Canvas;//Canvas�� ģ�� Ŭ������ ���
public://���� ������ ����
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}//����Ʈ �Ű������� ��� �ʱ�ȭ ����Ʈ�� ����� ������ ����
	int& operator[] (int id) {//�Ű������� �ڷ��� ����� �ε��� ������
		if (id == 0)//id���� 0���� Ȯ��
			return x;//x�� ��ȯ
		else if (id == 1)//id���� 1���� Ȯ��
			return y;//y�� ��ȯ
		else//id���� 0 �Ǵ� 1�� �ƴ��� Ȯ��
			exit(0);//���α׷� ����
	}
	operator double() {//double���� �� ��ȯ ������
		return sqrt((double)x * x + y * y);//�������κ����� ��Ŭ���� �Ÿ��� ��ȯ
	}
	void operator()(int maxx, int maxy) {//�Ű������� �ڷ��� ����� () ������ �ߺ� �Լ�
		if (x < 0)//x�� 0���� ������ Ȯ��
			x = 0;//x�� 0���� �ʱ�ȭ
		if (x >= maxx)//x�� maxx���� ũ�ų� ������ Ȯ��
			x = maxx - 1;//x�� maxx-1���� �ʱ�ȭ
		if (y < 0)//y�� 0���� ������ Ȯ��
			y = 0;//y�� 0���� �ʱ�ȭ
		if (y >= maxy)//y�� maxy���� ũ�ų� ������ Ȯ��
			y = maxy - 1;//y�� maxy-1���� �ʱ�ȭ
	}
	Point operator- () {//- ������ �ߺ� �Լ�
		return Point(-x, -y);//Point(-x, -y) ��ȯ
	}
	bool operator== (Point& p) {//�Ű������� Point�� == ������ �ߺ� �Լ�
		return x == p.x && y == p.y;//x == p.x �׸��� y == p.y ��ȯ
	}
	bool operator!= (Point& p) {//�Ű������� Point�� != ������ �ߺ� �Լ�
		return x != p.x || y != p.y; //x != p.x �Ǵ� y != p.y; ��ȯ
	}
	Point operator- (Point& p) {//�Ű������� Point�� - ������ �ߺ� �Լ�
		return Point(x - p.x, y - p.y);//Point(x - p.x, y - p.y) ��ȯ
	}
	Point operator+ (Point& p) {//�Ű������� Point�� + ������ �ߺ� �Լ�
		return Point(x + p.x, y + p.y);//Point(x + p.x, y + p.y) ��ȯ
	}
	void operator+= (Point& p) {//�Ű������� Point�� += ������ �ߺ� �Լ�
		x += p.x, y += p.y;//x += p.x �� y += p.y ��ȯ
	}
	void operator-= (Point& p) {//�Ű������� Point�� -= ������ �ߺ� �Լ�
		x -= p.x, y -= p.y;//x -= p.x �� y -= p.y ��ȯ
	}
};