#pragma once//�� ���α׷��� ���� ��� ������ �� ���� ����
#include "Monster.h"//�� ���α׷��� Monster.h ��� ������ ����
#include <conio.h>//�� ���α׷��� C++ ǥ�� ���̺귯�� conio.h ��� ������ ����
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };//��� �ʱ�ȭ�� ������ ����

class Human : public Monster {//Human Ŭ���� ����
public://���� ������ ����
	Human(string n = "�̷��η�", string i = "��", int px = 0, int py = 0) : Monster(n, i, px, py) {}//����Ʈ �Ű������� ��� �ʱ�ȭ ����Ʈ ����� ������ ����
	~Human() {//�Ҹ��� ����
		cout << " [Human   ]";//ȭ�鿡 ���� ���
	}
	int getDirKey() {//getDirKey �Լ�
		return getche() == 224 ? getche() : 0;//�Է��� Ű�� ����Ű��� ����Ű ���� ��ȯ�ϰ� �ƴ϶�� �Լ� ����
	}
	void move(int** map, int maxx, int maxy) {//�Ű������� �ڷ��� ����� move �Լ�
		if (kbhit()) {//����ڷκ��� Ű �Է� Ȯ��
			char ch = getDirKey();//�Ű������� �ڷ��� ����� getDirKey �Լ��� �ʱ�ȭ
			if (ch == Left)//���� ����Ű �Է� Ȯ��
				p[0]--;//�������� �� ĭ �̵�
			else if (ch == Right)//������ ����Ű �Է� Ȯ�� 
				p[0]++;//���������� �� ĭ �̵�
			else if (ch == Up)//�� ����Ű �Է� Ȯ��
				p[1]--;//���� �� ĭ �̵�
			else if (ch == Down)//�Ʒ� ����Ű �Է� Ȯ��
				p[1]++;//�Ʒ��� �� ĭ �̵�
			else//����Ű�� �ƴ� �Է� Ȯ��
				return;//�Լ� ����
			clip(maxx, maxy);//clip �Լ� ȣ��
			eat(map);//eat �Լ� ȣ��
		}
	}
};