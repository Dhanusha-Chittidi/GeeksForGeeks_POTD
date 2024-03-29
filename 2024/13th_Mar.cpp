/*

Author : Dhanusha Chittidi
Problem : Print matrix in diagonal pattern
Question Link(GFG) : https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1


*/

//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         vector<int>ans;
         int elements=0,n=mat.size();
         int i=0,j=0;
         int dir=1; // 1 for up and 0 for down
         
         while(elements<n*n){
             
             if(dir){ // For  up diagonal traversal
             
                 while(i>-1 and j<n){
                   ans.push_back(mat[i][j]);
                   elements++;
                   i--,j++;
                  
                 }
                 if(i<0 and j<n) i=0;
                 if(j==n) j=n-1,i+=2;
                 
              }else{   //For Down Diagaonal traversal
              
                  while(j>-1 and i<n){
                   ans.push_back(mat[i][j]);
                   j--,i++;
                   elements++;
                  }
                 
                 if(j<0 and i<n) j=0;
                 if(i==n) i=n-1,j+=2; 
                  
              }
              dir=!dir;
         }
         return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends