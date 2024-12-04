#include <bits/stdc++.h>
using namespace std;

bool monotonic(const vector<int>& report){
    if(report.empty()) return true;
    bool nonDec = true, nonInc = true;
    for(int i=1;i<report.size();i++){
        if(report[i] < report[i-1]) nonDec = false;
        if(report[i] > report[i-1]) nonInc = false;
        if(!nonDec && !nonInc) return false;
    }
    return nonDec || nonInc;
}

bool validDiff(const vector<int>& report){
    for(int i=1;i<report.size();i++){
        int diff = abs(report[i]-report[i-1]);
        if(diff <1 || diff >3) return false;
    }
    return true;
}

int main(){
    vector<vector<int>> reports;
    string line;
    while(getline(cin, line)){
        if(line.empty()) continue;
        vector<int> nums;
        stringstream ss(line);
        int num;
        while(ss >> num){
            nums.push_back(num);
        }
        reports.push_back(nums);
    }
    int ans=0, ans2=0;
    for(auto &report : reports){
        if(report.size() <2){
            ans++;
            ans2++;
            continue;
        }
        if(monotonic(report) && validDiff(report)){
            ans++;
            ans2++;
            continue;
        }
        bool safe=false;
        for(int i=0;i<report.size();i++){
            vector<int> modified = report;
            modified.erase(modified.begin()+i);
            if(modified.size() <2){
                safe=true;
                break;
            }
            if(monotonic(modified) && validDiff(modified)){
                safe=true;
                break;
            }
        }
        if(safe){
            ans2++;
        }
    }
    cout << ans << '\n';
    cout  << ans2 << '\n';
}

