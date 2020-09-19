#include <stdio.h>
// printf scanf

int main() {
	// 경찰관이 범죄자의 정보 입수
	// 이름 나이 몸무게 키 범죄명 입수하여 조서 작성
	
	// 배열은 앞에 &을 붙이지 않음
	char name[256];
	printf("이름이 무엇입니까?");
	scanf_s("%s\n", name, sizeof(name));
	printf("이름:\t\t%s\n", name);
	//%[^\n]s은 공백까지 포함한 문자열의 자료형

	// 일반 변수일 때는 변수 앞에 &를 붙임
	int age;
	printf("나이가 몇살 입니까?");
	scanf_s("%d\n", &age);
	printf("나이:\t\t%d\n", age);

	float weight;
	printf("몸무게는 몇 입니까?");
	scanf_s("%f\n", &weight);
	printf("몸무게:\t%.2f\n", weight);

	double height;
	printf("키는 몇입니까?");
	scanf_s("%lf\n", &height);
	printf("키:\t\t\t%lf\n", height);

	char crime[255];
	printf("무슨 범죄를 저질렀습니까?");
	scanf_s("%s\n", crime, sizeof(crime));
	printf("범죄명:\t%s\n", crime);

	// 조서 내용 출력
	printf("\n\n----범죄자 정보---\n\n");
	printf("%d살 %s는 %s를 저질렀기에 체포되었습니다.\n", age, name, crime);

	return 0;
}

