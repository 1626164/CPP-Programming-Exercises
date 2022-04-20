#include "Hangman.h"
#include "MyDic.h"//추가

void main()
{
	Hangman	game;
	MyDic words;//추가
	words.load("Words.txt");//추가
	srand((unsigned int)time(NULL));//추가
	int i = rand() % MAXWORDS;//추가
	//game.play("galaxy");
	game.play(words.getEng(i), words.getKor(i));//변경
}