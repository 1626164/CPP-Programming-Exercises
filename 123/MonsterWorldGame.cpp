#include "MonsterWorld.h"//�� ���α׷��� MonsterWorld.h ��� ������ ����
#include "Human.h"//�� ���α׷��� Human.h ��� ������ ����
#include "RankingBoard.h"//�� ���α׷��� RankingBoard.h ��� ������ ����
#include <time.h>//�� ���α׷��� C++ ǥ�� ���̺귯�� time.h ��� ������ ����

void main()//main �Լ�
{
	RankingBoard rank;//RankingBoard ��ü rank�� ��� ������ �߰�
	try {//���� �߻� Ȯ��
		rank.load("MonsterWorld.rnk");//�ش� ���� ����
	}
	catch (FileException e) {//���� ó��
		char str[80];//�Ű������� �ִ� ũ��� �ڷ��� ����
		string passwd, correct = "123456";//�Ű������� �ڷ��� ����� ��й�ȣ ����
		cout << "������ ��й�ȣ�� �Է��ϼ���: ";//ȭ�鿡 ���� ���
		for (int i = 0;; i++) {//���Ǿ��� �ݺ�
			str[i] = getch();//������ Ű �Է� �Լ��� �ʱ�ȭ
			putchar('*');//ȭ�鿡 ���ڸ� ����ϴ� �Լ�
			if (str[i] == '\r') {//�Է¹��� Ű�� �������� Ȯ��
				str[i] = '\0';//���� �ʱ�ȭ
				passwd = str;//str�� passwd�� �ʱ�ȭ
				cout << "\n";//ȭ�鿡 ���� ��� �� ����
				break;//�ݺ��� ����
			}
		}
		if (passwd != correct) {//��й�ȣ�� �´��� Ȯ��
			cout << "��й�ȣ�� ���� �ʽ��ϴ�. ���� ����.\n\n";//ȭ�鿡 ���� ���
			exit(0);//���α׷� ����
		}
	}
	rank.print("[���� ��ŷ: ����]");//ȭ�鿡 ������ ���� ���
	srand((unsigned int)time(NULL));//���� ���� �Լ�
	int w = 16, h = 8;//���� ũ��(16 x 8)�� ����
	MonsterWorld game(w, h);//���� ���� ��ü ���� �� ���� ũ��(16 x 8)�� �μ��� ����
	game.add(new Zombie("����������", "��", rand() % w, rand() % h));//Zombie ��ü�� �����ϰ� ���� ���� �߰�
	game.add(new Vampire("�����̾�¯", "��", rand() % w, rand() % h));//Vampire ��ü�� �����ϰ� ���� ���� �߰�
	game.add(new KGhost("��¼�ٱͽ�", "��", rand() % w, rand() % h));//KGhost ��ü�� �����ϰ� ���� ���� �߰�
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, true));//Jiangshi ��ü�� �����ϰ� ���� ���� �߰�
	game.add(new Jiangshi("���Ծ��", "��", rand() % w, rand() % h, false));//Jiangshi ��ü�� �����ϰ� ���� ���� �߰�
	Human* human = new Human("�̷����η�", "��", rand() % w, rand() % h);//human ��ü�� ����
	game.add(human);//human ��ü�� ���� ���� �߰�
	game.play(500, 10);//play �Լ��� �ִ� �ݺ� Ƚ��(500ȸ)�� ���ð�(0.01��)�� �μ��� ����
	printf("------���� ����-------------------\n");//ȭ�鿡 ���� ���
	rank.add(human->nItem, human->nItem / human->total);//human�� ������ ȹ�� ���� �̵� �Ÿ��� ������ ȹ�� ���� add �Լ��� �Ű������� ����
	rank.print("[���� ��ŷ: ����]");//���� ������ ȭ�鿡 ���
	rank.store("MonsterWorld.rnk");//���� ������ �ش� ���Ͽ� ���� 
}