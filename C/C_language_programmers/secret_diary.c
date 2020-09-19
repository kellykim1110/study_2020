#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

// 파일 입출력
// 보통 메모리에 저장되므로 프로그램을 off했을 때 
// 기존의데이터가 날아감
// 이를 방지

/*
비밀번호를 입력받아
비밀번호가 맞으면, 비밀일기를 읽어와서 보여주고 계속 작성 가능
비밀번호가 틀린경우, 경고 메시지를 표시하고 종료
*/
#define MAX 10000 // 최대 10000줄 받아 오겠다.

int main() {
	// fputs, fgets 활용
	char line[MAX]; // 파일에서 불러온 내용을 입력할 변수
	char contents[MAX]; //일기장에 입력할 내용
	char password[20]; // 비밀번호 입력
	char c; // 비밀번호 입력할 때 키값 확인용 (마스킹) password: *******이런식
	char * passwordNumber = "secretdiary"; // 저장했던 비밀번호


	printf("'비밀일기'에 오신 것을 환영합니다.\n");
	
	// 비밀번호 입력
	printf("비밀번호를 입력하세요: ");

	/*
	getchar()과 getch()의 차이

	getchar() : 엔터를 입력받아야 동작을 합니다.
	getch()   : 키 입력시 바로바로 동작을 합니다.
	*/
	int i = 0;
	while (1) {
		c = getch();
		if (c == 13) { //아스키코드  // Enter -> 비밀번호 입력 종료
			password[i] = "\0";
			break;
		}
		else { // 비밀번호 입력 중
			printf("*");
			password[i] = c;
		}
		i++;
	}

	// 비밀번호 확인
	printf("\n\n====비밀번호 확인 중...====\n\n");
	//printf("%d", strcmp(password, passwordNumber));

	// if (strcmp(password, <내가 친 비밀번호>) == 0) {// 비밀번호 일치
	if (strcmp(password, passwordNumber) == 1) {// 비밀번호 일치
		printf("====비밀번호 확인 완료====\n\n");

		// fopen(fileName, "a+b")
		//// a+b
		//// 파일 없으면 생성, 
		//// 파일 있으면 append를 한다(뒤에서부터 내용 추가)
		char * fileName = ".\\FileTest\\secretdiary.txt";
		FILE * file = fopen(fileName, "a+b");

		if (file == NULL) {
			printf("파일 열기 실패\n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL) {
			printf("%s", line);
		}

		printf("\n\n내용을 계속 작성하세요~\n종료하시려면 exit를 입력하세요!!\n\n");

		while (1) {
			// 줄바꿈(\n)나오기 전까지 계속 입력 받아라.
			// 한 줄씩 입력받을 예정
			scanf("%[^\n]", contents);
			// ENTER 입력(\n) Flush 처리
			getchar();

			if (strcmp(contents, "exit") == 0) {
				printf("비밀일기 입력을 종료합니다.\n\n");
				break;
			}

			fputs(contents, file);
			// ENTER를 위에서 무시 처리 했으므로 임의로 추가
			fputs("\n", file);
		}
			fclose(file);
	}
	else {
		// 비밀번호가 틀릴 경우
		printf("====비밀번호가 틀렸어요....====\n\n");
		printf("====누구냐... 못보니까 그만 나가라...====\n\n");
	}
	return 0;
}