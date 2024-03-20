/*

Author : Dhanusha Chittidi
Problem : Possible Paths in a Tree
Question Link(GFG) : https://www.geeksforgeeks.org/problems/possible-paths--141628/1


*/


//User function template for C++

class Solution{
	public:
	int ans=0;
	int find(int a,vector<int>&parent,vector<int>&size){
	    if(a== parent[a]) return a;
	    return parent[a]=find(parent[a],parent,size);
	}
	int Union(int a,int b,vector<int>&parent,vector<int>&size){
	    
	    int rootA=find(a,parent,size);
	    int rootB=find(b,parent,size);
	    
	    ans+=size[rootA]*size[rootB];
	    
	    if(size[rootA]< size[rootB]) {
	        parent[rootA]=rootB;
	        size[rootB]+=size[rootA];
	    }else{
	        parent[rootB]=rootA;
	        size[rootA]+=size[rootB];
	    }
	   // cout<<ans<<" ";
	   return ans;
	}
	vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
	{
	    // code here
	    ans=0;
	    vector<int>parent(n+1),size(n+1,1);
	    vector<int>res;
	    
	    for(int i=0;i<=n;i++){
	        parent[i]=i;
	    }
	    
	    map<int,int>m;
	    
	    sort(edges.begin(),edges.end(),[](vector<int>&edge1,vector<int>&edge2){
	         return edge1[2]<edge2[2];
	    });
	    
	    for(auto x : edges){
	        
	         m[x[2]]=Union(x[0],x[1],parent,size);
	        
	    }
	    
	    for(int que : queries){
	        
	        int maxm=0;
	        for(auto it=m.begin();it!=m.end();++it){
	            
	            if(it->first<=que) maxm=it->second;
	            else break;
	        }
	        res.push_back(maxm);
	    }
	    return res;
	}
};
