1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        string ans="";
5        for(string i:words){
6            int u=0;
7            for(char j:i){
8                u+=weights[j-'a'];
9            }
10            u%=26;
11            u=25-u;
12            ans+=(u+'a');
13        }
14        return ans;
15    }
16};