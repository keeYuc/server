#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{	
	int arr[]={1,23,2,4,2,4,5,33,65,36,4,6,99};
	int max =0;
	printf("%ld\n",sizeof(arr)/sizeof(arr[0]));
	for(int i =0;i<sizeof(arr)/sizeof(arr[0]);i++){
		if(arr[i]>max){
		max=arr[i];

		}
	}
	
	printf("%d\n",max);
	time_t time1=time(NULL);
	srand((unsigned int)time1);
	int fuck=rand();
	printf("%d\n",fuck);



}
