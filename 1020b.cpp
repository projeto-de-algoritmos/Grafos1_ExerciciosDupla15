#include <bits/stdc++.h>
using namespace std;
 
int second_hole;      
vector<int> adj[1005];
bool visited[1005];   				// se aluno ja tinha um furo
 
void dfs(int u){  
	
    visited[u] = true;
    for(int v : adj[u]){
        if(visited[v]){      			// achou ciclo? se sim, retorna aluno que teve segundo furo
            second_hole = v;
            return;         
        }
        dfs(v);				
        if(second_hole != -1){  
            return;
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);    
	
    int n;
    cin >> n; 
    
    int p;
    for(int i = 1; i <= n ; i++){
        cin >> p;
        adj[i].push_back(p);     		// faz lista de adj, ou seja, quem está culpando quem
    }
 
    for(int a = 1; a <= n; a++){                // vai fazer dfs no grafo começando pelo aluno a1 até an
        memset(visited, false, sizeof visited); // preenche visited com false
        second_hole = -1;
        dfs(a);
        cout << second_hole << " ";
    }
    
    cout << "\n";
    
    return 0;    
} 
