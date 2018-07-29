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

const int N = 100 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int dp[N*50000];
int v[N*32],w[N*32];
int cnt;

int main(){
	int n,W;
	mem(dp,0),cnt=0;
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++){
		int x,y,z,temp=1;
		scanf("%d%d%d",&x,&y,&z);
		//二进制优化，数的拆分 
		while(z>=temp){
			w[++cnt]=x*temp;
			v[cnt]=y*temp;
			z-=temp;
			temp*=2;
		}
		w[++cnt]=x*z;
		v[cnt]=y*z;
	}
	//01背包 
	for(int i=1;i<=cnt;i++){
		for(int j=W;j>=w[i];j--){
			dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
		}
	} 
	printf("%d\n",dp[W]);
	return 0;
}
