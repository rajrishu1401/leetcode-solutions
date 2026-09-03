1class Solution {
2public:
3    bool uniformArray(vector<int>& nums1) {
4        bool y=true;
5        int b=INT_MAX;
6        for(int i:nums1){
7            if(i%2==1){
8                y=false;
9            }
10            b=min(b,i);
11        }
12        if(y){
13            return true;
14        }
15        if(b%2==0){
16            return false;
17        }
18        return true;
19    }
20};