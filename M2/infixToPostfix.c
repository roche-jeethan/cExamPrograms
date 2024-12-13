#define SIZE 50
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
char s[SIZE];
int top = -1;
int cp=0,co=0; //counter for operators ,counter for operands//
void push(char elem) {
    s[++top]=elem;
}
char pop(){
    return(s[top--]);
}
int pr(char elem) /* This function assigns precedence values to operators. It returns
the precedence value based on the operator.*/
{
    switch (elem) {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': 
        case '%': return 3;
        case '^': return 4;
        default: return -1;
    }

}
void main(){
    char infx[50],pofx[50],ch, elem;
    int i=0,k=0;
    int prec;
    printf("\n\nRead the Infix Expression: ");
    scanf("%s",infx);
    push('#');
    while((ch=infx[i++])!='\0') {
        if(ch=='(')
            push(ch);
        else if(isalnum(ch)){
            pofx[k++]=ch;
            co++;
        }
        else if(ch==')'){
            while(s[top]!='('){
                pofx[k++]=pop(); 
            }
            elem=pop();
        }
        else { 
            cp++;
            prec=pr(ch);
            if(prec == -1){
                printf("Invalid operator\n");       
                exit(1);
            }
            while(pr(s[top])>= prec)
                pofx[k++]=pop();
            push(ch);
        }
    }
    while(s[top]!='#'){
        if(s[top]=='('){
            printf("Mismatched parenthesis\n");
            exit(1);
        }
        else if(cp!=co-1){
            printf("Invalid expression\n");
            exit(1);
        }
        else
            pofx[k++]=pop();
    }
    pofx[k]='\0';
    printf("\nPostfix Expression: %s\n",pofx);
}