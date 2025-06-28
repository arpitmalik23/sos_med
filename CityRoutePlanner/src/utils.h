#ifndef UTILS_H
#define UTILS_H

#include <bits/stdc++.h>
using namespace std;

void print_city_map(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char ch : row)
            cout << ch << ' ';
        cout << '\n';
    }
}

void mark_path_on_map(vector<vector<char>>& grid, const vector<pair<int, int>>& path) {
    for (int i = 1; i + 1 < path.size(); ++i) {
        auto [x, y] = path[i];
        grid[x][y] = '*';
    }
}

#endif // UTILS_H
