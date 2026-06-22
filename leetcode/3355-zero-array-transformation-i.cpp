1class Solution {
2public:
3    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
4        vector<int> d(nums.size());
5        for(vector<int> i:queries){
6            d[i[0]]+=1;
7            if(i[1]<(nums.size()-1))d[i[1]+1]-=1;
8        }
9        for(int i=1;i<d.size();i++){
10            d[i]+=d[i-1];
11        }
12        for(int i=0;i<d.size();i++){
13            if(nums[i]>d[i]){
14                return false;
15            }
16        }
17        return true;
18    }
19};