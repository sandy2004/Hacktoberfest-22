#include<stdio.h>
void main()
{
int a[5]={1,2,3,4,5};
int i;
int *p;
for(i=0;i<5;i++)
{
    printf("%d",*p);
    p=&a[i];
}
}
