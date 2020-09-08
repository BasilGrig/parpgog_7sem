#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
int N = atoi(argv[1]);//counting from 1 to N
int i, sum;// iterator and local sum
int result=0;//result sum
#pragma omp parallel private (i) reduction(+:sum) //parallelize program + use reduction to count local sum on eachthread
{

#pragma omp for //loop for sum counting
for (i=1;i < N + 1;i++)
{
sum=sum+i;

}
#pragma omp atomic //assembly to result sum
result = result + sum;
}
printf("sum is %d\n",result);
return 0;
}
