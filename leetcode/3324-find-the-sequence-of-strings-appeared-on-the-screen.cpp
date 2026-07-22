1class Solution {
2public:
3    vector<string> stringSequence(string target) {
4        string s="a";
5        s[0]-=1;
6        int j=0;
7        vector<string> ans;
8        for(char i:target){
9            while(i!=s[j]){
10                s[j]+=1;
11                ans.push_back(s);
12            }
13            s+=('a'-1);
14            j++;
15        }
16        return ans;
17    }
18};