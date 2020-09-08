#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main() {
int tid;
int i;
int num;
#pragma omp parallel shared(num) // parallelize programm
{
      num  = omp_get_num_threads();//get quantity of threads
      for(int i=num-1; i>=0; i--)//synchronization of threads with critical section
      {
            #pragma omp barrier
            {
		  tid = omp_get_thread_num();
                  if(i== tid)
                  {
                        #pragma omp critical
                        printf("Thread# %d: Hello world\n", i);
                  }
            }
      }
}
 return 0;
}
