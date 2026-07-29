1class Solution {
2public:
3    int minLength(vector<int>& nums, int k) {
4        unordered_map<int,int> m;
5        int j=0;
6        int i=0;
7        int su=0;
8        int l=INT_MAX;
9        while(i<nums.size()){
10            if(m[nums[i]]){
11                m[nums[i]]++;
12                i++;
13                continue;
14            }
15            su+=nums[i];
16            m[nums[i]]++;
17            i++;
18            while(su>=k){
19                l=min(i-j,l);
20                m[nums[j]]--;
21                if(m[nums[j]]==0){
22                    su-=nums[j];
23                }
24                j++;
25            }
26        }
27        if(l==INT_MAX){
28            return -1;
29        }
30        return l;
31    }
32};