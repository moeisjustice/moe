#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
typedef struct tree{
	int data;
	struct tree *left,*right;
}Tree,*pTree;
pTree search(pTree root,int key,pTree *parent){
	pTree p=root;
	int flag=0;
	if(p->data==key) *parent=NULL;
	while(p){
		if(p->data>key){
			*parent=p;
			p=p->left;
		}
		else if(p->data<key){
			*parent=p;
			p=p->right;
		}
		else{
			flag=1;
			break;
		}
	}
	if(flag) return p;
	else return NULL;
}
void insert(pTree *root,int key){
	pTree pNew=new Tree;
	pNew->data=key;
	pNew->left=NULL;
	pNew->right=NULL;
	if(*root==NULL){
		*root=pNew;
		return;
	}
	pTree Tparent=NULL,Tnode=*root;
	while(Tnode){
		Tparent=Tnode;
		if(key>Tnode->data) Tnode=Tnode->right;
		else Tnode=Tnode->left;
	}
	if(key>Tparent->data) Tparent->right=pNew;
	else Tparent->left=pNew;
}
int maxn(pTree root){
	while(root->right){
		root=root->right;
	}
	return root->data;
}
int minn(pTree root){
	while(root->left){
		root=root->left;
	}
	return root->data;
}
void in(pTree root){
	pTree p=root;
	if(p==NULL) return ;
	in(p->left);
	cout<<p->data<<' ';
	in(p->right);
}
void delet(pTree *root,int key){
	pTree parent=NULL;
	pTree k=search(*root,key,&parent);
	if(k==NULL){
		cout<<"É¾³ýÊ§°Ü"<<endl;
		return; 
	}
	int flag;
	if(k!=*root&&parent->left==k) flag=0;
	if(k!=*root&&parent->right==k) flag=1;
	if(k->left==NULL&&k->right==NULL){
		if(!flag) parent->left=NULL;
		else parent->right=NULL;
		free(k);
	}
	else if(k->left!=NULL&&k->right==NULL){
		if(!flag) parent->left=k->left;
		else parent->right=k->left;
		free(k);
	}
	else if(k->left==NULL&&k->right!=NULL){
		if(!flag) parent->left=k->right;
		else parent->right=k->right;
		free(k);
	}
	else if(k->left!=NULL&&k->right!=NULL){
		pTree kn=k->right;
		pTree mother=NULL;
		if(kn->left!=NULL){
			while(1){
				kn=kn->left;
				if(kn->left->left==NULL){
					mother=kn;
					break;
				}
			}
			kn=mother->left;
		}
		kn->left=k->left;
		if(k==*root){
			*root=k->right;
			kn->left=k->left;
			k->right=NULL;
			return;
		}
		if(!flag){
			parent->left=kn;
		}
		else{
			parent->right=kn;
		}
	}
}
int main(){
	freopen("in.txt","r",stdin);
	int a[100],n,data;
	pTree root=NULL;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		insert(&root,a[i]);
	}
	in(root);
	cout<<endl;
	pTree parent=NULL;
	pTree p=search(root,70,&parent);
	cout<<p->data<<' '<<parent->data<<endl;
	cout<<minn(root)<<' '<<maxn(root)<<endl;
	delet(&root,63);
	in(root);
	cout<<endl;
	cout<<minn(root)<<' '<<maxn(root)<<endl;
	return 0;
}






