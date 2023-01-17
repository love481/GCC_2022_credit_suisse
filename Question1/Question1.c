#include<stdio.h> 
 
char* solution(long n)
{   if (!(n % 4)) return "BUY";
    if (n % 2) return "SELL";
    else return "PASS";
}
 
int main(void) {
  	long n;
	scanf("%ld",&n);
	char *ans=solution(n);
  	printf("%s\n",ans);
   
	return 0;
}
