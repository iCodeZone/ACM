#include<bits/stdc++.h>
#define debug cout<<"aaa"<<endl
#define d(a) cout<<a<<endl
#define pb push_back
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
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;

int next[N],now[N];
map<int,int> id;

int main(){
	int n,num,cnt;
	while(~scanf("%d",&n)){
		cnt=0,mem(next,INF),mem(now,-1);
		for(int i=1;i<=n;i++){
			cin>>num;
			if(!id.count(num)) id[num]=++cnt;
			num=id[num];
			if(now[num]!=-1) next[now[num]]=i;
			now[num]=i;
		}
		cout<<"now:";
		for(int i=0;i<id.size();i++){
			cout<<now[id[i]]<<" ";
		}
		cout<<endl;
		cout<<"next:";
		for(int i=1;i<=n;i++){
			cout<<next[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
