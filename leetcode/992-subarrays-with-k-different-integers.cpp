1class Solution {
2public:
3    int subarraysWithKDistinct(vector<int>& nums, int k) {
4        
5        return hlp(nums,k)-hlp(nums,k-1);
6    }
7
8    int hlp(vector<int>& nums, int k){
9        if(k==0){
10            return 0;
11        }
12        unordered_map<int,int> m;
13        int i=0;
14        int j=0;
15        int ans=0;
16        int u=0;
17        int l=0;
18        while(i<nums.size()){
19            if(m.size()<k||m.count(nums[i])){
20                u=i-j+1;
21                ans+=u;
22                m[nums[i]]++;
23                i++;
24            }else{
25                while(m.size()==k){
26                    m[nums[j]]--;
27                    if(m[nums[j]]==0){
28                        m.erase(nums[j]);
29                    }
30                    j++;
31                }
32            }
33        }
34        return ans;
35    }
36};