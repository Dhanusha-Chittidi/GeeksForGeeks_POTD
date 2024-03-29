/*

Author : Dhanusha Chittidi
Problem :Euler Circuit in an Undirected Graph
Question Link(GFG) : https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void dfs(int node,vector<int>adj[] ,vector<int>&vis){
      vis[node]=1;
      
      for(int child: adj[node]){
          if(!vis[child])
            dfs(child,adj,vis);
      }
      
    
}
   bool isConnected(int v,vector<int>adj[] ,vector<int>&vis){
       
       int i;
       for(i=0;i<v;i++)
          if(adj[i].size()>0) break;
          
        if(i==v) return true;
        
        dfs(i,adj,vis);
        
        for(int i=0;i<v;i++){
            if(!vis[i] && adj[i].size()>0) return false;
        }
       return true;
   } 
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
	    vector<int>vis(v,0);
	    if(!isConnected(v,adj,vis)) return false;
	    
	    int oddDeg=0;
	    
	    for(int i=0;i<v;i++){
	        if(adj[i].size() & 1) oddDeg++;
	    }
	    
	    return oddDeg==0;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isEularCircuitExist(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
