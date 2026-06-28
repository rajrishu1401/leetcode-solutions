1class Cashier {
2public:
3    unordered_map<int,int> m;
4    int d;
5    int nu;
6    int c=1;
7    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
8        d=discount;
9        nu=n;
10        for(int i=0;i<products.size();i++){
11            m[products[i]]=prices[i];
12        }
13    }
14    
15    double getBill(vector<int> product, vector<int> amount) {
16        double ans=0;
17        for(int i=0;i<product.size();i++){
18            ans+=(m[product[i]]*amount[i]);
19        }
20
21        if(c==nu){
22            ans=ans*((double)(100-d)/100);
23            c=0;
24        }
25        c++;
26        return ans;
27    }
28};
29
30/**
31 * Your Cashier object will be instantiated and called as such:
32 * Cashier* obj = new Cashier(n, discount, products, prices);
33 * double param_1 = obj->getBill(product,amount);
34 */