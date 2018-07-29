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

const int N = 50000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int dp[N],a[N];
int n,len,pos;
//dp[i]:保存的是最长递增子序列长度为i的结尾的最小值 
//可以当作往里面一个一个加数字，更新最小那个 
int search(int l,int r,int x){
	while(l<=r){
		int mid=(l+r)>>1;
		if(dp[mid]==x){
			return mid;
		} 
		else if(dp[mid]>x){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return l;
}

void LIS(){
	mem(dp,0),len=1;
	dp[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>dp[len]){
			dp[++len]=a[i];
		}
		else{
			pos=search(1,len,a[i]);
			dp[pos]=a[i]; 
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		LIS();
		printf("%d\n",len);
	}
	return 0;
}
