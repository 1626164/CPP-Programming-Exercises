#include "MonsterWorld.h"//이 프로그램에 MonsterWorld.h 헤더 파일을 포함
#include "Human.h"//이 프로그램에 Human.h 헤더 파일을 포함
#include "RankingBoard.h"//이 프로그램에 RankingBoard.h 헤더 파일을 포함
#include <time.h>//이 프로그램에 C++ 표준 라이브러리 time.h 헤더 파일을 포함

void main()//main 함수
{
	RankingBoard rank;//RankingBoard 객체 rank를 멤버 변수에 추가
	try {//예외 발생 확인
		rank.load("MonsterWorld.rnk");//해당 파일 열기
	}
	catch (FileException e) {//예외 처리
		char str[80];//매개변수의 최대 크기와 자료형 선언
		string passwd, correct = "123456";//매개변수의 자료형 선언과 비밀번호 설정
		cout << "관리자 비밀번호를 입력하세요: ";//화면에 문장 출력
		for (int i = 0;; i++) {//조건없이 반복
			str[i] = getch();//변수에 키 입력 함수로 초기화
			putchar('*');//화면에 문자를 출력하는 함수
			if (str[i] == '\r') {//입력받은 키가 엔터인지 확인
				str[i] = '\0';//변수 초기화
				passwd = str;//str을 passwd로 초기화
				cout << "\n";//화면에 공백 출력 후 개행
				break;//반복문 종료
			}
		}
		if (passwd != correct) {//비밀번호가 맞는지 확인
			cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";//화면에 문장 출력
			exit(0);//프로그램 종료
		}
	}
	rank.print("[게임 랭킹: 시작]");//화면에 순위와 문장 출력
	srand((unsigned int)time(NULL));//난수 생성 함수
	int w = 16, h = 8;//맵의 크기(16 x 8)를 저장
	MonsterWorld game(w, h);//몬스터 세상 객체 생성 및 맵의 크기(16 x 8)를 인수로 전달
	game.add(new Zombie("허접한좀비", "§", rand() % w, rand() % h));//Zombie 객체를 생성하고 몬스터 세상에 추가
	game.add(new Vampire("뱀파이어짱", "★", rand() % w, rand() % h));//Vampire 객체를 생성하고 몬스터 세상에 추가
	game.add(new KGhost("어쩌다귀신", "♥", rand() % w, rand() % h));//KGhost 객체를 생성하고 몬스터 세상에 추가
	game.add(new Jiangshi("못먹어도고", "↔", rand() % w, rand() % h, true));//Jiangshi 객체를 생성하고 몬스터 세상에 추가
	game.add(new Jiangshi("못먹어세로", "↕", rand() % w, rand() % h, false));//Jiangshi 객체를 생성하고 몬스터 세상에 추가
	Human* human = new Human("미래의인류", "♀", rand() % w, rand() % h);//human 객체를 생성
	game.add(human);//human 객체를 몬스터 세상에 추가
	game.play(500, 10);//play 함수에 최대 반복 횟수(500회)와 대기시간(0.01초)을 인수로 전달
	printf("------게임 종료-------------------\n");//화면에 문장 출력
	rank.add(human->nItem, human->nItem / human->total);//human의 아이템 획득 수와 이동 거리당 아이템 획득 수를 add 함수의 매개변수로 전달
	rank.print("[게임 랭킹: 종료]");//현재 순위를 화면에 출력
	rank.store("MonsterWorld.rnk");//현재 순위를 해당 파일에 저장 
}