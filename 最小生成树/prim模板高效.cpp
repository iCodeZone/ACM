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
#define debug cout<<"aaa"<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
using namespace std;

const int N=1000+5;
const int mod=1000000000+7;
int mmap[N][N],dis[N],ans,n;

void prim(){
	int minn,now=1,u;
	for(int i=0;i<=n;i++){
		dis[i]=INT_MAX;
	}
	for(int i=1;i<n;i++){//ÕÒn-1Ìõ±ß
		dis[now]=-1;
		minn=INT_MAX;
		for(int j=1;j<=n;j++){
			if(now!=j&&dis[j]>=0){//µÈÐ§vis 
				dis[j]=min(dis[j],mmap[now][j]);
				if(dis[j]<minn){
					minn=dis[j];
					u=j;
				}
			}
		}
		ans+=minn;
		now=u;
	}
}

int main(){
	mem(mmap,0),ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;i<=n;j++){
			scanf("%d",&mmap[i][j]);
		}
	}
	prim();
	printf("%d\n",ans);
	return 0;
}
