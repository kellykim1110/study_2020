#include <stdio.h>

main(void) {
	// for �� ���
	printf("for ���� �̿��Ͽ� ������\n");
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			printf("%d X %d = %d\n", i,j,i*j);
		}
	}
	
	printf("for���� ����Ͽ� Ʈ�������\n");
	/*
	*
	**
	***
	****
	*****
	*/
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	/*
	    *
	   **
	  ***
	 ****
	*****
	*/
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5 - i; j++) {
			printf(" ");
		}
		for (int k = 1; k <= i; k++) {
			printf("*");
		}
		printf("\n");
	}

	/*
	    *
	   ***
	  *****
	 *******
	********* 
	*/
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5 - i; j++) {
			printf(" ");
		}
		for (int k = 1; k <= 2*i-1; k++) {
			printf("*");
		}
		printf("\n");
	}
}