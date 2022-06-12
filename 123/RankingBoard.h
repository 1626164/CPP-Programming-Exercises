#pragma once//�� ���α׷��� ���� ��� ������ �� ���� ����
#include <iostream>//�� ���α׷��� C++ ǥ�� ���̺귯�� iostream ��� ������ ����
#include <fstream>//�� ���α׷��� C++ ǥ�� ���̺귯�� fstream ��� ������ ����
#include "FileException.h"//�� ���α׷��� FileException.h ��� ������ ����
using namespace std;//ǥ�� �̸������� ���
#define NUM_MVP	5//���� ������ 5�� ����

struct PlayInfo {//PlayInfo Ŭ���� ����
	string name;//����� �̸��� �ڷ��� ����
	int nItem;//ȹ���� ������ ���� �ڷ��� ����
	double itemPerMove;//�̵� �Ÿ��� ������ ���� �ڷ��� ����
	PlayInfo(string na = "���η�", int ni = 0, double ipm = 0.0) : name(na), nItem(ni), itemPerMove(ipm) {}//����Ʈ �Ű������� ��� �ʱ�ȭ ����Ʈ�� ����� ������ ����
};
class RankingBoard {//RankingBoard Ŭ���� ����
	PlayInfo MVP[NUM_MVP];//���� ����
	int nMVP = NUM_MVP;//�Ű������� �ڷ��� ���� �� ���� ������ �Ű������� ����
public://���� ������ ����
	void load(string filename) {//�Ű������� �ڷ��� ����� load �Լ�
		ifstream is;//ifstream ��ü is�� ��� ������ �߰�
		is.open(filename);//���� ����
		if (!is)//������ ����� ������ ������ �ʴ��� Ȯ��
			throw(FileException(filename, true));//FileException ���ܸ� ����� ����
		for (int i = 0; i < nMVP; i++)//���� ������ �ѱ��� ������ �ݺ�
			is >> MVP[i].nItem >> MVP[i].name >> MVP[i].itemPerMove;//���Ͽ� ȹ���� ������ ��, ����� �̸�, �̵� �Ÿ��� ������ �� �б�
		is.close();//���� �ݱ�
	}
	void store(string filename) {//�Ű������� �ڷ��� ����� store �Լ�
		ofstream os;//ofstream ��ü os�� ��� ������ �߰�
		os.open(filename);//���� ����
		if (!os)//������ ������ ������ ������ �ʴ��� Ȯ��
			throw(FileException(filename, false));//FileException ���ܸ� ����� ����
		for (int i = 0; i < nMVP; i++)//���� ������ �ѱ��� ������ �ݺ�
			os << MVP[i].nItem << " " << MVP[i].name << " " << MVP[i].itemPerMove << "\n";//���Ͽ� ȹ���� ������ ��, ����� �̸�, �̵� �Ÿ��� ������ �� ���� ����
		os.close();//���� �ݱ�
	}
	void print(string title = "���� ��ŷ") {//����Ʈ �Ű����� ����� print �Լ�
		cout << endl << title << endl;//ȭ�鿡 ���� ��� �� ��� ���۸� ���� ����
		for (int i = 0; i < nMVP; i++)//���� ������ �ѱ��� ������ �ݺ�
			cout << "[" << i + 1 << "��] " << MVP[i].name << "\t" << MVP[i].nItem << " " << MVP[i].itemPerMove << "\n";//ȭ�鿡 ����, ����� �̸�, ȹ���� ������ ��, �̵� �Ÿ��� ������ �� ��� �� ����
		cout << "���͸� �Է��ϼ���.";//ȭ�鿡 ���� ���
		getchar();//ȭ�鿡 ���ڸ� �Է� �޴� �Լ� ȣ��
		cout << endl;//ȭ�鿡 ���� ��� �� ��� ���۸� ���� ����
	}
	int add(int nItem, double ipm) {//�Ű������� �ڷ��� ����� add �Լ�
		if (nItem <= MVP[nMVP - 1].nItem) {//���� ������ �� ����ں��� ȹ���� �������� ���� �۰ų� ������ Ȯ��
			return 0;//�Լ� ����
		}
		int pos = nMVP - 1;//�Ű������� �ڷ��� ���� �� ������ �Ű������� ����
		for (; pos > 0; pos--) {//�ش� ������ ���� �ݺ�
			if (nItem <= MVP[pos - 1].nItem) {//���� ������ �� ����ں��� ȹ���� �������� ���� �۰ų� ������ Ȯ��
				break;//�ݺ��� ����
			}
			MVP[pos] = MVP[pos - 1];//������ �ø�
		}
		MVP[pos].nItem = nItem;//ȹ���� ������ ���� �Ű������� ����
		MVP[pos].itemPerMove = ipm;//�̵� �Ÿ��� ������ ���� �Ű������� ����
		cout << "\n[" << pos + 1 << "��] �̸��� �Է��ϼ���: ";//ȭ�鿡 ������ ���� ���
		cin >> MVP[pos].name;//ȭ�鿡 ����� �̸� �Է�
		return pos + 1;//���� ������ ��ȯ
	}
};