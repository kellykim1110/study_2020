#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n);

int main() {
    printf("%d\n", solution(12));
    return 0;
}

int solution(int n) {
    int answer = 1 + n;
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 3;
    }
    else {
        for (int i = 2; i < n; i++) {
            if ((n % i == 0) && (!(i > n / i))) {
                answer += i;
                if (i < n / i) {
                    answer += n / i;
                }
            }
        }

        return answer;
    }
}