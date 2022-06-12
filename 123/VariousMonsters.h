#pragma once//이 프로그램에 사용된 헤더 파일을 한 번만 포함
#include "Monster.h"//이 프로그램에 Monster.h 헤더 파일을 포함

class Zombie : public Monster {//Monster 클래스를 상속한 Zombie 클래스 선언
public://접근 지정자 선언
	Zombie(string n = "허접좀비", string i = "§", int x = 0, int y = 0) : Monster(n, i, x, y) {}//디폴트 매개변수와 멤버 초기화 리스트를 사용한 생성자 선언
	~Zombie() {//소멸자 선언
		cout << " [Zombie  ]";//화면에 문장 출력
	}
};
class Vampire : public Monster {//Monster 클래스를 상속한 Vampire 클래스 선언
public://접근 지정자 선언
	Vampire(string n = "뱀파이어", string i = "★", int x = 0, int y = 0) : Monster(n, i, x, y) {}//디폴트 매개변수와 멤버 초기화 리스트를 사용한 생성자 선언
	~Vampire() {//소멸자 선언
		cout << " [Vampire ]";//화면에 문장 출력
	}
	void move(int** map, int maxx, int maxy) {//매개변수의 자료형 선언과 move 함수
		if (!isSleep()) {//isSleep 함수의 반환값이 false인지 확인
			int dir = rand() % 4;//매개변수의 자료형 선언과 무작위 값(0, 1, 2, 3)으로 초기화
			if (dir == 0)//dir값이 0인지 확인
				p[0]--;//왼쪽으로 한칸 이동
			else if (dir == 1)//dir값이 1인지 확인
				p[0]++;//오른쪽으로 한칸 이동
			else if (dir == 2)//dir값이 2인지 확인
				p[1]--;//위로 한칸 이동
			else//dir값이 3인지 확인
				p[1]++;//아래로 한칸 이동
			clip(maxx, maxy);//clip 함수 호출
			eat(map);//eat 함수 호출
		}
	}
};
class KGhost : public Monster {//Monster 클래스를 상속한 KGhost 클래스 선언
public://접근 지정자 선언
	KGhost(string n = "처녀귀신", string i = "♥", int x = 0, int y = 0) : Monster(n, i, x, y) {}//디폴트 매개변수와 멤버 초기화 리스트를 사용한 생성자 선언
	~KGhost() {//소멸자 선언
		cout << " [KGhost  ]";//화면에 문장 출력
	}
	void move(int** map, int maxx, int maxy) {//매개변수의 자료형 선언과 move 함수
		if (!isSleep()) {//isSleep 함수의 반환값이 false인지 확인
			p = Point(rand() % maxx, rand() % maxy);//Point의 생성자를 이용해 객체를 만들고 이를 현재 위치에 복사
			clip(maxx, maxy);//clip 함수 호출
			eat(map);//eat 함수 호출
		}
	}
};
class Jiangshi : public Monster {//Monster 클래스를 상속한 Jiangshi 클래스 선언
	bool bHori;//매개변수의 자료형 선언
public://접근 지정자 선언
	Jiangshi(string n = "대륙강시", string i = "↔", int x = 0, int y = 0, bool bH = true) : Monster(n, i, x, y), bHori(bH) {}//디폴트 매개변수와 멤버 초기화 리스트를 사용한 생성자 선언
	~Jiangshi() {//소멸자 선언
		cout << " [Jiangshi]";//화면에 문장 출력
	}
	void move(int** map, int maxx, int maxy) {//매개변수의 자료형 선언과 move 함수
		if (!isSleep()) {//isSleep 함수의 반환값이 false인지 확인
			int dir = rand() % 2;//매개변수의 자료형 선언과 무작위 값(0, 1)으로 초기화
			int jump = rand() % 2 + 1;//매개변수의 자료형 선언과 무작위 값(1, 2)으로 초기화
			if (bHori)//bHoir값이 true인지 확인
				p[0] += ((dir == 0) ? -jump : jump);//dir값이 0이면 왼쪽으로 1이면 오른쪽으로 한칸 또는 두칸 이동
			else//bHoir값이 false인지 확인
				p[1] += ((dir == 0) ? -jump : jump);//dir값이 0이면 위로 1이면 아래로 한칸 또는 두칸 이동
			clip(maxx, maxy);//clip 함수 호출
			eat(map);//eat 함수 호출
		}
	}
};