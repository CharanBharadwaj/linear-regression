#include<stdio.h>
#include<stdlib.h>

#define N 100
int main()
{
int i,temp;
printf("%d\n",N);
for(i=0;i<2*N;i++)
{
temp=rand()%100;
printf("%d\n",temp);
}
}
