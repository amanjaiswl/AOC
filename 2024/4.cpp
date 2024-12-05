#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string> grid;
    string line;
    while(getline(cin, line)){
        if(!line.empty()) grid.push_back(line);
    }
    int n = grid.size();
    
    int m = grid[0].size();
    // Directions: N, NE, E, SE, S, SW, W, NW
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'X'){
                for(int dir=0; dir<8; dir++){
                    int ni = i, nj = j;
                    bool found = true;
                    string word = "XMAS";
                    for(int k=1; k<word.size(); k++){
                        ni += dx[dir];
                        nj += dy[dir];
                        if(ni <0 || ni >=n || nj <0 || nj >=m || grid[ni][nj] != word[k]){
                            found = false;
                            break;
                        }
                    }
                    if(found) ans++;
                }
            }
        }
    }
    cout << ans << '\n';

    // part b
    int ans2 =0;

    for(int i = 1; i < n - 1; i++) {
    for(int j = 1; j < m - 1; j++) {
        if(grid[i][j] == 'A') {
            char top_left = grid[i-1][j-1];
            char top_right = grid[i-1][j+1];
            char bottom_left = grid[i+1][j-1];
            char bottom_right = grid[i+1][j+1];
            int count_M = 0, count_S = 0;
            vector<char> corners = {top_left, top_right, bottom_left, bottom_right};
            for(char ch : corners) {
                if(ch == 'M') count_M++;
                else if(ch == 'S') count_S++;
            }
            if(count_M == 2 && count_S == 2 && top_left != bottom_right) {
                ans2++;
            }
        }
    }
}
    cout << ans2 << '\n';

}

