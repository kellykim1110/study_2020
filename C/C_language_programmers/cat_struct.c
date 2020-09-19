#include <stdio.h>
#include <time.h>

// ����ü Struct
// printf("key1": %s\n",StructArr.key1);

/* 
����ü �����ʹ� �迭�� ���
�迭 ������ �� ����ü StructArr

struct StructArr * StructPtr;
StructPtr = &StructArr;
printf("key1": %s\n",(*StructPtr).key1);
printf("key1": %s\n",StructPtr->key1);
*/

/*
����ü �ȿ� ����ü
struct StructArr1{
char *key1;
int key2;

struct StructArr1 * SubStructArr;
}

struct StructArr2;


StructArr1.SubStructArr = &StructArr2;
printf("key1": %s\n",StructArr1.SubStructArr->key1);
*/

/*
5������ ����̰� ����
�ƹ� Ű�� ������ �������� ����� ����
5���� ����̸� ��� �����ؼ� Ű��� �Ǵ� ����
��, ���� ���� ����̰� �ߺ� ������ �߻� ����

�����
�̸�, ����, ����, Ű��� ���̵�(����)
*/


/*
typedef struct {
	char * name;
	int age;
	char* character;
	int level;
} CAT;

// ������� ������ �����
int collection[5] = { 0,0,0,0,0 };

// ��ü ����� ����Ʈ
CAT cats[5];

// ����� ���� �ʱ�ȭ
void initCats();

// ���� ����� ����
void printCat(int selected);

// collection�� 5������ ����̰� �� ��������� Ȯ��
int checkCollection();


int main() {
	srand(time(NULL));

	// �ʱ�ȭ
	initCats();

	while (1) {
		printf( "\n\n�αٵα�~~��� ������� ����(??)�� ���� �� �������???\n�ƹ� Ű�� ������ Ȯ���� ������!!\n\n" );
		getchar();

		int selected = rand() % 5; // 0~4
		// ���� ����� ����
		printCat(selected);
		
		// ���� ����� ó��
		collection[selected] = 1;

		checkCollection();
	}

	return 0;
}

// ����� ���� �ʱ�ȭ
void initCats() {
	char * nameArr[] = { "����", "����", "�ü�", "��Ż", "��ȣ" };
	char* charArr[] = { "��Ż", "Ȳ������", "����", "��" ,"����" };
	int ageArr[] = { 12, 12, 3, 3, 4 };
	int levelArr[] = {5, 5, 3, 4, 2};

	for (int i = 0; i < 5; i++) {
		cats[i].name = nameArr[i];
		cats[i].age = ageArr[i];
		cats[i].character = charArr[i];
		cats[i].level = levelArr[i];
	}
}

// ���� ����� ����
void printCat(int selected) {
	printf("\n\n===========����� �� ������� ���簡 �Ǿ����!!! ===========\n");
	printf("�̸�         : %s\n", cats[selected].name);
	printf("����         : %d\n", cats[selected].age);
	printf("Ư¡         : %s\n", cats[selected].character);
	printf("Ű��� ���̵�:" );
	// ������ ���ڷ� ǥ��
	for (int i = 0; i < cats[selected].level; i++) {
		printf("%s", "��");
	}
	printf("\n=================================================\n\n");
}

// collection�� 5������ ����̰� �� ��������� Ȯ��
int checkCollection() {
	// 1. ���� ������ ����� ��ϵ� Ȯ��
	// 2. �� ��Ҵ��� ���� Ȯ��

	// ����� 5���� �� ���� ����
	int collectAll = 1;

	printf("\n\n====������ ����� ���====\n\n");
	for(int i = 0; i < 5; i++) {
		// ���� ������ ������� ������ ���°� �ִ��� ����
		// �� �ڽ� or ������̸����� ���
		if (collection[i] == 0) {
			printf("%10s","(�� �ڽ�)");

			// ����� 5���� �� ���� X
			collectAll = 0;
		}
		else { 
			printf("%10s", cats[i].name);
		}
	}
	if (collectAll == 1){
		printf("\n�����մϴ�!!\n5������ ������� ���簡 �Ǿ����!!\n\n");
		exit(0);
	}
}

*/