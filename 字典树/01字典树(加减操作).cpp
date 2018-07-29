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
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MIN_INT (-2147483647-1)
#define MAX_INT 2147483647
#define MAX_LL 9223372036854775807i64
#define MIN_LL (-9223372036854775807i64-1)
using namespace std;

const int N = 2;
const int mod = 1000000000 + 7;
int arr[1000+5];

struct Tire{
	Tire *next[N];
	int cnt,val;
	Tire(){
		for(int i=0;i<N;i++){
			next[i]=NULL;
		}
		cnt=1;
		val=0;
	}
};

void Insert(Tire *root,const int num){
	Tire *p=root;
	int id;
	for(int i=30;i>=0;i--){
		id=(num&(1<<i));
		if(id) id=1;
		else id=0;
		if(p->next[id]==NULL){
			Tire *temp=new Tire();
			p->next[id]=temp;
			p=p->next[id];
		}
		else{
			p=p->next[id];
			(p->cnt)++;
		}
	}
	p->val=num;
}

void Delete(Tire *root,const int num){
	int id;
	Tire *p=root;
	for(int i=30;i>=0;i--){
		id=(num&(1<<i));
		if(id) id=1;
		else id=0;
		if(p->next[id]!=NULL){
			p=p->next[id];
			(p->cnt)--;
		}
	}
}

int Search(Tire *root,const int num){ 
	int id;
	Tire *p=root;
	for(int i=30;i>=0;i--){
		id=(num&(1<<i));
		if(id) id=1;
		else id=0;
		if(p->next[id^1]!=NULL&&((p->next[id^1])->cnt)>0){
			p=p->next[id^1];
		}
		else{
			p=p->next[id];
		}
	}
	return p->val;
}

void Del(Tire *root){
	for(int i=0;i<N;i++){
		if(root->next[i]!=NULL){
			Del(root->next[i]);
		}
	}
	delete root;
}

int main(){
	int t,n,ans;
	scanf("%d",&t);
	while(t--){
		Tire *root=new Tire();
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
			Insert(root,arr[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)
					continue;
				Delete(root,arr[i]);
				Delete(root,arr[j]);
				ans=max(ans,(arr[i]+arr[j])^Search(root,(arr[i]+arr[j])));
				Insert(root,arr[i]);
				Insert(root,arr[j]);
			}
		}
		printf("%d\n",ans);
		Del(root);
	}
	return 0;
}
