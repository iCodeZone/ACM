/*
1.前根序遍历：先遍历根结点，然后遍历左子树，最后遍历右子树。
2.中根序遍历：先遍历左子树，然后遍历根结点，最后遍历右子树。
3.后根序遍历：先遍历左子树，然后遍历右子树，最后遍历根节点。
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
	//数据
	char data;
	//左右孩子指针
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//按先序序列创建二叉树
int Build(BiTree &T){
	char data;
	scanf("%c",&data); 
	//按先序次序输入二叉树中结点的值，'#'表示空树
	if(data=='#'){
		T=NULL;
	} 
	else{
		T=(BiTree)malloc(sizeof(BiTNode));
		//生成根节点
		T->data=data;
		//生成左子树
		Build(T->lchild);
		//生成右子树
		Build(T->rchild); 
	}
	return 0; 
} 

//输出
void Visit(BiTree T){
	if(T->data!='#'){
		printf("%c ",T->data);
	}
} 

//先序遍历
void PreOrder(BiTree T){
	if(T!=NULL){
		//访问根节点
		Visit(T);
		//访问左子节点
		PreOrder(T->lchild);
		//访问右子节点
		PreOrder(T->rchild); 
	}
} 

//中序遍历
void InOrder(BiTree T){
	if(T!=NULL){
		//访问左子节点
		InOrder(T->lchild);
		//访问根节点
		Visit(T);
		//访问右子节点
		InOrder(T->rchild); 
	}
} 

//后序遍历
void PostOrder(BiTree T){
	if(T!=NULL){
		//访问左子节点
		PostOrder(T->lchild);
		//访问右子节点
		PostOrder(T->rchild); 
		//访问根节点
		Visit(T);
	}
} 

//层次遍历
void LevelOrder(BiTree T){
	BiTree p=T;
	queue<BiTree> q;
	//根节点入队
	q.push(p);
	while(!q.empty()){
		//对头元素出队
		p=q.front();q.pop();
		//访问p指向的结点
		printf("%c ",p->data);
		//左子树不空，将左子树入队
		if(p->lchild!=NULL){
			q.push(p->lchild);
		} 
		//右子树不空，将右子树入队
		if(p->rchild!=NULL){
			q.push(p->rchild);
		} 
	} 
} 

int main(){
	BiTree T;  
    Build(T);  
    printf("先序遍历：\n");  
    PreOrder(T);
    printf("\n");  
    printf("中序遍历：\n");  
    InOrder(T);  
    printf("\n");
    printf("后序遍历：\n");  
    PostOrder(T);  
    printf("\n");  
    printf("层次遍历：\n");  
    LevelOrder(T);  
    printf("\n");  
	return 0;
}
/*
debug
ABC##DE#G##F###
*/
