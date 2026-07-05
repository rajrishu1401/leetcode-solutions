1class Solution {
2public:
3    struct trie{
4        trie* ch[26]={nullptr};
5        bool isEnd=false;
6    };
7    trie* start;
8    vector<string> ans;
9    void insert(string s){
10        trie* curr=start;
11        for(char i:s){
12            if(curr->ch[i-'a']==nullptr){
13                curr->ch[i-'a']=new trie();
14            }
15            curr=curr->ch[i-'a'];
16        }
17        curr->isEnd=true;
18    }
19    void hlp(string& s,string& u,int i,trie* curr){
20        if(i>=s.size()&&!curr->isEnd){
21            return;
22        }
23        if(curr->isEnd){
24            if(i>=s.size()){
25                ans.push_back(u);
26                return;
27            }
28            u+=" ";
29            hlp(s,u,i,start);
30            u.pop_back();
31        }
32    
33        if(curr->ch[s[i]-'a']){
34            u+=s[i];
35            hlp(s,u,i+1,curr->ch[s[i]-'a']);
36            u.pop_back();
37        }
38        
39    }
40    vector<string> wordBreak(string s, vector<string>& w) {
41        start=new trie();
42        for(int i=0;i<w.size();i++){
43            insert(w[i]);
44        }
45        string u="";
46        hlp(s,u,0,start);
47        return ans;
48    }
49};