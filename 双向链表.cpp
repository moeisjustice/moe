#include<cstdio>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct node{
	int val;
	struct node *pNext;
	struct node *pFront;
}Node,*pNode;
pNode initList(){
	pNode pHead=(pNode)malloc(sizeof(Node));
	pNode pTail=pHead;
	pTail->pNext=NULL;
	pTail->pFront=NULL;
	int n,data;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>data;
		pNode pNew=(pNode)malloc(sizeof(Node));
		pNew->val=data;
		pNew->pFront=pTail;
		pNew->pNext=NULL;
		pTail->pNext=pNew;
		pTail=pNew;
	}
	return pHead;
}
void insert(pNode pHead,int pos,int data){
	pNode p=pHead;
	int i=0;
	while(p!=NULL&&i<pos){
		i++;
		p=p->pNext;
	}
	pNode pNew=(pNode)malloc(sizeof(Node));
	pNew->val=data;
	pNew->pNext=p->pNext;
	p->pNext->pFront=pNew;
	p->pNext=pNew;
	pNew->pFront=p;
}
void delet(pNode pHead,int pos){
	pNode p=pHead;
	int i=0;
	while(p!=NULL&&i<pos){
		i++;
		p=p->pNext;
	}
	p->pFront->pNext=p->pNext;
	p->pNext->pFront=p->pFront;
	free(p);
}
int print(pNode pHead){
	pNode p=pHead;
	int i=0;
	while(1){
		p=p->pNext;
		if(p==NULL) break;
		cout<<p->val<<' ';
		i++;
	}
	return i;
}
int main(){
	pNode pHead=NULL;
	pHead=initList();
	int n,pos,data;
	while(1){
		cin>>n;
		if(!n) break;
		if(n==1){
			cin>>pos>>data;
			insert(pHead,pos,data);
		}
		if(n==2){
			cin>>pos;
			delet(pHead,pos);
		}
		if(n==3){
			cout<<print(pHead)<<endl;
		}
	}
	return 0;
}
