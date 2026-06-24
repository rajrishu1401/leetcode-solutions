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
14    TreeNode* reverseOddLevels(TreeNode* root) {
15        queue<TreeNode*> q;
16        if(root==nullptr) return root;
17        q.push(root);
18        int i=1;
19        while(!q.empty()){
20            queue<TreeNode*> p;
21            vector<TreeNode*> t;
22            while(!q.empty()){
23                TreeNode* u=q.front();
24                q.pop();
25                if(u->left){
26                    if(i&1){
27                        t.push_back(u->left);
28                        t.push_back(u->right);
29                    }
30                    p.push(u->left);
31                    p.push(u->right);
32                }
33            }
34            if(i&1){
35                int j=0;
36                int e=t.size()-1;
37                while(j<e){
38                    int o=t[j]->val;
39                    t[j]->val=t[e]->val;
40                    t[e]->val=o;
41                    j++;
42                    e--;
43                }
44            }
45            q=move(p);
46            i++;
47        }
48        return root;
49        
50    }
51};