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