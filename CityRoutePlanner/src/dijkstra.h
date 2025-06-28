#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

pair<int, vector<pii>> dijkstra_pathfinder(const vector<vector<int>>& cost, pii start, pii end) {
    int n = cost.size(), m = cost[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    map<pii, pii> parent;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    pq.push({0, start.first, start.second});
    dist[start.first][start.second] = 0;

    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        auto [curr_cost, x, y] = pq.top();
        pq.pop();
        if (make_pair(x, y) == end) break;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && cost[nx][ny] != -1) {
                int new_cost = curr_cost + cost[nx][ny];
                if (new_cost < dist[nx][ny]) {
                    dist[nx][ny] = new_cost;
                    pq.push({new_cost, nx, ny});
                    parent[{nx, ny}] = {x, y};
                }
            }
        }
    }

    if (dist[end.first][end.second] == INT_MAX) return {-1, {}};
    vector<pii> path;
    for (pii curr = end; curr != start; curr = parent[curr])
        path.push_back(curr);
    path.push_back(start);
    reverse(path.begin(), path.end());
    return {dist[end.first][end.second], path};
}

#endif // DIJKSTRA_H
