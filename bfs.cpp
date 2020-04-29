#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

using namespace std;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  vector<int> d(adj.size(),10000); // 10,000 is infinity
  queue<int> q;
  vector<bool> visited(adj.size(),false);
  d[s] = 0;
  q.push(s);
  while(!q.empty()){
  	int u = q.front();
  	q.pop();
   	visited[u] = true;
  	for(int i = 0 ; i < adj[u].size() ; i++){
  		int v = adj[u][i];
  		if(d[v] == 10000){
  			d[v] = d[u] + 1;
  			q.push(v);
		  }
	  }
  }
  if(d[t] != 10000){
  	return d[t];
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
