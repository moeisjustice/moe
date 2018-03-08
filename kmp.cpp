#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100000;
void getNext(string t,int *next){
	int j=0,k=-1;
	next[0]=-1;
	while(j<t.length()){
		if(k==-1||t[k]==t[j]){
			j++;
			k++;
//			next[j]=k;
			if(t[j]!=t[k]) next[j]=k;
			else next[j]=next[k];
		}
		else k=next[k];
	}
//	for(int i=0;i<j;i++) cout<<next[i]<<' ';
//	cout<<endl;
}
int kmp(string s,string t){
	int i=0,j=0,next[maxn];
	getNext(t,next);
	while(i<s.length()&&j<(int)t.length()){
		if(j==-1||s[i]==t[j]){
			i++;
			j++;
		}
		else j=next[j];
	}
	if(j>=t.length()) return i-t.length();
	else return -1;
}
int main(){
	freopen("in.txt","r",stdin);
	string s,t;
	cin>>s>>t;
	cout<<kmp(s,t)+1;
	return 0;
}
