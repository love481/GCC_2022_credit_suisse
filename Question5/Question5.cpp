#include <bits/stdc++.h>
using namespace std;
int solution(int cutoffScore, int scoresLength, int *scores)
{   int BoW =0,s=0,e=0,sum=*scores;
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
int main(){
int cutoffScore;
int scoresLength;
cin>>cutoffScore;
cin>> scoresLength;
vector<int> input_data;
string buffer;
int data;
getline(cin, buffer);
getline(cin, buffer);
istringstream iss(buffer);
while (iss >> data)
    input_data.push_back(data);
 int scores[scoresLength];
    for (int i = 0; i < scoresLength; i++) {
        scores[i] = input_data[i];
    }

int result = solution(cutoffScore,scoresLength, scores);
cout << result;

}
