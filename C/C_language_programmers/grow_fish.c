#include <stdio.h>
#include <time.h>

// pointer

int level;
int arrayFish[6]; // ����� 6����
int * cursor; // cursor�� ���� ������� ���� ��ġ�� ã�ư� �����̸� ����(����)��Ű�� ����

void initData();
void printFishes();
void descreaseWater(long elapsedTime);
int checkFishAlive();

int main() {
	/*
	����Ⱑ 6������ �ִ�.
	�̵��� ���׿� ��� ������ �縷�� �ֱ� ������ ���� ���� ���ߵȴ�.
	�ð��� �������� ���� ���߼ӵ��� ��������.
	���� �� �����ϱ� ���� ���׿� ���� �־ ����⸦ �������.

	��, 20�ʸ��� �ѹ��� ������!!
	*/
	long starttime = 0; // ���� ���� �ð�
	long totalElapsedTime = 0; // �� ��� �ð�
	long prevElapsedTime = 0; // ���� ��� �ð� (�ֱٿ� ���� �� �ð� ����)

	int num; // �� �� ���׿� ���� �� ���ΰ�? // ����� �Է�
	initData();

	cursor = arrayFish;

	starttime = clock();

	while (1) {
		printFishes(); // ���� ������� ���� ���� ǥ��
		// getchar();  // �ӽ÷� ����� �Է� ���
		printf("�� �� ���׿� ���� �ֽðھ��? ");
		scanf_s("%d", &num);

		// �Է°� üũ
		// �Է°��� 1~6������ ���ڰ� �ƴ� ��
		if (num < 1 || num > 6) {
			printf("�Է°��� �߸��Ǿ����ϴ�.\n");
			continue;
		}

		// �� ��� �ð�
		totalElapsedTime = (clock() - starttime)/ CLOCKS_PER_SEC; //CLOCKS_PER_SEC�ʷ� �ٲ��ִ� ����
		printf("�� ��� �ð�: %ld �� \n", totalElapsedTime);

		// ���� �� �� �ð�
		// �� ��� �ð� - ���������� �� �� �ð�
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð�: %ld �� \n", prevElapsedTime);
		
		// ������ ���� ����
		descreaseWater(prevElapsedTime);

		// ����ڰ� �Է��� ���׿� ���� �ش�
		// 1. ������ ���� 0�̸� �̹� ������ die... -> ���� ���� �ʴ´�.
		if (cursor[num - 1] <= 0) {
			printf("%d �� ������ �̹� �׾����Ф�  ���� ���� �ʽ��ϴ�. \n", num);
		}
		// 2. ������ ���� 0�� �ƴ� ���, ���� �ش�. 100�� ���� �ʴ��� üũ
		// ���� ������ �� + 1 <= 100
		else if (cursor[num - 1] + 1 <= 100) {
			// �� �ֱ�
			printf("%d�� ���׿� ���� �ݴϴ�.\n\n", num);
			cursor[num - 1] += 1;
		}
		// �������� �� ���� Ȯ��(20�ʸ��� �ѹ��� ������!!)
		if (totalElapsedTime / 20 > level - 1) {
			level++;
			printf("*****��!������!!*****\n\n���� level.%d���� level.%d�� ���� ���׷��̵�\n\n", level-1, level);

			// ���� ����: 5
			if (level == 5) {
				printf("\n\n�����մϴ�. ���������� �޼��Ͽ����ϴ�. \n������ �����մϴ�.\n");
				exit(0);
			}
		}
		// ��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0) {
			// ����Ⱑ ��� ���
			printf("��� ����Ⱑ DIE.....\n");
			exit(0);
		}
		else {
			// �ּ� �Ѹ����� ����Ⱑ ����
			printf("����Ⱑ ���� ����־��.\n");
		}
		// 10�� -> 15�� : prevElapsedTime = 5�� 
		// -> 25�� : preveElasedTime = 10�� = 25�� - 15��
		// prevElapsedTime = totalElapsedTime - prevElapsedTime�̹Ƿ�
		// ������ prevElapsedTime�� prevElapsedTime = totalElapsedTime�� ������ �־�� ��
		prevElapsedTime = totalElapsedTime;

	}

	return 0;
}

void initData() {
	level = 1; //���� ���� 1~5
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100; // ������ ������(0~100)
	}
}

void printFishes() {
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
	// %3d��: 6byte���� 
	// %3d: 3byte ����
	// ��: 2byte ����
	//  : 1byte ����
	for (int i = 0; i < 6; i++) {
		printf(" %4d ", arrayFish[i]);
		// " %4d ": 1+4+1 = 6byte���� 
	}
	printf("\n\n");
}

void descreaseWater(long elapsedTime) {
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)elapsedTime); //3�� ���̵� ������ ���� ��
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive() {
	// ������ ���� ���� ���� ���� ���� Ȯ��
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0)
			return 1; // True
	}
	return 0; //False
}


/*
������ ������ �� �����Ͱ� ����ġ�� ������ ���� ���� �ٲܼ� �ִ�.

[ö��]: 101ȣ
[����]: 201ȣ
[�μ�]: 301ȣ

// �� �� �տ� '��ȣ'�� �ɷ� ����
// �̼�
1. ����Ʈ�� �� ���� �湮�Ͽ� ���� ���� ��ȣ Ȯ��

int ö�� = 1; // ��ȣ
int ���� = 2;
int �μ� = 3;

int *mission; // ������ ����
mission = &ö��;

printf("ö���� �ּ�: %d, ��ȣ: %d \n", &ö��, ö��);
printf("����� �ּ�: %d, ��ȣ: %d \n", &����, ����);

printf("mission�� �湮�ϴ� �� �ּ�: %d, ��ȣ: %d\n", mission, *mission);
// mission = &ö��, *mission = ö��

mission = &����; //������ ���� ��ȯ
printf("mission�� �湮�ϴ� �� �ּ�: %d, ��ȣ: %d\n", mission, *mission);
// mission = &����, *mission = ����

2. �� ��ȣ�� 3�� ���ض�
mission = &ö��;
*mission = *misson * 3;

printf("mission�� �湮�ϴ� �� �ּ�: %d, ��ȣ: %d\n", mission, *mission);
// mission = &ö��, *mission = ö��*3

3. mission�� ��ȣ���� 2�� ����
int *spy = mission;

spy = &ö��; // spy�� ö���� ��ġ�� �ǹ�
*spy = *spy -2; // mission�� ��ȣ���� -2�� �� ��
printf("spy�� �湮�� �� �ּ�: %d, ��ȣ %d\n", spy, *spy);
// spy = &ö��, *spy = ö��*3 - 2

mission = &�μ�;
*mission = *misson * 3;
spy = &�μ�; // spy�� �μ��� ��ġ�� �ǹ�
*spy = *spy -2; // mission�� ��ȣ���� -2�� �� ��
printf("spy�� �湮�� �� �ּ�: %d, ��ȣ %d\n", spy, *spy);
// spy = &�μ�, *spy = �μ�*3 - 2

printf("ö���� �ּ�: %d, ��ȣ: %d \n", &ö��, ö��);
printf("����� �ּ�: %d, ��ȣ: %d \n", &����, ����);
printf("�μ��� �ּ�: %d, ��ȣ: %d \n", &�μ�, �μ�);
// &name�� ������ ���� ����
// ö�� = 3*ö�� - 2
// ���� = 3*����
// �μ� = 3*�μ� - 2

*/

/*
// �迭�� �������� ����

int arr[3] = {5, 10, 15};
int *ptr = arr;
for (int i = 0; i<3; i++){
	printf("�迭 arr[%d] �� ��: %d\n", i, arr[i]);
	printf("������ ptr[%d] �� ��: %d\n", i, ptr[i]);
	// arr[i] = ptr[i] = 5 or 10 or 15
}

ptr[0] = 100;
ptr[1] = 200;
ptr[2] = 300;
for (int i = 0; i<3; i++){
	printf("�迭 arr[%d] �� ��: %d\n", i, arr[i]);
	printf("������ ptr[%d] �� ��: %d\n", i, ptr[i]);
	// arr[i] = ptr[i] = 100 or 200 or 300
}

for (int i = 0; i<3; i++){
	printf("�迭 arr[%d] �� ��: %d\n", i, arr[i]);
	printf("������ ptr[%d] �� ��: %d\n", i, *(arr + i));
	// arr[i] = *(arr + i)
	//*(arr + i)�� *(arr �迭�� ù��° ���� �ּ�(&arr[0])+ i)
}
*/

/*
Ư�� ����p�� ���� *&p�� �ƹ��͵� ���� ��(p)�� ����.  
&�� �ּ��̸�
*�� �� �ּ��� ���̱� ������
*&�� ���� ���ȴ�.
*/

