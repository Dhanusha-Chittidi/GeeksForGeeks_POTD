/*

Author : Dhanusha Chittidi
Problem : Linked List that is Sorted Alternatingly
Question Link(GFG) : https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1


*/



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    
    // Reversing a Linked List
    Node* rev(Node* head){
        Node* cur=head;
        Node* nxt=NULL,*prev=NULL;
        
        while(cur){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
    
    //Merging the splitted Linked lists recursively
    Node* mergeLL(Node* head1,Node* head2){
        if(!head1) return head2;
        
        if(!head2) return head1;
        
        Node* temp;
        if(head1->data < head2->data){
            temp=head1;
            head1->next=mergeLL(head1->next,head2);
        }else{
            temp=head2;
            head2->next=mergeLL(head1,head2->next);
        }
        
        return temp;
    }
    
    void sort(Node **head)
    {
         // Code here
         Node *head1,*head2,*cur=*head;
         
         head1=new Node(0); //creating two dummy nodes
         head2=new Node(0); //for storing splitted linked Lists
         
         Node* as=head1,*ds=head2; // temporary nodes to traverse the given linked list 
         
         while(cur){      //splitting int two linkedlists
            as->next=cur;
            as=as->next;
            cur=cur->next;
          if(cur){
            ds->next=cur;
            ds=ds->next;
            cur=cur->next;
           }
         }
         as->next=NULL;
         ds->next=NULL;
         
         head1=head1->next;
         head2=head2->next;
         
         head2=rev(head2);
         
         *head=mergeLL(head1,head2);  //merging
         
         
         
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends