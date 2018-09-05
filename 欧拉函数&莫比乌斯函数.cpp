#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=10000009;
int prime[N],phi[N],vis[N],mu[N];
int n,cnt=0;
void init(){
	mu[1]=1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			prime[++cnt]=i;
			vis[i]=i;
			phi[i]=i-1;
			mu[i]=-1;
		}
		for(int j=1;j<=cnt&&i*prime[j]<N;j++){
			vis[i*prime[j]]=prime[j];
			if(i%prime[j]==0){
				phi[i*prime[j]]=prime[j]*phi[i];
				mu[i*prime[j]]=0;
				break;
			}
			phi[i*prime[j]]=(prime[j]-1)*phi[i];
			mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=20;i++) cout<<prime[i]<<' ';
	cout<<endl;
	for(int i=1;i<=20;i++) cout<<phi[i]<<' ';
	cout<<endl;
	for(int i=1;i<=20;i++) cout<<mu[i]<<' ';
	cout<<endl;
}
int main(){
	init();
	return 0;
}
