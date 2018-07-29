#include<set>
#include<map>
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
int dfn[N],low[N],dfs_num;//dfn表示遍历深度，low(u)为u或u的子树能够追溯到的最早的栈中节点的次序号
int ans[N];

struct EdgeNode{
	int to,next;
}edge[N];

void add(int i,int j){
	edge[len].to=j;
	edge[len].next=head[i];
	head[i]=len++;
} 

void init(){
	mem(ans,0),mem(dfn,0),mem(low,0),mem(head,-1),len=dfs_num=0;
}

void tarjan(int x,int from){
	int son=0;
	dfn[x]=low[x]=++dfs_num;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int temp=edge[i].to;
		if(temp==from) continue;
		if(!dfn[temp]){
			son++;
			tarjan(temp,x);
			low[x]=min(low[x],low[temp]);
			if(dfn[x]<=low[temp]){
				ans[x]=1;
			}
		}
		else{
			low[x]=min(dfn[temp],low[x]);
		}
	} 
	if(from<0&&son==1){
		ans[x]=0;
	}
}

void solve(int n){
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i,-1);
		}
	}
}

int main(){
	int n,m,u,v;
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		solve(n);
		for(int i=1;i<=n;i++){
			if(ans[i]){
				cout<<i<<endl;
			}
		}
	}
	return 0;
}
/*
debug
5 6
1 2
1 3
2 3
3 4
3 5
4 5
*/
