#pragma once//이 프로그램에 사용된 헤더 파일을 한 번만 포함
#include <iostream>//이 프로그램에 C++ 표준 라이브러리 iostream 헤더 파일을 포함
#include <iomanip>//이 프로그램에 C++ 표준 라이브러리 iomanip 헤더 파일을 포함
using namespace std;//표준 이름공간을 사용

class Matrix {//Matrix 클래스 선언
	int rows, cols;//행과 열의 크기의 자료형 선언
	int** mat;//실제 행렬 데이터의 자료형 선언
public://접근 지정자 선언
	Matrix(int r = 0, int c = 0) : rows(r), cols(c), mat(NULL) {//디폴트 매개변수와 멤버 초기화 리스트를 사용한 생성자 선언
		mat = new int* [rows];//mat에 메모리 할당
		for (int i = 0; i < rows; i++)//행보다 작으면 반복
			mat[i] = new int[cols];//mat[i]에 메모리 할당
	}
	~Matrix() {//소멸자 선언
		if (mat != NULL) {//mat이 NULL이 아닌지 확인
			for (int i = 0; i < rows; i++)//행보다 작으면 반복
				delete[] mat[i];//mat[i]에 메모리 해제
			delete[] mat;//mat에 메모리 해제
		}
	}
	int& elem(int x, int y) {//매개변수의 자료형 선언과 elem 함수
		return mat[y][x];//mat[y][x]를 반환
	}
	int Rows() {//Rows 함수
		return rows;//행을 반환
	}
	int Cols() {//Cols 함수
		return cols;//열을 반환
	}
	int** Data() {//Data 함수
		return mat;//mat을 반환
	};
	void print(const char* str = "Mat") {//디폴트 매개변수 사용한 print 함수
		cout << str << " " << rows << "x" << cols << endl;//화면에 행렬과 문장을 출력 후 출력 버퍼를 비우고 개행
		for (int i = 0; i < rows; i++) {//행보다 작으면 반복
			for (int j = 0; j < cols; j++)//열보다 작으면 반복
				cout << setw(4) << mat[i][j];//화면에 행렬 출력
			cout << "\n";//화면에 공백 출력 후 개행
		}
	}
	void setRand(int val = 100) {//디폴트 매개변수 사용한 setRand 함수
		if (mat != NULL) {//mat값이 NULL이 아닌지 확인
			for (int i = 0; i < rows; i++)//행보다 작으면 반복
				for (int j = 0; j < cols; j++)//열보다 작으면 반복
					mat[i][j] = (rand() % val);//무작위 값으로 초기화
		}
	}
};