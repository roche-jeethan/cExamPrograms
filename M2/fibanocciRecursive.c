// fibannocci using recursion
#include<stdio.h>
int fib(int x);
int f=0,s=1;
int fib(int x){
	int th;
	if(x>0){
		th=f+s;
		printf("%d\n",th);
		f=s;
		s=th;
		fib(x-1);
	}
}

int main(){
	int n;
	printf("Enter a number:\n");
	scanf("%d",&n);
	printf("Fibanocci Series:\n%d\n%d\n",0,1);
	fib(n-2);
	return 0;
}
