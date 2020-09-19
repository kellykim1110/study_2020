#include <stdio.h>
#include <time.h>

// ������ �迭 Multidimensional Array
// int arr2[2][5] = {{1,2,3,4,5}, {1,2,3,4,5}};

/*
for (int i = 0; i< 2; i++){
	for(int j = 0; j < 5; j++){
		printf("2 ���� �迭 <%d, %d>�� �� : %d\n", i, j, arr2[i][j]);
		}
		printf("\n");
	}
*/


/*
	����ī�� ������ ������Ʈ
	������ 10������ ���� �ٸ� ����ī�尡 �� ������ 2�徿 ����
	����ڷ� ���� 2���� �Է°��� �޾Ƽ�
	���� ������ ã���� ī�� ������

	��� ���� ���� ã���� ���� ����

	�� ���� Ƚ�� �˷��ֱ�
	*/


int arrayAnimal[4][5];  // �� 20���� ���� ī�� �迭�ϱ�
void initAnimalArray();

char *strAnimal[10]; // 10������ ���� �̸��� �ּҸ� ������ �� �� �ֵ����ϱ� ���� �����ͷ� ����
void animalName();

int getEmptyPosition(); // ��ǥ���� ����� ã��
int conv_pos_x(int randPos); // x��ǥ
int conv_pos_y(int randPos); // y��ǥ
void shuffleAnimal();

// ���� ��ġ ���
void printAnimals();
// ���� ���(���� ī�� �迭)
void printQuestion();
// ī�尡 ������������ ���� Ȯ��
int checkAnimal[4][5];

// ī�尡 ��� ���������� ���� Ȯ��
int foundAllAnimals();



int main() {
	
	srand(time(NULL));

	// �ʱ� ����ī�带 arrayAnimal�� �°� �迭�Ͽ� ������ ���� �־���
	initAnimalArray(); 

	// 10������ ������ �̸� ����
	animalName();

	// ������ ������ �̸��� ���� ī�� �迭�� ��� ����������� ����
	shuffleAnimal();

	// ���� Ƚ��
	int failcnt = 0;

	while (1) {
		// ����ڰ� ������ ��, 0~19
		int select1 = 0;
		int select2 = 0;

		// ���� ��ġ ���
		printAnimals();
		// ���� ���(���� ī�� �迭)
		printQuestion();

		printf("������ ī�� 2���� ������.\n");
		scanf_s("%d\n%d", &select1, &select2);
		if (select1 == select2) {
			continue;
		}

		// ��ǥ�� �ش��ϴ� ī�带 ������ ���� ������ �Ȱ����� Ȯ��
		// // ���� ��ǥ�� (x,y)�� ��ȯ
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// // ī�尡 �̹� �������� �ʾҴ��� Ȯ��
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)
			&& // // �� ������ ���� ���
			arrayAnimal[firstSelect_x][firstSelect_y] 
			== arrayAnimal[secondSelect_x][secondSelect_y]) {
			printf("\n\nBingo!! %s �߰�\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}
		// // �� ������ �ٸ� ���
		else {
			printf("\n\n��!! Ʋ�Ȱų� �̹� ������ ī���Դϴ�.\n\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failcnt++;
		}

		// ��� ������ �� ã�� ���
		if (foundAllAnimals() == 1) {
			printf("\n\n �����մϴ�! ��� ������ �� ���߼̳׿�!! \n\n");
			printf("���ݱ��� �� %d�� �Ǽ��ϼ̽��ϴ�.",failcnt);
			break;
		}
	}

	return 0;
}



void initAnimalArray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arrayAnimal[i][j] = -1;
		}
	}
}


void animalName() {
	strAnimal[0] = "�⸰";
	strAnimal[1] = "������";
	strAnimal[2] = "�䳢";
	strAnimal[3] = "�罿";
	strAnimal[4] = "������";
	strAnimal[5] = "�����";
	strAnimal[6] = "ȣ����";
	strAnimal[7] = "����";
	strAnimal[8] = "�����";
	strAnimal[9] = "�ٶ���";
}

void shuffleAnimal() {
	for (int i = 0; i < 10; i++) { // 10���� ������
		for (int j = 0; j < 2; j++) { // 2���� �ҷ�
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

// ��ǥ���� ����� ã��
int getEmptyPosition() {
	while (1) {
		int randPos = rand() % 20; // 20���� position �ʿ�, 0~19
		// ��ǥ ��ü�� 4�� 5���̹Ƿ� randPos�� ���ڸ� �̿��� ������ �ʿ伺 ����
		// 19 -> (3,4)
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);
		//printf("%d %d\n", x, y);

		if (arrayAnimal[x][y] == -1) {
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int randPos) {
	// 1�� �� 5��
	// randPos = 5 * �� + ��
	// 19 = 5 * 3 + 4
	return randPos / 5;
}

int conv_pos_y(int randPos) {
	// 1�� �� 5��
	// randPos = 5 * �� + ��
	// 19 = 5 * 3 + 4
	return randPos % 5;
}

// ���� ��ġ ���
void printAnimals() {
	// ī�� �迭�� ������ ���
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("\n======================================\n\n");
}

// ���� ���(���� ī�� �迭)
void printQuestion() {
	// 0 ~ 19
	/*
					seq					checkAnimal
	������	0  1   2   3   4		 0 0 0 0 0
	������	5  6  �䳢 8   9		 0 0 1 0 0
	������	10 11 12  �䳢 14		 0 0 0 1 0
	������	15 16 17  18   19		 0 0 0 0 0
	*/
	int seq = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			// ī�带 ����� ������ ��������: '�����̸�'
			if (checkAnimal[i][j] != 0){
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// ī�带 ������ ��������(������ ������ X): ��ġ�� ��Ÿ���� ����
			else {
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}


int foundAllAnimals() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}

