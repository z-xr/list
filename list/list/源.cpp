#include<iostream>
using namespace std;

//1.定义
typedef struct Node* List;
struct Node {
	int num;
	Node* next;
};

void input(int* a)
{
	cin >> *a;
}

//2.创建链表
void CreateList(List* L, int n, void (*input)(int* a))
{
	List s;
	*L = new Node;
	(*L)->next = NULL;
	List LL = *L;
	LL->num = 1000;
	for (; n > 0; n--) {
		s = new Node;
		input(&s->num);
		s->next = (*L)->next;
		(*L)->next = s;

	}
}

//3.链表长度
int Length(List L)
{
	List p = L;
	int j = 0;
	while (p)
	{
		p = p->next;
		j++;
	}
	return j;
}

//4.按序号查找
List FindKth(int k, List Ptrl)
{
	List p = Ptrl;
	int i = 1;
	while (p != NULL && i < k) {
		p = p->next;
		i++;
	}
	if (i == k)return p;
	else return NULL;

}

//5.按值查找
List Find(int x, List Ptrl)
{
	List p = Ptrl;
	while (p != NULL && p->num != x) {
		p = p->next;
	}
	return p;
}

//6.插入
List Insert(int x, int i, List Ptrl)
{
	List p, s;
	if (i == 1) {
		s = new Node;
		s->num = x;
		s->next = Ptrl;
		return s;
	}
	p = FindKth(i - 1, Ptrl);
	if (p == NULL) {
		cout << "参数i错" << endl;
		return NULL;
	}
	else {
		s = new Node;
		s->num = x;
		s->next = p->next;
		p->next = s;
		return Ptrl;
	}
}

//7.删除
List Delete(int i, List Ptrl)
{
	List p, s;
	if (i == 1) {
		s = Ptrl;
		Ptrl = Ptrl->next;
		delete s;
		return Ptrl;
	}
	p = FindKth(i - 1, Ptrl);
	if (p == NULL) {
		cout << "第" << i - 1 << "个结点不存在" << endl;
		return NULL;
	}
	else if (p->next == NULL) {
		cout << "第" << i << "个结点不存在" << endl;
		return NULL;
	}
	else {
		s = p->next;
		p->next = s->next;
		delete s;
		return Ptrl;
	}
}

int main()
{
	List L;
	int n;
	int len;
	cin >> n;
	CreateList(&L, n, input);

	cout << "--------------------------" << endl;
	int i;
	List L1 = L;
	for (i = 0; i < n; i++) {
		L1 = L1->next;
		cout << L1->num << endl;
	}
	cout << "--------------------------" << endl;
	List L2 = L;
	L2 = Delete(2, L2);
	for (i = 0; i < n - 1; i++) {
		L2 = L2->next;
		cout << L2->num << endl;
	}

	return 0;
}