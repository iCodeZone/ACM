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
int next[N*2],to[N*2],head[N*2],num,deep[N*2],fa[N*2][21];
int n,m,rt,a,b,c;

void add(int false_from,int false_to){
	next[++num]=head[false_from];
	to[num]=false_to;
	head[false_from]=num;
}

void dfs(int x){
	deep[x]=deep[fa[x][0]]+1;
	for(int i=0;fa[x][i];i++){
		fa[x][i+1]=fa[fa[x][i]][i];
	}
	for(int i=head[x];i;i=next[i]){
		if(!deep[to[i]]){
			fa[to[i]][0]=x;
			dfs(to[i]);
		}
	}
}

int lca(int x,int y){
	if(deep[x]>deep[y]){
		swap(x,y);
	}
	for(int i=20;i>=0;i--){
		if(deep[fa[y][i]]>=deep[x]){
			y=fa[y][i];
		}
	}
	if(x==y){
		return y;
	}
	for(int i=20;i>=0;i--){
		if(fa[y][i]!=fa[x][i]){
			y=fa[y][i];
			x=fa[x][i];
		}
	}
	return fa[x][0];
}

int main(){
	scanf("%d%d%d",&n,&m,&rt);
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a);
	}
	dfs(rt);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
	return 0;
}

