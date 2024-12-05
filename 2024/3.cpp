#include <bits/stdc++.h>

using namespace std;

#define ll long long 
int main(){
    string content((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());


    regex pattern(R"(mul\(\s*(\d+)\s*,\s*(\d+)\s*\))");
    ll ans = 0;

    auto begin = sregex_iterator(content.begin(), content.end(), pattern);
    auto end = sregex_iterator();

    for(auto it = begin; it != end; it++){
        int x = stoi((*it)[1].str());
        int y = stoi((*it)[2].str());

        ans+= static_cast<ll>(x) * y;
    }

    cout << ans << '\n';

    return 0;
}
