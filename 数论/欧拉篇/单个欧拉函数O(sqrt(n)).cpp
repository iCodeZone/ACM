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
//单个欧拉函数求解 O(sqrt(n))
LL euler(LL n){
	LL ans=n;
	for(LL i=2;i*i<=n;i++){
		if(n%i==0){
			ans-=ans/i;
			while(n%i==0) n/=i;//保证了if进来的都是素质数 
		}
	}
	if(n>1) ans-=ans/n;
	return ans; 
} 

int main(){
	return 0;
}

