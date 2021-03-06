// GFG PROBLEM
// https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/


#include<bits/stdc++.h>
using namespace std;

 typedef struct Node{
     Node* left;
     Node* right;
     int data;
     Node(int x){
        data = x;
        left = right = NULL;
    }

    
}Node;



map<int, vector<int> > distance_map;

void preOrderDistance(Node *tree,int distance){
    if(tree){
        distance_map[distance].push_back(tree->data);
        preOrderDistance(tree->left,distance+1);
        preOrderDistance(tree->right,distance);
    }
}
vector< vector<int> >  dagonalTraversal(Node* tree){

    vector<vector<int> > ans;
    preOrderDistance(tree,0);
    for (auto i = distance_map.begin(); i != distance_map.end(); i++) {
        vector<int> row;
        vector<int> temp = i->second;
        for(auto it:temp)
          row.push_back(it);
        ans.push_back(row);
    }

    return ans;
} 

int main(){
    int n;
    cin>>n;
    vector<int> vct(n);

    for(int i = 0;i<n;i++){
        cin>>vct[i];
    }
    queue<Node*> queue;

    Node *tree = new Node(vct[0]);
    queue.push(tree);
    bool flag = false;

    for(int i = 1;i<n;i+=2){
        Node* prev_node = queue.front();
        if(vct[i]!=0){
            // cout<<" Node "<<vct[i]<<" left"<<endl;
            Node* left = new Node(vct[i]);
            prev_node->left = left;
            queue.push(left);
        }
        if(i+1<=n-1 && vct[i+1]!=0){
            // cout<<" Node "<<vct[i+1]<<" right"<<endl;
            Node* right = new Node(vct[i+1]);
            prev_node->right = right;
            queue.push(right);
        }
        queue.pop();
    }

    cout<<"Diagonal Order Traversal: \n";
    vector<vector<int> > ans = dagonalTraversal(tree);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}