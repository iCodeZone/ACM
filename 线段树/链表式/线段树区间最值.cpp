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

const int N = 200000 + 5;
const int mod = 1000000000 + 7;

int arr[N];

/*
���ܣ������߶���
root����ǰ�߶����ĸ��ڵ��±�
arr: ���������߶���������
istart���������ʼλ��
iend������Ľ���λ��
*/
struct SegTreeNode
{
    int val;
    int addMark;//�ӳٱ��
}segTree[N*20];//�����߶���

/*
���ܣ������߶���
root����ǰ�߶����ĸ��ڵ��±�
arr: ���������߶���������
istart���������ʼλ��
iend������Ľ���λ��
*/
void build(int root, int istart, int iend)
{
    segTree[root].addMark = 0;//----���ñ��ӳټ���
    if(istart == iend)//Ҷ�ӽڵ�
        segTree[root].val = arr[istart];
    else
    {
        int mid = (istart + iend) / 2;
        build(root*2, istart, mid);//�ݹ鹹��������
        build(root*2+1, mid+1, iend);//�ݹ鹹��������
        //���������������ڵ��ֵ�����µ�ǰ���ڵ��ֵ
		segTree[root].val = max(segTree[root*2].val, segTree[root*2+1].val);
    }
}

/*
���ܣ���ǰ�ڵ�ı�־�����ӽڵ㴫��
root: ��ǰ�߶����ĸ��ڵ��±�
*/
void pushDown(int root)
{
    if(segTree[root].addMark != 0)
    {
        //�������Һ��ӽڵ�ı�־����Ϊ���ӽڵ���ܱ�����ӳٱ����û�����´���
        //������ ��+=��
        segTree[root*2].addMark = segTree[root].addMark;
        segTree[root*2+1].addMark = segTree[root].addMark;
        //���ݱ�־�����ú��ӽڵ��ֵ����Ϊ��������������Сֵ����˵�������ÿ��Ԫ
        //�ؼ���һ��ֵʱ���������СֵҲ�������ֵ
        segTree[root*2].val = segTree[root].addMark;
        segTree[root*2+1].val = segTree[root].addMark;
        //���ݺ󣬵�ǰ�ڵ��������
        segTree[root].addMark = 0;
    }
}

/*
���ܣ��߶����������ѯ
root����ǰ�߶����ĸ��ڵ��±�
[nstart, nend]: ��ǰ�ڵ�����ʾ������
[qstart, qend]: �˴β�ѯ������
*/
int query(int root, int nstart, int nend, int qstart, int qend)
{
    //��ѯ����͵�ǰ�ڵ�����û�н���
    if(qstart > nend || qend < nstart)
        return 0;
    //��ǰ�ڵ���������ڲ�ѯ������
    if(qstart <= nstart && qend >= nend)
        return segTree[root].val;
    //�ֱ������������ѯ���������߲�ѯ����Ľ�Сֵ
    pushDown(root); //----�ӳٱ�־�����´���
    int mid = (nstart + nend) / 2;
    int a,b;
    a=query(root*2, nstart, mid, qstart, qend);
    b=query(root*2+1, mid + 1, nend, qstart, qend);
    return max(a,b);
}

/*
���ܣ������߶�����ĳ��������Ҷ�ӽڵ��ֵ
root����ǰ�߶����ĸ��ڵ��±�
[nstart, nend]: ��ǰ�ڵ�����ʾ������
[ustart, uend]: �����µ�����
addVal: ���µ�ֵ��ԭ����ֵ����addVal��
*/
void update(int root, int nstart, int nend, int ustart, int uend, int addVal)
{
    //��������͵�ǰ�ڵ�����û�н���
    if(ustart > nend || uend < nstart)
        return ;
    //��ǰ�ڵ���������ڸ���������
    if(ustart <= nstart && uend >= nend)
    {
        segTree[root].addMark = addVal;
        segTree[root].val = addVal;
        return ;
    }
    pushDown(root); //�ӳٱ�����´���
    //�������Һ��ӽڵ�
    int mid = (nstart + nend) / 2;
    int a,b;
    update(root*2, nstart, mid, ustart, uend, addVal);
    update(root*2+1, mid+1, nend, ustart, uend, addVal);
    //��������������ֵ���ݸ��µ�ǰ�ڵ��ֵ
    segTree[root].val = max(segTree[root*2].val, segTree[root*2+1].val);
}

int main(){
	int n,m,x,y,ans;
	char op[2];
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%d",&arr[i]);
		}
		build(1,1,n);
		/*for(int i=1;i<=n;i++){
			cout<<query(1,1,n,1,i)<<endl;
		}
		system("pause");*/
		while(m--){
			scanf("%s%d%d",op,&x,&y);
			if(op[0]=='Q'){
				ans=query(1,1,n,x,y);
				printf("%d\n",ans);
			}
			else{
				update(1,1,n,x,x,y);
			}
		}
	}
	return 0;
}
