/*巴什博弈：只有一堆n个物品，两个人轮流从这堆物品中取物，
规定每次至少取一个，最多取m个。最后取光者得胜。*/
#include<bits/stdc++.h>
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
	int n;
	while(~scanf("%d",&n)){
		if(n%3==0){
			puts("Cici");
		}
		else{
			puts("Kiki");
		}
	}
	return 0;
}
