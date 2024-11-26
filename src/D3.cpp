//zmiana struktury tablicy (poprawa 5,3s -> ~5s)
//tablica int part -> short part (pogorszenie)

#include<iostream>
#include<cstdint>
#include<vector>
#include<algorithm>
using namespace std;
#define ull unsigned long long

vector<int> i_offsets;

inline int c(int i, int j){
    return i_offsets[i] + j;
}

void fun(int p, int q, int r, const int*part, vector<int>&oh, const vector<int>&a){
    oh.push_back(a[r]);
    if (r - p > 1) fun(p,r,part[c(r-p-1,p)], part, oh, a);
    if (q - r > 1) fun(r,q,part[c(q-r-1,r)], part ,oh, a);
}

void solve(){
    int d, n; //d <= 10^9
    cin>>d>>n;//n <~ 10^3
    int size = (n+3)*(n+2)/2;
    for (int i=0; i<n+2; ++i){
        i_offsets.push_back((n-i+2)*(n+1-i)/2);
    }

    vector<int> a(n+2);
    a[0] = 0;
    a[n+1] = d;
    
    for (int i=1; i<=n; ++i)cin>>a[i];
    sort(a.begin(),a.end());

    ull dp[size]{};
    int part[size]{};

    for (int i = 1; i<n+1; ++i){
        for (int j = 0; j<n+1-i; ++j){
            int coords = c(i,j);
            dp[coords] = uint64_t(-1);
            for (int k = j+1; k<j+i+1; ++k){
                ull res = max(a[k]-a[j],a[j+i+1]-a[k]) + dp[c(k-j-1,j)] + dp[c(i-k+j,k)];
                if (res <= dp[coords]) {
                    dp[coords] = res;
                    part[coords] = k;
                }
            }    
        }
    }
    cout<<dp[c(n,0)]<<'\n';

    vector<int> oh;
    fun(0,n+1,part[c(n,0)], part, oh, a);
    for (int o : oh) cout<<o<<' ';
    cout<<'\n';
    i_offsets.clear();
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
