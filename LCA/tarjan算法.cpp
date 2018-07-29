#include<bits/stdc++.h>
#define debug cout<<"aaa"<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
int F[N],fs[N];//并查集父亲结点 父亲结点个数
bool vis[N];
int ans[N],in[N];//祖先
vector<int> son[N];//保存树，儿子结点 
vector<int> que[N];//保存查询
typedef vector<int>::iterator IT;

void init(){
	for(int i=0;i<N;i++){
		son[i].clear();
		que[i].clear();
		fs[i]=1;
		F[i]=i; 
	}
	mem(vis,0);
	mem(ans,0);
}

int Find(int x){
	return (F[x]==x)?x:F[x]=Find(F[x]);
} 

void Union(int x,int y){
	x=Find(x),y=Find(y);
	if(x==y) return;
	if(fs[x]<=fs[y]) F[x]=y,fs[y]+=fs[x];
	else F[y]=x,fs[x]+=fs[y];
}

void lca(int u){
	ans[u]=u;
	for(IT v=son[u].begin();v!=son[u].end();++v){
		lca(*v);
		Union(u,*v);
		ans[Find(u)]=u;
	}
	vis[u]=1;
	for(IT v=que[u].begin();v!=que[u].end();++v){
		if(vis[*v]){
			printf("LCA(%d,%d):%d\n",u,*v,ans[Find(*v)]);
		}
	}
}

int main(){
	int n,u,v,m;
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		if(u!=v){
			son[u].push_back(v);
			in[v]++;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		que[u].push_back(v);
		que[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			u=i;
			break;
		}
	}
	lca(u);
	return 0;
}
/*
9 5
1 2
1 3
2 4
2 5
3 6
3 9
6 7
6 8
7 9
2 8
4 6
1 3
6 5
*/
