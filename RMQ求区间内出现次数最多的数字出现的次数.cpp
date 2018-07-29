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
int a[N],cnt[N],maxn[N][20];
int n,ans;

void init(){
	for(int i=1;i<=n;i++){
		maxn[i][0]=cnt[i];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
		}
	}
}

void rmq(int l,int r){
	int k=log((double)(r-l+1))/log(2.0);
	ans=max(maxn[l][k],maxn[r-(1<<k)+1][k]);
	return ;
}

int main(){
	int x,y,q;
	while(~scanf("%d%d",&n,&q)){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		cnt[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				cnt[i]=cnt[i-1]+1;
			}
			else{
				cnt[i]=1;
			}
		} 
		init();
		while(q--){
			scanf("%d%d",&x,&y);
			int t=x;
			while(t<=y&&a[t]==a[t-1]){
				t++;
			}
			rmq(t,y);
			ans=max(ans,t-x);
			printf("%d\n",ans);
		}
	}
	return 0;
}
