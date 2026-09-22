1class Solution {
2public:
3    vector<int> findArray(vector<int>& pref) {
4        int u=0;
5        vector<int> v(pref.size());
6        for(int i=v.size()-2;i>=0;i--){
7            v[i+1]=pref[i]^pref[i+1];
8        }
9        v[0]=pref[0];
10        return v;
11    }
12};