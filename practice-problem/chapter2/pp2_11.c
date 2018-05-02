#include <stdio.h>

#define GET_ARRAY_LEN(array,len) {len = (sizeof(array)/sizeof(array[0]));}

void reverse_array(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt-1;
      first <= last;
      first++, last--)
    inplace_swap(&a[first],&a[last]);
}

int main()
{
  int a1[] = {1,2,3,4};
  int a2[] = {1,2,3,4,5};
  int len1 = 0,len2 = 0;

  GET_ARRAY_LEN(a1,len1);
  GET_ARRAY_LEN(a2,len2);

  reverse_array(a1,len1);
  reverse_array(a2,len2);

  for (i = 0;i < len1;i++) {
    printf(" %d",a1[i]);
  }
  printf("\n");

  for (i = 0;i < len2;i++) {
    printf(" %d",a2[i]);
  }

  return 0;
}
