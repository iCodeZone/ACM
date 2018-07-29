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

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;

double cal(double a){
	//根据题目的意思计算
}

double search(){
	double l,r,ll,rr;
	while(r-l>eps){
		ll=(2*l+r)/3;
		rr=(2*r+l)/3;
		if(cal(ll)>cal(rr)){
			r=rr; 
		}
		else{
			l=ll;
		}
	}
	return l;
}

int main(){
	return 0;
}
