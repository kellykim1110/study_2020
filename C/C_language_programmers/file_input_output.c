#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 파일 입출력
// 보통 메모리에 저장되므로 프로그램을 off했을 때 
// 기존의데이터가 날아감
// 이를 방지

/*
fputs, fgets 쌍
fprintf, fscanf 쌍
*/

#define MAX 10000

int main() {
	char line[MAX]; // char line[10000]
	
	
	// fputs fgets 문자열로 된 파일
	//fputs 파일에 쓰기
	// FILE * file = fopen(<파일 위치>, <동작>)
	// 동작 종류 
	//// w쓰기 r읽기 a띄어쓰기(append)
	//// t텍스트 b바이너리 데이터
	FILE * file = fopen(".\\FileTest\\test1.txt", "wb");
	if (file == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}
	else {
		fputs("fputs를 이용해서 글을 적어보자\n", file);
		fputs("잘 적히는지 확인\n", file);
		
		// 파일 닫으면서 저장
		// 데이터 손실 위험 방지
		fclose(file);
	}
	
	
	// fgets 파일에서 읽어오기
	FILE* file1 = fopen(".\\FileTest\\test1.txt", "rb");
	if (file1 == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}
	while (fgets(line, MAX, file1) != NULL) {
		printf("%s", line);
	}
	fclose(file1);
	

	//fprintf, fscanf 정형화된 format에 대해서 사용 시
	// fprintf
	// 로또 번호 저장 후 가져오기
	int num[6] = { 0,0,0,0,0,0 }; // 추첨번호
	int bonus = 0; // 보너스 번호
	char str1[MAX];
	char str2[MAX];

	FILE* file2 = fopen(".\\FileTest\\test2.txt", "wb");
	if (file2 == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}

	// 로또 번호 저장
	fprintf(file2, "%s %d %d %d %d %d %d\n", "추첨번호", 1, 2, 3, 4, 5, 6);
	fprintf(file2, "%s %d\n", "보너스번호", 7);

	fclose(file2);

	//fscanf
	FILE* file3 = fopen(".\\FileTest\\test2.txt", "rb");
	if (file3 == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}
	// 읽을 텍스트 , &num[]
	fscanf(file3, "%s %d %d %d %d %d %d", 
		str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n",
		str1, num[0], num[1], num[2], num[3], num[4], num[5]);

	fscanf(file3, "%s %d", str2, &bonus);
	printf("%s %d\n", str2, bonus);
	fclose(file3);
}

