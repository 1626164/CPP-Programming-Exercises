#pragma once
#include "Monster.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80};

class Human : public Monster {
public:
	Human(string n = "미래우파", string i = "우", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " [Human   ]"; }
	//int getDirKey() { return getche() == 224 ? getche() : 0; }//제거
	//void move(int** map, int maxx, int maxy) {
	void move(int** map, int maxx, int maxy, unsigned char ch) {//변경
		//if (kbhit()) {//제거
			//char ch = getDirKey();//제거
			//ch = getche();//제거
			if (ch == Left) x--;
			else if (ch == Right) x++;
			else if (ch == Up) y--;
			else if (ch == Down) y++;
			else return;
			clip(maxx, maxy);
			eat(map);
		//}//제거
	}
};
class Tuman : public Human {//추가
public://추가
	Tuman(string n = "미래좌파", string i = "좌", int x = 0, int y = 0)//추가
		: Human(n, i, x, y) {}//추가
	~Tuman() {}//추가

	void moveHuman(int** map, int maxx, int maxy, unsigned char ch) {//추가
		if (ch == 'a') x--;//추가
		else if (ch == 'd') x++;//추가
		else if (ch == 'w') y--;//추가
		else if (ch == 's') y++;//추가
		else return;//추가
		clip(maxx, maxy);//추가
		eat(map);//추가
	}
};