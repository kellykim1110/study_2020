// 배열 Array
// (배열의 형) (배열의 이름)[원소 개수]
#include <stdio.h>
/*int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i;
	int ave = 0; // 평균 구하기
	for (i = 0; i < 10; i++) {
		printf("Array %d번째 원소: %d \n", i+1, arr[i]);
		ave += arr[i];
	}
	printf("전체의 평균은 %d 이다.\n", ave / 10);
	return 0;
}
*/

/*
// 소수 프로그램
// 소수란 자기자신과 1만을 공약수로 가지는 자연수를 의미
int main() {
	int guess = 5; //추가할 소수 원소
	int prime[1000]; //소수를 담을 배열
	int index = 1; //for문의 변수
	int i, ok; // i는 소수인지 판별하기 위해 쓰이는 변수, ok는 처음 두 소수는 특별한 경우로 친다.
	prime[0] = 2; // 첫번째 소수
	prime[1] = 3; // 두번째 소수
	printf(" 1 번째 소수 : 2 \n");
	printf(" 2 번째 소수 : 3 \n");

	for (;;) {
		ok = 0;
		for (i = 0; i <= index; i++) {
			if (guess % prime[i] != 0) { // 소수는 다른 수로 나누어지면 안된다.
				ok++;
			}
			else {
				break;
			}
		}
		if (ok == (index + 1)) { // 배열 prime 안의 원소가 모두 소수일 때,
			index++;
			prime[index] = guess; // 배열에 소수 추가
			printf(" %d 번째 소수 : %d \n",index + 1, prime[index]);
			if (index == 999) break ; // 원소의 개수가 1000개일 때 정지
		}
		guess += 2;
	}
	return 0;
}
*/
