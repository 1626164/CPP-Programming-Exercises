#pragma once
#include "Canvas.h"
#define DIM 40

class Monster {
	string name, icon;
	int x, y, nItem;
	int nEnergy;//�߰�
	static int nMon;//�߰�

	void clip(int maxx, int maxy) {
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	}
	void eat(int** map) {
		if (map[y][x] == 1) {
			map[y][x] = 0;
			nItem++;
			nEnergy = nEnergy + 8;//�߰�
		}
		else if (nEnergy > 0) {//�߰�
			nEnergy = nEnergy - 1;//�߰�
		}//�߰�
	}
public:
	int getEnergy() {//�߰�
		return nEnergy;//�߰�
	}//�߰�
	Monster(string n = "������", string i = "��", int px = 0, int py = 0)
		//: name(n), icon(i), x(px), y(py), nItem(0) {}
		: name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) { nMon = 4; }//����
	~Monster() { nMon = nMon - 1; cout << "\t" << name << icon << " �������ϴ�~~~\n"; }
	
	void draw(Canvas& canvas) { canvas.draw(x, y, icon); }
	void move(int** map, int maxx, int maxy) {
		switch (rand() % 8) {
		case 0: y--; break;
		case 1: x++; y--; break;
		case 2: x++; break;
		case 3: x++; y++; break;
		case 4: y++; break;
		case 5: x--; y++; break;
		case 6: x--; break;
		case 7: x--; y--; break;
		}
		clip(maxx, maxy);
		eat(map);
	}
	//void print() { cout << "\t" << name << icon << ":" << nItem << endl; }
	void print() { cout << "\t" << name << icon << ":" << nItem << " E:" << nEnergy << endl; }//����
	static void printCount() { cout << " ��ü ������ �� : "<< nMon << endl; };//�߰�
};
int Monster::nMon;//�߰�