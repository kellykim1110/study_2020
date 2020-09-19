#include <stdio.h>
#include <time.h>

// functioin

// void : �ƹ��͵� ����. �ڷ������� ����.
// void function(void parameter) void {return output}
/*
�Լ��� ����
���ް� ����
��ȯ�� ����
*/

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main() {
	/* 
	���� 5���� �ְ�
	�� ������ ���� ����� ���� ���� ����(����)
	������ ���, Ʋ���� ����
	*/

	srand(time(NULL));
	int count = 0;
	int answer = -1;
	for (int i = 1; i <= 5; i++) {
		// ���� �ΰ� for Question
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		// ����
		showQuestion(i, num1, num2);
		//����
		scanf_s("%d", &answer);
		if (answer == -1) {
			printf("���α׷��� �����մϴ�.\n");
			exit(0); // ���α׷� �ٷ� ����
		}
		else if (answer == num1 * num2) {
			// ����
			success();
			count++;
		}
		else {
			// ����
			fail();
		}
	}
	printf("\n\n ����� 5���� ��й�ȣ �� %d���� ���ƽ��ϴ�.\n\n", count);

	return 0;
}

int getRandomNumber(int level) {
	return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2) {
	printf("\n\n\n----- %d ��° ��й�ȣ -------\n", level);
	printf("\n\t%d X %d = ?\n\n", num1, num2);
	printf("=================================\n");
	printf("\n ��й�ȣ�� �Է��ϼ��� (����: -1) >> ");
}

void success() {
	printf(" >> �����Դϴ�.\n");
}

void fail() {
	printf("  >> Ʋ�Ƚ��ϴ�. �ƽ��� ��׿�. ������ �����ϼ���.\n");
}