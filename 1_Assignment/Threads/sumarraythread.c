#include <stdio.h> 
#include <pthread.h> 
  
// size of array 
#define MAX 1000
  
// maximum number of threads 
#define MAX_THREAD 10 
  
int a[1000]; 
int sum[10] = { 0 }; 
int part = 0; 
int i;

void arrgen()
{
    for(int i=0;i<MAX;i++)
    {
        a[i]=rand()%2;
    }
}

void* sum_array(void* arg) 
{ 
    // Each thread computes sum of 1/10th of array 
    int thread_part = part++; 
    printf("\n thread part:%d",thread_part);
    for (i = thread_part * (MAX / 10); i < (thread_part + 1) * (MAX / 10); i++) 
        sum[thread_part] += a[i];
        printf("\nindex value:%d",i-1);
}
// Driver Code 
int main() 
{ 
     arrgen();
    pthread_t threads[MAX_THREAD]; 
  
    // Creating 10 threads 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL); 
  
    // joining 10 threads i.e. waiting for all 4 threads to complete 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_join(threads[i], NULL); 
  
    // adding sum of all 10 parts 
    int total_sum = 0; 
    for (int i = 0; i < MAX_THREAD; i++) 
        total_sum += sum[i]; 
  
    printf("\nsum of array: %d",total_sum);
  
    return 0; 
} 
