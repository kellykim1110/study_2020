#include <stdio.h>

int main() {
	/*
	
	    *
	   ***
	  *****
	 *******
	********* 
	
	*/
	int floor;
	printf("�� �� �װڴ���?");
	scanf_s("%d", &floor);
	printf("\n--%d��¥�� �Ƕ�̵� �����--\n", floor);

	for (int i = 1; i <= floor; i++) {
		for (int j = 1; j <= floor - i; j++) {
			printf(" ");
		}
		for (int k = 1; k <= 2 * i - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}