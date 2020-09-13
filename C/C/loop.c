#include <stdio.h>

// for 문
// for(변수명 = 초기값; 조건 식; 변화 식)
int main() {
	int i, sum = 0;
	
	for (i = 1; i < 20; ++i) {
		sum += i;
	}
	printf("1부터 %d까지의 합은 %d이다.\n", i-1, sum);
	
	return 0;
}


/*
// while 문
// while(조건식)
int main() {
	int i = 1, sum = 0;
	
	while (i < 20) {
		sum += i;
		i++;
	}
	printf("1부터 %d까지의 합은 %d이다.\n", i - 1, sum);
	
	return 0;
}
*/

/*
// do-while 문
int main() {
	int i = 1, sum = 0;
	
	do {
		sum += i;
		i++;
	} while (i < 20);
	printf("1부터 %d까지의 합은 %d이다.\n", i - 1, sum);

	return 0;
}
*/

/*
// Examples of Loop
int main() {
	int i,j, N, n;

	printf("몇번째 줄까지 원하십니까?:\n");
	scanf("%d", &N);
	printf("%d번째 줄까지 삼각형 출력\n", N);
	n = N;
	for (i = 1; i < n+1;++i) {
		for (j = 1; j <= (2 * i - 1); ++j) {
			printf("*");
		}
		printf("\n");
	}

	printf("%d번째 줄까지 역삼각형 출력\n", N);
	n = N;
	for (i = 1; i < n+1; ++i) {
		for (j = 1; j <= 2*(n-i)+1; ++j) {
			printf("*");
		}
		printf("\n");
	}

	printf("1000이하의 3또는 5의 배수인 자연수들의 합 구하기\n");
	int sum = 0;
	for (i = 1; i <= 1000; ++i) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			sum += i;
		}
	}
	printf("답은 %d \n", sum);

	printf("피보나치 수열의 짝수 항들의 합이 1000000이하인 가장 큰 수 구하기\n");
	int even_sum = 0, before2 = 0, before1 = 1, fibo;
	for (i = 0;; ++i) {
		if (i == 0) {
			fibo = 0;
		}
		else if (i == 1) {
			fibo = 1;
		}
		else if (i > 1) {
			fibo = before1 + before2;
			before2 = before1;
			before1 = fibo;
			if (i % 2 == 0) {
				even_sum += fibo;
			}
		}
		if (even_sum >= 1000000) {
			printf("답은 %d", even_sum-fibo);
			break;
		}
	}

	return 0;
}
*/
