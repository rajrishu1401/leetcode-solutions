1class Solution {
2public:
3    int minOperations(vector<int>& nums, int k) {
4        int x=0;
5        for(int i:nums){
6            x=x^i;
7        }
8        x=k^x;
9        return __builtin_popcount(x);
10    }
11};