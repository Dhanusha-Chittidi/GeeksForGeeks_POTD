
/*

Author : Dhanusha Chittidi
Problem : Diagonal sum in binary tree
Question Link(GFG) :https://www.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1
*/
/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/

class Solution
{
    public:
    vector <int> diagonalSum(Node* root) {
        // Add your code here
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size(),sum=0;
            
            for(int i=0;i<n;i++){
                Node* node=q.front();
                q.pop();
                
                sum+=node->data;
                if(node->left)q.push(node->left);
                
                Node* temp=node;
                while(temp->right){
                    if(temp->right->left) q.push(temp->right->left);
                    sum+=temp->right->data;
                    temp=temp->right;
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};