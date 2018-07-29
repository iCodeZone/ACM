#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<string>

#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<climits>

#include<iomanip>
#include<iostream>

#define debug cout<<"aaa"<<endl
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
using namespace std;

const int N=1000+5;
const int mod=1000000000+7;
int n,q,xx,yy,x[N],y[N],dis[N][N],lowcost[N],pre[N];

void prim(){
	int minn,pos;
	for(int i=1;i<=n;i++){
		lowcost[i]=dis[i][1];
		pre[i]=1;
	}
	lowcost[1]=-1;
	for(int i=1;i<n;i++){
		minn=INT_MAX;
		for(int j=1;j<=n;j++){
			if(lowcost[j]!=-1&&lowcost[j]<minn){
				pos=j;
				minn=lowcost[j];
			}
		}
		if(dis[pre[pos]][pos])
			printf("%d %d\n",pre[pos],pos);
		lowcost[pos]=-1;
		for(int j=1;j<=n;j++){
			if(lowcost[j]>dis[pos][j]){
				lowcost[j]=dis[pos][j];
				pre[j]=pos;
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		for(int j=1;j<i;j++){
			dis[i][j]=dis[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		}
		dis[i][i]=INT_MAX;
	}
	prim();
	return 0;
}

