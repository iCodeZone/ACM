#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100
#define M 10000
struct edge
{
    int u,v,val;//u点连接到v点的无向边权值是val
}E[M];
int e=0;//边计数器

int F[N];

bool cmp(edge a,edge b)//排序所用的比较函数
{
    return a.val<b.val;
}

int findf(int x)//并查集操作
{
    if(F[x] == -1)
        return x;
    return F[x]=findf(F[x]);
}

char s[2],to[2];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        int t,m;
        memset(E,-1,sizeof(E));
        memset(F,-1,sizeof(F));
        e=0;
        for(int i=0;i<n-1;i++)
        {
            scanf("%s %d",s,&m);
            while(m--)
            {
                scanf("%s %d",to,&t);
                E[e].u=s[0]-'A';
                E[e].v=to[0]-'A';
                E[e++].val=t;
            }
        }
        //Kruskal
        int ans=0;
        m=0;
        sort(E,E+e,cmp);//排序
        for(int i=0;i<e;i++)
        {
            int u=E[i].u;
            int v=E[i].v;
            int w=E[i].val;
            if(findf(u)!=findf(v))
                ans+=w,F[findf(u)]=findf(v),m++;//合并
            if(m==n-1)
                break;
        }

        if(m==n-1)
            printf("%d\n",ans);
        else
            printf("0\n");//无解
    }
    return 0;
}
