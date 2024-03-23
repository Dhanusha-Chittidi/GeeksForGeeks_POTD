/*

Author : Dhanusha Chittidi
Problem : Fibonacci series up to Nth term
Question Link(GFG) : https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    const int mod=1e9+7;
    
    vector<int> Series(int n) {
        // Code here
        vector<int>fibonacci(n+1);
        
        int x=0,y=1;
        int cnt=2;
        fibonacci[0]=x;
        fibonacci[1]=y;
        while(cnt<=n){
            int nxt=(x+y)%mod;
            fibonacci[cnt]=nxt;
            
            x=y;
            y=nxt;
            cnt++;
        }
        return fibonacci;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends