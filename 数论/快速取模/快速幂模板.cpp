//¿ìËÙÃİÄ£°å
#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
const int mod = 1e9 + 7;

LL quick(LL a,LL b){
	LL ans=1;
	a%=mod;
	while(b){
		if(b&1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
} 

int main(){
	LL a,b,mod;
	while(~scanf("%lld%lld%lld",&a,&b,&mod))
		printf("%lld\n",quickMod(a,b,mod));
	return 0;
}
