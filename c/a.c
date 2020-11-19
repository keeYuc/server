#include<stdio.h>
#include<stdlib.h>
int main()
{
	system("ls");
	printf("hello\n");
	int a=0;
	scanf("%d",&a);
	switch(a)
{
	case 1:
		printf("shi 1");
	case 2:
		printf("shi 2");
	default:
		printf("sha bushi");

}
	return 0;
}
