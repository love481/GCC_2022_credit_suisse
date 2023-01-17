#include <stdio.h>
#include<string.h>
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
int solution(int n, int m, int costs[]){
    int prevCost,cost[n+1][m];
    memset(cost, 0, sizeof cost); 
    for (int i = 1; i <= n; i++) {
        prevCost = -1000;
        for (int j = 1; j <m; j++) {
            prevCost = max(prevCost,*(*(cost + i-1) + j-1) - *(costs+j - 1));
            *(*(cost + i) + j)= max(*(*(cost + i) + j-1), *(costs+j)+ prevCost);
            }}
    return  *(*(cost + n) + m-1);
}

int main(void) {
    int N, M;
    scanf("%d %d",&N,&M);
    int costs[M];
    for(int i=0;i<M;i++){
        scanf("%d", &costs[i]);
    }
    printf("%d",solution(N,M,costs));
    printf("\n");

    return 0;
}
