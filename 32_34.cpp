//32��������1���ֵĴ���
//����������
//���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�����

//�������1��
//�ֱ��ж�ÿһλ�Ƿ�Ϊ1.��1�Ļ�������Ϳ�����

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

//�������2��

//�ֱ��ж�ÿһλΪ0����1���ߴ���1��ʱ�����λȡ1������ж����֡�

//30:TopK����

����1.ʹ�ô�С�ѽ����
���ȴ���һ����СΪK�Ķѣ�ȡn�����е�ǰK����Ȼ�����Ҫ���ҳ�����Ԫ�صĻ�����С��
Ȼ����ں����Ԫ�ؽ��в��룬����ǰ�Ͷ�����С��Ԫ�رȽϣ��������С��Ԫ�ش�Ļ������滻��С�� Ԫ�أ�Ȼ����������
ֱ�������������������Ժ󣬶��е�Ԫ�ؾ�����С��Ԫ��
void Adjust(int *arr, int parent, int size)//��������������ǰ4��Ԫ��
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

//����2ʹ��multiset

��ǰK������ֵ������һ��less��set��ȼ��set�е�Ԫ�ص����ĸ��Ժ�ֻҪ����set.begin��set��beginɾ�������µĲ���

#include<vector>
multiset<int, less<int>> test(const vector<int>& data, int k)//���������鴫����
{

	if (k < 1 || k > data.size())//���Ԫ��С��l����С��1��ֱ���˳�
		return;
	multiset<int, less<int>> tok;//����һ��set���൱�ڴ���һ��k����С������
	vector<int>::const_iterator it_data = data.begin();//ע��const_iterator
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


