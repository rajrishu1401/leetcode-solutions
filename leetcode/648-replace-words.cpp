1
2class Solution {
3public:
4struct trie{
5    trie* ch[26]={nullptr};
6    int isEnd=-1;
7};
8    trie* start;
9    void inst(string s,int j){
10        trie* curr=start;
11        for(char i:s){
12            if(curr->ch[i-'a']==nullptr){
13                curr->ch[i-'a']=new trie();
14            }
15            curr=curr->ch[i-'a'];
16        }
17        curr->isEnd=j;
18    }
19    string ans="";
20    void hlp(string s,vector<string>& d){
21        trie* curr=start;
22        if(ans.size()>0){
23            ans+=" ";
24        }
25        for(char i:s){
26            if(curr->ch[i-'a']==nullptr){
27                ans+=s;
28                return;
29            }
30            curr=curr->ch[i-'a'];
31            if(curr->isEnd>=0){
32                ans+=d[curr->isEnd];
33                return;
34            }
35        }
36        ans+=s;
37    }
38    string replaceWords(vector<string>& d, string sentence) {
39        start=new trie();
40        for(int i=0;i<d.size();i++){
41            inst(d[i],i);
42        }
43        stringstream ss(sentence);
44        string u;
45        while(ss>>u){
46            hlp(u,d);
47        }
48        return ans;
49    }
50};