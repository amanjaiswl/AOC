#include <bits/stdc++.h>

using namespace std;

#define ll long long 
int main(){
    string content((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());


    regex mul_pattern(R"(mul\(\s*(\d+)\s*,\s*(\d+)\s*\))");
    ll ans = 0;

    auto begin = sregex_iterator(content.begin(), content.end(), mul_pattern);
    auto end = sregex_iterator();

    for(auto it = begin; it != end; it++){
        int x = stoi((*it)[1].str());
        int y = stoi((*it)[2].str());

        ans+= static_cast<ll>(x) * y;
    }

    cout << ans << '\n';

    // part b
    regex do_pattern(R"(do\(\))");
    regex dont_pattern(R"(don't\(\))");

    ll ans2 = 0; 
    bool is_enabled = true; 

    
    sregex_iterator mul_it(content.begin(), content.end(), mul_pattern);
    sregex_iterator do_it(content.begin(), content.end(), do_pattern);
    sregex_iterator dont_it(content.begin(), content.end(), dont_pattern);

    vector<pair<size_t, string>> matches;

    for (; mul_it != end; ++mul_it) {
        matches.emplace_back(mul_it->position(), "mul(" + (*mul_it)[1].str() + "," + (*mul_it)[2].str() + ")");
    }
    for (; do_it != end; ++do_it) {
        matches.emplace_back(do_it->position(), "do()");
    }
    for (; dont_it != end; ++dont_it) {
        matches.emplace_back(dont_it->position(), "don't()");
    }

    sort(matches.begin(), matches.end()); 

    for (const auto& match : matches) {
        if (match.second == "do()") {
            is_enabled = true;
        } else if (match.second == "don't()") {
            is_enabled = false;
        } else {
            smatch mul_match;
            if (regex_search(match.second, mul_match, mul_pattern)) {
                int x = stoi(mul_match[1].str());
                int y = stoi(mul_match[2].str());
                if (is_enabled) {
                    ans2 += static_cast<ll>(x) * y;
                }
            }
        }
    }

    cout << ans2 << '\n';
    return 0;
}
