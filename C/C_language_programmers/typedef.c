#include <stdio.h>

// typedef �ڷ����� ���� ����
int main() {
	int i = 1;
	typedef int ����;
	typedef float �Ǽ�;

	���� �������� = 3;
	�Ǽ� �Ǽ����� = 3.33f;

	printf("�������� %d, �Ǽ����� %.2f\n", ��������, �Ǽ�����);
	
	typedef struct GameInfo {
		char* name;
	} ��������;
	// struct GameInfo = ��������
	�������� game1;
	game1.name = "�ѱ۰���";
	
	printf("%s\n", game1.name);

	return 0;
}