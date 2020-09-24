#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool solution(int x);

int main() {
    int arr[4] = { 10, 11, 12, 13 };

    for (int i = 0; i < 4; i++) {
        if (solution(arr[i]) == true) {
            printf("The hashard of %d is TRUE.\n", arr[i]);
        }
        else {
            printf("The hashard of %d is FALSE.\n", arr[i]);
        }
    }

    return 0;
}


bool solution(int x) {
    bool answer = true;
    int num = x;
    int q = 0;
    while (num) {
        q += (num % 10);
        num /= 10;
    }
    if (x % q != 0) {
        answer = false;
    }
    return answer;
}