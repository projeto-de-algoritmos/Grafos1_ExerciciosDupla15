#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	int n, m; 		// n = num de vertices, m = num de arestas 
	cin >> n >> m;
	
	vector<int> adj[1005]; 		// lista de adjascencia
	
	for(int i = 0; i < m; i++){
		int s, u;
		cin >> s >> u;
		adj[s].push_back(u); 	// preenchendo a lista de adjascencia	
	}
	
	int ordem[n];   // vector com a ordem proposta
	for(int i = 0; i < n; i++) {
		cin >> ordem[i];
	}
	
	unordered_map<int,int> mp; 		// dicionario mp. 
									// key = num do vertice. valor = posição do vertice na ordem 

	for (int i = 0; i < n; i++) 	// preechemento do dicionario 
		mp[ordem[i]] = i;
		
	for (int u = 1; u <= n; u++)
		for (auto v : adj[u])
			if (mp[u] > mp[v]){ 	// se o u estiver depois de v na ordem, não é uma ordenação topologica valida 
				cout << "NO\n";
				return 0;
			}
				
	cout << "YES\n";
	
    return 0;
}

