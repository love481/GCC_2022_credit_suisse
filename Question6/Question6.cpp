#include<bits/stdc++.h>
using namespace std;
void solution(int n, int *flows){
int flows_count[n+1];
memset(flows_count,0,sizeof flows_count);
int count,start;
for (int i=0;i<n;i++)
{
    start=*(flows+i);
    if (*(flows_count+start)==0)
        {
        count=1;
        vector<int>list_systems;
        list_systems.push_back(start);
        while(*(flows+start-1)!=list_systems[0])
        {
            start=*(flows+start-1);
            list_systems.push_back(start);
            count++;
        }
        for(int system:list_systems)
            *(flows_count+system)=count;
        }
  cout<<*(flows_count+(*(flows+i)))<<" ";}
}
int main(){

    int n;
    cin>>n;
    int flows[n];
    for(int i=0;i<n;i++)
    {
        int q;cin>>q;
        flows[i]=q;
    }
    solution(n,flows);
    return 0;

}