/*
单点更新:最最基础的线段树,只更新叶子节点,然后把信息用PushUP(int r)这个函数更新上来
hdu1166 敌兵布阵
题意:O(-1)
思路:O(-1)
线段树功能:update:单点增减 query:区间求和
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
#define max_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 200000 + 5;
const int mod = 1000000000 + 7;
int maxn[N<<4],n,m,ans,x,y;
char op;

void pushup(int root){
	maxn[root]=max(maxn[root<<1],maxn[root<<1|1]);
}

void build(int l,int r,int root){
	if(l==r){
		scanf("%d",&maxn[root]);
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
		return ;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) update(ql,qr,l,mid,num,root<<1);
	if(qr>mid) update(ql,qr,mid+1,r,num,root<<1|1);
	pushup(root);
}

void query(int ql,int qr,int l,int r,int root){
	if(ql<=l&&qr>=r){
		ans=max(ans,maxn[root]);
		return ;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) query(ql,qr,l,mid,root<<1);
	if(qr>mid) query(ql,qr,mid+1,r,root<<1|1);
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		build(1,n,1);
		while(m--){
			getchar();
			scanf("%c%d%d",&op,&x,&y);
			if(op=='Q'){
				ans=MIN_INT;
				query(x,y,1,n,1);
				printf("%d\n",ans);
			}
			else{
				update(x,x,1,n,y,1);
			}
		}
	}
	return 0;
}
