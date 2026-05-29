#include <stdio.h>
#define n 8

int main()
{
	int t,a[]={10,8,5,3,9,2,11,51};
	int i,j;
	
	for(i = 1; i < n; i++)
	{
		j = i-1;
		t = a[i];
		while (j >= 0 && t < a[j])
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = t;
	}
	for(i = 0; i < n; i++)
		printf("%d %d \n",i,a[i]);
	
	return 0;
}
