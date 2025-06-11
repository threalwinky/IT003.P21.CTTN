
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
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {

        Node* cur = root;
        queue<pair<Node*, int>> q;
        q.push({cur, 1});
        int maxHeight = 0;
        while(!q.empty()) {
            pair<Node*, int> p = q.front();
            maxHeight = max(maxHeight, p.second);
            q.pop();
            Node* node = p.first;
            int height = p.second;
            if (node->left != NULL) {
                q.push({node->left, height + 1});
            }
            if (node->right != NULL) {
                q.push({node->right, height + 1});
            }
        }
        return maxHeight;
    }

}; //End of Solution

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
  
    int height = myTree.height(root);
    
  	std::cout << height;

    return 0;
}



