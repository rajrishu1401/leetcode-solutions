1class Solution {
2public:
3    void gameOfLife(vector<vector<int>>& board) {
4        vector<pair<int,int>> m;
5        vector<pair<int,int>> r={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,0},{-1,-1},{-1,1}};
6        for(int i=0;i<board.size();i++){
7            for(int j=0;j<board[i].size();j++){
8                int o=0;
9                for(pair<int,int> f:r){
10                    int i1=i+f.first;
11                    int j1=j+f.second;
12                    if(i1>=0&&j1>=0&&i1<board.size()&&j1<board[i].size()&&board[i1][j1]==1){
13                        o++;
14                    }
15                }
16                if(board[i][j]==1){
17                    if(o<2||o>3){
18                        m.push_back({i,j});
19                    }
20                }else{
21                    if(o==3){
22                        m.push_back({i,j});
23                    }
24                }
25            }
26        }
27
28        for(pair<int,int> k:m){
29            board[k.first][k.second]++;
30            board[k.first][k.second]%=2;
31        }
32    }
33};