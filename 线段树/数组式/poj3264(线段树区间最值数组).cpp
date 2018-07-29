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

const int N = 200000 + 5;
const int mod = 1000000000 + 7;
int maxn[N<<4],minn[N<<4],n,m,x,y,ans_max,ans_min;

void pushup(int root){
	maxn[root]=max(maxn[root<<1],maxn[root<<1|1]);
	minn[root]=min(minn[root<<1],minn[root<<1|1]);
}

void build(int l,int r,int root){
	if(l==r){
		scanf("%d",&maxn[root]);
		minn[root]=maxn[root];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}

void update(int ql,int qr,int l,int r,int num,int root){
	if(l==r){
		maxn[root]=num;
		minn[root]=num;
		return ;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) update(ql,qr,l,mid,num,root<<1);
	if(qr>mid) update(ql,qr,mid+1,r,num,root<<1|1);
	pushup(root);
}

void query(int ql,int qr,int l,int r,int root){
	if(maxn[root]<=ans_max&&minn[root]>=ans_min) return ;
	if(ql<=l&&qr>=r){
		ans_max=max(ans_max,maxn[root]);
		ans_min=min(ans_min,minn[root]);
		return ;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) query(ql,qr,l,mid,root<<1);
	if(qr>mid) query(ql,qr,mid+1,r,root<<1|1);
}

int main(){
	scanf("%d%d",&n,&m);
	build(1,n,1);
	while(m--){
		ans_max=MIN_INT,ans_min=MAX_INT;
		scanf("%d%d",&x,&y);
		query(x,y,1,n,1);
		printf("%d\n",ans_max-ans_min);
	}
	return 0;
}
