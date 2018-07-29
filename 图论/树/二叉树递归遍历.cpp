/*
1.ǰ����������ȱ�������㣬Ȼ���������������������������
2.�и���������ȱ�����������Ȼ���������㣬��������������
3.�����������ȱ�����������Ȼ����������������������ڵ㡣
*/
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

typedef struct BiTNode{
	//����
	char data;
	//���Һ���ָ��
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//���������д���������
int Build(BiTree &T){
	char data;
	scanf("%c",&data); 
	//�������������������н���ֵ��'#'��ʾ����
	if(data=='#'){
		T=NULL;
	} 
	else{
		T=(BiTree)malloc(sizeof(BiTNode));
		//���ɸ��ڵ�
		T->data=data;
		//����������
		Build(T->lchild);
		//����������
		Build(T->rchild); 
	}
	return 0; 
} 

//���
void Visit(BiTree T){
	if(T->data!='#'){
		printf("%c ",T->data);
	}
} 

//�������
void PreOrder(BiTree T){
	if(T!=NULL){
		//���ʸ��ڵ�
		Visit(T);
		//�������ӽڵ�
		PreOrder(T->lchild);
		//�������ӽڵ�
		PreOrder(T->rchild); 
	}
} 

//�������
void InOrder(BiTree T){
	if(T!=NULL){
		//�������ӽڵ�
		InOrder(T->lchild);
		//���ʸ��ڵ�
		Visit(T);
		//�������ӽڵ�
		InOrder(T->rchild); 
	}
} 

//�������
void PostOrder(BiTree T){
	if(T!=NULL){
		//�������ӽڵ�
		PostOrder(T->lchild);
		//�������ӽڵ�
		PostOrder(T->rchild); 
		//���ʸ��ڵ�
		Visit(T);
	}
} 

//��α���
void LevelOrder(BiTree T){
	BiTree p=T;
	queue<BiTree> q;
	//���ڵ����
	q.push(p);
	while(!q.empty()){
		//��ͷԪ�س���
		p=q.front();q.pop();
		//����pָ��Ľ��
		printf("%c ",p->data);
		//���������գ������������
		if(p->lchild!=NULL){
			q.push(p->lchild);
		} 
		//���������գ������������
		if(p->rchild!=NULL){
			q.push(p->rchild);
		} 
	} 
} 

int main(){
	BiTree T;  
    Build(T);  
    printf("���������\n");  
    PreOrder(T);
    printf("\n");  
    printf("���������\n");  
    InOrder(T);  
    printf("\n");
    printf("���������\n");  
    PostOrder(T);  
    printf("\n");  
    printf("��α�����\n");  
    LevelOrder(T);  
    printf("\n");  
	return 0;
}
/*
debug
ABC##DE#G##F###
*/
