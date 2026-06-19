1class Solution {
2public:
3    struct trie{
4        trie* ch[26]={nullptr};
5        bool isEnd=false;
6    };
7    trie* start;
8    vector<bool> dp;
9    void insert(string s){
10        trie* curr=start;
11        
12        for(char i:s){
13            int u=i-'a';
14            if(curr->ch[u]==nullptr){
15                curr->ch[u]=new trie();
16            }
17            curr=curr->ch[u];
18        }
19        curr->isEnd=true;
20    }
21    bool hlp(string& s,int i){
22        if(!dp[i]){
23            return false;
24        }
25        trie* curr=start;
26        for(; i<s.size();i++){
27            int u=s[i]-'a';
28            if(curr->ch[u]==nullptr){
29                return false;
30            }
31            curr=curr->ch[u];
32            if(curr->isEnd==true){
33                if(i==s.size()-1){
34                    return true;
35                }
36                if(hlp(s,i+1)){
37                    return true;
38                }
39                dp[i+1]=false;
40            }
41        }
42        return false;
43    }
44    bool wordBreak(string s, vector<string>& wordDict) {
45        dp.resize(s.size(),true);
46        start=new trie();
47        for(string i:wordDict){
48            insert(i);
49        }
50        return hlp(s,0);
51            
52    }
53};