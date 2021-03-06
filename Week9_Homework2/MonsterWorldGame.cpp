#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("허접한좀비", "◎", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어짱", "★", rand() % w, rand() % h));
	game.add(new KGhost("어쩌다귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("못먹어도고", "↔", rand() % w, rand() % h, true));
	game.add(new Jiangshi("못먹어세로", "↕", rand() % w, rand() % h, false));
	game.add(new Smombi("스몸비이다", "※", rand() % w, rand() % h));//추가
	game.add(new Siangshi("수퍼강시다", "○", rand() % w, rand() % h));//추가
	game.add(new Mymonster("내몬스터다", "●", rand() % w, rand() % h));//추가
	game.play(500, 10);
	printf("------게임 종료-------------------\n");
}