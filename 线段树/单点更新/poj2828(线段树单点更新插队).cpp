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
int n;
int pos[N],cnt[N<<4],ans[N<<4],val[N];

void pushup(int root){
	cnt[root]=cnt[root<<1]+cnt[root<<1|1];
}

void build(int l,int r,int root){
	cnt[root]=r-l+1;
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(lson),build(rson);
}

void update(int p,int num,int l,int r,int root){
	if(l==r){
		cnt[root]=0;
		ans[root]=num;
		return ;
	}
	int mid=(l+r)>>1;
	if(p<cnt[root<<1]) update(p,num,lson);
	else update(p-cnt[root<<1],num,rson);
	pushup(root);
}

void query(int l,int r,int root){
	if(l==r){
		printf("%d ",ans[root]);
		return ;
	}
	int mid=(l+r)>>1;
	query(lson),query(rson);
}

int main(){
	while(~scanf("%d",&n)){
		build(1,n,1);
		for(int i=0;i<n;i++){
			scanf("%d%d",&pos[i],&val[i]);
		}
		for(int i=n-1;i>=0;i--){
			update(pos[i],val[i],1,n,1);
		}
		query(1,n,1);
		puts("");
	}
	return 0;
}
