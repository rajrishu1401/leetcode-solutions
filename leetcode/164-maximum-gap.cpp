1class Solution {
2public:
3    int maximumGap(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        int ans=0;
6        for(int i=1;i<nums.size();i++){
7            ans=max(nums[i]-nums[i-1],ans);
8        }
9        return ans;
10    }
11};