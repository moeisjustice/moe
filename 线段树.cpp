#include<cstdio>
#include<iostream>
using namespace std;
struct Tree{
	int w;
	int l,r;
	int lazy;
}tree[400000];
int ans;
void init(int k,int l,int r){
	tree[k].l=l;
	tree[k].r=r;
	if(tree[k].l==tree[k].r){
		cin>>tree[k].w;
		return;
	}
	int m=(l+r)/2;
	init(k*2,l,m);
	init(k*2+1,m+1,r);
	tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
void down(int k){
	tree[k*2].lazy+=tree[k].lazy;
	tree[k*2+1].lazy+=tree[k].lazy;
	tree[k*2].w+=tree[k].lazy*(tree[k*2].r-tree[k*2].l+1);
	tree[k*2+1].w+=tree[k].lazy*(tree[k*2+1].r-tree[k*2+1].l+1);
	tree[k].lazy=0;
}
void query(int k,int x){
	if(tree[k].l==tree[k].r){
		ans=tree[k].w;
		return;
	}
	if(tree[k].lazy) down(k);
	int m=(tree[k].l+tree[k].r)/2;
	if(x<=m) query(k*2,x);
	else query(k*2+1,x);
}
void modify(int k,int x,int y){
	if(tree[k].l==tree[k].r){
		tree[k].w=y;
		return;
	}
	if(tree[k].lazy) down(k);
	int m=(tree[k].l+tree[k].r)/2;
	if(x<=m) modify(k*2,x,y);
	else modify(k*2+1,x,y);
	tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
void sum(int k,int l,int r){
	if(l<=tree[k].l&&tree[k].r<=r){
		ans+=tree[k].w;
		return;
	}
	if(tree[k].lazy) down(k);
	int m=(tree[k].l+tree[k].r)/2;
	if(l<=m) sum(k*2,l,r);
	if(m<r) sum(k*2+1,l,r);
}
void add(int k,int l,int r,int x){
	if(l<=tree[k].l&&tree[k].r<=r){
		tree[k].w+=x*(tree[k].r-tree[k].l+1);
		tree[k].lazy+=x;
		return;
	}
	if(tree[k].lazy) down(k);
	int m=(tree[k].l+tree[k].r)/2;
	if(l<=m) add(k*2,l,r,x);
	if(m<r) add(k*2+1,l,r,x);
	tree[k].w=tree[k*2].w+tree[k*2+1].w;
}
void print(int k){
	if(tree[k].l==tree[k].r){
		cout<<tree[k].w<<' ';
		return;
	}
	if(tree[k].lazy) down(k);
	print(k*2);
	print(k*2+1);
}
int main(){
	int n,m,x,y,l,r;
	cin>>n;
	init(1,1,n);
	while(1){
		cin>>m;
		if(m==0) break;
		if(m==1){
			ans=0;
			cin>>x;
			query(1,x);
			cout<<ans<<endl;
		}
		if(m==2){
			cin>>x>>y;
			modify(1,x,y);
		}
		if(m==3){
			ans=0;
			cin>>l>>r;
			sum(1,l,r);
			cout<<ans<<endl;
		}
		if(m==4){
			cin>>l>>r>>x;
			add(1,l,r,x);
		}
		if(m==5) print(1);
	}
	return 0;
}
