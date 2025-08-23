// write an open np program which launches a parallel region and it has each thread prints its id and team size 


#include<stdio.h>
#include<omp.h>

int main(){
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        int thread_id=omp_get_thread_num();
        int team_size=omp_get_num_threads();
        printf("%d out of %d", thread_id, team_size);
    }
}