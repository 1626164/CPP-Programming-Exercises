#pragma once//�� ���α׷��� ���� ��� ������ �� ���� ����
#include "Monster.h"//�� ���α׷��� Monster.h ��� ������ ����

class Zombie : public Monster {//Monster Ŭ������ ����� Zombie Ŭ���� ����
public://���� ������ ����
	Zombie(string n = "��������", string i = "��", int x = 0, int y = 0) : Monster(n, i, x, y) {}//����Ʈ �Ű������� ��� �ʱ�ȭ ����Ʈ�� ����� ������ ����
	~Zombie() {//�Ҹ��� ����
		cout << " [Zombie  ]";//ȭ�鿡 ���� ���
	}
};
class Vampire : public Monster {//Monster Ŭ������ ����� Vampire Ŭ���� ����
public://���� ������ ����
	Vampire(string n = "�����̾�", string i = "��", int x = 0, int y = 0) : Monster(n, i, x, y) {}//����Ʈ �Ű������� ��� �ʱ�ȭ ����Ʈ�� ����� ������ ����
	~Vampire() {//�Ҹ��� ����
		cout << " [Vampire ]";//ȭ�鿡 ���� ���
	}
	void move(int** map, int maxx, int maxy) {//�Ű������� �ڷ��� ����� move �Լ�
		if (!isSleep()) {//isSleep �Լ��� ��ȯ���� false���� Ȯ��
			int dir = rand() % 4;//�Ű������� �ڷ��� ����� ������ ��(0, 1, 2, 3)���� �ʱ�ȭ
			if (dir == 0)//dir���� 0���� Ȯ��
				p[0]--;//�������� ��ĭ �̵�
			else if (dir == 1)//dir���� 1���� Ȯ��
				p[0]++;//���������� ��ĭ �̵�
			else if (dir == 2)//dir���� 2���� Ȯ��
				p[1]--;//���� ��ĭ �̵�
			else//dir���� 3���� Ȯ��
				p[1]++;//�Ʒ��� ��ĭ �̵�
			clip(maxx, maxy);//clip �Լ� ȣ��
			eat(map);//eat �Լ� ȣ��
		}
	}
};
class KGhost : public Monster {//Monster Ŭ������ ����� KGhost Ŭ���� ����
public://���� ������ ����
	KGhost(string n = "ó��ͽ�", string i = "��", int x = 0, int y = 0) : Monster(n, i, x, y) {}//����Ʈ �Ű������� ��� �ʱ�ȭ ����Ʈ�� ����� ������ ����
	~KGhost() {//�Ҹ��� ����
		cout << " [KGhost  ]";//ȭ�鿡 ���� ���
	}
	void move(int** map, int maxx, int maxy) {//�Ű������� �ڷ��� ����� move �Լ�
		if (!isSleep()) {//isSleep �Լ��� ��ȯ���� false���� Ȯ��
			p = Point(rand() % maxx, rand() % maxy);//Point�� �����ڸ� �̿��� ��ü�� ����� �̸� ���� ��ġ�� ����
			clip(maxx, maxy);//clip �Լ� ȣ��
			eat(map);//eat �Լ� ȣ��
		}
	}
};
class Jiangshi : public Monster {//Monster Ŭ������ ����� Jiangshi Ŭ���� ����
	bool bHori;//�Ű������� �ڷ��� ����
public://���� ������ ����
	Jiangshi(string n = "�������", string i = "��", int x = 0, int y = 0, bool bH = true) : Monster(n, i, x, y), bHori(bH) {}//����Ʈ �Ű������� ��� �ʱ�ȭ ����Ʈ�� ����� ������ ����
	~Jiangshi() {//�Ҹ��� ����
		cout << " [Jiangshi]";//ȭ�鿡 ���� ���
	}
	void move(int** map, int maxx, int maxy) {//�Ű������� �ڷ��� ����� move �Լ�
		if (!isSleep()) {//isSleep �Լ��� ��ȯ���� false���� Ȯ��
			int dir = rand() % 2;//�Ű������� �ڷ��� ����� ������ ��(0, 1)���� �ʱ�ȭ
			int jump = rand() % 2 + 1;//�Ű������� �ڷ��� ����� ������ ��(1, 2)���� �ʱ�ȭ
			if (bHori)//bHoir���� true���� Ȯ��
				p[0] += ((dir == 0) ? -jump : jump);//dir���� 0�̸� �������� 1�̸� ���������� ��ĭ �Ǵ� ��ĭ �̵�
			else//bHoir���� false���� Ȯ��
				p[1] += ((dir == 0) ? -jump : jump);//dir���� 0�̸� ���� 1�̸� �Ʒ��� ��ĭ �Ǵ� ��ĭ �̵�
			clip(maxx, maxy);//clip �Լ� ȣ��
			eat(map);//eat �Լ� ȣ��
		}
	}
};