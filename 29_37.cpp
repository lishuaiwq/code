//35:第一次只出现一次的字符
//方法1：两个for循环分别比较当前字符和其后面的每一个字符
//方法2:空间换时间
char fun(char *src)
{
	char dest[256] = {0};
	int size = strlen(src);
	char *s = new char[size + 1];
	strcpy(s, src);
	while (*s)
	{
		++dest[*s];
		s++;
	}
	while (*src)
	{
		if (dest[*src] == 1)
			return *src;
		src++;
	}
}
//36:数组中的逆序对
//问题描述:在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P

//代码如下：
//方法1.两个for循环去遍历
//方法2.归并排序加一个计数器
int sum = 0;
void Merge_sort(int* arr, int left, int right, int mid, int *tmp)
{
	int begin1 = mid;
	int begin2 = right;
	int index = right;
	while (begin1 >= left&&begin2 >= mid + 1)
	{
		if (arr[begin1] > arr[begin2])
		{
			sum = sum + (begin2 - mid);
			tmp[index--] = arr[begin1--];
		}
		else
		{
			tmp[index--] = arr[begin2--];
		}
	}
	while (begin1 >= left)
		tmp[index--] = arr[begin1--];
	while (begin2 >= mid + 1)
		tmp[index--] = arr[begin2--];
	memcpy(arr + left, tmp + left, sizeof(int)*(right - left + 1));
}