# include <stdio.h>
int main() {
	// �������� �������� ���� �Լ�
	// �̸� ���� ������ Ű ���˸� �Լ��Ͽ� ���� �ۼ�
	char name[256];

	/*
	char crime[255];
	int age;
	float weight;
	double height;*/

	printf("�̸��� �����Դϱ�?");
	scanf_s("%s\n", name, sizeof(name));

	int age;
	printf("���̰� ��� �Դϱ�?");
	scanf_s("%d\n", &age);

	float weight;
	printf("�����Դ� �� �Դϱ�?");
	scanf_s("%f\n", &weight);

	double height;
	printf("Ű�� ���Դϱ�?");
	scanf_s("%lf\n", &height);

	char crime[255];
	printf("���� ���˸� ���������ϱ�?");
	scanf_s("%s\n", crime, sizeof(name));

	// ���� ���� ���
	printf("\n\n----������ ����---\n\n");
	printf("%d�� %s�� %s�� �������⿡ ü���Ǿ����ϴ�.\n", age, name, crime);

	return 0;
}
