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

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;

struct node{
	int to,w,next;
};

struct node2{
	int to;
	int g,f;
	bool operator< (const node2 &a) const{
		if(a.f==f){
			return a.g<g;
		}
		return a.f<f;
	}
};

node edge[N],edge2[N];
int n,m,s,k,t,cnt,cnt2;
int dis[N],vis[N],head[N],head2[N];

void add(int i,int j,int w){
	edge[cnt].to=j;
	edge[cnt].w=w;
	edge[cnt].next=head[i];
	head[i]=cnt++;
} 

void add2(int i,int j,int w){
	edge2[cnt2].to=j;
	edge2[cnt2].w=w;
	edge2[cnt2].next=head2[i];
	head2[i]=cnt2++;
} 

bool SPFA(int s,int n,int head[],node edge[],int dis[]){
	//vis标记是否在队列中 
	int inq[N];
	mem(vis,0),mem(inq,0);
	for(int i=0;i<=n;i++){
		dis[i]=MAX_INT;
	}
	dis[s]=0;
	queue<int> q;
	q.push(s);vis[s]=inq[s]=1;
	while(!q.empty()){
		//队头元素出队，并且消除标记 
		int x=q.front();q.pop();vis[x]=0;
		for(int k=head[x];k!=-1;k=edge[k].next){
			int y=edge[k].to;
			if(dis[x]+edge[k].w<dis[y]){
				dis[y]=dis[x]+edge[k].w;//松弛
				if(!vis[y]){//点y不在队内 
					vis[y]=1;//标记 
					inq[y]++;//统计次数
					q.push(y);
					if(inq[y]>n)//超过入队次数上限说明有负环 
						return 0; 
				} 
			}
		} 
	}
	return 1; 
}

int A_star(int s,int t,int n,int k,int head[],node edge[],int dis[]){
	node2 e,ne;
	int cnt=0;
	priority_queue<node2> q;
	if(s==t) k++;
	if(dis[s]==MAX_INT) return -1;
	e.to=s,e.g=0,e.f=e.g+dis[e.to];
	q.push(e);
	while(!q.empty()){
		e=q.top();q.pop();
		if(e.to==t){//找到一条最短路 
			cnt++;
		}
		if(cnt==k){//找到k短路 
			return e.g;
		}
		for(int k=head[e.to];k!=-1;k=edge[k].next){
			ne.to=edge[k].to;
			ne.g=e.g+edge[k].w;
			ne.f=ne.g+dis[ne.to];
			q.push(ne);
		}
	}
	return -1;
}

void init(){
	mem(head,-1),mem(head2,-1);
	cnt=cnt2=1;
}

int main(){
	int u,v,w,ans;
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			add2(v,u,w);
		}
		scanf("%d%d%d",&s,&k,&t);
		SPFA(t,n,head2,edge2,dis);
		ans=A_star(s,t,n,k,head,edge,dis);
		printf("%d\n",ans);
	}
	return 0;
}
