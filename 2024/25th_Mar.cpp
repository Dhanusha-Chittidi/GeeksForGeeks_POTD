/*

Author : Dhanusha Chittidi
Problem : Print N-bit binary numbers having more 1s than 0s
Question Link(GFG) : https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void helper(string s,int extraones,int n,vector<string>&ans){
        if(n==0){
            ans.push_back(s);
            return;
        }
        
        helper(s+"1",extraones+1,n-1,ans);
        
        if(extraones>0)
           helper(s+"0",extraones-1,n-1,ans);
           
        
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    
	    vector<string>ans;
	    
	    helper("",0,n,ans);
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends