#include <bits/stdc++.h>

using namespace std;

int dp[13][1 << 12];
int x[13], y[13];

int n;

int calc(int p, int mask) {
    cout<<"p:"<<p<<", mask:"<<mask<<endl;
    if (p == 0) return (mask != 0) * 1e9;
    int &ret = dp[p][mask];
    if (ret != -1) return ret;
    ret = 1e9;
    for (int i = 0; i <= n; ++i) {
        if (mask & (1 << i)) {
            int dist = abs(x[p] - x[i]) + abs(y[p] - y[i]);
            ret = min(ret, calc(i, mask ^ (1 << i)) + dist);
        }
    }
    return ret;
}

int main() {
    for (int cases = 0; cases < 1; ++cases) {
        scanf("%d", &n);
        cout<<n<<endl;
        scanf("%d %d", &x[n + 1], &y[n + 1]);
        // cin>>x[n+1]>>y[n+1];
        cout<<x[n+1]<<" "<<y[n+1]<<endl;
        scanf("%d %d", &x[0], &y[0]);
        for (int j = 1; j <= n; ++j) {
            scanf("%d %d", &x[j], &y[j]);
        }
        for(int i=0;i<=n+1;i++){
            cout<<"x["<<i<<"]="<<x[i]<<", ";
            cout<<endl;
        }
        memset(dp, -1, sizeof dp);
        printf("#%d %d\n", cases + 1, calc(n + 1, (1 << (n + 1)) - 1));
    }
    return 0;
}