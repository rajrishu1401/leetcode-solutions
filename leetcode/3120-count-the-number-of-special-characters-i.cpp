1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        vector<int> a(26,0);
5        int ans=0;
6        for(char i:word){
7            if(i>='A'&&i<='Z'){
8                if(a[i-'A']==0){
9                    a[i-'A']=1;
10                }else if(a[i-'A']==2){
11                    a[i-'A']=-1;
12                    ans++;
13                }
14            }else{
15                if(a[i-'a']==0){
16                    a[i-'a']=2;
17                }else if(a[i-'a']==1){
18                    a[i-'a']=-1;
19                    ans++;
20                }
21            }
22        }
23        return ans;
24    }
25};