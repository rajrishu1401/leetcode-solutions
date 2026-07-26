1class Solution {
2public:
3    int maximumProduct(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        int n=nums.size()-1;
6        int u=nums[0]*nums[1]*nums[n];
7        u=max(u,(nums[n-2]*nums[n-1]*nums[n]));
8        return u;
9    }
10};