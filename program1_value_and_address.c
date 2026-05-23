#include<stdio.h>
int main();{
  int a=10;
  int *p=&a;
  printf("Value of a=%d\n",a);
  printf("address of a=%p\n",(void*)&a);
  printf("pointer p stores=%p\n",(void*)p);
  printf("Value using pointer p=%d\n",*p);
  return 0;
}
