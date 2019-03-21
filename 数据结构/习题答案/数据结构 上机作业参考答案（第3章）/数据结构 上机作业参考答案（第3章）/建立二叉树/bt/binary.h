#include "Queue.h"
template <class T> 
class BinaryTree;
template <class T> 
class BinaryTreeNode {
friend BinaryTree<T>;
friend void InOrder(BinaryTreeNode<T> *t);
friend void PreOrder(BinaryTreeNode<T> *t);
friend void PostOrder(BinaryTreeNode<T> *t);
friend void LevelOrder(BinaryTreeNode<T> *t);
friend void InOrderTranvers(BinaryTreeNode<T> *t);
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
void LevelOrder(BinaryTreeNode<T> *t)
{//��*t������
	BinaryTreeNode<T> *p=t;
	LinkedQueue<BinaryTreeNode<T>*> Q;
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
template <class T>
class BinaryTree
{
public:
	BinaryTree(){root=0;}
	~BinaryTree(){};
	bool IsEmtpy() const
	{ return ((root)?false:true); }
	bool Root(T& x) const;
	void MakeTree(const T& element,BinaryTree<T>& left,BinaryTree<T>& right);
	void BreakTree(T& element,BinaryTree<T>& left,BinaryTree<T>& right);
    void InOrder() {InOrd(root);}
	void PreOrder(){PreOrd(root);}
	void PostOrder() {PostOrd(root);}
	void LevelOrder() {LevelOrd(root);}
	int High(){return Height(root);} 
	int Total(){return TotalCount(root);} //ͳ�ƽ����
private:
	BinaryTreeNode<T> *root;//�����ָ��
	void InOrd(BinaryTreeNode<T> *t);
	void PreOrd(BinaryTreeNode<T> *t);
	void PostOrd(BinaryTreeNode<T> *t);
	void LevelOrd(BinaryTreeNode<T> *t);	
	int Height(BinaryTreeNode<T> *t);
	int TotalCount(BinaryTreeNode<T> *t);//ͳ�ƽ����
};
template<class T>
bool BinaryTree<T>::Root(T& x) const
{
	if(root){x=root->data; return true;}
	else  return false;
}
template<class T>
void BinaryTree<T>::MakeTree(const T& element,BinaryTree<T>& left,BinaryTree<T>& right)
{
	root=new BinaryTreeNode<T>(element,left.root,right.root);
	left.root=right.root=0;
}
template<class T>
void BinaryTree<T>::BreakTree( T& element,BinaryTree<T>& left,BinaryTree<T>& right)
{
	if(!root) {cout<<"no tree node"<<endl; return;}
	element=root->data;
	left.root=root->LeftChild;
	right.root=root->RightChild;
	delete root;
	root=0;
}
template <class T>
void BinaryTree<T>::PreOrd(BinaryTreeNode<T> *t)
{//��*t����ǰ�����
	if(t){
		cout<<t->data;           //���ʸ����
		PreOrd(t->LeftChild);  //ǰ�����������
		PreOrd(t->RightChild); //ǰ�����������
	}
	
}
template <class T>
void BinaryTree<T>::InOrd(BinaryTreeNode<T> *t)
{//��*t�����������
	if(t){
		InOrd(t->LeftChild);  //�������������
		cout<<t->data;           //���ʸ����
		InOrd(t->RightChild); //�������������
	}
	
}
template <class T>
void BinaryTree<T>::PostOrd(BinaryTreeNode<T> *t)
{//��*t���к������
	if(t){
		PostOrd(t->LeftChild);  //�������������
		PostOrd(t->RightChild); //�������������
		cout<<t->data;           //���ʸ����
	}
	
}
template <class T>
void BinaryTree<T>::LevelOrd(BinaryTreeNode<T> *t)
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

template <class T>
int BinaryTree<T>::Height(BinaryTreeNode<T> *t) 
{//������*t�ĸ߶�
	if(!t) return 0;
	int hl=Height(t->LeftChild);
	int hr=Height(t->RightChild);
	if(hl>hr) return ++hl;
	else return ++hr;
}
template <class T>
int BinaryTree<T>::TotalCount(BinaryTreeNode<T> *t) 
{//��*t����ǰ�������ͬʱ��¼�����Ŀ
	if(!t)
		return 0;         //��¼�����
        else    
        {   
        	int lc=TotalCount(t->LeftChild);  //�����������
		int rc=TotalCount(t->RightChild); //�����������
		return lc+rc+1;
	}
}
