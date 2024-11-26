//podział środkowej pętli między wątki


#include<iostream>
#include<cstdint>
#include<vector>
#include<algorithm>
#include<thread>
using namespace std;
#define ull unsigned long long 

int t_number = 8;
int n;
vector<vector<ull>> dp;
vector<vector<short>> part;
vector<int> a;

void fun(int p, int q, int r, vector<int>&oh){
    oh.push_back(a[r]);
    if (r - p > 1) fun(p,r,part[r-p-1][p],oh);
    if (q - r > 1) fun(r,q,part[q-r-1][r],oh);
}

void calc_parallel(int no, int i){
    for (int j = no; j<n+1-i; j+=t_number){
        dp[i][j] = uint64_t(-1);
        for (int k = j+1; k<j+i+1; ++k){
            ull res = max(a[k]-a[j],a[j+i+1]-a[k]) + dp[k-j-1][j] + dp[i-k+j][k];
            if (res <= dp[i][j]) {
                dp[i][j] = res;
                part[i][j] = k;
            }
        }
    }
}

void calc_seq(int i){
    for (int j = 0; j<n+1-i; j++){
        dp[i][j] = uint64_t(-1);
        for (int k = j+1; k<j+i+1; ++k){
            ull res = max(a[k]-a[j],a[j+i+1]-a[k]) + dp[k-j-1][j] + dp[i-k+j][k];
            if (res <= dp[i][j]) {
                dp[i][j] = res;
                part[i][j] = k;
            }
        }
    }
}

void solve(){
    int d;    //d <= 10^9
    cin>>d>>n;//n <~ 10^3

    a.assign(n+2,0);
    a[n+1] = d;
    
    for (int i=1; i<=n; ++i)cin>>a[i];
    sort(a.begin(),a.end());

    dp.assign(n+1,vector<ull>(n+1,0));
    part.assign(n+1,vector<short>(n+1,0));

    for (int i = 1; i<n+1; ++i){
        vector<thread> threads;
        //int real_t_number = min(t_number, n+1-i);
        for (int no = 0; no<t_number; ++no)
            threads.push_back(thread(calc_parallel,no,i));
        for (int no = 0; no<t_number; ++no)
            threads[no].join();

    }
    cout<<dp[n][0]<<'\n';

    vector<int> oh;
    fun(0,n+1,part[n][0],oh);
    for (int o : oh) cout<<o<<' ';
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin>>z;
    while(z--)
        solve();

    return 0;
}
