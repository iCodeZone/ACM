/*
hdu1698 Just a Hook

题意:O(-1)

思路:O(-1)

线段树功能:update:成段替换 (由于只query一次总区间,所以可以直接输出1结点的信息)
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
int sum[N<<4],lazy[N<<4],t,n,op,x,y,val,cas;

void pushup(int root){
	sum[root]=sum[root<<1]+sum[root<<1|1];
}

void pushdown(int root,int k){
	if(lazy[root]!=0){
		sum[root<<1]=lazy[root]*(k-(k>>1));
		sum[root<<1|1]=lazy[root]*(k>>1);
		lazy[root<<1]=lazy[root];
		lazy[root<<1|1]=lazy[root];
		lazy[root]=0;
	}
}

void update(int ql,int qr,int l,int r,int num,int root){
	if(ql<=l&&qr>=r){
		sum[root]=(r-l+1)*num;
		lazy[root]=num;
		return ;
	}
	pushdown(root,r-l+1);
	int mid=(l+r)>>1;
	if(ql<=mid) update(ql,qr,l,mid,num,root<<1);
	if(qr>mid) update(ql,qr,mid+1,r,num,root<<1|1);
	pushup(root);
}

int query(int ql,int qr,int l,int r,int root){
	if(ql<=l&&qr>=r){
		return sum[root];
	}
	pushdown(root,r-l+1);
	int mid=(l+r)>>1;
	int s=0;
	if(ql<=mid) s+=query(ql,qr,l,mid,root<<1);
	if(qr>mid) s+=query(ql,qr,mid+1,r,root<<1|1);
	return s;
}

int main(){
	while(~scanf("%d",&t)){
		cas=0;
		while(t--){
			scanf("%d%d",&n,&op);
			mem(sum,0),mem(lazy,0),update(1,n,1,n,1,1);
			for(int i=1;i<=op;i++){
				scanf("%d%d%d",&x,&y,&val);
				update(x,y,1,n,val,1);
			}
			printf("Case %d: The total value of the hook is %d.\n",++cas,query(1,n,1,n,1));
		}
	}
	return 0;
}
