#include <cstdio>
#include <cstring>
using namespace std;
#define N 100
#define M 10000

int mmap[N][N];
int vis[N];//访问标记
char s[2],to[2];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        int t,m;
        memset(mmap,-1,sizeof(mmap));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n-1;i++)
        {
            scanf("%s %d",s,&m);
            while(m--)
            {
                scanf("%s %d",to,&t);
                int u = s[0]-'A',v = to[0]-'A';
                mmap[u][v] = mmap[v][u] = t;
            }
        }
        //prim
        int ans=0;
        m=0;
        vis[0] = 1;
        while(m < n-1)
        {
            int mmin=0x3f3f3f3f,u=-1;
            for(int i=0;i<n;i++)
                if(vis[i])
                    for(int j=0;j<n;j++)
                        if(!vis[j] && mmap[i][j] != -1 && mmap[i][j] < mmin)
                        {
                            mmin = mmap[i][j];
                            u=j;
                        }
            if(mmin != 0x3f3f3f3f)
            {
                m++;
                vis[u] = 1;
                ans += mmin;
            }
            else
                break;
        }

        if(m==n-1)
            printf("%d\n",ans);
        else
            printf("0\n");//无解
    }
    return 0;
}
