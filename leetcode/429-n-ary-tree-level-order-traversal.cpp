1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> children;
7
8    Node() {}
9
10    Node(int _val) {
11        val = _val;
12    }
13
14    Node(int _val, vector<Node*> _children) {
15        val = _val;
16        children = _children;
17    }
18};
19*/
20
21class Solution {
22public:
23    vector<vector<int>> levelOrder(Node* root) {
24        if(root==nullptr){
25            return {};
26        }
27        queue<Node*> q;
28        vector<vector<int>> ans;
29        q.push(root);
30        while(!q.empty()){
31            queue<Node*> p;
32            vector<int> a;
33            while(!q.empty()){
34                Node* h=q.front();
35                q.pop();
36                a.push_back(h->val);
37                for(Node* i:h->children){
38                    if(i){
39                        p.push(i);
40                    }
41                }
42            }
43            q=move(p);
44            ans.push_back(a);
45        }
46        return ans;
47    }
48};