#include <stdio.h>
/*
��-���� ���ڿ�  null-terminated string
���ڿ��� �̿��� ������ ���ڿ��� ���̸� �˷����� �ʾƵ� '\0'(�ƽ�Ű �ڵ�� 0)�� ���Ṯ�ڷ� �������μ� ���ڿ��� ���̸� �˼� �ִ�.
'\0'
0
(char)NULL
*/


/*
int str_length(char* str);

int main() {
	char sen1[4] = { 'P','s','i','\0' }; // ���� ����ǥ�� �ϳ��� ����
	char sen2[4] = { 'P','s','i',0 };
	char sen3[4] = { 'P','s','i',(char)NULL };
	char sen4[4] = { "Psi" }; // ū ����ǥ�� ���ڿ�

	printf("%s\n", sen1);
	printf("%s\n", sen2);
	printf("%s\n", sen3);
	printf("%s\n", sen4);

	char word[30] = { "long sentence" };
	char* str = word;

	printf("%s \n", str);

	// ���ڿ� ����
	word[0] = 's';
	word[1] = 'm';
	word[2] = 'a';
	word[3] = 'l';
	word[4] = 'l';
	printf("%s \n", str);

	printf("%s ���ڿ��� ����: %d \n", str, str_length(str));

	return 0;
}
*/

int str_length(char* str) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}