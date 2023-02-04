//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  Node* x=NULL;
  void mark(unordered_map<Node*,Node*> &TR,Node* root){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* t = q.front();
            q.pop();
            if(t->left){
                TR[t->left]=t;
                q.push(t->left);
            }
            if(t->right){
                TR[t->right]=t;
                q.push(t->right);
            }
        }
        return;

    }
        Node* fnd(Node* root,int start){
        if(root!=NULL){
            //cout<<root->val<<"-n";
            if(root->data==start){
                x=root;
                return root;
            }
            Node* l = fnd(root->left,start);
            if(l==NULL){
                Node* l = fnd(root->right,start);
            }
            return l;
        }else{
            return NULL;
        }
        
    }
    int minTime(Node* root, int start) 
    {
int count=0;
    unordered_map<Node*,Node*> TR;
    mark(TR,root);
    queue<Node*> q;
    unordered_map<Node*,bool> visited;
    
    Node* st = fnd(root,start);
    //cout<<x->val;
    q.push(x);
    visited[x]=true;
    //int count=0;
    while(!q.empty()){
        int siz = q.size();
        count++;
        //cout<<siz<<endl;
        for(int i=0;i<siz;i++){
            Node* t = q.front();
            q.pop();
            //cout<<t->val<<endl;
            if(t->right && !visited[t->right]){
                q.push(t->right);
                visited[t->right]=true;
            }
            if(t->left && !visited[t->left]){
                q.push(t->left);
                visited[t->left]=true;
            }
            if(TR[t] && !visited[TR[t]]){
                q.push(TR[t]);
                visited[TR[t]]=true;
            }

        }
    }
    
    return count-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends