/*

Author : Dhanusha Chittidi
Problem : City With the Smallest Number of Neighbors at a Threshold Distance
Question Link(GFG) : https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {   
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        vector<vector<int>>dist(n,vector<int>(n,distanceThreshold+1));
        
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        
        for(int i=0;i<m;i++){
            int v1=edges[i][0];
            int v2=edges[i][1];
            int w=edges[i][2];
            
            dist[v1][v2]=w;
            dist[v2][v1]=w;
            
            
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }

        }
        int minCities=INT_MAX,ans=0;
        
        for(int v=0;v<n;v++){
            int cities=0;
            for(int u=0;u<n;u++){
                if(dist[v][u]<=distanceThreshold) cities++;
            }
            if(cities<=minCities){
              ans=v;
              minCities=cities;
            }
            
        }
        return ans;
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends
