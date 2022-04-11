#include "MineSweeper.h"
void main()
{
	int total;
	int	row;//추가
	int	column;//추가
	printf(" <Mine Sweeper>\n");//추가
	printf(" 지뢰 맵의 크기 입력 : ");//추가
	scanf("%d", &row);//추가
	scanf("%d", &column);//추가
	system("cls");//추가
	printf(" <Mine Sweeper>\n");
	printf(" 매설할 총 지뢰의 개수 입력 : ");
	scanf("%d", &total);
	//playMineSweeper( total );
	playMineSweeper(total, row, column);//변경
}