//29�������г��ִ�������һ���Ԫ��

���ⷽ��1��������������������м��Ԫ�ؾ�������Ҫ�ҵ�Ԫ��

���ⷽ��2��ʹ�ù�ϣ��˼�룬�������б�ͳ��ÿ��Ԫ�س��ֵĴ�����Ȼ���ҳ����ִ�������һ�������
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
���ⷽ��3����Ϊ����Ҫ�ҵ�Ԫ�س�������������Ԫ�صĳ��ִ�������������ÿ��ɾ��������ͬ�����֣������ʣ�µ���һ�����֣�һ��������Ҫ�ҵ�Ԫ��
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

28.�ַ���������
��������������һ���ַ���, ���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc, ���ӡ�����ַ�a, b, c�������г����������ַ���abc, acb, bac, bca, cab��cba��

���ⷽ����ȫ����

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
			Permie(arr,front+1, end);//���ﲻ�ܱ�ã�
			Swap(arr, i, front);
			
		}
	}
}

28.������ת˫������

1.�����������������prev���б������ݹ�д��
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

2.�ǵݹ��д������ʹ�÷ǵݹ�ķ�ʽ�������������
TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* cur = pRootOfTree;
	TreeNode* prev = NULL;
	stack<TreeNode*> s;
	while (cur || !s.empty())
	{
		while (cur)//��cur�����ڿյ�ʱ��ѹ��ȥ
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
