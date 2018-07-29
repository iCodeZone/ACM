#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<limits.h>
#define LL long long
using namespace std;

const int N=100+5;
const int mod=1000000000+7;
LL C[N][N];

void Init(){
	memset(C,0,sizeof(C));
	for(int i=0;i<N;i++){
		C[i][0]=1;C[i][i]=1;
		for(int j=0;j<i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}

LL C(int n,int m)
{
	LL ans=1;
	for(int i=1;i<=m;i++)
	{
		ans=ans*(n-m+i)/i;
	}
	return ans;
}

double lnchoose(int n, int m)
{
    if (m > n)
    {
        return 0;
    }
    if (m < n/2.0)
    {
        m = n-m;
    }
    double s1 = 0;
    for (int i=m+1; i<=n; i++)
    {
        s1 += log((double)i);
    }
    double s2 = 0;
    int ub = n-m;
    for (int i=2; i<=ub; i++)
    {
        s2 += log((double)i);
    }
    return s1-s2;
}
double choose(int n, int m)
{
    if (m > n)
    {
        return 0;
    }
    return exp(lnchoose(n, m));
}

int main(){
	Init();
	return 0;
}
