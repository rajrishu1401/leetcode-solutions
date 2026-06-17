1class Solution {
2public:
3    vector<int> countBits(int n) {
4        vector<int> ans;
5        for(int i=0;i<=n;i++){
6            ans.push_back(__builtin_popcount(i));
7        }
8        return ans;
9    }
10};