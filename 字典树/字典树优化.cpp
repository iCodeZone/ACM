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

const int N=11;
const int mod=1000000000+7;
int cnt;
char str[10005][N];

struct Trie{
	struct Trie *next[N];//���ӷ�֧ 
	bool isStr;//��Ǹý�㴦�Ƿ񹹳ɵ��� 
}trie[100005];

void Insert(Trie *root,const char *s){//�����ʲ����ֵ��� 
	Trie *p=root;
	while(*s!='\0'){
		if(p->next[*s-'0']==NULL){//��������ڣ�������� 
			p->next[*s-'0']=&trie[cnt++];
		}
		p=p->next[*s-'0'];
		s++;
	}
	p->isStr=1;//���ʽ����ĵط���Ǵ˴����Թ���һ������
}

bool Search(Trie *root,const char *s){
	Trie *p=root;
	while(*s!='\0'){
		p=p->next[*s-'0'];
		s++;
		if(p->isStr&&*s!='\0'){
			return 0;
		}
	}
	return 1;
}

int main(){
	int t,n;
	bool flag;
	scanf("%d",&t);
	while(t--){
		mem(trie,0),cnt=1,flag=1;
		Trie *root=&trie[0];
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",str[i]);
			Insert(root,str[i]);
		}
		for(int i=1;i<=n;i++){
			if(Search(root,str[i])) continue;
			flag=0;break;
		}
		if(flag){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}
