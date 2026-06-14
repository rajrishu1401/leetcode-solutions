1class Solution {
2public:
3    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
4        unordered_set<int> n2;
5        for(int i:nums2){
6            n2.insert(i);
7        }
8        vector<vector<int>> ans(2);
9        unordered_set<int> n1;
10        for(int i:nums1){
11            if(!n1.count(i)){
12                n1.insert(i);
13                if(!n2.count(i)){
14                    ans[0].push_back(i);
15                }else{
16                    n2.erase(i);
17                }
18            }
19            
20        }
21        for(int i:n2){
22            ans[1].push_back(i);
23        }
24        return ans;
25    }
26};