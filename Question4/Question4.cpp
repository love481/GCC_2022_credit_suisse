#include <bits/stdc++.h>
using namespace std;
void solution(int n, vector<string> *employees, vector<vector<int>> shifts){
  vector<int> shiftsList;
  int e_s;
  for(int i=0;i<n;i++){
    for(int j=0;j<2;j++){
      if(find(shiftsList.begin(),shiftsList.end(),shifts[i][j])==shiftsList.end())
        shiftsList.push_back(shifts[i][j]); } }
  sort(shiftsList.begin(),shiftsList.end());
  cout<<shiftsList.size()-1<<endl;
  for(int i=0;i<shiftsList.size()-1;i++){
    vector<string> employeess;
    for(int j=0;j<n;j++){
      if(shifts[j][0]<=shiftsList[i] && shifts[j][1]>=shiftsList[i+1])
        employeess.push_back(employees->at(j));
        }
    sort(employeess.begin(),employeess.end());
    e_s=employeess.size();
    cout<<shiftsList[i]<<" "<<shiftsList[i+1]<<" "<<e_s<<" ";
    if (e_s>0)
    {
    for(int k=0;k<e_s-1;k++)
      cout<<employeess[k]<<" ";
      cout<<employeess[e_s-1];
    } printf("\n");}
}
int main() 
{
    int n;
    cin >> n;
    vector<string> employees;  
    string name;
    for(int i = 0; i < n; i++){
      cin >> name;
      employees.push_back(name);
    }

    vector<vector<int>> shifts;
    vector<int> shift(2);
    for (int i = 0; i < n; i++) {
      cin >> shift[0] >> shift[1];
      shifts.push_back(shift);
    }
     solution(n, &employees, shifts);
    
}