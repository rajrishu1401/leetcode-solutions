1class Solution {
2public:
3    int numOfStrings(vector<string>& patterns, string word) {
4        int ans=0;
5        for(string s:patterns){
6            if(word.contains(s)){
7                ans++;
8            }
9        }
10        return ans;
11    }
12};