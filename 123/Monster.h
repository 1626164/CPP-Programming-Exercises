#pragma once//이 프로그램에 사용된 헤더 파일을 한 번만 포함
#include "Canvas.h"//이 프로그램에 Canvas.h 헤더 파일을 포함
#include "Point.h"//이 프로그램에 Point.h 헤더 파일을 포함

class Monster {//Monster 클래스 선언
public://접근 지정자 선언
	string name, icon;//몬스터 이름과 화면 출력용 아이콘의 자료형 선언
	int nItem;//먹은 아이템 수의 자료형 선언
	Point q, p, p2;//이전 위치와 현재 위치의 자료형 선언
	int nSleep;//쉬어야 하는 횟수의 자료형 선언
	double dist;//쉬고 난 다음 움직인 거리의 자료형 선언
	double total;//총 움직인 거리의 자료형 선언
	void clip(int maxx, int maxy) {//매개변수의 자료형 선언과 clip 함수
		p(maxx, maxy);//Point의 함수 호출 연산자를 사용
	}
	void eat(int** map) {//매개변수의 자료형 선언과 eat 함수
		if (map[p.y][p.x] == 1) {//맵에 아이템이 있는지 확인
			map[p.y][p.x] = 0;//맵에 아이템을 제거
			nItem++;//먹은 아이템 수 증가
		}
		dist += (double)(p - q);//이동거리만큼 쉬고 난 다음 움직인 거리 증가
		total += (double)(p - q);//이동거리만큼 총 움직인 거리 증가
		q = p;//이전 위치를 현재 위치로 초기화
		if (dist > 20) {//쉬고 난 다음 움직인 거리가 20보다 큰지 확인
			dist = 0;//쉬고 난 다음 움직인 거리를 0으로 초기화
			nSleep = 10;//쉬어야 하는 횟수를 10으로 초기화
		}
	}
	bool isSleep() {//isSleep 함수
		if (nSleep > 0) {//쉬어야 하는 횟수가 0보다 큰지 확인
			nSleep--;//쉬어야 하는 횟수 감소
			return true;//true값 반환
		}
		else//쉬어야 하는 횟수가 0보다 작거나 같은지 확인 
			return false;//false값 반환
	}
public://접근 지정자 선언
	Monster(string n = "무명괴물", string i = "※", int x = 0, int y = 0) : name(n), icon(i), nItem(0), p(x, y), q(x, y), nSleep(0), dist(0.0), total(0.0) {}//디폴트 매개변수와 멤버 초기화 리스트를 사용한 생성자 선언
	virtual ~Monster() {//가상 소멸자 선언
		cout << icon << nItem << "거리:" << total << endl;//화면에 아이콘, 먹은 아이템 수, 거리 합계 출력 후 출력 버퍼를 비우고 개행
	}
	void draw(Canvas& canvas) {//매개변수가 Point인 draw 함수
		canvas.draw(p, icon);//Canvas 클래스의 매개변수가 Point와 string인 draw함수 호출
	}
	virtual void move(int** map, int maxx, int maxy) {//매개변수의 자료형 선언과 가상 move 함수
		if (!isSleep()) {//isSleep 함수의 반환값이 false인지 확인
			int num = rand() % 9 + 1;//매개변수의 자료형 선언과 무작위 값(1, 2, 3, 4, 5, 6, 7, 8, 9)으로 초기화
			p2 = Point(num % 3 - 1, num / 3 - 1);//Point의 생성자를 이용해 객체를 만들고 이를 현재 위치로 초기화
			p += p2;//현재 위치에서 다음 위치로 이동
			clip(maxx, maxy);//clip 함수 호출
			eat(map);//eat 함수 호출
		}
	}
	void print() {//print 함수
		cout << "\t" << name << icon << ":" << nItem << ":" << nSleep << endl;//화면에 이름, 아이콘, 출력 후 출력 버퍼를 비우고 개행
	}
};