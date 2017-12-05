#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=30010;
int dep[maxn],p[maxn][20];
vector<int> g[maxn];
void dfs(int u,int fa){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		p[v][0]=u;
		dfs(v,u);
	}
}
void init(int n){
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			if(p[i][j-1]!=-1){
				p[i][j]=p[p[i][j-1]][j-1];
			}
		}
	}
}
int lca(int x,int y){
	int i,j;
	if(dep[x]<dep[y]) swap(x,y);
	for(i=0;(1<<i)<=dep[x];i++);
	i--;
	for(j=i;j>=0;j--){
		if(dep[x]-dep[y]>=(1<<j)){
			x=p[x][j];
		}
	}
	if(x==y) return x;
	for(int j=i;j>=0;j--){
		if(p[x][j]!=-1&&p[x][j]!=p[y][j]){
			x=p[x][j];
			y=p[y][j];
		}
	}
	return p[x][0];
}
int main(){
	freopen("in.txt","r",stdin);
	int n,u,v;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>u>>v; 
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dep[1]=1;
	p[1][0]=-1;
	dfs(1,-1);
	init(n);
	int x,y;
	while(1){
		cin>>x>>y;
		if(x==-1&&y==-1) break;
		cout<<lca(x,y)<<endl;
	}
	return 0;
}
