#include <stdio.h>
#include <limits.h>
int main() {
    int N = 5;
    int data[5][2] = {
        {15, 8},
        {5, 11},
        {6, 3},
        {7, 2},
        {9, 14}
    };

    int sum = 0;
    int even_count = 0, odd_count = 0;
    int min_diff = INT_MAX;   // правильная инициализация

    for (int i = 0; i < N; i++) {
        int a = data[i][0];
        int b = data[i][1];

        int min = (a < b) ? a : b;
        int max = (a > b) ? a : b;

        sum += min;

        if (min % 2 == 0)
            even_count++;
        else
            odd_count++;

        if ((a % 2) != (b % 2)) {
            int diff = max - min;
            if (diff < min_diff)
                min_diff = diff;
        }
    }

    int majority_parity = (odd_count > even_count) ? 1 : 0;

    if ((sum % 2) != majority_parity) {
        sum += min_diff;
    }

    printf("8 lab\n");
    printf("sum = %d\n", sum);

    return 0;
}