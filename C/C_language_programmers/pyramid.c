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
	printf("몇 층 쌓겠느냐?");
	scanf_s("%d", &floor);
	printf("\n--%d층짜리 피라미드 만들기--\n", floor);

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