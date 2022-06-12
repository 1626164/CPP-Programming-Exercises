#pragma once//이 프로그램에 사용된 헤더 파일을 한 번만 포함
#include <string>//이 프로그램에 C++ 표준 라이브러리 string 헤더 파일을 포함
struct FileException {//FileException 클래스 선언
	string filename;//파일 이름의 자료형 선언
	bool bRead;//bRead가 true이면 읽기 모드 그리고 false이면 쓰기 모드로 처리하는 파일 모드의 자료형 선언
	FileException(string name, bool b) : filename(name), bRead(b) {}//멤버 초기화 리스트를 사용한 생성자 선언
};