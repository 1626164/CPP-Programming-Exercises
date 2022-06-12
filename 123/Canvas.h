#pragma once//이 프로그램에 사용된 헤더 파일을 한 번만 포함
#include <iostream>//이 프로그램에 C++ 표준 라이브러리 iostream 헤더 파일을 포함
#include <string>//이 프로그램에 C++ 표준 라이브러리 string 헤더 파일을 포함
#include "Point.h"//이 프로그램에 Point.h 헤더 파일을 포함
#define MAXLINES 100//맵의 최대 높이를 100으로 설정
using namespace std;//표준 이름공간을 사용

class Canvas {//Canvas 클래스 선언
	string line[MAXLINES];//화면 출력을 위한 자료형 선언
	int xMax, yMax;//맵의 너비와 높이의 자료형 선언
public://접근 지정자 선언
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {//디폴트 매개변수와 멤버 초기화 리스트를 사용한 생성자 선언
		for (int y = 0; y < yMax; y++)//변수가 캔버스 내부에 있으면 반복
			line[y] = string(xMax * 2, ' ');//각 라인에 대한 string 객체 초기화
	}
	void draw(int x, int y, string val) {//매개변수의 자료형 선언과 draw 함수
		if (x >= 0 && y >= 0 && x < xMax && y < yMax)//변수가 캔버스 내부에 있는지 확인
			line[y].replace(x * 2, 2, val);//캔버스의 모든 화소 값을 val로 변경
	}
	void draw(Point& p, string val) {//매개변수의 자료형 선언과 draw 함수
		draw(p.x, p.y, val);//매개변수가 Point와 string인 draw 함수
	}
	void clear(string val = ". ") {//디폴트 매개변수 사용한 clear 함수
		for (int y = 0; y < yMax; y++)//변수가 캔버스 내부에 있으면 반복
			for (int x = 0; x < xMax; x++)//변수가 캔버스 내부에 있으면 반복
				draw(x, y, val);//캔버스의 모든 화소 값을 val로 변경 
	}
	void print(const char* title = "<My Canvas>") {//디폴트 매개변수 사용한 print 함수
		system("cls");//화면 정리
		cout << title << endl;//화면에 제목 출력 후 출력 버퍼를 비우고 개행
		for (int y = 0; y < yMax; y++)//변수가 캔버스 내부에 있으면 반복
			cout << line[y] << endl;//화면에 각 라인 출력 후 출력 버퍼를 비우고 개행
		cout << endl;//화면에 공백 출력 후 출력 버퍼를 비우고 개행
	}
};