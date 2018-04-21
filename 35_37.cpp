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

//37.两个链表的第一个公共结点
//问题描述：输入两个链表，找出它们的第一个公共结点。

//方法1：依次将链表1的每个结点和链表2的每个结点做比较，时间复杂度为0（mn）
//方法2：建立两个栈，从后往前比，空间复杂度太高0(m+n)
//方法3：找出两个链表的长度，判断较长的链表比较短的链表长多少，然后让较长的链表先走多少，然后两个一起走。

//方法3的代码：
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