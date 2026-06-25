1class Solution {
2public:
3    int combinationSum4(vector<int>& nums, int target) {
4        vector<long long> dp(target+1);
5        dp[0]=1;
6        for(int i=1;i<=target;i++){
7            long long count=0;
8            for(int j=0;j<nums.size();j++){
9                if(i>=nums[j]){
10                    count+=dp[i-nums[j]];
11                    if(count>INT_MAX){
12                        break;
13                    }
14                }
15            }
16            dp[i]=count;
17        }
18        return dp[target];
19    }
20};