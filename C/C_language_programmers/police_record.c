#include <stdio.h>
// printf scanf

int main() {
	// �������� �������� ���� �Լ�
	// �̸� ���� ������ Ű ���˸� �Լ��Ͽ� ���� �ۼ�
	
	// �迭�� �տ� &�� ������ ����
	char name[256];
	printf("�̸��� �����Դϱ�?");
	scanf_s("%s\n", name, sizeof(name));
	printf("�̸�:\t\t%s\n", name);
	//%[^\n]s�� ������� ������ ���ڿ��� �ڷ���

	// �Ϲ� ������ ���� ���� �տ� &�� ����
	int age;
	printf("���̰� ��� �Դϱ�?");
	scanf_s("%d\n", &age);
	printf("����:\t\t%d\n", age);

	float weight;
	printf("�����Դ� �� �Դϱ�?");
	scanf_s("%f\n", &weight);
	printf("������:\t%.2f\n", weight);

	double height;
	printf("Ű�� ���Դϱ�?");
	scanf_s("%lf\n", &height);
	printf("Ű:\t\t\t%lf\n", height);

	char crime[255];
	printf("���� ���˸� ���������ϱ�?");
	scanf_s("%s\n", crime, sizeof(crime));
	printf("���˸�:\t%s\n", crime);

	// ���� ���� ���
	printf("\n\n----������ ����---\n\n");
	printf("%d�� %s�� %s�� �������⿡ ü���Ǿ����ϴ�.\n", age, name, crime);

	return 0;
}

