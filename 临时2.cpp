//hhh 给小傻子看
#include <iostream>
using namespace std;
class Array
{
public:
	Array(int (&p)[4][4], int y);
	int fun(int n);
	void intencode();
	void print();
	void printcount();
private:
	int a[4][4];
	int count;
};
Array::Array(int(&p)[4][4], int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			a[i][j] = p[i][j];
	}
	count = y;
}
int Array::fun(int n)  //小傻子 判断个素数为啥总是这么复杂呢hhh
{
	if (n == 2 || n == 3) return 1;
	if (n == 1) return 0;
	int i;
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return 0;
	}
    return 1; 
}

void Array::intencode()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= i; j++)
			if (fun(a[i][j]))
			{
				count++;
				int w = a[i][j] + 1;
				while(fun(w)==0)
				w++;

				a[i][j] = w;
			}
	}
}
void Array::print()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j] << " ";
		}
		if(i!=3) cout << endl;
	}
}

void Array::printcount()
{
	cout << endl<<"count="<< count << endl;
}

int main()
{
	int xx[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			cin >> xx[i][j];
	}
	Array A(xx, 0);
	A.print();
	cout << endl; //为了格式问题 前面不输出 这边单独输出
	A.intencode();
	A.printcount(); //重新写一个函数来访问私有数据成员呢
	A.print();
}