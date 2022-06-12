#pragma once//이 프로그램에 사용된 헤더 파일을 한 번만 포함
#include <iostream>//이 프로그램에 C++ 표준 라이브러리 iostream 헤더 파일을 포함
#include <cmath>//이 프로그램에 C++ 표준 라이브러리 cmath 헤더 파일을 포함
using namespace std;//표준 이름공간을 사용

class Point {//Point 클래스 선언
	int x, y;//좌표값의 자료형 선언
	friend class Monster;//Monster를 친구 클래스로 등록
	friend class Canvas;//Canvas를 친구 클래스로 등록
public://접근 지정자 선언
	Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}//디폴트 매개변수와 멤버 초기화 리스트를 사용한 생성자 선언
	int& operator[] (int id) {//매개변수의 자료형 선언과 인덱스 연산자
		if (id == 0)//id값이 0인지 확인
			return x;//x값 반환
		else if (id == 1)//id값이 1인지 확인
			return y;//y값 반환
		else//id값이 0 또는 1이 아닌지 확인
			exit(0);//프로그램 종료
	}
	operator double() {//double로의 형 변환 연산자
		return sqrt((double)x * x + y * y);//원점으로부터의 유클리드 거리를 반환
	}
	void operator()(int maxx, int maxy) {//매개변수의 자료형 선언과 () 연산자 중복 함수
		if (x < 0)//x가 0보다 작은지 확인
			x = 0;//x를 0으로 초기화
		if (x >= maxx)//x가 maxx보다 크거나 같은지 확인
			x = maxx - 1;//x를 maxx-1으로 초기화
		if (y < 0)//y가 0보다 작은지 확인
			y = 0;//y를 0으로 초기화
		if (y >= maxy)//y가 maxy보다 크거나 같은지 확인
			y = maxy - 1;//y를 maxy-1으로 초기화
	}
	Point operator- () {//- 연산자 중복 함수
		return Point(-x, -y);//Point(-x, -y) 반환
	}
	bool operator== (Point& p) {//매개변수가 Point인 == 연산자 중복 함수
		return x == p.x && y == p.y;//x == p.x 그리고 y == p.y 반환
	}
	bool operator!= (Point& p) {//매개변수가 Point인 != 연산자 중복 함수
		return x != p.x || y != p.y; //x != p.x 또는 y != p.y; 반환
	}
	Point operator- (Point& p) {//매개변수가 Point인 - 연산자 중복 함수
		return Point(x - p.x, y - p.y);//Point(x - p.x, y - p.y) 반환
	}
	Point operator+ (Point& p) {//매개변수가 Point인 + 연산자 중복 함수
		return Point(x + p.x, y + p.y);//Point(x + p.x, y + p.y) 반환
	}
	void operator+= (Point& p) {//매개변수가 Point인 += 연산자 중복 함수
		x += p.x, y += p.y;//x += p.x 와 y += p.y 반환
	}
	void operator-= (Point& p) {//매개변수가 Point인 -= 연산자 중복 함수
		x -= p.x, y -= p.y;//x -= p.x 와 y -= p.y 반환
	}
};