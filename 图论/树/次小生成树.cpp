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

const int N = 100 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int F[N],ans;

int Find(int x){
	return F[x]==x?x:F[x]=Find(F[x]);
}

struct node{
	int a,b;
	int w;
	bool flag;
}edge[N*N/2];

bool cmp(node a,node b){
	if(a.w!=b.w) return a.w<b.w;
	if(a.a!=b.a) return a.a<b.a;
	return a.b<b.b;
}

struct Node{
	int to,next;
}link[N];
int head[N];//邻接表的头节点位置
int end[N];//邻接表的尾节点位置
int len[N][N];//每两点在最小生成树上路径中的最长边长

void kruskal(node *edge,int n,int m){
	int x,y,cnt=0;
	//初始化邻接表，对于每个节点添加一条指向其自身的边，表示以i为代表元的集合只有点i 
	for(int i=0;i<n;i++){
		link[i].to=i+1;
		link[i].next=head[i+1];
		end[i+1]=i;
		head[i+1]=i;
	}
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		if(edge[i].w<0) continue;
		x=Find(edge[i].a);
		y=Find(edge[i].b);
		if(x!=y){
			
			//遍历两个节点所在集合
			for(int w=head[x];w!=-1;w=link[w].next){
				for(int v=head[y];v!=-1;v=link[v].next){
					//每次合并两个等价类的时候，分别属于两个等价类的两个点间的最长边一定是当前加入的边
					len[link[w].to][link[v].to]=len[link[v].to][link[w].to]=edge[i].w;debug;
				}
			} 
			//合并两个邻接表
			link[end[y]].next=head[x];
			end[y]=end[x];
			F[x]=y;
			cnt++;
			edge[i].flag=1; 
		}
	} 
} 

void Build(node *edge,int n,int m){
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].w);
	}
}

void init(){
	mem(edge,0),mem(link,0),mem(head,-1),mem(end,0),mem(len,0);
	for(int i=1;i<N;i++){
		F[i]=i;
	}
}

int main(){
	int t,n,m,minn,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init(),minn=0,ans=INT_MAX;
		Build(edge,n,m);
		kruskal(edge,n,m);
		for(int i=1;i<=m;i++){
			if(edge[i].flag){
				minn+=edge[i].w;
			}
		}
		for(int i=1;i<=m;i++){
			if(!edge[i].flag){
				ans=min(ans,minn+edge[i].w-len[edge[i].a][edge[i].b]);
			}
		}
		if(ans==minn){
			puts("Not Unique!");
		}
		else{
			printf("%d\n",minn);
		}
	}
	return 0;
}
/*
debug
2
3 3
1 2 1
2 3 2
3 1 3
4 4
1 2 2
2 3 2
3 4 2
4 1 2
*/
