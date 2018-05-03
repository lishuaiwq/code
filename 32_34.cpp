//32：整数中1出现的次数
//问题描述：
//求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

//解决方法1：
//分别判断每一位是否为1.是1的话则计数就可以了

int NumberOf1Between1AndN_Solution(int n)
{
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		int n = i;
		while (n)
		{
			if (n % 10 == 1)
				++result;
			n = n / 10;
		}
	}
	return result;
}

//解决方法2：

//分别判断每一位为0或者1或者大于1的时候，这个位取1的情况有多少种。

//30:TopK问题

方法1.使用大小堆解决，
首先创建一个大小为K的堆，取n个数中的前K个，然后如果要是找出最大的元素的话则建立小堆
然后对于后面的元素进行插入，插入前和堆中最小的元素比较，如果比最小的元素大的话，则替换最小的 元素，然后继续调整额，
直到将整个数组遍历完成以后，堆中的元素就是最小的元素
void Adjust(int *arr, int parent, int size)//此例子是找最大的前4个元素
{
	int child = parent * 2 + 1;
	while (child <= size - 1)
	{
		if (child + 1 <= size - 1 && arr[child]>arr[child + 1])
			++child;
		if (arr[parent]>arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void Topk(int *arr, int size, int k)
{
	int *tmp = new int[k];
	int index;
	for (index = 0; index < k; index++)
		tmp[index] = arr[index];
	for (int i = ((k - 2) >> 1); i >= 0; i--)
		Adjust(tmp, i, k);
	for (int j = index; j < size; j++)
	{
		if (tmp[0] < arr[j])
		{
			tmp[0] = arr[j];
			Adjust(tmp, 0, k);
		}
	}
	for (int m = 0; m < k; m++)
		cout << tmp[m] << " " << endl;
}
int main()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23 };
	Topk(array, 8, 4);
	system("pause");
	return 0;
}

//方法2使用multiset

求前K个最大的值，则建立一个less的set，燃后set中的元素等于四个以后，只要大于set.begin则将set的begin删除，将新的插入

#include<vector>
multiset<int, less<int>> test(const vector<int>& data, int k)//将数据数组传过来
{

	if (k < 1 || k > data.size())//如果元素小于l或者小于1则直接退出
		return;
	multiset<int, less<int>> tok;//创建一个set，相当于创建一个k个大小的容易
	vector<int>::const_iterator it_data = data.begin();//注意const_iterator
	for (; it_data != data.end(); ++it_data)
	{
		if (tok.size() < k)
		{
			tok.insert(*it_data);
		}
		else
		{
			multiset<int, less<int>>::iterator it_tok = tok.begin();
			if ((*it_tok)<*it_data)
			{
				tok.erase(*it_tok);
				tok.insert(*it_data);
			}
		}
	}
	return tok;
}
int main()
{
	vector<int> s = { 53, 17, 78, 9, 45, 65, 87, 23 };
	multiset<int, less<int>> reslut = test(s, 4);

	system("pause");
	return 0;
}


