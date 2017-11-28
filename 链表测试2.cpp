#include<cstdio>
#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct node{
	int val;
	struct node *pNext;
}Node,*pNode;
pNode initList(){
	pNode pHead=(pNode)malloc(sizeof(Node));
	if(pHead==NULL) exit(-1);
	else{
		pNode pTail=pHead;
		pHead->pNext=NULL;
		int n,data;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>data;
			pNode pNew=(pNode)malloc(sizeof(Node));
			pNew->val=data;
			pTail->pNext=pNew;
			pNew->pNext=NULL;
			pTail=pNew;
		}
	}
	return pHead;
}
void insert(pNode pHead,int position,int data){
	pNode p=pHead;
	int i=0;
	while(p!=NULL&&i<position-1){
		i++;
		p=p->pNext;
	}
	pNode pNew=(pNode)malloc(sizeof(Node));
	pNew->val=data;
	pNew->pNext=p->pNext;
	p->pNext=pNew;
}
void delet(pNode pHead,int position){
	pNode p=pHead;
	int i=0;
	while(p!=NULL&&i<position-1){
		i++;
		p=p->pNext;
	}
	pNode pNew=p->pNext;
	p->pNext=pNew->pNext;
	free(pNew);
}
int find(pNode pHead,int position){
	pNode p=pHead;
	int i=0;
	while(p!=NULL&&i<position){
		i++;
		p=p->pNext;
	}
	return p->val;
}
int len(pNode pHead){
	pNode p=pHead;
	int i=0;
	while(1){
		p=p->pNext;
		if(p==NULL) break;
		i++;
	}
	return i;
}
void print(pNode pHead){
	pNode p=pHead;
	int i=0;
	while(1){
		p=p->pNext;
		if(p==NULL) break;
		cout<<p->val<<' ';
		i++;
	}
}
int main(){
	pNode pHead=NULL;
	pHead=initList();
	int n,position,data;
	while(1){
		cin>>n;
		if(!n) break;
		if(n==1){
			cin>>position>>data;
			insert(pHead,position,data);
		}
		if(n==2){
			cin>>position;
			delet(pHead,position);
		}
		if(n==3){
			cin>>position;
			cout<<find(pHead,position)<<endl;
		}
		if(n==4){
			cout<<len(pHead)<<endl;
		}
		if(n==5){
			print(pHead);
			cout<<endl;
		}
	}
	return 0;
}


