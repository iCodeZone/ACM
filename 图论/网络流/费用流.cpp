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
#define pb push_back
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
const int M = 10000 + 5;
const int mod = 1000000000 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int head[N],len;
int pre[N],dis[N];//¼ÇÂ¼Ç°Çýµã
int ans;
bool vis[N]; 

struct node{
	int from,to,w,c,next;
}edge[M*4];

void init(){
	mem(vis,0),mem(head,-1),ans=len=0;
}

void add(int u,int v,int w,int c){
	edge[len].from=u,edge[len].to=v,edge[len].w=w,edge[len].c=c;
	edge[len].next=head[u],head[u]=len++;
	
	edge[len].from=v,edge[len].to=u,edge[len].w=-w,edge[len].c=0;
	edge[len].next=head[v],head[v]=len++;
}

void update(int s,int t){
	int f=INF;
	for(int i=t;i!=s;i=edge[pre[i]].from){
		f=min(f,edge[pre[i]].c);
	}
	for(int i=t;i!=s;i=edge[pre[i]].from){
		edge[pre[i]].c-=f;
		edge[pre[i]^1].c+=f;
		ans+=f*edge[pre[i]].w;
	}
}

bool spfa(int s,int t){
	int u,v,w;
	mem(pre,-1),mem(dis,0x3f);
	queue<int> q;
	q.push(s);dis[s]=0,vis[s]=1;
	while(!q.empty()){
		u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i!=-1;i=edge[i].next){
			v=edge[i].to,w=edge[i].w;
			if(edge[i].c&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pre[v]=i;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
	return pre[t]!=-1;
}

void solve(int s,int t){
	ans=0;
	while(spfa(s,t)){
		update(s,t);
	}
}

int main(){
	int n,m,u,v,w,c;
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d%d%d",&u,&v,&w,&c);
			add(u,v,w,c);
		}
		solve(1,n);
		printf("%d\n",ans);
	}
	return 0;
}

