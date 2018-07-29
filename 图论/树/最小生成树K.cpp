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

void Build(int n,int m){
	for(int i=1;i<=m;i++){
		cin>>edge[i].a>>edge[i].b>>edge[i].w;
	}
}

void kruskal(node *edge,int n,int m){
	int x,y,cnt=0;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		x=Find(edge[i].a);
		y=Find(edge[i].b);
		if(x!=y){
			ans+=edge[i].w;
			edge[i].flag=1;
			F[x]=y;
			cnt++;
		}
	}
}

int main(){
	int n,m,t;
	cin>>t;
	while(t--){
		mem(edge,0),ans=0;
		for(int i=1;i<N;i++){
			F[i]=i;
		}
		cin>>n>>m;
		Build(n,m);
		kruskal(edge,n,m);
		cout<<ans<<endl;
	}
	return 0;
}
/*
debug
1
3 3
1 2 990
1 3 692
2 3 179
*/
