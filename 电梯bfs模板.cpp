#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int btn[205];	
int n,a,b;
int vis[205];
int check(int t){
	if(t>0&&t<=n&&!vis[t]) return 1;
	else return 0;
}
struct node{
	int v,step;
	node(){}
	node(int a,int b){v=a;step=b;}
}k,tk;
void bfs(int a,int b){
	queue<node>q;
	k=node(a,0);
	vis[a]=1;
	q.push(k);
	while(!q.empty()){
		k=node(q.front().v,q.front().step);	
		if(k.v==b){
			cout<<k.step<<endl;
			return;
		}
		//cout<<k.v<<' '<<k.step<<endl;
		q.pop();
		for(int i=-1;i<2;i+=2){
			tk.v=k.v+(i)*btn[k.v];
			//cout<<k<<"->"<<tk<<endl;
			if(check(tk.v)){
				tk.step=k.step+1;
				vis[tk.v]=1;
				q.push(tk);
				}
				
		}
	}
	cout<<-1<<endl;
	return;
}
void init(){
	memset(vis,0,sizeof(vis));
	memset(btn,0,sizeof(btn));
}
int main(){
	while(~scanf("%d",&n)&&n){
		scanf("%d%d",&a,&b);
		init();
		for(int i=1;i<=n;i++)
			scanf("%d",&btn[i]);
		bfs(a,b);
	}
	return 0;
}	
