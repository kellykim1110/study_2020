#include <stdio.h>

// pointer�� �̿��Ͽ� array�� �����ϱ�
void changeArray(int arr);

int main() {
	int arr[3] = { 1, 2, 3 };
	// arr[2]�� ���� 9�� ��������
	// �迭�� ���, �迭 arr�� �ٷ� �ּҸ� ������.
	changeArray(arr);
	// �迭�� ���ӵ� ��ġ�̱� ������ �̷��� �ص� ������ �߻������� �ʴ´�.
	// ������, arr[0]�� ����° ��ġ�� ���� ����ǹǷ� arr[0] = 1 �״���̴�.
	//changeArray(&arr[0]);
	for (int i = 0; i < 3; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}

void changeArray(int *ptr) {
	ptr[2] = 9;
}
