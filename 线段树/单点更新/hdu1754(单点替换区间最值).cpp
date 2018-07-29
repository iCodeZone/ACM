/*
hdu1754 I Hate It
题意:O(-1)
思路:O(-1)
线段树功能:update:单点替换 query:区间最值
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

const int N = 50000 + 5;
const int mod = 1000000000 + 7;
int sum[N<<4],t,n,cas=0,x,y;
char str[10];

void pushup(int root){
	sum[root]=sum[root<<1]+sum[root<<1|1];
}

void build(int l,int r,int root){
	if(l==r){
		scanf("%d",&sum[root]);
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1);
	build(mid+1,r,root<<1|1);
	pushup(root);
}

void update(int ql,int qr,int l,int r,int num,int root){
	if(l==r){
		sum[root]+=num;
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid) update(ql,qr,l,mid,num,root<<1);
	if(qr>mid) update(ql,qr,mid+1,r,num,root<<1|1);
	pushup(root);
}

int query(int ql,int qr,int l,int r,int root){
	if(ql>r||qr<l) return 0;
	if(ql<=l&&qr>=r){
		return sum[root];
	}
	int mid=(l+r)>>1;
	int s=0;
	if(ql<=mid) s+=query(ql,qr,l,mid,root<<1);
	if(qr>mid) s+=query(ql,qr,mid+1,r,root<<1|1);
	return s;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		build(1,n,1);
		printf("Case %d:\n",++cas);
		while(~scanf("%s",str)){
			if(str[0]=='E'){
				break;
			}
			scanf("%d%d",&x,&y);
			if(str[0]=='Q'){
				printf("%d\n",query(x,y,1,n,1));
			}
			if(str[0]=='A'){
				update(x,x,1,n,y,1);
			} 
			if(str[0]=='S'){
				update(x,x,1,n,-y,1);
			}
		}
	}
	return 0;
}

