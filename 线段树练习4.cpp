#include<cstdio>
#include<iostream>
using namespace std;
#define MAXN 100000
struct Tree{
	int l,r,mod[20];
	int lazy;
}tree[400001];
int ans=0,tmp[20],data;
void pushup(int k){
	for(int i=0;i<7;i++){
		tree[k].mod[i]=tree[k<<1].mod[i]+tree[k<<1|1].mod[i];
	}
}
void pushdown(int k){
	tree[k<<1].lazy+=tree[k].lazy;
	tree[k<<1|1].lazy+=tree[k].lazy;
	for(int i=0;i<7;i++) tmp[(i+tree[k].lazy)%7]=tree[k<<1].mod[i];
	for(int i=0;i<7;i++) tree[k<<1].mod[i]=tmp[i];
	for(int i=0;i<7;i++) tmp[(i+tree[k].lazy)%7]=tree[k<<1|1].mod[i];
	for(int i=0;i<7;i++) tree[k<<1|1].mod[i]=tmp[i];
	tree[k].lazy=0;
}
void init(int k,int l,int r){
	tree[k].l=l;
	tree[k].r=r;
	if(tree[k].l==tree[k].r){
		cin>>data;
		tree[k].mod[data%7]=1;
		return;
	}
	int m=(l+r)/2;
	init(k<<1,l,m);
	init(k<<1|1,m+1,r);
	pushup(k);
}
void add(int k,int l,int r,int x){
	if(l<=tree[k].l&&tree[k].r<=r){
		tree[k].lazy+=x;
		for(int i=0;i<7;i++) tmp[(i+x)%7]=tree[k].mod[i];
		for(int i=0;i<7;i++) tree[k].mod[i]=tmp[i];
		return;
	}
	if(tree[k].lazy) pushdown(k);
	int m=(tree[k].l+tree[k].r)/2;
	if(m>=l) add(k<<1,l,r,x);
	if(m<r) add(k<<1|1,l,r,x);
	pushup(k);
}
void sum(int k,int l,int r){
	if(l<=tree[k].l&&tree[k].r<=r){
		ans+=tree[k].mod[0];
		return;
	}
	if(tree[k].lazy) pushdown(k);
	int m=(tree[k].l+tree[k].r)/2;
	if(m>=l) sum(k<<1,l,r);
	if(m<r) sum(k<<1|1,l,r);
}
int main(){
	freopen("in.txt","r",stdin);
	int n,m,x,y,l,r;
	char s[50];
	cin>>n;
	init(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++){
	    cin>>s;
	    if(s[0]=='a'){
	        cin>>l>>r>>x;
			add(1,l,r,x);
	    }
	    if(s[0]=='c'){
	        ans=0;
			cin>>l>>r;
			sum(1,l,r);
			cout<<ans<<endl;
	    }
	}
	return 0;
}
