#include <bits/stdc++.h>
using namespace std;
bool get_cycle_state(int current, vector<int>*transfers,bool *visited,bool *stac)
{
    visited[current] = true;
    stac[current]=true;
    for(auto iter: transfers[current])
    {  if (!visited[iter])
       {if(get_cycle_state(iter,transfers, visited,stac)==true)
            return true;
        }
        else if (stac[iter]==true)
            return true;}
    stac[current]=false;
    return false;
}
bool solution(int n, int l, vector<int>*transfers)
{  
    bool visited[n],stac[n];
    for(int i=0;i<n;i++)
    {
    visited[i]=false;
    stac[i]=false;
    }
   for(int i=0;i<n;i++)
   {
    if (!visited[i])
        {
            if(get_cycle_state(i,transfers,visited,stac)==true)
            return true;
            }
   }
   return false;
}
int main() {
	
	int n, l;
    cin >> n >> l;
  
    vector<int>transfers[n];
    vector<int> transfer(2);
    for (int i = 0; i < l; i++) {
      cin >> transfer[0] >> transfer[1];
      if (transfer[0] != transfer[1])
      transfers[transfer[0]].push_back(transfer[1]);

    }
    bool result = solution(n, l, transfers);
    result ? cout<< "Ineligible" : cout<< "Eligible";
	
	return 0;
}