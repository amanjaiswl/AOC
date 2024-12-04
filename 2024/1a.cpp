#include <bits/stdc++.h>

using namespace std; 

int main(){
    vector<int> a;
    vector<int> b;

    int x, y;

    while(cin>> x >> y){
        a.push_back(x);
        b.push_back(y);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long ans = 0;

    for(int i=0; i<a.size(); i++){
        ans+= abs((long long)a[i] - (long long)b[i]);
    }

    cout << ans << '\n';

    // part b
    
    long long ans2 = 0;
    for(int i=0;i < a.size(); i++){
        long long cnt = count(b.begin(), b.end(), a[i]);
        long long z = (long long)a[i] * cnt;
        ans2+= z;
    }

    cout << ans2 << '\n';
    return 0;
}
