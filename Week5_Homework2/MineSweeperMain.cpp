#include "MineSweeper.h"
void main()
{
	int total;
	int	row;//�߰�
	int	column;//�߰�
	printf(" <Mine Sweeper>\n");//�߰�
	printf(" ���� ���� ũ�� �Է� : ");//�߰�
	scanf("%d", &row);//�߰�
	scanf("%d", &column);//�߰�
	system("cls");//�߰�
	printf(" <Mine Sweeper>\n");
	printf(" �ż��� �� ������ ���� �Է� : ");
	scanf("%d", &total);
	//playMineSweeper( total );
	playMineSweeper(total, row, column);//����
}