#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

map<int, int> check;

struct Node{
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

struct BST{
    Node *root;
    
    BST() : root(NULL) {}

    void insert(int x){
        if (root == NULL){
            root = new Node(x);
        } else {
            insertHelper(root, x);
        }
    }

    void insertHelper(Node *node, int x){
        if (x <= node->data){
            if (node->left == NULL){
                node->left = new Node(x);
            } else {
                insertHelper(node->left, x);
            }
        } else {
            if (node->right == NULL){
                node->right = new Node(x);
            } else {
                insertHelper(node->right, x);
            }
        }
    }

    void printRoot(){
        if (root != NULL){
            cout << root->data << endl;
        } else {
            cout << "Tree is empty" << endl;
        }
    }

    void traverseFromRoot(){
        if (root == NULL) return;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()){
            pair<Node*, int> p = q.front();
            Node *current = p.first;
            int level = p.second;
            if (check[level] == 0){
                // cout << current->data << " " << level << "\n";
                check[level] = current -> data; // Mark this level as visited
            }
            q.pop();
            if (current->right != NULL) q.push({current->right, level + 1});
            if (current->left != NULL) q.push({current->left, level - 1});
        }
    }

};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}

    int n;
    cin >> n;
    
    BST tree;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree.insert(x);
    }
    // tree.printRoot();
    tree.traverseFromRoot();
    vector<int> levels;
    for (auto it : check){
        levels.push_back(it.second);
    }
    sort(levels.begin(), levels.end());
    for (int i = 0; i < levels.size(); i++){
        cout << levels[i] << " ";
    }
}