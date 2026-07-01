1class Solution {
2public:
3    // struct trie{
4    //     trie* ch[26]={nullptr};
5    //     bool isEnd=false;
6    // };
7    // trie* start;
8    // void inst(string s,int j){
9    //     trie* curr=start;
10    //     for(char i:s){
11    //         if(curr->ch[i-'a']==nullptr){
12    //             curr->ch[i-'a']=new trie();
13    //         }
14    //         curr=curr->ch[i-'a'];
15    //     }
16    //     curr->isEnd=ture;
17    // }
18    vector<string> topKFrequent(vector<string>& words, int k) {
19        unordered_map<string,int> m;
20        for(int i=0;i<words.size();i++){
21            m[words[i]]++;
22        }
23        auto cmp=[](const pair<int,string>& a, const pair<int,string>& b) {
24            if (a.first == b.first){
25                return a.second<b.second;
26            }
27            return a.first > b.first;
28        };
29        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(cmp)> q(cmp);
30        for(auto t:m){
31            if(k){
32                q.push({t.second,t.first});
33                k--;
34            }else{
35                if(q.top().first<t.second){
36                    q.pop();
37                    q.push({t.second,t.first});
38                }else if(q.top().first==t.second&&q.top().second>t.first){
39                    q.pop();
40                    q.push({t.second,t.first});
41                }
42            }
43        }
44        vector<string> ans(q.size());
45        int i=ans.size()-1;
46        while(!q.empty()){
47            ans[i]=q.top().second;
48            i--;
49            q.pop();
50        }
51        return ans;
52    }
53};