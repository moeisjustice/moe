#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef struct trie{
	int exist;
	struct trie *ch[26];
	struct trie *fail;
}node,*trieNode;
trieNode creatNode(){
	trieNode newNode=new node;
	newNode->exist=0;
	newNode->fail=NULL;
	memset(newNode->ch,0,sizeof(newNode->ch));
	return newNode;
}
void buildTree(trieNode root,string word){							//构建trie树 
	trieNode node=root;
	for(int i=0;i<word.length();i++){
		int id=word[i]-'a';
		if(!node->ch[id]) node->ch[id]=creatNode();
		node=node->ch[id];
	}
	node->exist=1;
}
void buildACautomation(trieNode root){								//构建AC自动机 
	queue<trieNode> q;
	q.push(root);
	while(!q.empty()){
		trieNode p=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(p->ch[i]){
				if(p==root) p->ch[i]->fail=root;
				else {
					trieNode pt=p->fail;
					while(pt){
						if(pt->ch[i]){
							p->ch[i]->fail=pt->ch[i];
							break;
						}
						pt=pt->fail;
					}
					if(!pt) p->ch[i]->fail=root;
				}
				q.push(p->ch[i]);
			}
		}
	}
}
int query(trieNode root,string word){
	trieNode p=root;
	int cnt=0;
	for(int i=0;i<word.length();i++){
		int id=word[i]-'a';
		while(!p->ch[id]&&p!=root) p=p->fail;
		p=p->ch[id];
		if(!p) p=root;
		trieNode pt=p;
		while(pt!=root){
			if(pt->exist>0){
				cnt+=pt->exist;
				pt->exist=0;                         //统计后去掉标记避免重复统计 
			}
			pt=pt->fail;
		}
	}
	return cnt;
}
int flag=0;
void destroy(trieNode root){
    for(int i=0;i<26;i++){
        if(root->ch[i]){
            flag=1;
            break;
        }
    }
    if(!flag) return;
    for(int i=0;i<26;i++){
        if(root->ch[i]){
            destroy(root->ch[i]);
            delete root->ch[i];
        }
    }
}
int main(){
	freopen("in.txt","r",stdin);
	int n;
	string word;
	cin>>n;
	trieNode root=creatNode();
	for(int i=1;i<=n;i++){
		cin>>word;
		buildTree(root,word);
	}
	buildACautomation(root);
	cin>>word;
	cout<<query(root,word);
	destroy(root);
	delete root;
	return 0;
}





