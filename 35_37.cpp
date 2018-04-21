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

//37.��������ĵ�һ���������
//�����������������������ҳ����ǵĵ�һ��������㡣

//����1�����ν�����1��ÿ����������2��ÿ��������Ƚϣ�ʱ�临�Ӷ�Ϊ0��mn��
//����2����������ջ���Ӻ���ǰ�ȣ��ռ临�Ӷ�̫��0(m+n)
//����3���ҳ���������ĳ��ȣ��жϽϳ�������Ƚ϶̵��������٣�Ȼ���ýϳ����������߶��٣�Ȼ������һ���ߡ�

//����3�Ĵ��룺
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		int count1 = 0, count2 = 0;
		ListNode* List1 = pHead1;
		ListNode* List2 = pHead2;
		while (List1)
		{
			List1 = List1->next;
			++count1;
		}
		while (List2)
		{
			List2 = List2->next;
			++count2;
		}
		int n = (count1>count2 ? count1 : count2) - (count1>count2 ? count2 : count1);
		while (n--)
		{
			pHead1 = pHead1->next;
		}
		while (pHead1&&pHead2)
		{
			if (pHead1 == pHead2)
				return pHead1;
			else
			{
				pHead1 = pHead1->next;
				pHead2 = pHead2->next;
			}
		}
		return NULL;
	}
};