#include "MineSweeper.h"
//#define DIM 9

enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open, Flag };
//static int	MineMapMask[DIM][DIM];
static int	MineMapMask[40][80];//변경
//static int	MineMapLabel[DIM][DIM];
static int	MineMapLabel[40][80];//변경
//static int	nx = DIM, ny = DIM;
static int	nx , ny;//변경
//static int	nBomb = DIM;
static int nBomb;//변경


inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }
inline bool	isValid(int x, int y) { return (x >= 0 && x < nx&& y >= 0 && y < ny); }
inline bool	isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }
inline bool	isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; }

static void dig(int x, int y) {
	if (isValid(x, y) && mask(x, y) != Open) {
		mask(x, y) = Open;
		if (label(x, y) == 0) {
			dig(x - 1, y - 1);
			dig(x - 1, y);
			dig(x - 1, y + 1);
			dig(x, y - 1);
			dig(x, y + 1);
			dig(x + 1, y - 1);
			dig(x + 1, y);
			dig(x + 1, y + 1);
		}
	}
}
static void mark(int x, int y) {
	if (isValid(x, y) && mask(x, y) == Hide)
		mask(x, y) = Flag;
}
static int getBombCount() {
	int count = 0;
	for (int y = 0; y < ny; y++)
	for (int x = 0; x < nx; x++)
		if (mask(x, y) == Flag) count++;
	return count;
}
static void print() {
	system("cls");
	printf("   발견:%2d   전체:%2d\n", getBombCount(), nBomb);
	//printf("   ①②③④⑤⑥⑦⑧⑨\n");
	printf("   ");//추가
	for (int x = 0; x < nx; x++) {//추가
		printf("%2d", 1 + x);//추가
	}//추가
	printf("\n");//추가
	for (int y = 0; y < ny; y++) {
		//printf("%2c ", '1' + y);
		printf("%2d ", 1 + y);//변경
		for (int x = 0; x < nx; x++) {
			if (mask(x, y) == Hide)	printf("□");
			else if (mask(x, y) == Flag) printf("¤");
			else {
				if (isBomb(x, y)) printf("※");
				else if (isEmpty(x, y)) printf("  ");
				else printf("%2d", label(x, y));
			}
		}
		printf("\n");
	}
}
static int countNbrBombs(int x, int y) {
	int count = 0;
	for (int yy = y - 1; yy <= y + 1; yy++)
		for (int xx = x - 1; xx <= x + 1; xx++)
			if (isValid(xx, yy) && label(xx, yy) == Bomb)
				count++;
	return count;
}
//static void init(int total = 9) {
static void init(int total, int row, int column = 9) {//변경
	srand((unsigned int)time(NULL));
	nx = row;//추가
	ny = column;//추가
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) {
			mask(x, y) = Hide;
			label(x, y) = 0;
		}
	nBomb = total;
	for (int i = 0; i < nBomb; i++) {
		int x, y;
		do {
			x = rand() % nx;
			y = rand() % ny;
		} while (label(x, y) != Empty);
		label(x, y) = Bomb;
	}
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++)
			if (label(x, y) == Empty)
				label(x, y) = countNbrBombs(x, y);
}
static bool getPos(int& x, int& y) {
	//printf("\n지뢰(P)행(A-I)열(1-9)\n      입력 --> ");
	printf("\n지뢰(P)행(1-%d)열(1-%d)\n      입력 --> ", ny, nx);//변경
	bool isBomb = false;
	//y = toupper(getch()) - 'A';
	char p;//추가
	p = toupper(getche());//추가
	//if (y == 'P' - 'A') {
	if (p == 'P') {//변경
		isBomb = true;
		//y = toupper(getche()) - 'A';
		scanf("%d", &y);//추가
		y = y - 1;//추가
		scanf("%d", &x);//추가
		x = x - 1;//추가
	}
	else {//추가
		char pp;//추가
		pp = getche();//추가
		if (pp == 32) {//추가
			y = p - 49;//추가
		}//추가
		else {//추가
		y = 10*(p - 48) + pp - 49;//추가
		}//추가
		scanf("%d", &x);//추가
		x = x - 1;//추가
	}
	//x = getch() - '1';
	return isBomb;
}
static int checkDone() {
	int count = 0;
	for (int y = 0; y < ny; y++)
		for (int x = 0; x < nx; x++) {
			if (mask(x, y) != Open) count++;
			else if (isBomb(x, y)) return -1;
		}
	return (count == nBomb) ? 1 : 0;
}
//void playMineSweeper(int total) {
void playMineSweeper(int total, int row, int column) {//변경
	int x, y, status;
	//init(total);
	init(total, row, column);//변경
	do {
		print();
		bool isBomb = getPos(x, y);
		if (isBomb) mark(x, y);
		else dig(x, y);
		status = checkDone();
	} while (status == 0);
	print();
	if (status < 0)
		printf("\n실패: 지뢰 폭발!!!\n\n");
	else printf("\n성공: 탐색 성공!!!\n\n");
}