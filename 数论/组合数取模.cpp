#include<bits/stdc++.h>
#define debug cout<<"aaa"<<endl
#define d(a) cout<<a<<endl
#define pb push_back
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
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

LL F[N],Inv[N];

LL quick(LL a,LL b){
	LL ans=1;
	while(b){
		if(b&1){
			ans=(ans*a)%mod;
		}
		b>>=1;
		a=(a*a)%mod;
	}
	return ans;
}

void init(){
	F[0]=Inv[0]=1;
	for(int i=1;i<N;i++){
		F[i]=(F[i-1]*i)%mod;
		Inv[i]=quick(F[i],mod-2);
	}
}

LL C(LL a,LL b){
	LL ans=F[a];
	ans=(ans*Inv[b])%mod;
	ans=(ans*Inv[a-b])%mod;
	return ans;
}

int main(){
	init();
	cout<<C(5,2)<<endl;
	return 0;
}
