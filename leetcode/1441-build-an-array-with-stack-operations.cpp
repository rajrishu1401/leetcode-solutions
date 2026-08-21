1class Solution {
2public:
3    vector<string> buildArray(vector<int>& target, int n) {
4        int j=0;
5        vector<string> st;
6        for(int i=1;i<=n;i++){
7            if(j==target.size()){
8                return st;
9            }
10            st.push_back("Push");
11            if(target[j]!=i){
12                st.push_back("Pop");
13            }else{
14                j++;
15            }
16        }
17        return st;
18    }
19};