#include <stdio.h>

// pointer를 이용하여 array값 변경하기
void changeArray(int arr);

int main() {
	int arr[3] = { 1, 2, 3 };
	// arr[2]의 값을 9로 변경하자
	// 배열일 경우, 배열 arr은 바로 주소를 가진다.
	changeArray(arr);
	// 배열은 연속된 위치이기 때문에 이렇게 해도 오류가 발생하지는 않는다.
	// 하지만, arr[0]의 세번째 위치의 값이 변경되므로 arr[0] = 1 그대로이다.
	//changeArray(&arr[0]);
	for (int i = 0; i < 3; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

void changeArray(int *ptr) {
	ptr[2] = 9;
}
