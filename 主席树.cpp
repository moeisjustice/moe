#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int N=2e5+3;
struct node{
    int l,r,w;
}tree[N*20];
int n,m,a[N],b[N],id[N],root[N],cnt;
void init(int &k,int l,int r){
    k=++cnt;
    tree[k].w=0;
    if(l==r) return;
    int m=(l+r)>>1;
    init(tree[k].l,l,m);
    init(tree[k].r,m+1,r);
}
void build(int &k,int last,int l,int r,int x){
    tree[++cnt]=tree[last];
    k=cnt;
    tree[k].w++;
    if(l==r) return;
    int m=(l+r)>>1;
    if(x<=m) build(tree[k].l,tree[last].l,l,m,x);
    else build(tree[k].r,tree[last].r,m+1,r,x);
}
int query(int k,int l,int r,int x,int y){//查询区间第k小
    if(l==r) return l;
    int m=(l+r)>>1,cnt=tree[tree[y].l].w-tree[tree[x].l].w;
    if(cnt>=k) return query(k,l,m,tree[x].l,tree[y].l);
    return query(k-cnt,m+1,r,tree[x].r,tree[y].r);
}
int sum(int k,int l,int r,int x,int y){//求第k个版本区间[x,y]的和
    if(x<=l&&r<=y) return tree[k].w;
    int m=(l+r)>>1,ans=0;
    if(x<=m) ans+=sum(tree[k].l,l,m,x,y);
    if(m<y) ans+=sum(tree[k].r,m+1,r,x,y);
    return ans;
}
int main(){
//    freopen("/Users/apple/Desktop/in.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int size=(int)(unique(b+1,b+1+n)-b-1);
    for(int i=1;i<=n;i++) id[i]=(int)(lower_bound(b+1,b+1+size,a[i])-b);
    cnt=0;
    init(root[0],1,size);
    for(int i=1;i<=n;i++) build(root[i],root[i-1],1,size,id[i]);
    for(int i=1;i<=m;i++){
        int l,r,x;
        cin>>l>>r>>x;
        cout<<b[query(x,1,size,root[l-1],root[r])]<<endl;
    }
    return 0;
}
/*
5 5
25957 6405 15770 26287 26465
2 2 1
3 4 1
4 5 1
1 2 2
4 4 1
*/
