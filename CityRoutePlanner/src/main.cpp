#include <bits/stdc++.h>
#include "city_map.h"
#include "dijkstra.h"
#include "utils.h"
using namespace std;

int main() {
    vector<vector<char>> city_grid = load_city_map("../data/sample_map.txt");
    unordered_map<char, int> road_cost = get_default_cost_map();

    pair<int, int> start = find_location(city_grid, 'S');
    pair<int, int> end = find_location(city_grid, 'E');

    if (start.first == -1 || end.first == -1) {
        cout << "Start or End point not found in the map.\n";
        return 1;
    }

    cout << "\nOriginal Map:\n";
    print_city_map(city_grid);

    vector<vector<int>> cost_grid = convert_to_cost_grid(city_grid, road_cost);

    auto [total_cost, path] = dijkstra_pathfinder(cost_grid, start, end);

    if (total_cost == -1) {
        cout << "No path found.\n";
        return 0;
    }

    cout << "\nPath Found! Cost: " << total_cost << "\n";
    mark_path_on_map(city_grid, path);

    cout << "\nPath Map:\n";
    print_city_map(city_grid);

    return 0;
}
