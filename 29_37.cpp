//35:��һ��ֻ����һ�ε��ַ�
//����1������forѭ���ֱ�Ƚϵ�ǰ�ַ���������ÿһ���ַ�
//����2:�ռ任ʱ��
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
//36:�����е������
//��������:�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ������,�����������е�����Ե�����P

//�������£�
//����1.����forѭ��ȥ����
//����2.�鲢�����һ��������
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