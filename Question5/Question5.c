#include <stdio.h>

int solution(int cutoffScore, int *scores,int scoresLength)
{  int BoW =0,s=0,e=0,sum=*scores;
    while (s < scoresLength && e < scoresLength) 
    {   if(sum >= cutoffScore) 
          {
          sum = sum - *(scores+s);
          s = s + 1;
         } 
        else 
        {   e = e + 1;
        if (e < scoresLength) 
             sum = sum + *(scores+e);
        if (s <= e) 
             BoW = BoW + e - s;
     }
    } return BoW;
}

int main(void) {
    int cutoffScore;
    scanf("%d\n", &cutoffScore);
    int size = 0;
    scanf("%d\n", &size);
    int scores[size];
    for(int i = 0; i < size; i++) {
        scanf("%d", &scores[i]);
    }
    int result = solution(cutoffScore, scores, size);
    printf("%d\n",result);
    return 0;
}
