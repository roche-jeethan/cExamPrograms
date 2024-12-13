#include<stdio.h>
struct student{
	char name[30];
	char usn[10];
	int m1,m2,m3,total;
	float avg;
};
int main(){
	struct student s[20];
	int n,i;
	printf("Enter the number of records:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the details of the %d student:\n",i+1);
		printf("Enter name: ");
		scanf("%s",s[i].name);
		printf("Enter USN: ");
		scanf("%s",s[i].usn);
		printf("Enter the marks of 3 subjects:\n");
		scanf("%d %d %d",&s[i].m1,&s[i].m2,&s[i].m3);
		s[i].total=s[i].m1+s[i].m2+s[i].m3;
		s[i].avg=s[i].total/3;
		printf("Total marks of %d student is %d\n",i+1,s[i].total);
		printf("Average marks of %d student is %f\n",i+1,s[i].avg);
	}
	for(i=0;i<n;i++){
		if(s[i].avg>35){
			printf("%s has scored more than average\n",s[i].name);
		}
		else {
			printf("%s has scored less than average\n",s[i].name);
		}
	}
	return 0;
}
