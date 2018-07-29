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
#include<ctime>

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

const int N = 1000000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;

LL exgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	LL r=exgcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
	return r;
} 

LL CRT(LL a[],LL w[],int n){
	LL M=1,ans=0;
	for(int i=1;i<=n;i++){
		M*=w[i];
	}
	for(int i=1;i<=n;i++){
		LL x,y,temp;
		temp=M/w[i];
		exgcd(w[i],temp,x,y);
		ans=(ans+temp*y*a[i])%M;
	}
	return (ans%M+M)%M;
}


LL a[N],r[N];

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&a[i],&r[i]);
		}
		printf("%lld\n",CRT(a,r,n));
	}
	return 0;
}
