//prosty generator danych losowych


#include <iostream>
#include <vector>
#include <set>
#include <random>

using namespace std;

set<int> generate(int d, int n) {
    set<int> numbers;
    while (numbers.size() < n){
        numbers.insert(rand()%(d-2)+1);
    }
    return numbers;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0));

    int z, d, n;
    cin>>z>>d>>n;

    cout<<z<<"\n";

    while (z--){
        cout<<d<<" "<<n<<"\n";
        set<int> cuts = generate(d,n);
        for (int c : cuts) {
            cout<<c<<" ";
        }
        cout<<"\n";
    }
    return 0;
}