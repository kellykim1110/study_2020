
//Swap �Լ�
#include <stdio.h>

void swap1(int a, int b);
void swap2(int *a, int *b);

int main(){
	int a = 1;
	int b = 2;
	printf("swap�Լ� ��: a = %d, b = %d\n", a, b);
	printf("swap�Լ� ��: a�ּ� = %d, b�ּ� = %d\n", &a, &b);
	// swap�Լ� ��: a�ּ� = 10221516, b�ּ� = 10221504

	// a�� b�� ���� �ٲ۴�.
	swap1(a, b);
	printf("swap1�Լ�: a = %d, b = %d\n", a, b);
	// a = 1, b = 2 ������� ����

	swap2(&a, &b);
	printf("swap2�Լ�: a = %d, b = %d\n", a, b);
	// a = 2, b = 1 �����
}

void swap1(int a, int b){
	int temp = a;
	a= b;
	b = temp;
	printf("swap1�Լ� ��: a = %d, b = %d\n", a, b);
	printf("swap1�Լ� ��: a�ּ� = %d, b�ּ� = %d\n", &a, &b);
	// a = 2, b = 1
	//swap1�Լ� ��: a�ּ� = 10221288, b�ּ� = 10221292
	// main������ a,b�� �Լ����� a,b�� ���� �ٸ���.
}

void swap2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("swap2�Լ� ��: a = %d, b = %d\n", *a, *b);
	// a = 2, b = 1
}
