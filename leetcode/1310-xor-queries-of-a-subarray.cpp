1class Solution {
2public:
3    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
4        for(int i=1;i<arr.size();i++){
5            arr[i]^=arr[i-1];
6        }
7        vector<int> ans;
8        for(vector<int> t:queries){
9            if(t[0]==0){
10                ans.push_back(arr[t[1]]);
11            }else{
12                ans.push_back(arr[t[1]]^arr[t[0]-1]);
13            }
14        }
15        return ans;
16    }
17};