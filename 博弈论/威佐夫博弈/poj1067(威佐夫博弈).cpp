/*威佐夫博弈（Wythoff Game）：有两堆各若干个物品，
两个人轮流从某一堆或同时从两堆中取同样多的物品，
规定每次至少取一个，多者不限，最后取光者得胜。*/
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

int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		if(a>b){
			swap(a,b);
		}
		double k=b-a;
		double x=(1+sqrt(5.0))/2;
		int t=k*x;
		if(t==a){//奇异局势
			puts("1");
		}
		else{
			puts("0");
		}
	}
	return 0;
}
