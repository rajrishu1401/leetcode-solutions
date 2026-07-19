1class Solution {
2public:
3    string removeDuplicateLetters(string s) {
4        unordered_set<char> m;
5        vector<int> v(26);
6        for(int i=0;i<s.size();i++){
7            v[s[i]-'a']=i;
8        }
9        stack<char> st;
10        for(int i=0;i<s.size();i++){
11            if(!m.count(s[i])){
12                m.insert(s[i]);
13                while(!st.empty()&&st.top()>s[i]&&(v[st.top()-'a'])>i){
14                    m.erase(st.top());
15                    st.pop();
16                }
17                st.push(s[i]);
18            }
19        }
20        string r(st.size(),'*');
21        int i=r.size()-1;
22        while(i>=0){
23            r[i]=st.top();
24            i--;
25            st.pop();
26        }
27        
28        return r;
29    }
30};