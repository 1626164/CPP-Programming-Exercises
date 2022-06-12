#pragma once//이 프로그램에 사용된 헤더 파일을 한 번만 포함
#include <iostream>//이 프로그램에 C++ 표준 라이브러리 iostream 헤더 파일을 포함
#include <fstream>//이 프로그램에 C++ 표준 라이브러리 fstream 헤더 파일을 포함
#include "FileException.h"//이 프로그램에 FileException.h 헤더 파일을 포함
using namespace std;//표준 이름공간을 사용
#define NUM_MVP	5//최저 순위를 5로 설정

struct PlayInfo {//PlayInfo 클래스 선언
	string name;//사용자 이름의 자료형 선언
	int nItem;//획득한 아이템 수의 자료형 선언
	double itemPerMove;//이동 거리당 아이템 수의 자료형 선언
	PlayInfo(string na = "신인류", int ni = 0, double ipm = 0.0) : name(na), nItem(ni), itemPerMove(ipm) {}//디폴트 매개변수와 멤버 초기화 리스트를 사용한 생성자 선언
};
class RankingBoard {//RankingBoard 클래스 선언
	PlayInfo MVP[NUM_MVP];//최저 순위
	int nMVP = NUM_MVP;//매개변수의 자료형 선언 후 최저 순위를 매개변수에 저장
public://접근 지정자 선언
	void load(string filename) {//매개변수의 자료형 선언과 load 함수
		ifstream is;//ifstream 객체 is를 멤버 변수에 추가
		is.open(filename);//파일 열기
		if (!is)//순위가 저장된 파일이 열리지 않는지 확인
			throw(FileException(filename, true));//FileException 예외를 만들어 던짐
		for (int i = 0; i < nMVP; i++)//최저 순위를 넘기지 않으면 반복
			is >> MVP[i].nItem >> MVP[i].name >> MVP[i].itemPerMove;//파일에 획득한 아이템 수, 사용자 이름, 이동 거리당 아이템 수 읽기
		is.close();//파일 닫기
	}
	void store(string filename) {//매개변수의 자료형 선언과 store 함수
		ofstream os;//ofstream 객체 os를 멤버 변수에 추가
		os.open(filename);//파일 열기
		if (!os)//순위를 저장할 파일이 열리지 않는지 확인
			throw(FileException(filename, false));//FileException 예외를 만들어 던짐
		for (int i = 0; i < nMVP; i++)//최저 순위를 넘기지 않으면 반복
			os << MVP[i].nItem << " " << MVP[i].name << " " << MVP[i].itemPerMove << "\n";//파일에 획득한 아이템 수, 사용자 이름, 이동 거리당 아이템 수 쓰고 개행
		os.close();//파일 닫기
	}
	void print(string title = "게임 랭킹") {//디폴트 매개변수 사용한 print 함수
		cout << endl << title << endl;//화면에 제목 출력 후 출력 버퍼를 비우고 개행
		for (int i = 0; i < nMVP; i++)//최저 순위를 넘기지 않으면 반복
			cout << "[" << i + 1 << "위] " << MVP[i].name << "\t" << MVP[i].nItem << " " << MVP[i].itemPerMove << "\n";//화면에 순위, 사용자 이름, 획득한 아이템 수, 이동 거리당 아이템 수 출력 후 개행
		cout << "엔터를 입력하세요.";//화면에 문장 출력
		getchar();//화면에 문자를 입력 받는 함수 호출
		cout << endl;//화면에 공백 출력 후 출력 버퍼를 비우고 개행
	}
	int add(int nItem, double ipm) {//매개변수의 자료형 선언과 add 함수
		if (nItem <= MVP[nMVP - 1].nItem) {//비교할 순위에 든 사용자보다 획득한 아이템의 수가 작거나 같은지 확인
			return 0;//함수 종료
		}
		int pos = nMVP - 1;//매개변수의 자료형 선언 후 순위를 매개변수에 저장
		for (; pos > 0; pos--) {//해당 순위에 들어가면 반복
			if (nItem <= MVP[pos - 1].nItem) {//비교할 순위에 든 사용자보다 획득한 아이템의 수가 작거나 같은지 확인
				break;//반복문 종료
			}
			MVP[pos] = MVP[pos - 1];//순위를 올림
		}
		MVP[pos].nItem = nItem;//획득한 아이템 수를 매개변수에 저장
		MVP[pos].itemPerMove = ipm;//이동 거리당 아이템 수를 매개변수에 저장
		cout << "\n[" << pos + 1 << "위] 이름을 입력하세요: ";//화면에 순위와 문장 출력
		cin >> MVP[pos].name;//화면에 사용자 이름 입력
		return pos + 1;//현재 순위를 반환
	}
};