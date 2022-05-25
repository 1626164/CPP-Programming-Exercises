#pragma once
#include "Screen.h"
class Monster {
protected:
	string name;
	string icon;
	int posX, posY;
	int nItem;
	void clip(int maxx, int maxy) {
		if (posX < 0) posX = 0;
		if (posX >= maxx) posX = maxx - 1;
		if (posY < 0) posY = 0;
		if (posY >= maxy) posY = maxy - 1;
	}
	void eat(int** map) {
		if (map[posY][posX] == 1) {
			map[posY][posX] = 0;
			nItem++;
		}
	}
public:
	Monster(string n = "무명괴물", string i = "※", int px = 0, int py = 0)
		: name(n), icon(i), posX(px), posY(py), nItem(0) {}
	virtual ~Monster() { cout << "\t" << name << icon << "사라집니다\n"; }

	void draw(Screen& scr) { scr.draw(posX, posY, icon); }
	virtual void move(int** map, int maxx, int maxy) {
		switch (rand() % 8) {
		case 0: posY--; break;
		case 1: posX++; posY--; break;
		case 2: posX++; break;
		case 3: posX++; posY++; break;
		case 4: posY++; break;
		case 5: posX--; posY++; break;
		case 6: posX--; break;
		case 7: posX--; posY--; break;
		}
		clip(maxx, maxy);
		eat(map);
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << endl; }
};