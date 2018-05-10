//29：数组中出现次数超过一半的元素

解题方法1：对整个数组进行排序，中间的元素就是我们要找的元素

解题方法2：使用哈希的思想，建立三列表统计每个元素出现的次数，然后找出出现次数大于一半的数字
void Solution(int *array, int size)
{
	int *arr = new int[size];
	memset(arr, 0, sizeof(int)*size);
	int mid = size >> 1;

	for (int i = 0; i < size; i++)
		++arr[array[i]];
	for (int j = 0; j < size; j++)
	{
		if (arr[j]>mid)
			cout << j << " " << endl;
	}
}
解题方法3：因为我们要找的元素超过其他的所有元素的出现次数，所以我们每次删除两个不同的数字，则最后剩下的那一个数字，一定是我们要找的元素
void Solution(vector<int>& s)
{
	int n = s.size();
	int count = 1;
	int result = s[0];
	for (int i = 1; i < n; i++)
	{
		if (count == 0)
			result = s[i];
		else if (result != s[i])
			--count;
		else
			++count;
	}
	cout << result << endl;
}

28.字符串的排列
问题描述：输入一个字符串, 按字典序打印出该字符串中字符的所有排列。例如输入字符串abc, 则打印出由字符a, b, c所能排列出来的所有字符串abc, acb, bac, bca, cab和cba。

解题方法：全排列

void Swap(int *arr, int a, int b)
{
	swap(arr[a], arr[b]);
}
void Permie(int *arr, int front, int end)
{
	if (front == end)
	{
		for (int i = 0; i < end; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int i = front; i < end; i++)
		{
			Swap(arr,i,front);
			Permie(arr,front+1, end);//这里不能变得！
			Swap(arr, i, front);
			
		}
	}
}

28.搜索树转双向链表

1.根据中序遍历，设置prev进行遍历，递归写法
PNode TransList()
{
	PNode prev = NULL;
	_TransList(_pRoot, &prev);
	while (_pRoot->_left)
	{
		_pRoot = _pRoot->_left;
	}
	return _pRoot;
}
private:
	void _TransList(PNode pRoot, PNode *prev)
	{
		if (pRoot)
		{
			_TransList(pRoot->_left, &(*prev));
			if (*prev)
			{
				(*prev)->_right = pRoot;
			}
			pRoot->_left = *prev;
			*prev = pRoot;
			_TransList(pRoot->_right, &(*prev));
		}
	}

2.非递归的写法，即使用非递归的方式中序遍历二叉树
TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* cur = pRootOfTree;
	TreeNode* prev = NULL;
	stack<TreeNode*> s;
	while (cur || !s.empty())
	{
		while (cur)//当cur不等于空的时候压进去
		{
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		if (prev)
		{
			prev->right = cur;
		}
		cur->left = prev;
		prev = cur;
		s.pop();
		if (cur->right)
		{
			cur = cur->right;
		}
		else
		{
			cur = NULL;
		}
	}
	while (pRootOfTree->left)
	{
		pRootOfTree = pRootOfTree->left;
	}
	return pRootOfTree;
}
