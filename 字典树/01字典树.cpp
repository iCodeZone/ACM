#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>

#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

#include<iomanip>
#include<iostream>

#define debug cout<<"aaa"<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 2;
const int mod = 1000000000 + 7;

struct Trie{
	struct Trie *next[N];
	int val;
	Trie(){
		for(int i=0;i<N;i++){
			next[i]=NULL;
		}
		val=0;
	}
};

void Insert(Trie *root,const int num){
	if(root==NULL){
		return ;
	}
	Trie *p=root;
	for(int i=30;i>=0;i--){
		int t=num&(1<<i);
		if(t) t=1;
		else t=0;
		if(p->next[t]==NULL){
			Trie *temp=new Trie();
			p->next[t]=temp;
			p=p->next[t];
		}
		else{
			p=p->next[t];
		}
	}
	p->val=num;
}

int Search(Trie *root,const int num){
	Trie *p=root;
	int id,ans=0;
	for(int i=30;i>=0;i--){
		id=(num>>i)&1;
		if(id) id=1;
		else id=0;
		if(p->next[id^1]!=NULL){
			p=p->next[id^1];
		}
		else{
			p=p->next[id];
		}
	}
	return p->val;
}

void Del(Trie *root){
	for(int i=0;i<N;i++){
		if(root->next[i]!=NULL){
			Del(root->next[i]);
		}
	}
	delete(root);
}

int main(){
	int t,cas,n,m,num=3,ans;
	while(~scanf("%d",&t)){
		cas=0;
		while(t--){
			Trie *root=new Trie();
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++){
				scanf("%d",&num);
				Insert(root,num);
			}
			printf("Case #%d:\n",++cas);
			for(int i=1;i<=m;i++){
				scanf("%d",&num);
				ans=Search(root,num);
				printf("%d\n",ans);
			}
			Del(root);
		}
	}
	return 0;
}
