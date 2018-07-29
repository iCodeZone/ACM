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

const int N = 1000 + 5;
const int mod = 1000000000 + 7;
const double eps = 1e-8;
int mp[N][N];

int zhuliu(int mp[][N],int n,int root){
	bool vis[N];
	bool flag[N];//������Ϊtrue����õ��Ѿ���������������Ȼ����
	int pre[N];
	double sum=0;
	int i,j,k;
	for(i=0;i<=n;i++){
		flag[i]=0;
		mp[i][i]=MAX_INT;
	}
	pre[root]=root;
	while(true){
		//����̻�����E0 
		for(i=0;i<n;i++){
			if(flag[i]||i==root) continue;
			pre[i]=i; 
			for(j=0;j<n;j++){
				if(!flag[j]&&mp[j][i]<mp[pre[i]][i]){
					pre[i]=j;
				}
			}
			//û����ߣ��㷨���� 
			if(pre[i]==i) return -1;
		}
		//���E0
		for(i=0;i<n;i++){
			if(flag[i]||i==root) continue;
			//�ӵ�ǰvi��ʼ�һ�
			mem(vis,0);
			vis[root]=1;
			j=i;//�ӵ�ǰ�㿪ʼ�һ� 
			do{
				vis[j]=1;
				j=pre[j];
			}while(!vis[j]);
			if(j==root) continue;//û���ҵ���
			//����G�е�����
			i=j;
			//����������Ȩֵ���棬�ۼ���ԭͼ����С����ͼ
			do{
				sum+=mp[pre[j]][j];
				j=pre[j];
			}while(j!=i);
			j=i;
			//���뻷�ϵĵ��йصıߣ��޸ı�Ȩ
			do{
				for(k=0;k<n;k++){
					if(!flag[k]&&mp[k][j]<MAX_INT&&k!=pre[j]){
						mp[k][j]-=mp[pre[j]][j];
					}
				}
				j=pre[j];
			}while(j!=i);
			//���㣬������������i�ŵ㣬�����뻷�ϵĵ��йصı�ת�Ƶ���i
			for(j=0;j<n;j++){
				if(j==i) continue;
				for(k=pre[i];k!=i;k=pre[k]){
					if(mp[k][j]<mp[i][j]) mp[i][j]=mp[k][j];
					if(mp[j][k]<mp[j][i]) mp[j][i]=mp[j][k];
				}
			} 
			//��ǻ��������ĵ�Ϊ������
			for(j=pre[i];j!=i;j=pre[j]) flag[j]=1;
			//��ǰ������������γ��µ�ͼG'������������G'����С����ͼ
			break; 
		} 
		//������еĵ㶼�������û�л����ڣ����ڵ���̻�����E0������С����ͼ���ۼ���sum���㷨����
		if(i>=n){
			for(i=0;i<n;i++){
				if(!flag[i]&&i!=root) sum+=mp[pre[i]][i];
			}
			break;
		} 
	}
	return sum;
}

int main(){
	int n,m,u,v,w;
	while(scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				mp[i][j]=mp[j][i]=MAX_INT;
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			mp[u][v]=w;
		}
		cout<<zhuliu(mp,n,0)<<endl;
	}
	return 0;
}
/*
debug
7 15
1 2 9
4 1 3
1 5 5
2 3 3
3 2 7
2 4 9
5 4 4
6 5 3
4 3 8
4 6 5
3 6 9
3 7 6
7 3 4
6 7 4
7 6 8
*/
