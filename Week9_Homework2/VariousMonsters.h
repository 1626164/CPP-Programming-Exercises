#pragma once
#include "Monster.h"

class Zombie : public Monster {
public:
	Zombie(string n = "허접좀비", string i = "§", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << " Zombie"; }
};

class Vampire : public Monster {
public:
	Vampire(string n = "뱀파이어", string i = "★", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "처녀귀신", string i = "♥", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(int** map, int maxx, int maxy) {
		x = rand() % maxx;
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {
	bool bHori;
public:
	Jiangshi(string n = "대륙강시", string i = "↔", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class Smombi : public Monster {//추가
public://추가
	Smombi(string n = "스몸비", string i = "※", int x = 0, int y = 0)//추가
		: Monster(n, i, x, y) {}//추가
	~Smombi() { cout << " Smombi"; }//추가

	void move(int** map, int maxx, int maxy) {//추가
		int dir = rand() % 4;//추가
		if (dir == 0) { x--; y--; }//추가
		else if (dir == 1) { x++; y++; }//추가
		else if (dir == 2) { x++; y--; }//추가
		else { x--; y++; }//추가
		clip(maxx, maxy);//추가
		eat(map);//추가
	}//추가
};//추가

class Siangshi : public Jiangshi {//추가
	int nMove = 0;//추가
public://추가
	Siangshi(string n = "수퍼강시", string i = "○", int x = 0, int y = 0)//추가
		: Jiangshi(n, i, x, y) {}//추가
	~Siangshi() { cout << " Siangshi"; }//추가

	void move(int** map, int maxx, int maxy) {//추가
		int dir = rand() % 2;//추가
		int jump = rand() % 2 + 1;//추가
		if (nMove < 100) {//추가
			x += ((dir == 0) ? -jump : jump);//추가
			nMove++;//추가
		}//추가
		else if (nMove >= 100 && nMove < 200) {//추가
			y += ((dir == 0) ? -jump : jump);//추가
			nMove++;//추가
		}//추가
		else if (nMove >= 200 && nMove < 300) {//추가
			x += ((dir == 0) ? -jump : jump);//추가
			nMove++;//추가
		}//추가
		else if (nMove >= 300 && nMove < 400) {//추가
			y += ((dir == 0) ? -jump : jump);//추가
			nMove++;//추가
		}//추가
		else if (nMove >= 400 && nMove < 500) {//추가
			x += ((dir == 0) ? -jump : jump);//추가
			nMove++;//추가
		}//추가
		else x += ((dir == 0) ? -jump : jump);//추가
		clip(maxx, maxy);//추가
		eat(map);//추가
	}//추가
};//추가

class Mymonster : public Smombi {//추가
public://추가
	Mymonster(string n = "내몬스터", string i = "●", int x = 0, int y = 0)//추가
		: Smombi(n, i, x, y) {}//추가
	~Mymonster() { cout << " Mymonster"; }//추가

	void move(int** map, int maxx, int maxy) {//추가
		int dir = rand() % 8;//추가
		if (dir == 0) { x--; y--; }//추가
		else if (dir == 1) { x++; y++; }//추가
		else if (dir == 2) { x++; y--; }//추가
		else if (dir == 3) { x--; y++; }//추가
		else if (dir == 4) x--;//추가
		else if (dir == 5) x++;//추가
		else if (dir == 6) y--;//추가
		else y++;//추가
		clip(maxx, maxy);//추가
		eat(map);//추가
	}//추가
};//추가