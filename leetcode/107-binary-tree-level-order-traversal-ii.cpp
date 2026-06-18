1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    vector<vector<int>> ans;
15    vector<vector<int>> levelOrderBottom(TreeNode* root) {
16        if(root==nullptr){
17            return ans;
18        }
19        queue<TreeNode*> q;
20        q.push(root);
21        hlp(q);
22        return ans;
23    }
24    void hlp(queue<TreeNode*>& q){
25        if(q.empty()){
26            return;
27        }
28        vector<int> a;
29        queue<TreeNode*> p;
30        while(!q.empty()){
31            a.push_back(q.front()->val);
32            if(q.front()->left)p.push(q.front()->left);
33            if(q.front()->right)p.push(q.front()->right);
34            q.pop();
35        }
36        hlp(p);
37        ans.push_back(a);
38    }
39};