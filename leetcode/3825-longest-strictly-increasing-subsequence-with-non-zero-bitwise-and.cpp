1class Solution {
2public:
3    int longestSubsequence(vector<int>& nums) {
4        int ans=0;
5        for(int b=0;b<=30;b++){
6            int y=pow(2,b);
7            vector<int> t;
8            t.push_back(-1);
9            for(int i=0;i<nums.size();i++){
10                if(y&nums[i]){
11                    if(nums[i]>t[t.size()-1]){
12                        t.push_back(nums[i]);
13                    }else{
14                        int u=bs(t,nums[i]);
15                        t[u]=nums[i];
16                    }
17                }
18            }
19            ans=max(ans,(int)t.size()-1);
20        }
21        return ans;
22    }
23
24    int bs(vector<int>& t,int tar){
25        int s=0;
26        int e=t.size();
27        while(s<e){
28            int mid=(s+e)/2;
29            if(t[mid]>=tar){
30                e=mid;
31            }else{
32                s=mid+1;
33            }
34        }
35        return s;
36    }
37};