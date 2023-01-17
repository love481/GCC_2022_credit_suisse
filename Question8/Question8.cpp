#include <bits/stdc++.h>
using namespace std;
void solution(int n, int m, int *costs) {
    int prevCost,cost[n+1][m];
    memset(cost, 0, sizeof cost); 
    for (int i = 1; i <= n; i++) {
        prevCost = INT_MIN;
        for (int j = 1; j <m; j++) {
            prevCost = max(prevCost,*(*(cost + i-1) + j-1) - *(costs+j - 1));
            *(*(cost + i) + j)= max(*(*(cost + i) + j-1), *(costs+j)+ prevCost);
            }}
    printf("%d\n",*(*(cost + n) + m-1));
    return;
}
int main() {
    int n,m;
    cin>>n>>m;
    int costs[m];
    for(int i=0;i<m;i++){
        cin>>costs[i];
    }
	solution(n,m,costs);
return 0;
}