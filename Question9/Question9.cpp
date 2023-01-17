#include<bits/stdc++.h>
using namespace std;
int MaxSumSubSquare(vector<vector<int>> &matrix, int k)
{   int L=matrix.size(),i_index=0,j_index=0,sum=0;
    if (k > L)
        return 0;
    int strip_sum[L][L];
    memset(strip_sum, 0, sizeof strip_sum); 
    for (int j = 0; j < L; j++) {
        sum = 0;
        for (int i = 0; i < k; i++)
            sum += matrix[i][j];
        strip_sum[0][j] = sum;
 
        for (int i = 1; i < L - k + 1; i++) {
            sum += (matrix[i + k - 1][j] - matrix[i - 1][j]);
            strip_sum[i][j] = sum;
        }
    }
    int max_sum = INT_MIN;
    for (int i = 0; i < L - k + 1; i++) {
        sum = 0;
        for (int j = 0; j < k; j++)
            sum +=  strip_sum[i][j];
 
        if (sum > max_sum) {
            max_sum = sum;
            i_index=i;
            j_index=0;
        }
        for (int j = 1; j < L - k + 1; j++) {
            sum += (strip_sum[i][j + k - 1]
                    - strip_sum[i][j - 1]);
 
            if (sum > max_sum) {
                max_sum = sum;
                i_index=i;
                j_index=j;
            }
        }
    }
 
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++)
            matrix[i_index+i][j_index+j]=0;
    }
    return max_sum;
}
int dfs(vector<int> &add_list,int i,int j,vector<vector<int>> &matrix)
{
    if(i<0 || i>=matrix.size() || j<0 || j>=matrix.size() || matrix[i][j]==0)
    {
        return 0;
    }
    matrix[i][j]=0;
    int count=1;
    add_list[0]=min(add_list[0],i);
    add_list[1]=min(add_list[1],j);
    add_list[2]=max(add_list[2],i);
    add_list[3]=max(add_list[3],j);
    count+=dfs(add_list,i,j+1,matrix);
    count+=dfs(add_list,i+1,j+1,matrix);
    count+=dfs(add_list,i-1,j+1,matrix);
    count+=dfs(add_list,i+1,j-1,matrix);
    return count;
}
int minimize_cost(vector<vector<int>>&matrix,int &total_1_for_max_area) {
    int x,y,L,out=0,Total_1=0,ROW=matrix.size();
    while (total_1_for_max_area>Total_1)
    {   auto mp(matrix);
        int max_area=0;
        vector<int>top_list(4,0);
        top_list[0]=ROW-1;
        top_list[1]=ROW-1;
        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<ROW;j++)
            {
                if(mp[i][j]==1)
                {
                    vector<int>add_list(4,0);
                    add_list[0]=ROW-1;
                    add_list[1]=ROW-1;
                    add_list[2]=0;
                    add_list[3]=0;
                    int count=dfs(add_list,i,j,mp);
                    if(count>max_area)
                    {
                        max_area=count;
                        top_list=add_list;
                    }
               }
            }
        }
        x=top_list[0];
        y=top_list[1];
        L=abs(max(top_list[2]-x,top_list[3]-y))+1;
        if (L>0)
           {out+=L;
            Total_1 +=MaxSumSubSquare(matrix,L);
           }
    }
    return out;
}

int solution(vector<string> &P , int L){
    vector<vector<int>> Q(L,vector<int>(L,0));
    int mini=L-1,minj=L-1,maxi=0,maxj=0,Total_sum=0;
    for(int i=0;i<L;i++)
    {
        for(int j=0;j<L;j++)
        {
            if(P[i][j]=='$')
            {
                Q[i][j]=1;
                Total_sum+=1;
               if(mini>=i)
                    mini=i;
                if(minj>=j)
                    minj=j;
                if(maxi<=i)
                    maxi=i;
               if(maxj<=j)
                    maxj=j;
            }
        }
    }
    if (Total_sum==0)
        return 0;
    else if (Total_sum==1)
        return 1;
    else if (Total_sum==2)
        return 2;
    int out=minimize_cost(Q,Total_sum);
    int out1=min(out,b_size); 
    return out1;
}
int main(){
  int L;
  cin >> L;
  vector<string> P(L,"");
  for(int i=0;i<L;i++)
  cin >> P[i];
  cout << solution(P, L) << '\n';
  return 0;
}
