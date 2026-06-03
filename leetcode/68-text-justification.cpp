1class Solution {
2public:
3    vector<string> fullJustify(vector<string>& words, int maxWidth) {
4        string s="";
5        vector<string> ans;
6        int c=maxWidth;
7        vector<string> hlp;
8        for(int u=0;u<words.size();u++){
9            string h=words[u];
10            if((int)h.size()<=c){
11                hlp.push_back(h+" ");
12                c-=h.size();
13                c--;
14            }else{
15                string r=hlp.back();
16                r=r.substr(0,r.size()-1);
17                c++;
18                hlp.pop_back();
19                if(hlp.size()==0){
20                    while(c>0){
21                        r+=" ";
22                        c--;
23                    }
24                    ans.push_back(r);
25                }else{
26                    int p=0;
27                    while(c>0){
28                        c--;
29                        hlp[p]+=" ";
30                        p++;
31                        p%=hlp.size();
32                    }
33                    string y="";
34                    for(string l:hlp){
35                        y+=l;
36                    }
37                    y+=r;
38                    ans.push_back(y);
39                }
40                c=maxWidth;
41                hlp=vector<string>();
42                u--;
43            }
44        }
45        string r=hlp.back();
46        r=r.substr(0,r.size()-1);
47        c++;
48        hlp.pop_back();
49        while(c>0){
50            r+=" ";
51            c--;
52        }
53        string y="";
54        for(string l:hlp){
55            y+=l;
56        }
57        y+=r;
58        ans.push_back(y);
59        return ans;
60    }
61};