1class Solution {
2public:
3    bool stoneGameIX(vector<int>& stones) {
4        vector<int> a(3);
5        vector<int> b(3);
6        for(int i:stones){
7            int u=i%3;
8            a[u]++;
9            b[u]++;
10        }
11
12        if(a[1]){
13            int r=1;
14            bool c=false;
15            a[1]--;
16            if(a[0]&1){
17                c=true;
18            }
19            int count=stones.size()-1-a[0];
20            while(count){
21                if(r==1){
22                    if(a[1]==0){
23                        if(!c){
24                            return true;
25                        }
26                    }
27                    a[1]--;
28                    r+=1;
29                    r%=3;
30                }else{
31                    if(a[2]==0){
32                        if(!c){
33                            return true;
34                        }
35                    }
36                    a[2]--;
37                    r+=2;
38                    r%=3;
39                }
40                c=!c;
41                count--;
42            }
43        }
44        if(b[2]){
45            int r=2;
46            bool c=false;
47            b[2]--;
48            if(b[0]&1){
49                c=true;
50            }
51            int count=stones.size()-1-b[0];
52            while(count){
53                if(r==1){
54                    if(b[1]==0){
55                        if(!c){
56                            return true;
57                        } 
58                    }
59                    b[1]--;
60                    r+=1;
61                    r%=3;
62                }else{
63                    if(b[2]==0){
64                        if(!c){
65                            return true;
66                        }
67                    }
68                    b[2]--;
69                    r+=2;
70                    r%=3;
71                }
72                c=!c;
73                count--;
74            }
75        }
76        return false;
77        
78    }
79};