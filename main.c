#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int xchng_cnt = 0, cmp_cnt = 0;
unsigned long long timeb = 0, timea = 0;
int *arrx, *arry;
void bubble(unsigned int n, int *arr);
void qsrt(int *arr, int f, int l);
void sorted(unsigned int n, int *arr1, int *arr2);
void revsort(unsigned int n, int *arr1, int *arr2);
void randomize(unsigned int n, int *arr1, int *arr2);
void shres(unsigned int n, int *arr1, int *arr2);
extern int compare(int a, int b);
extern void xchng(int *x, int *y);
extern unsigned long long timestamp(void);

int main(void)
{
    unsigned int n = 10;
    int i = 0, j = 0;
    int *arr1 = NULL, *arr2 = NULL;
    for(n; n <= 10000; n *= 10)
    {
        arr1 = malloc(n*sizeof(int));
        arr2 = malloc(n*sizeof(int));
	printf("Sorted ");
	sorted(n, arr1, arr2);
        shres(n, arr1, arr2);
        printf("Unsorted ");
	revsort(n, arr1, arr2);
        shres(n, arr1, arr2);
	printf("Random1 ");
        randomize(n, arr1, arr2);
        shres(n, arr1, arr2);
	printf("Random2 ");
        randomize(n, arr1, arr2);
        shres(n, arr1, arr2);
	printf("==============================\n");
    }
    return 0;
}
void shres(unsigned int n, int *arr1, int*arr2)
{
        printf("Size %d:\n", n);
	timea = timestamp();
        cmp_cnt = 0;
	xchng_cnt = 0;
	bubble(n, arr1);
	timeb = timestamp();
        printf("\t Bubblesort: time %lld, number of compares: %d, number of exchanges %d.\n\n", timeb-timea, cmp_cnt, xchng_cnt);
	cmp_cnt = 0;
	xchng_cnt = 0;
        timea = timestamp();
        qsrt(arr2, 0, n);
        timeb = timestamp();
        printf("\t Quicksort: time %lld, number of compares: %d, number of exchanges %d.\n\n", timeb-timea, cmp_cnt, xchng_cnt);
        return ;
}
void randomize(unsigned int n, int *arr1, int *arr2)
{
    int i;
    int k = 1;
    srand(time(NULL));
    for (i = 0; i < n; i++)
      {     
	arr1[i]= rand();
	arr2[i] = arr1[i];
      }
    return ;
}

void qsrt(int *arr, int f, int l)
{
    int i=f, j=l;
    int d = abs(arr[(f+l)/2]), tmp;
    do
    {
        while (!(compare(arr[i],d))&&(i<l))
            ++i;
        while (compare(arr[j],d)&&(j>f))
            --j;
        if(i<=j)
        {
            if (i<j)
            xchng(arr+i, arr+j);
            ++i;
            --j;
        }
    } while (i<=j);
    if (i<l)
        qsrt(arr, i, l);
    if (f<j)
        qsrt(arr, f, j);
    return ;
}

void bubble(unsigned int n, int *arr)
{
    int i, j, temp;
    for (i = (n - 1); i >= 1; i--)
    {
        for (j = 0; j <= i; j++)
        {
 
	  if (compare(arr[j-1],arr[j]))	
	      xchng (arr+j-1, arr+j);
	}
    }
    return ;
}
void revsort(unsigned int n, int *arr1, int *arr2)
{
    int i;
    for (i = 0; i < n; i++)
      {
        arr1[i] = i;
	arr2[i] = i;
      }
    return ;
}
void sorted(unsigned int n, int *arr1, int *arr2)
{
    int i;
    for (i = 0; i < n; i++)
      {
	arr1[i] = n - i;
	arr2[i] = n - i;
      }
    return ;
}
