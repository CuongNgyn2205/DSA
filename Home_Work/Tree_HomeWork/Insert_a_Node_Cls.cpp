/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
insert
###End banned keyword*/

#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
	}

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
//###INSERT CODE HERE -
    Node* curr = root;
    Node* p = NULL;
    while(curr){
        p = curr;
        if(data < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    Node* temp = new Node(data);
    if(!p){
        return temp;
    }
    if(data < p->data){
        p->left = temp;
    }
    else{
        p->right = temp;
    }
    return root;
}
}; 

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);

    return 0;
}