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
int n,q,op,x,y,cas=0;
LL sum[N<<4];

void build(int l,int r,int root){
	if(l==r){
		scanf("%lld",&sum[root]);
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	sum[root]=sum[root<<1]+sum[root<<1|1];
}

void update(int ql,int qr,int nl,int nr,int root){
	if(nl==nr){
		sum[root]=sqrt(sum[root]);
		return ;
	}
	if(ql<=nl&&qr>=nr&&sum[root]==nr-nl+1) return;
	int mid=(nl+nr)>>1;
	if(ql<=mid) update(ql,qr,nl,mid,root<<1);
	if(qr>mid) update(ql,qr,mid+1,nr,root<<1|1);
	sum[root]=sum[root<<1]+sum[root<<1|1];
}

LL query(int ql,int qr,int nl,int nr,int root){
	if(ql<=nl&&qr>=nr) return sum[root];
	int mid=(nl+nr)>>1;
	LL s=0;
	if(ql<=mid) s+=query(ql,qr,nl,mid,root<<1);
	if(qr>mid) s+=query(ql,qr,mid+1,nr,root<<1|1);
	return s;
}

int main(){
	while(~scanf("%d",&n)){
		printf("Case #%d:\n",++cas);
		build(1,n,1);
		scanf("%d",&q);
		while(q--){
			scanf("%d%d%d",&op,&x,&y);
			int xx=min(x,y),yy=max(x,y);
			if(op==0){
				update(xx,yy,1,n,1);
			}
			else{
				printf("%lld\n",query(xx,yy,1,n,1));
			}
		}
		puts("");
	}
	return 0;
}
