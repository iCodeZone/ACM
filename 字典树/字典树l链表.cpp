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
	struct Trie *next[N];//���ӷ�֧ 
	bool isStr;//��Ǹý�㴦�Ƿ񹹳ɵ��� 
};

void Insert(Trie *root,const char *s){//�����ʲ����ֵ��� 
	if(root==NULL||*s=='\0')
		return;
	Trie *p=root;
	while(*s!='\0'){
		if(p->next[*s-'a']==NULL){//��������ڣ�������� 
			Trie *temp=new(Trie);
			for(int i=0;i<N;i++){//��ʼ���ý�� 
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
	p->isStr=true;//���ʽ����ĵط���Ǵ˴����Թ���һ������
} 

int Search(Trie *root,const char *s){//����ĳ�������Ƿ��Ѿ����� 
	Trie *p=root;
	while(p!=NULL&&*s!='\0'){
		p=p->next[*s-'a'];
		s++;
	} 
	return (p!=NULL&&p->isStr==true);//���ﵥ�ʽ�β�� 
}

void Del(Trie *root){//�ͷ������ֵ���ռ�Ķ����ռ�
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
