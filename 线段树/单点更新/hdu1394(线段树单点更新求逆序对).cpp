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

const int N = 5000 + 5;
const int mod = 1000000000 + 7;
int sum[N<<2],n,s,ans;
int a[N];

void pushup(int root){
	sum[root]=sum[root<<1]+sum[root<<1|1];
}

void build(int l,int r,int root){
	sum[root]=0;
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(lson);
	build(rson);
}

void update(int q,int l,int r,int root){
	if(l==r){
		sum[root]++;
		return ;
	}
	int mid=(l+r)>>1;
	if(q<=mid) update(q,lson);
	if(q>mid) update(q,rson);
	pushup(root);
}

int query(int ql,int qr,int l,int r,int root){
	if(ql<=l&&qr>=r){
		return sum[root];
	}
	int mid=(l+r)>>1;
	int s=0;
	if(ql<=mid) s+=query(ql,qr,lson);
	if(qr>mid) s+=query(ql,qr,rson);
	return s;
}

int main(){
	while(~scanf("%d",&n)){
		build(0,n-1,1),s=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			s+=query(a[i],n-1,0,n-1,1);
			update(a[i],0,n-1,1);
		}
		ans=s;
		for(int i=1;i<=n;i++){
			s=s-a[i]+(n-a[i]-1);
			ans=min(ans,s);
		}
		printf("%d\n",ans);
	}
	return 0;
}
