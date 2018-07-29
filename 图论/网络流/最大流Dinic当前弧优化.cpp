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
int n,m;
int head[N],len;
int dep[N],cur[N];//cur就是记录当前点u循环到了哪一条边

struct EdgeNode{
	int to,next,flow,cap;
}edge[N*N];

void add(int i,int j,int flow){
	edge[len].to=j;edge[len].cap=flow;edge[len].flow=0;edge[len].next=head[i];head[i]=len++;
	edge[len].to=i;edge[len].cap=0;edge[len].flow=0;edge[len].next=head[j];head[j]=len++;
}

void init(){
	mem(head,-1),len=0;
}
//分层 
bool bfs(int s,int t){
	queue<int> q;q.push(s);
	mem(dep,0),dep[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(u==t) return 1;
		for(int k=head[u];k!=-1;k=edge[k].next){
			int v=edge[k].to;
			if(edge[k].cap>edge[k].flow&&!dep[v]){
				q.push(v);
				dep[v]=dep[u]+1;
			}
		} 
	}
	return 0;
}

int DFS(int u,int a,int t){
	if(u==t||a==0) return a;
	int flow=0,f;
	for(int &k=cur[u];k!=-1;k=edge[k].next){
		int v=edge[k].to;
		if(dep[v]==dep[u]+1){
			f=DFS(v,min(a,edge[k].cap-edge[k].flow),t);
			if(f>0){
				edge[k].flow+=f;
				edge[k^1].flow-=f;
				flow+=f;
				a-=f;
				if(a==0) break;
			} 
		}
	}
	return flow;
}

int Dinic(int s,int t){
	int ans=0;
	while(bfs(s,t)){
		for(int i=s;i<=t;i++){
			cur[i]=head[i];
		}
		ans+=DFS(s,MAX_INT,t);
	}
	return ans;
}

int main(){
	int u,v,f; 
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&f);
			add(u,v,f);
		}
		scanf("%d%d",&u,&v);
		printf("%d\n",Dinic(u,v));
	}
	return 0;
}
/*
debug
4 5
1 2 1
2 4 1
1 3 1
3 4 1
2 3 1
1 4
*/
