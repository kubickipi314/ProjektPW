//lokalna zmienna w środkowej pętli - gorszy czas dla kompilacji -O3 (5,2s -> 5,3s)
//                                  - dla -O1 5,4 -> 5,3
//                                  - dla -O0 20s -> 18s
#include<iostream>
#include<cstdint>
#include<vector>
#include<algorithm>
using namespace std;
#define ull unsigned long long 

void fun(int p, int q, int r, const vector<vector<int>>&part, vector<int>&oh, const vector<int>&a){
    oh.push_back(a[r]);
    if (r - p > 1) fun(p,r,part[r-p-1][p], part, oh, a);
    if (q - r > 1) fun(r,q,part[q-r-1][r], part ,oh, a);
}

void solve(){
    int d, n; //d <= 10^9
    cin>>d>>n;//n <~ 10^3

    vector<int> a(n+2,0);
    a[n+1] = d;
    
    for (int i=1; i<=n; ++i)cin>>a[i];
    sort(a.begin(),a.end());

    ull dp[n+1][n+1]{};

    vector<vector<int>> part(n+1,vector<int>(n+1,0));

    for (int i = 1; i<n+1; ++i){
        for (int j = 0; j<n+1-i; ++j){
            ull min_res = uint64_t(-1);
            int p = 0;
            for (int k = j+1; k<j+i+1; ++k){
                ull res = max(a[k]-a[j],a[j+i+1]-a[k]) + dp[k-j-1][j] + dp[i-k+j][k];
                if (res <= min_res) {
                    min_res = res;
                    p = k;
                }
            }
            dp[i][j] = min_res;
            part[i][j] = p;
        }
    }
    cout<<dp[n][0]<<'\n';

    vector<int> oh;
    fun(0,n+1,part[n][0], part, oh, a);
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