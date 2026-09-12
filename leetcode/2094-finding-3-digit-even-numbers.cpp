1class Solution {
2public:
3    unordered_set<string> st;
4    vector<int> ans;
5    vector<int> findEvenNumbers(vector<int>& digits) {
6        hlp(digits,"aaa",0,0);
7        sort(ans.begin(),ans.end());
8        return ans;
9    }
10    void hlp(vector<int>& digits,string s,int i,int y){
11        if(i>=digits.size()){
12            return;
13        }
14        hlp(digits,s,i+1,y);
15        if(digits[i]!=0&&s[0]=='a'){
16            s[0]=digits[i]+'0';
17            if(y==2){
18                if(!st.count(s)){
19                    ans.push_back(stoi(s));
20                    st.insert(s);
21                }
22            }else{
23                hlp(digits,s,i+1,y+1);
24            }
25            s[0]='a';
26        }
27        if(s[1]=='a'){
28            s[1]=digits[i]+'0';
29            if(y==2){
30                if(!st.count(s)){
31                    ans.push_back(stoi(s));
32                    st.insert(s);
33                }
34            }else{
35                hlp(digits,s,i+1,y+1);
36            }
37            s[1]='a';
38        }
39        if(digits[i]%2==0){
40            if(s[2]=='a'){
41                s[2]=digits[i]+'0';
42                if(y==2){
43                    if(!st.count(s)){
44                        ans.push_back(stoi(s));
45                        st.insert(s);
46                    }
47                }else{
48                    hlp(digits,s,i+1,y+1);
49                }
50                s[2]='a';
51            }
52        }
53    }
54
55};