1class Solution {
2public:
3    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
4        unordered_map<int,int> s[4];
5        for(int i=0;i<nums1.size();i++){
6            s[0][nums1[i]]++;
7            s[1][nums2[i]]++;
8            s[2][nums3[i]]++;
9            s[3][nums4[i]]++;
10        }
11        int ans=0;
12        for(auto i:s[0]){
13            for(auto j:s[1]){
14                for(auto k:s[2]){
15                    int a=i.first+j.first+k.first;
16                    a=-a;
17                    if(s[3].count(a)){
18                        ans+=(i.second*j.second*k.second*s[3][a]);
19                    }
20                }
21            }
22        }
23        return ans;
24    }
25};