/*
poj3468 A Simple Problem with Integers

题意:O(-1)

思路:O(-1)

线段树功能:update:成段增减 query:区间求和
*/
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
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
int x,y,n,q;
LL sum[N<<4],add,lazy[N<<4],ans;
char op;

void pushdown(int root,int k){
	if(lazy[root]!=0){
		sum[root<<1]+=lazy[root]*(k-(k>>1));
		sum[root<<1|1]+=lazy[root]*(k>>1);
		lazy[root<<1]+=lazy[root];
		lazy[root<<1|1]+=lazy[root];
		lazy[root]=0;
	}
}

void build(int l,int r,int root){
	lazy[root]=0;
	if(l==r){
		scanf("%lld",&sum[root]);
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	sum[root]=sum[root<<1]+sum[root<<1|1];
}

void update(int ql,int qr,int l,int r,LL num,int root){
	if(ql<=l&&qr>=r){
		sum[root]+=(r-l+1)*num;
		lazy[root]+=num;
		return ;
	}
	pushdown(root,r-l+1);
	int mid=(l+r)>>1;
	if(ql<=mid) update(ql,qr,l,mid,num,root<<1);
	if(qr>mid) update(ql,qr,mid+1,r,num,root<<1|1);
	sum[root]=sum[root<<1]+sum[root<<1|1];
}

LL query(int ql,int qr,int l,int r,int root){
	if(ql<=l&&qr>=r){
		return sum[root];
	}
	pushdown(root,r-l+1);
	int mid=(l+r)>>1;
	LL s=0;
	if(ql<=mid) s+=query(ql,qr,l,mid,root<<1);
	if(qr>mid) s+=query(ql,qr,mid+1,r,root<<1|1);
	return s;
}

int main(){
	scanf("%d%d",&n,&q);
	build(1,n,1);
	while(q--){
		getchar();
		scanf("%c",&op);
		if(op=='C'){
			scanf("%d%d%lld",&x,&y,&add);
			update(x,y,1,n,add,1);
		}
		else{
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(x,y,1,n,1));
		}
	}
	return 0;
}
