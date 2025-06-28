#ifndef CITY_MAP_H
#define CITY_MAP_H

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> load_city_map(const string& filename) {
    vector<vector<char>> grid;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        vector<char> row;
        for (char ch : line) {
            if (!isspace(ch)) row.push_back(ch);
        }
        grid.push_back(row);
    }
    return grid;
}

unordered_map<char, int> get_default_cost_map() {
    return {
        {'H', 1}, {'L', 2}, {'A', 3}, {'T', 5},
        {'#', -1}, {'.', 1}, {'S', 1}, {'E', 1}
    };
}

vector<vector<int>> convert_to_cost_grid(const vector<vector<char>>& grid, const unordered_map<char, int>& cost_map) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> cost(n, vector<int>(m, -1));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (cost_map.count(grid[i][j]))
                cost[i][j] = cost_map.at(grid[i][j]);
    return cost;
}

pair<int, int> find_location(const vector<vector<char>>& grid, char target) {
    for (int i = 0; i < grid.size(); ++i)
        for (int j = 0; j < grid[0].size(); ++j)
            if (grid[i][j] == target)
                return {i, j};
    return {-1, -1};
}

#endif // CITY_MAP_H
