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

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int n,m,len;
int head[N],indeg[N],ans[N];

struct node{
	int to,w,next;
}edge[N];

void add(int i,int j,int w){
	indeg[j]++;
	edge[len].to=j;
	edge[len].w=w;
	edge[len].next=head[i];
	head[i]=len++;
} 

bool topo(){
	mem(ans,0);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(indeg[i]==0){
			ans[++cnt]=i;
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int k=head[ans[i]];k!=-1;k=edge[k].next){
			indeg[edge[k].to]--;
			if(indeg[edge[k].to]==0){
				ans[++cnt]=edge[k].to;
			}
		}
	}
	return cnt==n;
}

void init(){
	mem(head,-1),mem(edge,0),mem(indeg,0),len=1;
}

int main(){
	int u,v,w;
	while(~scanf("%d%d",&n,&m)){
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
		}
		topo();
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		puts("");
	}
		
	return 0;
}
/*
debug
8 10
1 3 1
1 2 1
3 5 1
3 6 1
2 4 1
4 6 1
5 7 1
6 7 1
6 8 1
7 8 1
*/
