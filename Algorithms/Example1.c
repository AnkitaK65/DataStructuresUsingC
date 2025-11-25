#include <stdio.h>
#include <time.h>

#define SIZE 100000   // Large array size to show time difference

// Recursive function to find sum
long long recursiveSum(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n-1] + recursiveSum(arr, n-1);
}

int main() {
    int arr[SIZE];
    long long sum = 0;
    int i;

    // Fill array with values
    for (i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    clock_t start, end;
    double time_taken;

    // ----------------------------------------------
    // 1. Using For Loop
    // ----------------------------------------------
    sum = 0;
    start = clock();
    for (i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    end = clock();

    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("For Loop Sum = %lld, Time = %.5f ms\n", sum, time_taken);

    // ----------------------------------------------
    // 2. Using While Loop
    // ----------------------------------------------
    sum = 0;
    i = 0;
    start = clock();
    while (i < SIZE) {
        sum += arr[i];
        i++;
    }
    end = clock();

    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("While Loop Sum = %lld, Time = %.5f ms\n", sum, time_taken);

    // ----------------------------------------------
    // 3. Using Recursion
    // ----------------------------------------------
    start = clock();
    long long recSum = recursiveSum(arr, SIZE);
    end = clock();

    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("Recursive Sum = %lld, Time = %.5f ms\n", recSum, time_taken);

    return 0;
}

/*
Output:
For Loop Sum = 5000050000, Time = 0.43000 ms
While Loop Sum = 5000050000, Time = 0.44400 ms
Recursive Sum = 5000050000, Time = 2.24200 ms
*/