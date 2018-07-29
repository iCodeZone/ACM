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

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
int primes[N],tot=0;
bool isPrime[N];

void getPrime(){
    mem(isPrime,true);
    for(int i=2;i<N;i++){
        if(isPrime[i])
            primes[++tot]=i;
        for(int j=1;j<=tot;j++){
            if(i*primes[j]>=N) break;
            isPrime[i*primes[j]]=false;
            if(i%primes[j]==0) break;
        }
    }
}

int main(){
	return 0;
}
