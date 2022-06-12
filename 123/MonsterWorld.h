#pragma once//�� ���α׷��� ���� ��� ������ �� ���� ����
#include "Canvas.h"//�� ���α׷��� Canvas.h ��� ������ ����
#include "VariousMonsters.h"//�� ���α׷��� VariousMonsters.h ��� ������ ����
#include "Human.h"//�� ���α׷��� Human.h ��� ������ ����
#include "Matrix.h"//�� ���α׷��� Matrix.h ��� ������ ����
#include <windows.h>//�� ���α׷��� C++ ǥ�� ���̺귯�� windows.h ��� ������ ����
#define MAXMONS 8//�ִ� ���� ���� 8�� ����

class MonsterWorld {//MonsterWorld Ŭ���� ����
	Matrix world;//Matrix ��ü world�� ��� ������ �߰�
	int xMax, yMax, nMon, nMove;//���� �ʺ�, ����, ���� ��, ��ü �̵� Ƚ���� �ڷ��� ����
	Monster* pMon[MAXMONS];//ũ�Ⱑ 8�� pMon ������ �迭
	Canvas canvas;//Canvas ��ü canvas�� ��� ������ �߰�
	int& Map(int x, int y) {//�Ű������� �ڷ��� ����� Map �Լ�
		return world.elem(x, y);//world.elem(x, y)�� ��ȯ
	}
	bool isDone() {//isDone �Լ�
		return countItems() == 0;//countitems() == 0�� ��ȯ
	}
	int countItems() {//countItems �Լ�
		int nItems = 0;//������ ���� �ڷ��� ����� 0���� �ʱ�ȭ
		for (int y = 0; y < yMax; y++)//���� ���̺��� ������ �ݺ�
			for (int x = 0; x < xMax; x++)//���� �ʺ񺸴� ������ �ݺ�
				if (Map(x, y) > 0) //���� �ʺ�� ���̰� 0���� ū�� Ȯ��
					nItems++;//������ �� ����
		return nItems;//������ �� ��ȯ
	}
	void print() {//print �Լ�
		canvas.clear();//Canvas Ŭ������ clear �Լ� ȣ��
		for (int y = 0; y < yMax; y++)//���� ���̺��� ������ �ݺ�
			for (int x = 0; x < xMax; x++)//���� �ʺ񺸴� ������ �ݺ�
				if (Map(x, y) > 0)//Map(x, y)�� 0���� ū�� Ȯ��
					canvas.draw(x, y, "��");//Canvas Ŭ������ draw �Լ� ���
		for (int i = 0; i < nMon; i++)//���� ������ ������ �ݺ�
			pMon[i]->draw(canvas);//�ش� ������ draw �Լ� ȣ��
		canvas.print("[ Monster World (�������� ��) ]");//ȭ�鿡 ���� ���
		cerr << " ��ü �̵� Ƚ�� = " << nMove << endl;//ȭ�鿡 ����� ��ü �̵� Ƚ���� ��� �� ��� ���۸� ���� ����
		cerr << " ���� ������ �� = " << countItems() << endl;//ȭ�鿡 ����� ���� ������ ���� ��� �� ��� ���۸� ���� ����
		for (int i = 0; i < nMon; i++)//���� ������ ������ �ݺ�
			pMon[i]->print();//�ش� ������ print �Լ� ȣ��
	}
public:
	MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {//����Ʈ �Ű������� ��� �ʱ�ȭ ����Ʈ�� ����� ������ ����
		nMon = 0;//���� ���� 0���� �ʱ�ȭ
		nMove = 0;//��ü �̵� Ƚ���� 0���� �ʱ�ȭ
		for (int y = 0; y < yMax; y++)//���� ���̺��� ������ �ݺ�
			for (int x = 0; x < xMax; x++)//���� �ʺ񺸴� ������ �ݺ�
				Map(x, y) = 1;//Map(x, y)�� 1�� �ʱ�ȭ
	}
	~MonsterWorld() {//�Ҹ��� ����
		for (int i = 0; i < nMon; i++)//���� ������ ������ �ݺ�
			delete pMon[i];//pMon[i]�� �޸� ����
	}
	void add(Monster* m) {//�Ű������� Point�� add �Լ�
		if (nMon < MAXMONS)//���� ���� 8���� ������ Ȯ��
			pMon[nMon++] = m;//pMon �迭�� �ּ� ����
	}
	void play(int maxwalk, int wait) {//�Ű������� �ڷ��� ����� play �Լ�
		print();//print �Լ� ȣ��
		cerr << " ���͸� ��������...";//ȭ�鿡 ���� ���
		getchar();//ȭ�鿡 ���ڸ� �Է� �޴� �Լ� ȣ��
		for (int i = 0; i < maxwalk; i++) {//�ִ� �ݺ� Ƚ������ ������ �ݺ�
			for (int k = 0; k < nMon; k++)//���� ������ ������ �ݺ�
				pMon[k]->move(world.Data(), xMax, yMax);//�ش� ������ move �Լ� ȣ��
			nMove++;//��ü �̵� Ƚ�� ����
			print();//print �Լ� ȣ��
			if (isDone())//
				break;//�ݺ��� ����
			Sleep(wait);//sleep �Լ� ȣ��
		}
	}
};