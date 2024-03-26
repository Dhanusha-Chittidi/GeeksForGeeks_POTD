/*

Author : Dhanusha Chittidi
Problem : Additive sequence
Question Link(Leetcode) : https://www.geeksforgeeks.org/problems/additive-sequence/1
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
  int value(string a,int pos){
      if(pos>=a.size()) return 0;
      return a[pos]-'0';
  }
   string add(string a ,string b){
       string sum="";
       int carry=0;
       int i=a.size()-1,j=b.size()-1;
       while(i>=0 || j>=0){
           int val=value(a,i)+value(b,j)+carry;
           sum+=(val%10+'0');
           carry=val/10;
           i--;
           j--;
       }
       if(carry){
           sum+=(carry+'0');
       }
       reverse(sum.begin(),sum.end());
       return sum;
   }
   
   bool check(string a, string b, string rem){
       if((a.size()>1 && a[0]=='0') || (b.size()>1 && b[0]=='0'))
           return false;
           
        string sum=add(a,b);
        
        if(sum==rem) return true;
        
        if( rem.size()<= sum.size() || rem.substr(0,sum.size())!=sum) return false;
        else
          return check(b,sum,rem.substr(sum.size()));
   }
   
    bool isAdditiveSequence(string n) {
        // Your code here
        int l=n.size();
        for(int i=1;i<=l/2;i++){
            for(int j=1;j<=(l-i)/2;j++){
                if(check(n.substr(0,i),n.substr(i,j),n.substr(i+j)))return true;
            }
        }
        return false;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends
