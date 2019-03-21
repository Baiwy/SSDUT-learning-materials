#include "Queue.h"
#include "Stack.h"
template <class T> 
class BinaryTree;
template <class T> 
class BinaryTreeNode {
friend void InOrder(BinaryTreeNode<T> *t);
friend void PreOrder(BinaryTreeNode<T> *t);
friend void PostOrder(BinaryTreeNode<T> *t);
friend void LevelOrder(BinaryTreeNode<T> *t);
friend void InOrderTranverse(BinaryTreeNode<T> *t);
public:
	BinaryTreeNode(){LeftChild=RightChild=0;}
	BinaryTreeNode(const T& e)
	{
		data=e;
		LeftChild=RightChild=0;
	}
	BinaryTreeNode(const T&e, BinaryTreeNode *l,BinaryTreeNode *r)
	{
		data=e;
		LeftChild=l;
		RightChild=r;
		
	}
private:
	T data;
	BinaryTreeNode<T> *LeftChild;//������
	BinaryTreeNode<T> *RightChild;//������
};
template <class T>
void PreOrder(BinaryTreeNode<T> *t)
{//��*t����ǰ�����
	if(t){
		cout<<t->data;           //���ʸ����
		PreOrder(t->LeftChild);  //ǰ�����������
		PreOrder(t->RightChild); //ǰ�����������
	}
	
}
template <class T>
void InOrder(BinaryTreeNode<T> *t)
{//��*t�����������
	if(t){
		InOrder(t->LeftChild);  //�������������
		cout<<t->data;           //���ʸ����
		InOrder(t->RightChild); //�������������
	}
	
}
template <class T>
void PostOrder(BinaryTreeNode<T> *t)
{//��*t���к������
	if(t){
		PostOrder(t->LeftChild);  //�������������
		PostOrder(t->RightChild); //�������������
		cout<<t->data;           //���ʸ����
	}
	
}
template <class T>
void InOrderTranverse(BinaryTreeNode<T> *t)//��������ǵݹ��㷨
{
	Stack<BinaryTreeNode<T>*> s(20);
	BinaryTreeNode<T> *p;
	p=t;
	while(p||!s.IsEmpty())
	{
		if(p){s.Add(p);p=p->LeftChild;}
		else
		{
			s.Delete(p);
			cout<<p->data;
			p=p->RightChild;
		}
	}
}
template <class T>
void LevelOrder(BinaryTreeNode<T> *t)
{//��*t������
	BinaryTreeNode<T> *p=t;
	Queue<BinaryTreeNode<T>*> Q;
	while(p)
	{
		cout<<p->data;//����p
		//��p�ĺ��ӷ������
		if(p->LeftChild) Q.Add(p->LeftChild);
		if(p->RightChild) Q.Add(p->RightChild);
		
		//������һ�����
		if(Q.IsEmpty())
			return;
		else
			Q.Del(p);
	}
}
