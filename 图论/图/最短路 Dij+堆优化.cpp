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

const int N = 100 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
//堆 
struct HeapElement{
	int key,value;
};
//小顶堆 
struct MinHeap{
	HeapElement H[N];//堆元素数组
	int size;//堆大小
	int Position[N];//堆中元素的位置，可以通过键值直接定位，便于修改权值
	
	//堆初始化
	void init(){
		H[size=0].value=MIN_INT;
	}
	//向堆中添加元素 
	void insert(int key,int value){
		int i,f;
		HeapElement p={key,value};
		for(i=++size;p.value<H[f=i>>1].value;i=f){
			H[i]=H[f];
			Position[H[i].key]=i;
		}
		H[i]=p;
		Position[H[i].key]=i;
	}
	//修改队中键值为key的元素的权值，并调整位置 
	void decrease(int key,int value){
		int i,f;
		HeapElement p={key,value};
		for(i=Position[key];p.value<H[f=i>>1].value;i=f){
			H[i]=H[f];
			Position[H[i].key]=i;
		}
		H[i]=p;
		Position[H[i].key]=i;
	}
	//删除栈顶元素
	void pop(){
		int i,c;
		HeapElement p=H[size--];
		for(i=1;(c=i<<1)<=size;i=c){
			if(c+1<=size&&H[c+1].value<H[c].value) c++;
			if(H[c].value<p.value){
				H[i]=H[c];
				Position[H[i].key]=i;
			}
			else break;
		}
		H[i]=p;
		Position[H[i].key]=i;
	} 
}H;

struct edge{
	int to,w;
	int next;
}edge[N];
int head[N];
int n,m,len;
long long dis[N];

void add(int i,int j,int w){
	edge[len].to=j;
	edge[len].w=w;
	edge[len].next=head[i];
	head[i]=len++;
}

void init(){
	mem(head,-1),mem(edge,0),len=0;
}

void Dijkstra(int s){
	int i,j,k;
	H.init();
	//初始化，将所有点压入堆中 
	for(int i=1;i<=n;i++){
		H.insert(i,INT_MAX);
		dis[i]=INT_MAX; 
	}
	dis[s]=0;
	H.decrease(s,0);
	for(i=s;;){
		d(i);
		H.pop();
		d(i);
		for(k=head[i];k!=-1;k=edge[k].next){
			if(dis[i]<dis[j=edge[k].to]-edge[k].w){
				dis[j]=dis[i]+edge[k].w;
				H.decrease(j,dis[j]);
			}
		}
		if(H.size)
			i=H.H[1].key;
		else
			break;
	}
}

int main(){
	int n,m,u,v,w;
	init();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	//	add(v,u,w);
	}
	for(int i=1;i<=n;i++){
		Dijkstra(1);
		for(int j=1;j<=n;j++){
			cout<<dis[j]<<endl;
		}
	}
	return 0;
}
/*
debug
5 7
1 2 10
1 3 3
1 4 9
2 3 4
2 5 1
3 5 2
4 5 3
*/
