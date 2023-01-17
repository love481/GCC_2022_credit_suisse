#include <bits/stdc++.h>
using namespace std;
int solution(int N, int M, int *P)
{   if (N<=0)
       return -1;
    if (N==1 && *P<=M)
        return 1;
    if (N==1 && *P>M)
        return 0;
    int j=0;
    while(j+1<N)
    {
        if(*(P+j+1)-*(P+j)<0)
        {
            if(*(P+j+1)+*(P+j)<=M) swap(*(P+j+1),*(P+j));
            else return 0;
        }
        j++;}
    return 1;
}
int main() {
    int n,m;
    cin>>n>>m;
    int P[n];
    for(int i=0;i<n;i++){
        scanf("%d", &P[i]);
    }
	cout<<solution(n,m,P)<<endl;
	return 0;
}