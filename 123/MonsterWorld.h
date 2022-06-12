#pragma once//이 프로그램에 사용된 헤더 파일을 한 번만 포함
#include "Canvas.h"//이 프로그램에 Canvas.h 헤더 파일을 포함
#include "VariousMonsters.h"//이 프로그램에 VariousMonsters.h 헤더 파일을 포함
#include "Human.h"//이 프로그램에 Human.h 헤더 파일을 포함
#include "Matrix.h"//이 프로그램에 Matrix.h 헤더 파일을 포함
#include <windows.h>//이 프로그램에 C++ 표준 라이브러리 windows.h 헤더 파일을 포함
#define MAXMONS 8//최대 몬스터 수를 8로 설정

class MonsterWorld {//MonsterWorld 클래스 선언
	Matrix world;//Matrix 객체 world를 멤버 변수에 추가
	int xMax, yMax, nMon, nMove;//맵의 너비, 높이, 몬스터 수, 전체 이동 횟수의 자료형 선언
	Monster* pMon[MAXMONS];//크기가 8인 pMon 포인터 배열
	Canvas canvas;//Canvas 객체 canvas를 멤버 변수에 추가
	int& Map(int x, int y) {//매개변수의 자료형 선언과 Map 함수
		return world.elem(x, y);//world.elem(x, y)을 반환
	}
	bool isDone() {//isDone 함수
		return countItems() == 0;//countitems() == 0을 반환
	}
	int countItems() {//countItems 함수
		int nItems = 0;//아이템 수의 자료형 선언과 0으로 초기화
		for (int y = 0; y < yMax; y++)//맵의 높이보다 작으면 반복
			for (int x = 0; x < xMax; x++)//맵의 너비보다 작으면 반복
				if (Map(x, y) > 0) //맵의 너비와 높이가 0보다 큰지 확인
					nItems++;//아이템 수 증가
		return nItems;//아이템 수 반환
	}
	void print() {//print 함수
		canvas.clear();//Canvas 클래스의 clear 함수 호출
		for (int y = 0; y < yMax; y++)//맵의 높이보다 작으면 반복
			for (int x = 0; x < xMax; x++)//맵의 너비보다 작으면 반복
				if (Map(x, y) > 0)//Map(x, y)가 0보다 큰지 확인
					canvas.draw(x, y, "■");//Canvas 클래스의 draw 함수 출력
		for (int i = 0; i < nMon; i++)//몬스터 수보다 작으면 반복
			pMon[i]->draw(canvas);//해당 몬스터의 draw 함수 호출
		canvas.print("[ Monster World (경쟁적인 삶) ]");//화면에 문장 출력
		cerr << " 전체 이동 횟수 = " << nMove << endl;//화면에 문장과 전체 이동 횟수를 출력 후 출력 버퍼를 비우고 개행
		cerr << " 남은 아이템 수 = " << countItems() << endl;//화면에 문장과 남은 아이템 수를 출력 후 출력 버퍼를 비우고 개행
		for (int i = 0; i < nMon; i++)//몬스터 수보다 작으면 반복
			pMon[i]->print();//해당 몬스터의 print 함수 호출
	}
public:
	MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {//디폴트 매개변수와 멤버 초기화 리스트를 사용한 생성자 선언
		nMon = 0;//몬스터 수를 0으로 초기화
		nMove = 0;//전체 이동 횟수를 0으로 초기화
		for (int y = 0; y < yMax; y++)//맵의 높이보다 작으면 반복
			for (int x = 0; x < xMax; x++)//맵의 너비보다 작으면 반복
				Map(x, y) = 1;//Map(x, y)를 1로 초기화
	}
	~MonsterWorld() {//소멸자 선언
		for (int i = 0; i < nMon; i++)//몬스터 수보다 작으면 반복
			delete pMon[i];//pMon[i]에 메모리 해제
	}
	void add(Monster* m) {//매개변수가 Point인 add 함수
		if (nMon < MAXMONS)//몬스터 수가 8보다 작은지 확인
			pMon[nMon++] = m;//pMon 배열의 주소 복사
	}
	void play(int maxwalk, int wait) {//매개변수의 자료형 선언과 play 함수
		print();//print 함수 호출
		cerr << " 엔터를 누르세요...";//화면에 문장 출력
		getchar();//화면에 문자를 입력 받는 함수 호출
		for (int i = 0; i < maxwalk; i++) {//최대 반복 횟수보다 작으면 반복
			for (int k = 0; k < nMon; k++)//몬스터 수보다 작으면 반복
				pMon[k]->move(world.Data(), xMax, yMax);//해당 몬스터의 move 함수 호출
			nMove++;//전체 이동 횟수 증가
			print();//print 함수 호출
			if (isDone())//
				break;//반복문 종료
			Sleep(wait);//sleep 함수 호출
		}
	}
};