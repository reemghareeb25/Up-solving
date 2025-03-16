#include <bits/stdc++.h>
using namespace std;

void InOutFast() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

#define int long long
#define bye return 0
#define all(a) ((a).begin()), ((a).end())
#define ll long long
#define isON(n, k) (((n) >> (k)) & 1)
const int N = 2e3 + 9, oo = 1e17, MOD = 998244353;

int f[N], inv[N], finv[N];
void prec() {
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = 1LL * i * f[i - 1] % MOD;

    inv[1] = 1;
    for (int i = 2; i < N; i++ ) {
        inv[i] = (-(1LL * MOD / i) * inv[MOD % i] ) % MOD;
        inv[i] = (inv[i] + MOD) % MOD;
    }
    finv[0] = 1;
    for (int i = 1; i < N; i++)
        finv[i] = 1LL * inv[i] * finv[i - 1] % MOD;
}
int npr(int n, int r) {
    if (n < r || n < 0 || r < 0)
        return 0;
    return 1LL * f[n] * finv[n - r] % MOD;
}

int ncr(int n, int r) {
    if (n < r || n < 0 || r < 0)
        return 0;
    return 1LL * f[n] * finv[n - r] % MOD * finv[r] % MOD;
}
int fastPower(int base, int pow){
    if(pow <= 0)
        return 1LL;
    int res = fastPower((base*base)%MOD, pow/2) %MOD;
    if(pow & 1)
        res = (res*base)%MOD;;
    return res;
}

int times(int a, int b){
    return (a % MOD * b % MOD) % MOD;
}

signed main() {
    InOutFast();
    prec();
    int n, m, k;
    cin >> n >> m >> k;
    int x = times(m, ncr(n-1, k));
    int y = fastPower(m-1, k);
    cout << times(x, y) ;
    bye;
}