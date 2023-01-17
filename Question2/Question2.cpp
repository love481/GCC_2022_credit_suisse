#include <bits/stdc++.h>
using namespace std;
int solution(string files) { 
    int len_files = files.length();
    if (len_files==0)
      return -1;
    else if (len_files==1)
      return 1;
    int totalOddLet = 0;
    unordered_map<char, int> counter_letter;
    for (auto c:files) {
        if (counter_letter.find(c) == counter_letter.end()) 
            counter_letter[c] = 1;
         else 
            counter_letter[c] += 1;
    }
    for (auto x : counter_letter) {
        if (x.second % 2 != 0) 
            totalOddLet += 1;
    }
    while (len_files != 0) {
        if ( (totalOddLet % 2 != 1 && len_files % 2 == 0) || totalOddLet > 1) {
            len_files--;
            totalOddLet--;
        } else 
             return len_files;
    }
    return 0;}
int main() {
     string files="";
     cin>>files;
     cout<<solution(files);
     return 0;
}