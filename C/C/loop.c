#include <stdio.h>
/*
// for ��
// for(������ = �ʱⰪ; ���� ��; ��ȭ ��)
int main() {
	int i, sum = 0;
	
	for (i = 1; i < 20; ++i) {
		sum += i;
	}
	printf("1���� %d������ ���� %d�̴�.\n", i-1, sum);
	
	return 0;
}
*/

/*
// while ��
// while(���ǽ�)
int main() {
	int i = 1, sum = 0;
	
	while (i < 20) {
		sum += i;
		i++;
	}
	printf("1���� %d������ ���� %d�̴�.\n", i - 1, sum);
	
	return 0;
}
*/

/*
// do-while ��
int main() {
	int i = 1, sum = 0;
	
	do {
		sum += i;
		i++;
	} while (i < 20);
	printf("1���� %d������ ���� %d�̴�.\n", i - 1, sum);

	return 0;
}
*/

/*
// Examples of Loop
int main() {
	int i,j, N, n;

	printf("���° �ٱ��� ���Ͻʴϱ�?:\n");
	scanf("%d", &N);
	printf("%d��° �ٱ��� �ﰢ�� ���\n", N);
	n = N;
	for (i = 1; i < n+1;++i) {
		for (j = 1; j <= (2 * i - 1); ++j) {
			printf("*");
		}
		printf("\n");
	}

	printf("%d��° �ٱ��� ���ﰢ�� ���\n", N);
	n = N;
	for (i = 1; i < n+1; ++i) {
		for (j = 1; j <= 2*(n-i)+1; ++j) {
			printf("*");
		}
		printf("\n");
	}

	printf("1000������ 3�Ǵ� 5�� ����� �ڿ������� �� ���ϱ�\n");
	int sum = 0;
	for (i = 1; i <= 1000; ++i) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			sum += i;
		}
	}
	printf("���� %d \n", sum);

	printf("�Ǻ���ġ ������ ¦�� �׵��� ���� 1000000������ ���� ū �� ���ϱ�\n");
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
			printf("���� %d", even_sum-fibo);
			break;
		}
	}

	return 0;
}
*/
