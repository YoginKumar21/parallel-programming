// write an open np program to transform  each elments with A[i]=3*A[i]+2 using hash pragmd omp paralel for schedule(dynamic,2) then switch to (static,2) 
// int A[6]=(1,2,3,4,5,6}; dynamic
// int A2[6]={1,2,3,4,5,6}; static

#include <stdio.h>
#include <omp.h>

int main() {
    int A[6] = {1, 2, 3, 4, 5, 6};   // Dynamic scheduling
    int A2[6] = {1, 2, 3, 4, 5, 6};  // Static scheduling

    // Dynamic scheduling with chunk size 2
    #pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < 6; i++) {
        A[i] = 3 * A[i] + 2;
    }

    // Static scheduling with chunk size 2
    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < 6; i++) {
        A2[i] = 3 * A2[i] + 2;
    }

    // Print results
    printf("Results with dynamic scheduling:\n");
    for (int i = 0; i < 6; i++) {
        printf("A[%d] = %d\n", i, A[i]);
    }

    printf("\nResults with static scheduling:\n");
    for (int i = 0; i < 6; i++) {
        printf("A2[%d] = %d\n", i, A2[i]);
    }

    return 0;
}