#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=30001;
vector<int> g[maxn];
int order[maxn<<1],dep[maxn<<1],first[maxn];
int visit[maxn],dis[maxn];
int tot=0;
void dfs(int u,int depth){
	visit[u]=1;
	order[++tot]=u;
	dep[tot]=depth;
	first[u]=tot;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!visit[v]){
			dfs(v,depth+1);
			order[++tot]=u;
			dep[tot]=depth;
		}
	}
}
int main(){
	int n,u,v;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=tot;i++) cout<<order[i]<<' ';
	cout<<endl;
	for(int i=1;i<=tot;i++) cout<<dep[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<first[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++){
		dis[i]=dep[first[i]];
	}
	for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
	return 0;
}
