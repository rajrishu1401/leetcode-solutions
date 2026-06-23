1class Solution {
2public:
3    int findLengthOfLCIS(vector<int>& nums) {
4        int u=1;
5        int ans=0;
6        for(int i=1;i<nums.size();i++){
7            if(nums[i]>nums[i-1]){
8                u++;
9            }else{
10                ans=max(ans,u);
11                u=1;
12            }
13        }
14        ans=max(ans,u);
15        return ans;
16    }
17};