1class Solution {
2public:
3    struct trie{
4        trie* ar[26]={nullptr};
5        vector<int> idx;
6    };
7    trie* start;
8    void insert(string s,int id){
9        trie* curr=start;
10        for(char i:s){
11            if(curr->ar[i-'a']==nullptr){
12                curr->ar[i-'a']=new trie();
13            }
14            curr=curr->ar[i-'a'];
15            curr->idx.push_back(id);
16        }
17    }
18    vector<vector<string>> ans;
19    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
20        start=new trie();
21        for(int i=0;i<products.size();i++){
22            insert(products[i],i);
23        }
24        hlp(searchWord,products);
25        while(ans.size()<searchWord.size()){
26            ans.push_back({});
27        }
28        return ans;
29
30    }
31
32    void hlp(string s,vector<string>& p){
33        trie* curr=start;
34        for(char i:s){
35            if(curr->ar[i-'a']==nullptr){
36                return;
37            }
38            curr=curr->ar[i-'a'];
39            priority_queue<string> q;
40            for(int j:curr->idx){
41                q.push(p[j]);
42                if(q.size()>3){
43                    q.pop();
44                }
45            }
46            vector<string> g;
47            while(!q.empty()){
48                g.push_back(q.top());
49                q.pop();
50            }
51            reverse(g.begin(),g.end());
52            ans.push_back(g);
53        }
54    }
55
56};