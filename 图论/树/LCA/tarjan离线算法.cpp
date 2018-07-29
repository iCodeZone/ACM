#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<bitset>

#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>

#include<iomanip>
#include<iostream>

#define debug cout<<"aaa"<<endl
#define d(a) cout<<a<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 1000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int head[N],len;
int qhead[N],qlen;
int F[N];
bool vis[N];

struct EdgeNode{
	int from,to,next;
	int lca;
}edge[N*N],qedge[N*N];

void add(int i,int j){
	edge[len].from=i;
	edge[len].to=j;
	edge[len].next=head[i];
	head[i]=len++;
} 

void qadd(int i,int j){
	qedge[qlen].from=i;
	qedge[qlen].to=j;
	qedge[qlen].next=qhead[i];
	qhead[i]=qlen++;
} 

void init(){
	mem(vis,0),mem(head,-1),mem(qhead,-1),len=qlen=0;
}

int Find(int x){
	return F[x]==x?x:F[x]=Find(F[x]);
}

void LCA(int u){
	F[u]=u;
	vis[u]=1;
	for(int k=head[u];k!=-1;k=edge[k].next){
		int temp=edge[k].to;
		if(!vis[temp]){
			LCA(temp);
			F[temp]=u;
		}
	}
	for(int k=qhead[u];k!=-1;k=qedge[k].next){
		int temp=qedge[k].to;
		if(vis[temp]){
			qedge[k].lca=qedge[k^1].lca=Find(temp);
		}
	}
}

int main(){
	int n,m,q,u,v;
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			scanf("%d%d",&u,&v);
			qadd(u,v);
			qadd(v,u);
		}
		LCA(1);
		for(int i=0;i<q;i++){
			printf("%d %dµÄLCA:%d\n",qedge[2*i].from,qedge[2*i].to,qedge[2*i].lca);
		}
	}
	return 0;
}
/*
8 7
1 2
1 3
2 4
2 5
3 6
3 7
7 8
5
2 3
4 6
6 8
5 7
5 2
*/
