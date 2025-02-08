/* By subrata mondal */
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
#include<climits>
using namespace std;
#define pp pair<int, int> 
vector<list<pp> > g;

unordered_map<int, bool> vis;
unordered_map<int, int> mp;
priority_queue<pp, vector<pp>, greater<pp> > pq;

void prims(int n) {
    pq.push({0, 0});
    for(int i = 0; i < n; i++) {
        mp[i] = INT_MAX;
    }
    mp[0] = 0;
    while(not pq.empty()) {
        int curr = pq.top().second;
        // cout<<curr<<"\n";
        if(vis.find(curr) != vis.end()) {
            pq.pop();
            continue;
        }
        vis[curr] = true;
        pq.pop();
        for(auto neigh : g[curr]) {
            if(neigh.second < mp[neigh.first] and !(vis.find(neigh.first) != vis.end())) {
                mp[neigh.first] = neigh.second;
                pq.push({mp[neigh.first],neigh.first});
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int n,m;
    cin>>n>>m;
    g.resize(n, list<pp> ());
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    prims(n);
    for(auto el : mp) {
        cout<<el.first<<" "<<el.second<<"\n";
    }
    return 0;
}
