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
//中国剩余定理  r[]存放余数  a[]存放两两互质的除数
/*若模数两两互质，我们可以用中国剩余定理来解。 
这里我们先考虑两个方程：
x≡r1(moda1)
x≡r2(moda2)
我们可以写成:
x+y1a1=r1
x-y2a2=r2

相减得：y1a1+y2a2=r1-r2也就是ax+by=m的形式。 
这是可以用扩展欧几里德解的。 
若gcd(a,b)/|m那么方程就无解，直接输出-1。 
否则我们可以解出上式的y1。回带得到一个特解x0=r1-y1a1。 
通解可以写成x=x0+k*lcm(a1,a2)也就是x≡x0(mod lcm(a1,a2))。 
这样我们就将两个方程合并为了一个。重复进行以上操作，我们最终能将n个方程全部合并，再用扩展欧几德得解出来就好了。
*/
LL solve(LL a[],LL r[],int n){
	LL M=a[1],R=r[1],x,y,d,temp;
	for(int i=2;i<=n;i++){
		d=exgcd(M,a[i],x,y);
		if((R-r[i])%d!=0) return -1;//无解 
		temp=a[i]/d;  
        x=(R-r[i])/d*x;//特解x1。  
        x=(x%temp+temp)%temp;  
		R-=x*M;//特解x0，新的余数。
		M=M/d*a[i];////新的模数。
		R%=M;
	}
	return R==0?M:(R%M+M)%M;//余数全为0，则返回lcm 
}

LL a[N],r[N];

int main(){
	int n,t,cas=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&r[i]);
		}
		printf("Case %d: %lld\n",++cas,solve(a,r,n));
	}
	return 0;
}

