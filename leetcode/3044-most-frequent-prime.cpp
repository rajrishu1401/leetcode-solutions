int func(int prev_num, int temp)
{
    return prev_num*10 + temp;
}

int mostFrequentPrime(vector<vector<int>>&mat) {
    int inf = 1e6 + 1;
    vector<bool> isPrime(inf, true);
    isPrime[1] = false;

    for (int p = 2; p * p <= inf; p++) {
        // If prime[p] is not changed, then it is a prime
        if (isPrime[p] == true) {
            for (int i = p * p; i <= inf; i += p)
                isPrime[i] = false;
        }
    }
    int n = mat.size();
    int m = mat[0].size();
    vector<pair<int,int>> directions;
    directions.push_back({0,1}); directions.push_back({1, 0}); directions.push_back({0, -1}); directions.push_back({-1, 0});
    directions.push_back({1,1}); directions.push_back({1, -1}); directions.push_back({-1, 1}); directions.push_back({-1, -1});
        
    vector<int> cnt(inf, 0);
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< m ; j++)
        {
            // start from i , j
            for(auto dir: directions)
            {
                int ind1 = i +dir.first;
                int ind2 = j +dir.second;
                int prev_num = mat[i][j];
                while(ind1 < n && ind1 >=0 && ind2 < m && ind2 >=0)
                {
                    int temp = mat[ind1][ind2];
                    prev_num = func(prev_num, temp);
                    cnt[prev_num]++;
                    ind1 += dir.first;
                    ind2 += dir.second;
                }
            }
        }
    }
    int ans = 0;
    int fin_ans = -1;
    // cout<<cnt[47]<<" "<<cnt[97]<<endl;
    for(int i = 1; i<= 1e6; i++)
    {
        if(isPrime[i] ==  true)
        {
             if(cnt[i] >= ans)
             {
                 ans = max(ans, cnt[i]);
                 fin_ans = i;
             }
        }
           
    }
    if(ans == 0)
        return -1;
    return fin_ans;
}