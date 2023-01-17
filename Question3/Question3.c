#include <stdio.h>

int solution(int N, int M, int *P){
    int j=0,temp;
    while(j+1<N)
    {
        if(*(P+j+1)-*(P+j)<0)
        {
            if(*(P+j+1)+*(P+j)<=M) 
            {
                temp=*(P+j+1);
                *(P+j+1)=*(P+j);
                *(P+j)=temp;
            }
            else return 0;
        }
        j++;}
    return 1;
}

int main(void) {
    int N, M;
    scanf("%d %d",&N,&M);
    int P[N];
    for(int i=0;i<N;i++){
        scanf("%d", &P[i]);
    }
    printf("%d",solution(N,M,P));
    printf("\n");

    return 0;
}
