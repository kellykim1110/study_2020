// �迭 Array
// (�迭�� ��) (�迭�� �̸�)[���� ����]
#include <stdio.h>
/*int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i;
	int ave = 0; // ��� ���ϱ�
	for (i = 0; i < 10; i++) {
		printf("Array %d��° ����: %d \n", i+1, arr[i]);
		ave += arr[i];
	}
	printf("��ü�� ����� %d �̴�.\n", ave / 10);
	return 0;
}
*/

/*
// �Ҽ� ���α׷�
// �Ҽ��� �ڱ��ڽŰ� 1���� ������� ������ �ڿ����� �ǹ�
int main() {
	int guess = 5; //�߰��� �Ҽ� ����
	int prime[1000]; //�Ҽ��� ���� �迭
	int index = 1; //for���� ����
	int i, ok; // i�� �Ҽ����� �Ǻ��ϱ� ���� ���̴� ����, ok�� ó�� �� �Ҽ��� Ư���� ���� ģ��.
	prime[0] = 2; // ù��° �Ҽ�
	prime[1] = 3; // �ι�° �Ҽ�
	printf(" 1 ��° �Ҽ� : 2 \n");
	printf(" 2 ��° �Ҽ� : 3 \n");

	for (;;) {
		ok = 0;
		for (i = 0; i <= index; i++) {
			if (guess % prime[i] != 0) { // �Ҽ��� �ٸ� ���� ���������� �ȵȴ�.
				ok++;
			}
			else {
				break;
			}
		}
		if (ok == (index + 1)) { // �迭 prime ���� ���Ұ� ��� �Ҽ��� ��,
			index++;
			prime[index] = guess; // �迭�� �Ҽ� �߰�
			printf(" %d ��° �Ҽ� : %d \n",index + 1, prime[index]);
			if (index == 999) break ; // ������ ������ 1000���� �� ����
		}
		guess += 2;
	}
	return 0;
}
*/
