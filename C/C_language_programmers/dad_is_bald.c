#include <stdio.h>
#include <time.h>

// array
int main() {
	printf("\n\n=====�ƺ��� ��Ӹ�=====\n\n");
	int answer; // ����� �Է°�
	int treatment = rand() % 4; //�߸��� ����(0~3)

	int cntShowBottle = 0; // �̹� ���ӿ� ������ ���� ����
	int prevCntShowBottle = 0; // �� ���ӿ� ������ ���� ����
	// ���� �����ִ� ���� ������ �ٸ��� �Ͽ� ����� ���(ó���� 2�� -> ������ 3��...)
	
	// 3 ���� �߸��� ���� �õ�
	for (int i = 1; i <= 3; i++) {
		int bottle[4] = { 0,0,0,0 }; // 4���� ��
		do {
			cntShowBottle = rand() % 2 + 2; // ������ ���� ����(2�� or3��)
		} while (cntShowBottle == prevCntShowBottle);

		int isIncluded = 0; //������ �� �߿� �߸����� ���ԵǾ����� ����
		printf(" > %d��° �õ�", i);

		// ������ �� ������ ����
		for (int j = 0; j < cntShowBottle; j++) {
			int randBottle = rand() % 4; // 0~3 �� �ϳ�

			// ���� ���õ��� �ʴ� ���̸�, ����ó��
			if (bottle[randBottle] == 0) {
				bottle[randBottle] = 1;
				if (randBottle == treatment) {
					isIncluded = 1;
				}
			}
			// �̹� ���õ� ���̸�, �ߺ��̹Ƿ� �ٽ� ����
			else {
				j--;
			}
		}
		// ����ڿ��� ���� ǥ��
		for (int k = 0; k < 4; k++) {
			if (bottle[k] == 1) {
				printf(" %d", k + 1);
			}
			}
		printf("������ �Ӹ��� �ٸ��ϴ�.\n\n");
		if (isIncluded == 1) {
			printf(" >> ���� ! �Ӹ��� �����!! \n");
		}
		else {
			printf(" >> ���� ! �Ӹ��� ���� �ʾƿ� �Ф�\n ");
		}
		printf("\n ����Ϸ��� �ƹ�Ű�� ��������~~~!!");
		getchar();
	}
	printf("������ ���° �߸��� �ϱ��? ");
	scanf_s("%d", &answer);

	if (answer == treatment + 1) {
		printf("\n >> �����Դϴ�~\n");
	}
	else {
		printf("\n >> Ʋ�Ƚ��ϴ�, ������ %d�Դϴ�.\n", treatment + 1);
	}
	return 0;
}



/*
�迭 �� �����ϱ�

	int arr[] = {1, 2};
	arr[2] = {1, 2};�� ����.

	���� �ݵ�� �ʱ�ȭ �ؾ� ��
	int arr[<�̺κ��� ������ �̿����� �ƴ� ���� ����� �Է�>]

	����
	int arr[10] = {1,2};�� �Ѵٸ�
	arr[10] = {1, 2, 0, 0, 0, 0, 0, 0, 0, 0};�� ���� 
*/

/*
���� vs ���ڿ�

������ ���
char c = 'A';
printf("%c\n",c);�� A�� ���

���ڿ��� ���
char str[6] = "coding";
printf("%s\n",str);�� coding���� �ٸ� �̻��� ���ڵ� ������.
�ֳ��ϸ� ���ڿ� ������ "��"�� �ǹ��ϴ� NULL ���� '\0'�� ���ԵǾ�� ��
char str[7] = "coding";
printf("%s\n",str);�̾�� coding�� ���

char str[10] = "coding";
printf("%s\n",str);�� coding�� ���
������ ���� �ڸ��� '\0'�� �����ϹǷ� ���� 
char arr[10] = c o d i n g \0 _ _ _ �̶� �����ϸ�  �ȴ�.

char str[7] = "coding";
printf("%d\n",str); �̸� %d�� �������� �̴� ���̹Ƿ� �� �迭��ġ�� ���� ���ĺ��� ASCII �ڵ� ������ ��µȴ�(null�� 0���� ���)
	- �ƽ�Ű�ڵ�
	 for(int i = 0; i<128; i++){
		printf("�ƽ�Ű�ڵ� ���� %d: %c \n", i, i);
		// �ƽ�Ű�ڵ� ���� 104 : h
	}
char str[] = "coding";
printf("%s\n",str);  >> coding
printf("%d\n",sizeof(str));  >> 7

char str[] = "�ڵ�";
printf("%s\n",str);  >> �ڵ�
printf("%d\n",sizeof(str));  >> 5

char ũ�� 1byte
����� 1byte  >> 6*1 + 1 = 7  
�ѱ��� 2 byte >> 2*2 + 1 = 5
*/

