1class Solution {
2public:
3    string findLongestWord(string s, vector<string>& dic) {
4        sort(dic.begin(),dic.end(),[](string& a,string& b){
5            if(a.size()==b.size()){
6                return a<b;
7            }
8            return a.size()>b.size();
9        });
10        
11        for(string i:dic){
12            int k=0;
13            for(int j=0;j<s.size();j++){
14                if(i[k]==s[j]){
15                    k++;
16                    if(k==i.size()){
17                        return i;
18                    }
19                }
20            }
21            
22        }
23        return "";
24    }
25};