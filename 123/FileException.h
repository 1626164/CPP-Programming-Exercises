#pragma once//�� ���α׷��� ���� ��� ������ �� ���� ����
#include <string>//�� ���α׷��� C++ ǥ�� ���̺귯�� string ��� ������ ����
struct FileException {//FileException Ŭ���� ����
	string filename;//���� �̸��� �ڷ��� ����
	bool bRead;//bRead�� true�̸� �б� ��� �׸��� false�̸� ���� ���� ó���ϴ� ���� ����� �ڷ��� ����
	FileException(string name, bool b) : filename(name), bRead(b) {}//��� �ʱ�ȭ ����Ʈ�� ����� ������ ����
};