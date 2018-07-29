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
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 200000 + 5;
const int mod = 1000000000 + 7;
int maxn[N<<2],n,m,q,len;

void pushup(int root){
	maxn[root]=max(maxn[root<<1],maxn[root<<1|1]);
}

void build(int l,int r,int root){
	maxn[root]=m;
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(lson),build(rson);
}

int query(int x,int l,int r,int root){
	if(l==r){
		maxn[root]-=x;
		return l;
	}
	int mid=(l+r)>>1;
	int s;
	if(maxn[root<<1]>=x) s=query(x,lson);
	else s=query(x,rson);
	pushup(root);
	return s;
}

int main(){
	while(~scanf("%d%d%d",&n,&m,&q)){
		if(q<n) n=q;
		build(1,n,1);
		while(q--){
			scanf("%d",&len);
			if(maxn[1]<len) puts("-1");
			else printf("%d\n",query(len,1,n,1));
		}
	}
	return 0;
}
