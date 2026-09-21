1class Solution {
2public:
3    int maxAbsoluteSum(vector<int>& nums) {
4        int ans=0;
5        int curr=0;
6        for(int i=0;i<nums.size();i++){
7            curr+=nums[i];
8            if(curr<0){
9                curr=0;
10            }
11            ans=max(ans,curr);
12        }
13        curr=0;
14        for(int i=0;i<nums.size();i++){
15            curr+=nums[i];
16            if(curr>0){
17                curr=0;
18            }
19            ans=max(ans,-curr);
20        }
21        return ans;
22    }
23};