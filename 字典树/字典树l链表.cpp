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
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
using namespace std;

const int N=26;
const int mod=1000000000+7;

struct Trie{
	struct Trie *next[N];//儿子分支 
	bool isStr;//标记该结点处是否构成单词 
};

void Insert(Trie *root,const char *s){//将单词插入字典树 
	if(root==NULL||*s=='\0')
		return;
	Trie *p=root;
	while(*s!='\0'){
		if(p->next[*s-'a']==NULL){//如果不存在，则建立结点 
			Trie *temp=new(Trie);
			for(int i=0;i<N;i++){//初始化该结点 
				temp->next[i]=NULL;
			}
			temp->isStr=false;
			p->next[*s-'a']=temp;
			p=p->next[*s-'a'];
		}
		else{
			p=p->next[*s-'a'];
		}
		s++;
	}
	p->isStr=true;//单词结束的地方标记此处可以构成一个单词
} 

int Search(Trie *root,const char *s){//查找某个单词是否已经存在 
	Trie *p=root;
	while(p!=NULL&&*s!='\0'){
		p=p->next[*s-'a'];
		s++;
	} 
	return (p!=NULL&&p->isStr==true);//到达单词结尾处 
}

void Del(Trie *root){//释放整个字典树占的堆区空间
	for(int i=0;i<N;i++){
		if(root->next[i]!=NULL){
			Del(root->next[i]);
		}
	}
	delete(root);
} 

int main(){
	int n;
	char s[110];
	Trie *root=new(Trie);
	for(int i=0;i<N;i++){
		root->next[i]=NULL;
	}
	root->isStr=false;
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		Insert(root,s);
	}
	Del(root);
	while(~scanf("%s",s)){
		if(Search(root,s))
			puts("YES");
		else
			puts("NO");
	}
	Del(root);
	return 0;
}
