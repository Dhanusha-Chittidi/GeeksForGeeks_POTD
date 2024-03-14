/*

Author : Dhanusha Chittidi
Problem : Largest subsquare surrounded by X
Question Link(GFG) : https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1


*/
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    
    
    int largestSubsquare(int n, vector<vector<char>>a) {
        // code here
        
        vector<vector<pair<int,int>>>dp(n+1,vector<pair<int,int>>(n+1)); // for storing horizontal and vertical values

        int x=0,y=0;
        for(int i=0;i<n;i++){
            x=0;
            for(int j=0;j<n;j++){
                if(a[i][j]=='X')
                  ++x;
                else
                  x=0;
                dp[i][j].first=x;
                
            }
        }
        
         for(int i=0;i<n;i++){
            y=0;
            for(int j=0;j<n;j++){
                if(a[j][i]=='X')
                  ++y;
                else
                  y=0;
                dp[j][i].second=y;
                
            }
        }
        
        int max=0,val=0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                
                val=min(dp[i][j].first,dp[i][j].second);
                
                while(val>max){
                   if(dp[i-val+1][j].first>=val && dp[i][j-val+1].second>=val)
                        max=val;
                
                   val--;  

            }
        }
        }
        
        return max;
       
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends