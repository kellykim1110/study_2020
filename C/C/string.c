#include <stdio.h>
/*
널-종료 문자열  null-terminated string
문자열을 이용할 때마다 문자열의 길이를 알려주지 않아도 '\0'(아스키 코드로 0)을 종료문자로 받음으로서 문자열의 길이를 알수 있다.
'\0'
0
(char)NULL
*/


/*
int str_length(char* str);

int main() {
	char sen1[4] = { 'P','s','i','\0' }; // 작은 따옴표는 하나의 문자
	char sen2[4] = { 'P','s','i',0 };
	char sen3[4] = { 'P','s','i',(char)NULL };
	char sen4[4] = { "Psi" }; // 큰 따옴표는 문자열

	printf("%s\n", sen1);
	printf("%s\n", sen2);
	printf("%s\n", sen3);
	printf("%s\n", sen4);

	char word[30] = { "long sentence" };
	char* str = word;

	printf("%s \n", str);

	// 문자열 조작
	word[0] = 's';
	word[1] = 'm';
	word[2] = 'a';
	word[3] = 'l';
	word[4] = 'l';
	printf("%s \n", str);

	printf("%s 문자열의 길이: %d \n", str, str_length(str));

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