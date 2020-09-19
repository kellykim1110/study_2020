#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// ���� �����
// ���� �޸𸮿� ����ǹǷ� ���α׷��� off���� �� 
// �����ǵ����Ͱ� ���ư�
// �̸� ����

/*
fputs, fgets ��
fprintf, fscanf ��
*/

#define MAX 10000

int main() {
	char line[MAX]; // char line[10000]
	
	
	// fputs fgets ���ڿ��� �� ����
	//fputs ���Ͽ� ����
	// FILE * file = fopen(<���� ��ġ>, <����>)
	// ���� ���� 
	//// w���� r�б� a����(append)
	//// t�ؽ�Ʈ b���̳ʸ� ������
	FILE * file = fopen(".\\FileTest\\test1.txt", "wb");
	if (file == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}
	else {
		fputs("fputs�� �̿��ؼ� ���� �����\n", file);
		fputs("�� �������� Ȯ��\n", file);
		
		// ���� �����鼭 ����
		// ������ �ս� ���� ����
		fclose(file);
	}
	
	
	// fgets ���Ͽ��� �о����
	FILE* file1 = fopen(".\\FileTest\\test1.txt", "rb");
	if (file1 == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}
	while (fgets(line, MAX, file1) != NULL) {
		printf("%s", line);
	}
	fclose(file1);
	

	//fprintf, fscanf ����ȭ�� format�� ���ؼ� ��� ��
	// fprintf
	// �ζ� ��ȣ ���� �� ��������
	int num[6] = { 0,0,0,0,0,0 }; // ��÷��ȣ
	int bonus = 0; // ���ʽ� ��ȣ
	char str1[MAX];
	char str2[MAX];

	FILE* file2 = fopen(".\\FileTest\\test2.txt", "wb");
	if (file2 == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}

	// �ζ� ��ȣ ����
	fprintf(file2, "%s %d %d %d %d %d %d\n", "��÷��ȣ", 1, 2, 3, 4, 5, 6);
	fprintf(file2, "%s %d\n", "���ʽ���ȣ", 7);

	fclose(file2);

	//fscanf
	FILE* file3 = fopen(".\\FileTest\\test2.txt", "rb");
	if (file3 == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}
	// ���� �ؽ�Ʈ , &num[]
	fscanf(file3, "%s %d %d %d %d %d %d", 
		str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n",
		str1, num[0], num[1], num[2], num[3], num[4], num[5]);

	fscanf(file3, "%s %d", str2, &bonus);
	printf("%s %d\n", str2, bonus);
	fclose(file3);
}

