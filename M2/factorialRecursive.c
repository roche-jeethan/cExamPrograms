#include<stdio.h>
int fact(int x);

int fact(int x){
	if(x==0){
		return 1;
	}
	else {
		return x*fact(x-1);
	}
}
int main(){
	int n;
	printf("Enter the number:\n");
	scanf("%d",&n);
	printf("Factorial of a number is %d\n",fact(n));
	return 0;
}
