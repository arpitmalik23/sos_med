#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Cell {
    int x, y, cost;
    bool operator>(const Cell& other) const {
        return cost > other.cost;
    }
};

bool is_valid(int x, int y, int n, int m, vector<vector<int>>& grid) {
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != -1;
}

void print_path(pair<int, int> end, map<pair<int, int>, pair<int, int>>& parent) {
    vector<pair<int, int>> path;
    while (parent.find(end) != parent.end()) {
        path.push_back(end);
        end = parent[end];
    }
    path.push_back(end);
    reverse(path.begin(), path.end());
    cout << "\nPath (row, col):\n";
    for (auto [x, y] : path) {
        cout << "(" << x << ", " << y << ") ";
    }
    cout << "\nTotal steps: " << path.size() - 1 << endl;
}

void shortest_path(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    map<pair<int, int>, pair<int, int>> parent;

    pq.push({start.first, start.second, 0});
    dist[start.first][start.second] = 0;

    while (!pq.empty()) {
        auto [x, y, cost] = pq.top();
        pq.pop();

        if (make_pair(x, y) == end) break;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (is_valid(nx, ny, n, m, grid)) {
                int new_cost = cost + grid[nx][ny];
                if (new_cost < dist[nx][ny]) {
                    dist[nx][ny] = new_cost;
                    pq.push({nx, ny, new_cost});
                    parent[{nx, ny}] = {x, y};
                }
            }
        }
    }

    if (dist[end.first][end.second] == INF) {
        cout << "No path found.\n";
    } else {
        cout << "Shortest path cost: " << dist[end.first][end.second] << endl;
        print_path(end, parent);
    }
}

int main() {
    int n , m ;
    cin >> n >> m;

    vector<vector<int>> city_grid (n,vector<int >(m));
    for(int i = 0; i< n ;i++){
        for(int j = 0;j<m;j++){
             cin >> city_grid[i][j];

        }
    }
    pair<int, int> start,end;
    cin >> start.first >> start.second;
    cin >> end.first >> end .second;
    

   
    shortest_path(city_grid, start, end);

    return 0;
}
