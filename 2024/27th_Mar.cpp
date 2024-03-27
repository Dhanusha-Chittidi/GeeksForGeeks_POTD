/*

Author : Dhanusha Chittidi
Problem : Find shortest safe route in a matrix
Question Link(GFG) : 
Question Link(GFG) : https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1
*/
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
int dx[4]={-1, 0, 0, 1 };
int dy[4]={0, -1, 1, 0 };
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       int n=mat.size(),m=mat[0].size();
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(mat[i][j]==0){
                   for(int k=0;k<4;k++){
                       int nx=i+dx[k];
                       int ny=j+dy[k];
                       
                       if(nx>=0 && nx<n && ny>=0 && ny<m)
                          mat[nx][ny]=-1;
                   }
               }
           }
       }
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(mat[i][j]==-1) mat[i][j]=0;
           }
       }
               
       vector<vector<int>>dist(n,vector<int>(m,-1));
       queue<pair<int,int>>q;
       
       for(int i=0;i<n;i++){
            if(mat[i][0]==1){
                   q.push({i,0});
                   dist[i][0]=1;
               }
       }
       
       while(!q.empty()){
           int r=q.front().first;
           int c=q.front().second;
           q.pop();
           int d=dist[r][c];
           
           for(int k=0;k<4;k++){
                int nx=r+dx[k];
                int ny=c+dy[k];
                       
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(mat[nx][ny]==1 && dist[nx][ny]==-1){
                        q.push({nx,ny});
                        dist[nx][ny]=d+1;
                    }
                }
           }
       }
       int ans=INT_MAX;
       for(int i=0;i<n;i++){
           if(dist[i][m-1]!=-1 && mat[i][m-1]==1)
           ans=min(dist[i][m-1],ans);
       }
       return (ans==INT_MAX) ? -1 : ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
