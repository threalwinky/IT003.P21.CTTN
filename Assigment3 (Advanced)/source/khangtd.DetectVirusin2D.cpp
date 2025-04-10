#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 1e6 + 9;
const int N2 = N * 10;
const int mod = 1e9 + 7;
const int inf = LLONG_MAX;

class AhoCorasick {
    private:
        struct Node {
            unordered_map<char, Node*> children;
            Node* fail = nullptr;
            vector<string> outputs;
        };
    
        Node* root;
    
    public:
        AhoCorasick() {
            root = new Node();
        }
    
    void addWord(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->children.count(ch))
                node->children[ch] = new Node();
            node = node->children[ch];
        }
        node->outputs.push_back(word);
    }

    void build() {
        queue<Node*> q;
        root->fail = root;
        for (auto& [ch, node] : root->children) {
            node->fail = root;
            q.push(node);
        }

        while (!q.empty()) {
            Node* current = q.front(); q.pop();
            for (auto& [ch, child] : current->children) {
                Node* fallback = current->fail;
                while (fallback != root && !fallback->children.count(ch)) {
                    fallback = fallback->fail;
                }
                if (fallback->children.count(ch) && fallback->children[ch] != child) {
                    child->fail = fallback->children[ch];
                } else {
                    child->fail = root;
                }
                child->outputs.insert(child->outputs.end(),
                                        child->fail->outputs.begin(),
                                        child->fail->outputs.end());
                q.push(child);
            }
        }
    }

    vector<pair<int, string>> search(const string& text) {
        vector<pair<int, string>> results;
        Node* node = root;

        for (int i = 0; i < text.size(); ++i) {
            char ch = text[i];
            while (node != root && !node->children.count(ch)) {
                node = node->fail;
            }
            if (node->children.count(ch)) {
                node = node->children[ch];
            }
            for (const string& match : node->outputs) {
                results.emplace_back(i - match.size() + 1, match);
            }
        }
        return results;
    }

    ~AhoCorasick() {
        destroy(root);
    }

private:
    void destroy(Node* node) {
        for (auto& [ch, child] : node->children) {
            destroy(child);
        }
        delete node;
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<char>> a(n + 5, vector<char>(m + 5));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    vector<string> patt;
    while (q--){
        string x;
        cin >> x;
        patt.push_back(x);
    }
    string s1 = "", s2 = "";
    for (int i=0; i<n; i++){
        string s = "";
        for (int j=0; j<m; j++){
            s += a[i][j];
        }
        s1 += s + "$hehe$";
    }
    for (int i=0; i<m; i++){
        string s = "";
        for (int j=0; j<n; j++){
            s += a[j][i];
        }
        s2 += s + "$hehe$";
    }
    AhoCorasick ac1;
    AhoCorasick ac2;
    for (const auto& p : patt) {
        ac1.addWord(p);
        ac2.addWord(p);
    }
    ac1.build();
    ac2.build();
    map<string, int> mp;

    auto matches1 = ac1.search(s1);
    for (auto& [pos, pattern] : matches1) {
        mp[pattern]=1;
    }

    auto matches2 = ac2.search(s2);
    for (auto& [pos, pattern] : matches2) {
        mp[pattern]=1;
    }
    for (auto it : patt){
        if (mp[it]){
            cout << 1;
        }
        else cout << 0;
    }
}
