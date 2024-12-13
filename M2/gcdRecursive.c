/*Explain recursion in your own words and write program for Factorial and gcd of two
numbers using recursion Function

Ans: Recursion is a concept of calling a function inside the function again and again, 
till the requirement isnt satisfied. it acts as a while loop, but for user defined functions.
Here is an example on factorial and gcd programs with recursion function.*/
#include <stdio.h>
int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
int gcd(int a, int b)
{
    if (b != 0)
        return gcd(b, a % b);
    else
        return a;
}
int main()
{
    int n, a, b;
    printf("Enter the number for factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));
    printf("Enter two numbers for gcd: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}