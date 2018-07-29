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

const int N = 1000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
char a[N],b[N],ans[N];
int dp[N][N],lena,lenb;

int main(){
	scanf("%s%s",a+1,b+1);
	lena=strlen(a+1),lenb=strlen(b+1);
	mem(dp,0);
	for(int i=1;i<=lena;i++){
		for(int j=1;j<=lenb;j++){
			if(a[i]==b[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	int i=lena,j=lenb,cnt=dp[i][j];
	while(dp[i][j]){
		if(a[i]==b[j]){
			ans[cnt]=a[i];
			cnt--,i--,j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	ans[dp[lena][lenb]+1]='\0';
	printf("%s\n",ans+1);
	return 0;
}
