#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

// ���� �����
// ���� �޸𸮿� ����ǹǷ� ���α׷��� off���� �� 
// �����ǵ����Ͱ� ���ư�
// �̸� ����

/*
��й�ȣ�� �Է¹޾�
��й�ȣ�� ������, ����ϱ⸦ �о�ͼ� �����ְ� ��� �ۼ� ����
��й�ȣ�� Ʋ�����, ��� �޽����� ǥ���ϰ� ����
*/
#define MAX 10000 // �ִ� 10000�� �޾� ���ڴ�.

int main() {
	// fputs, fgets Ȱ��
	char line[MAX]; // ���Ͽ��� �ҷ��� ������ �Է��� ����
	char contents[MAX]; //�ϱ��忡 �Է��� ����
	char password[20]; // ��й�ȣ �Է�
	char c; // ��й�ȣ �Է��� �� Ű�� Ȯ�ο� (����ŷ) password: *******�̷���
	char * passwordNumber = "secretdiary"; // �����ߴ� ��й�ȣ


	printf("'����ϱ�'�� ���� ���� ȯ���մϴ�.\n");
	
	// ��й�ȣ �Է�
	printf("��й�ȣ�� �Է��ϼ���: ");

	/*
	getchar()�� getch()�� ����

	getchar() : ���͸� �Է¹޾ƾ� ������ �մϴ�.
	getch()   : Ű �Է½� �ٷιٷ� ������ �մϴ�.
	*/
	int i = 0;
	while (1) {
		c = getch();
		if (c == 13) { //�ƽ�Ű�ڵ�  // Enter -> ��й�ȣ �Է� ����
			password[i] = "\0";
			break;
		}
		else { // ��й�ȣ �Է� ��
			printf("*");
			password[i] = c;
		}
		i++;
	}

	// ��й�ȣ Ȯ��
	printf("\n\n====��й�ȣ Ȯ�� ��...====\n\n");
	//printf("%d", strcmp(password, passwordNumber));

	// if (strcmp(password, <���� ģ ��й�ȣ>) == 0) {// ��й�ȣ ��ġ
	if (strcmp(password, passwordNumber) == 1) {// ��й�ȣ ��ġ
		printf("====��й�ȣ Ȯ�� �Ϸ�====\n\n");

		// fopen(fileName, "a+b")
		//// a+b
		//// ���� ������ ����, 
		//// ���� ������ append�� �Ѵ�(�ڿ������� ���� �߰�)
		char * fileName = ".\\FileTest\\secretdiary.txt";
		FILE * file = fopen(fileName, "a+b");

		if (file == NULL) {
			printf("���� ���� ����\n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL) {
			printf("%s", line);
		}

		printf("\n\n������ ��� �ۼ��ϼ���~\n�����Ͻ÷��� exit�� �Է��ϼ���!!\n\n");

		while (1) {
			// �ٹٲ�(\n)������ ������ ��� �Է� �޾ƶ�.
			// �� �پ� �Է¹��� ����
			scanf("%[^\n]", contents);
			// ENTER �Է�(\n) Flush ó��
			getchar();

			if (strcmp(contents, "exit") == 0) {
				printf("����ϱ� �Է��� �����մϴ�.\n\n");
				break;
			}

			fputs(contents, file);
			// ENTER�� ������ ���� ó�� �����Ƿ� ���Ƿ� �߰�
			fputs("\n", file);
		}
			fclose(file);
	}
	else {
		// ��й�ȣ�� Ʋ�� ���
		printf("====��й�ȣ�� Ʋ�Ⱦ��....====\n\n");
		printf("====������... �����ϱ� �׸� ������...====\n\n");
	}
	return 0;
}