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