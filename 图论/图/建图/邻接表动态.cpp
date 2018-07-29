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

const int N = 100000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;

struct EdgeNode{//邻接表结点 
	int to,w;//终点和权值
	EdgeNode* next;//指向下一条边的指针 
};

struct VNode{//起点表结点 
	int from;//起点 
	EdgeNode* first;//邻接表头指针 
};
VNode list[N];//整个图的邻接表 

void add(){
	int i,j,w;
	scanf("%d%d%d",&i,&j,&w);
	EdgeNode* p=new EdgeNode();
	p->to=j;
	p->w=w;
	p->next=list[i].first;
	list[i].first=p;
} 

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		add();
	}
	for(int i=1;i<=n;i++){
		for(EdgeNode* k=list[i].first;k!=NULL;k=k->next){
			cout<<i<<" "<<k->to<<" "<<k->w<<endl;
		}
	}
	return 0;
}
/*
debug
12
5 8 29
6 1 12
8 3 11
1 2 4
3 1 22
4 3 17
7 4 25
6 5 9
8 7 7
1 6 9
3 2 19
6 7 4
*/
