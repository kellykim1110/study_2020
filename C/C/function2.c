#include <stdio.h>
int main() {
	int arr[10];
	int i; // for문의 변수

	for (i = 0; i < 10; i++) {
		printf("%d번째 원소: ", i + 1);
		scanf("%d\n",&arr[i]);
	}

	printf("배열에서 가장 큰 수: %d \n", max_number(arr));
	
	return 0;
}


int max_number(int *parr) {
	int j;
	int max = parr[0];

	for (j = 1; j < 10; j++) {
		if (max < parr[j]) {
			max = parr[j];
		}
	}
	return max;
}
