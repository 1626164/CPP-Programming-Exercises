#include "Ranking.h"
extern int playFifteenPuzzle();
void main()
{
	//loadRanking("ranking.txt");
	loadRanking("ranking.bin");//�����
	int rank = playFifteenPuzzle();
	printRanking();
	//storeRanking("ranking.txt");
	storeRanking("ranking.bin");//�����
}