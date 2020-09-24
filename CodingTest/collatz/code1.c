#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num);

int main() {
    printf("The collatz of %d is %d\n",6,solution(6));
    printf("The collatz of %d is %d\n",16,solution(16) );
    printf("The collatz of %d is %d\n",626331 ,solution(626331));
    return 0;
}

int solution(int num) {
    int answer = 0;
    for (int i = 0; i <= 500; i++) {
        if (num % 2 == 0) {
            num /= 2;
           // printf("%d\n", num);
            answer++;
        }
        else if ((num % 2 == 1) && (num != 1)) {
            num = (3 * num + 1);
            answer++;
            //printf("%d\n", num);
        }
        else if (num == 1) {
            //printf("%d\n", num);
            break;
        }
        else if ((answer == 500) || (num < 1) || (num > 8000000)) {
            answer = -1;
            //printf("%d\n", num);
            break;
        }

    }
    return answer;
}