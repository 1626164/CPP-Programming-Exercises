#pragma once//�� ���α׷��� ���� ��� ������ �� ���� ����
#include "Canvas.h"//�� ���α׷��� Canvas.h ��� ������ ����
#include "Point.h"//�� ���α׷��� Point.h ��� ������ ����

class Monster {//Monster Ŭ���� ����
public://���� ������ ����
	string name, icon;//���� �̸��� ȭ�� ��¿� �������� �ڷ��� ����
	int nItem;//���� ������ ���� �ڷ��� ����
	Point q, p, p2;//���� ��ġ�� ���� ��ġ�� �ڷ��� ����
	int nSleep;//����� �ϴ� Ƚ���� �ڷ��� ����
	double dist;//���� �� ���� ������ �Ÿ��� �ڷ��� ����
	double total;//�� ������ �Ÿ��� �ڷ��� ����
	void clip(int maxx, int maxy) {//�Ű������� �ڷ��� ����� clip �Լ�
		p(maxx, maxy);//Point�� �Լ� ȣ�� �����ڸ� ���
	}
	void eat(int** map) {//�Ű������� �ڷ��� ����� eat �Լ�
		if (map[p.y][p.x] == 1) {//�ʿ� �������� �ִ��� Ȯ��
			map[p.y][p.x] = 0;//�ʿ� �������� ����
			nItem++;//���� ������ �� ����
		}
		dist += (double)(p - q);//�̵��Ÿ���ŭ ���� �� ���� ������ �Ÿ� ����
		total += (double)(p - q);//�̵��Ÿ���ŭ �� ������ �Ÿ� ����
		q = p;//���� ��ġ�� ���� ��ġ�� �ʱ�ȭ
		if (dist > 20) {//���� �� ���� ������ �Ÿ��� 20���� ū�� Ȯ��
			dist = 0;//���� �� ���� ������ �Ÿ��� 0���� �ʱ�ȭ
			nSleep = 10;//����� �ϴ� Ƚ���� 10���� �ʱ�ȭ
		}
	}
	bool isSleep() {//isSleep �Լ�
		if (nSleep > 0) {//����� �ϴ� Ƚ���� 0���� ū�� Ȯ��
			nSleep--;//����� �ϴ� Ƚ�� ����
			return true;//true�� ��ȯ
		}
		else//����� �ϴ� Ƚ���� 0���� �۰ų� ������ Ȯ�� 
			return false;//false�� ��ȯ
	}
public://���� ������ ����
	Monster(string n = "������", string i = "��", int x = 0, int y = 0) : name(n), icon(i), nItem(0), p(x, y), q(x, y), nSleep(0), dist(0.0), total(0.0) {}//����Ʈ �Ű������� ��� �ʱ�ȭ ����Ʈ�� ����� ������ ����
	virtual ~Monster() {//���� �Ҹ��� ����
		cout << icon << nItem << "�Ÿ�:" << total << endl;//ȭ�鿡 ������, ���� ������ ��, �Ÿ� �հ� ��� �� ��� ���۸� ���� ����
	}
	void draw(Canvas& canvas) {//�Ű������� Point�� draw �Լ�
		canvas.draw(p, icon);//Canvas Ŭ������ �Ű������� Point�� string�� draw�Լ� ȣ��
	}
	virtual void move(int** map, int maxx, int maxy) {//�Ű������� �ڷ��� ����� ���� move �Լ�
		if (!isSleep()) {//isSleep �Լ��� ��ȯ���� false���� Ȯ��
			int num = rand() % 9 + 1;//�Ű������� �ڷ��� ����� ������ ��(1, 2, 3, 4, 5, 6, 7, 8, 9)���� �ʱ�ȭ
			p2 = Point(num % 3 - 1, num / 3 - 1);//Point�� �����ڸ� �̿��� ��ü�� ����� �̸� ���� ��ġ�� �ʱ�ȭ
			p += p2;//���� ��ġ���� ���� ��ġ�� �̵�
			clip(maxx, maxy);//clip �Լ� ȣ��
			eat(map);//eat �Լ� ȣ��
		}
	}
	void print() {//print �Լ�
		cout << "\t" << name << icon << ":" << nItem << ":" << nSleep << endl;//ȭ�鿡 �̸�, ������, ��� �� ��� ���۸� ���� ����
	}
};