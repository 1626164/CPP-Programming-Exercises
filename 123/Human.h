#pragma once//이 프로그램에 사용된 헤더 파일을 한 번만 포함
#include "Monster.h"//이 프로그램에 Monster.h 헤더 파일을 포함
#include <conio.h>//이 프로그램에 C++ 표준 라이브러리 conio.h 헤더 파일을 포함
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };//상수 초기화와 열거형 선언

class Human : public Monster {//Human 클래스 선언
public://접근 지정자 선언
	Human(string n = "미래인류", string i = "♀", int px = 0, int py = 0) : Monster(n, i, px, py) {}//디폴트 매개변수와 멤버 초기화 리스트 사용한 생성자 선언
	~Human() {//소멸자 선언
		cout << " [Human   ]";//화면에 문장 출력
	}
	int getDirKey() {//getDirKey 함수
		return getche() == 224 ? getche() : 0;//입력한 키가 방향키라면 방향키 값을 반환하고 아니라면 함수 종료
	}
	void move(int** map, int maxx, int maxy) {//매개변수의 자료형 선언과 move 함수
		if (kbhit()) {//사용자로부터 키 입력 확인
			char ch = getDirKey();//매개변수의 자료형 선언과 getDirKey 함수로 초기화
			if (ch == Left)//왼쪽 방향키 입력 확인
				p[0]--;//왼쪽으로 한 칸 이동
			else if (ch == Right)//오른쪽 방향키 입력 확인 
				p[0]++;//오른쪽으로 한 칸 이동
			else if (ch == Up)//위 방향키 입력 확인
				p[1]--;//위로 한 칸 이동
			else if (ch == Down)//아래 방향키 입력 확인
				p[1]++;//아래로 한 칸 이동
			else//방향키가 아닌 입력 확인
				return;//함수 종료
			clip(maxx, maxy);//clip 함수 호출
			eat(map);//eat 함수 호출
		}
	}
};