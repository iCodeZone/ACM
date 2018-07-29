//œﬂ–‘…∏
#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 100000 
using namespace std;

int primes[MAXN],tot=0;
bool isPrime[MAXN];

void getPrime(){
	memset(isPrime,true,sizeof(isPrime));
	for(int i=2;i<=MAXN;i++){
		if(isPrime[i]){
			primes[++tot]=i;
			for(LL j=(LL)i*i;j<=MAXN;j+=i)
				isPrime[j]=false;
		}
	}
}

int main(){
	getPrime();
	for(int i=1;i<=tot;i++)
		printf("%d\n",primes[i]);
}
