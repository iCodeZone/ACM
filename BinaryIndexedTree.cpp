/****************************************************************************
树状数组 ( Binary Indexed Tree，BIT，二分索引树 )

模板示例 by ouzheng 2017.2.16

树状数组的基础是一个被构造出来的式子:C[i]=A[i]+A[i-1]+....+A[i-2^k+1];k代表i的二进制的最后连续0的个数 比如 对于1000和101000，k=3。

特性：
1.对于两个数组下标x，y(x < y)，如果x + 2^k = y (k等于x的二进制表示中末尾0的个数)，那么定义(y, x)为一组树上的父子关系，其中y为父结点，x为子结点。

主要函数：
1、add( x,value)(1<=x<=n)		对第i个元素的值自增value       O(logn)
2、sum( x )   (1<=x<=n)			统计[1...x]元素值的和          O(logn)

Example Array(size = 10):
10 11 25 36 98 456465 21254 8 66 15451 
****************************************************************************/

#include <iostream>
using namespace std;

#define MAX_NUM 500 
#define lowbit(x) (x&(-x))
//lowbit(k)就是把k的二进制的高位1全部清空，只留下最低位的1,比如10的二进制是1010,则lowbit(k)=lowbit(1010)=0010(2进制)

void print_Array(int* Array, int printSize, int beginPos = 1);
void add(int x, int value);
int sum(int* Array, int x);

int A[MAX_NUM];
int arraySize;
int BitTree[MAX_NUM];

int main()
{
	cout << "******************************Binary Indexed Tree**************************" << endl << endl;
	cout << "********************************Example Start******************************" << endl << endl;
	cout << "Please input the array size( <=500 ):" << endl;

	cin >> arraySize;
	cout << endl;
	cout << "Please input the array num( <=1000000 ):" << endl;

	for (int i = 1; i <= arraySize; ++i)
	{
		cin >> A[i];
	}

	//print_Array(A, arraySize);

	for (int i = 1; i <= arraySize; ++i)
	{
		BitTree[i] = 0;
		for (int j = i; (j >= (i - lowbit(i)+1)) && (j>=0); j--)
		{
			BitTree[i] += A[j];
		}
	}
	cout << "the Binary Indexed Tree:" << endl;
	print_Array(BitTree, arraySize);

	int Index = 0;
	cout << "Please input the array Sum Index:" << endl;
	cin >> Index;

	cout << "The Sum :" << endl;
	cout << sum(BitTree, Index) << endl;

	int addIndex = 0;
	int addValue = 0;
	cout << "Please input the array add Index:" << endl;
	cin >> addIndex;

	cout << "Please input the array add Value:" << endl;
	cin >> addValue;

	add(addIndex, addValue);

	cout << "Fresh Binary Indexed Tree:" << endl;
	print_Array(BitTree, arraySize);

	cout << "********************************Example End******************************" << endl << endl;

	return 0;
}

void print_Array(int* Array, int printSize, int beginPos)
{
	for (int i = beginPos; i <= printSize; ++i)
	{
		cout << Array[i] << " ";
		if (i % 20 == 19)
			cout << endl;
	}
	cout << endl<<endl;
}

void add(int x, int value)
{//原始数据变化 只会影响 x及后面的树状数组值
	while (x <= arraySize)
	{
		BitTree[x] += value;
		x += lowbit(x);
	}
}

int sum(int* Array, int x)
{
	int Sum = 0;

	for (int i = x; i; i-= lowbit(i))
	{
		Sum += Array[i];
	}

	return Sum;
}