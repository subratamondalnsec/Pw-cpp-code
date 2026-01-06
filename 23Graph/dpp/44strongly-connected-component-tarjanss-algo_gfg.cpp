/* Problem Link - https://www.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1
 By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	vector<vector<int>>ans;
	void  dfs(int node,vector<int> adj[],vector<int>&disc,vector<int>&low,vector<bool>&visit,stack<int>&s,vector<bool>&instack,int& timer){
	    visit[node]=1;
	    disc[node]=low[node]=timer;
	    s.push(node);
	    instack[node]=1;
	    
	    for(auto nei : adj[node]){
	        if(!visit[nei]){
	            timer++;
	            dfs(nei,adj,disc,low,visit,s,instack,timer);
	            low[node]=min(low[node],low[nei]);
	            
	        } 
	        else{
	            if(instack[nei]) low[node]=min(low[node],disc[nei]);
	        }
	    }
	    if(disc[node]==low[node]){
	        vector<int>temp;
	        while(!s.empty() && s.top()!=node){
	            temp.push_back(s.top());
	            instack[s.top()]=0;
	            s.pop();
	        }
	        temp.push_back(node);
	        instack[node]=0;
	        s.pop();
	        sort(temp.begin(),temp.end());
	        ans.push_back(temp);
	    }
	}
	
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[]){
       
       vector<int>disc(V);
       vector<int>low(V);
       vector<bool>visit(V,0);
       stack<int>s;
       vector<bool>instack(V,0);
       int timer=0;
       for(int i=0;i<V;i++){
          if(!visit[i]) dfs(i,adj,disc,low,visit,s,instack,timer);
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V];
    
    // Example graph: Adding directed edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);

    // Create an instance of Solution
    Solution sol;
    vector<vector<int>> scc = sol.tarjans(V, adj);

    // Output the SCCs
    cout << "Strongly Connected Components:" << endl;
    for (auto& component : scc) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
