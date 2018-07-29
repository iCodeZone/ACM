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
int maxn[N][20],minn[N][20];
int a[N],n,m;
int max_ans,min_ans;

void init(){
	for(int j=1;(1<<j)<=n;++j){
		for(int i=1;i+(1<<(j-1))-1<=n;++i){
			maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
			minn[i][j]=min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
		}
	}
}

void rmq(int l,int r){
	int k=int(log((double)(r-l+1))/log(2.0));
	max_ans=max(maxn[l][k],maxn[r-(1<<k)+1][k]);
	min_ans=min(minn[l][k],minn[r-(1<<k)+1][k]);
	return ;
}

int main(){
	int l,r;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			maxn[i][0]=minn[i][0]=a[i];
		}
		init();
		while(m--){
			scanf("%d%d",&l,&r);
			rmq(l,r);
			printf("MAX=%d MIN=%d\n",max_ans,min_ans);
		}
	}
	return 0;
}
