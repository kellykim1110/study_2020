#include <stdio.h>
// ���ǹ� 
// if else switch


int presentation(int classNum);
int rockscissorspaper();

int main() {
	// 5�� �ȿ� ���ڸ� �����.
	srand(time(NULL));
	int num = rand() % 100 + 1; // 1 ~ 100���� ����
	// printf("����: %d\n", num);
	int answer; // ����
	int chance = 5; // ��ȸ
	while (chance > 0) {
		printf("---���ڸ� ���纸����.---\n\n");
		scanf_s("%d", &answer);
		if (answer > num) {
			printf(" DOWN ��\n\n");
			printf("���� ��ȸ %d �� \n", --chance);
		}
		else if (answer < num) {
			printf("UP ��\n\n");
			printf("���� ��ȸ %d �� \n", --chance);
		}
		else if (answer == num){
			printf("�����Դϴ�!!!\n\n");
			break;
		}
	}
	if (chance == 0) {
		printf("��ȸ�� �� ����ϼ̽��ϴ�. ������ %d�����ϴ�.", num);
	}
	// presentation(23);
	// rockscissorspaper();
	return 0;
}



// if else
// break continue

int presentation(int classNum) {
	// �ݿ��� 1-6������ ��ǥ
	for (int i = 1; i <= classNum; i++) {
		if (i > 6) {
			printf("�̹� ��ǥ �� ������ �л����� �����ð��� �ҰԿ�.\n");
			break; // for�� Ż��!!
		}
		else {
			printf("%d �� �л�, ��ǥ �����ϼ���.\n", i);
		}
	}
	printf("\n\tNext Class...\n\n");
	// 8���� �Ἦ
	// 8���� ������ 7������ 13������ ��ǥ
	for (int i = 1; i <= 34; i++) {
		if (i >= 7 && i < 14) {
			if (i == 8) {
				printf("8�� �л��� �Ἦ�̳׿�. ���� ��ȣ�� �Ѿ�Կ�.\n");
				continue; // i���� ���� ���ǿ� �������� �� �Ʒ��� �������� �ʰ� i+1������ �Ѿ�� ���� 
			}
			printf("%d �� �л�, ��ǥ �����ϼ���.\n", i);
		}
	}
	return 0;
}

// switch case
int rockscissorspaper () {
	// ����������
	srand(time(NULL));
	// ���� 0 ���� 1 �� 2
	int i = rand() % 3; // 0~2��ȯ
	if (i == 0) {
		printf("����\n");
	}
	else if(i==1){
		printf("����\n");
	}
	else {
		printf("��\n");
	}
	// ���� ������������ switch�� �ٲٸ�
	switch (i) {
	case 0: printf("����\n"); break;
	case 1: printf("����\n"); break; 
	case 2: printf("��\n"); break;
	default: printf("�����\n"); break;
	}
	return 0;
}