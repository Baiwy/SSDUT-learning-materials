#ifndef MINHEAP_H
#define MINHEAP_H
#include "HuffmanNode.h"
using namespace std;

/*
	�洢huffman�����ָ�����С��
	���֮��ͨ����Ա����freq�Ƚϴ�С
*/
class MinHeap
{
private:
	HuffmanNode** nodes;
	int capacity;
	int currentSize;

	void shiftUp(int index);
	void shiftDown(int index);
public:
	MinHeap();
	MinHeap(int cap);
	~MinHeap();
	void add(HuffmanNode * v);
	HuffmanNode* top();
	void removeRoot();
	int size();
};

MinHeap::MinHeap()
{
	capacity = 256;
	currentSize = 0;
	nodes = new HuffmanNode*[capacity];
}

MinHeap::MinHeap(int cap)
{
	capacity = cap;
	currentSize = 0;
	nodes = new HuffmanNode*[capacity];
}

MinHeap::~MinHeap()
{
	delete[] nodes;
	currentSize = 0;
	capacity = 0;
}

void MinHeap::add(HuffmanNode* v)
{
	if(currentSize == capacity)
	{
		return;	//resize...
	}
	else
	{
		nodes[currentSize++] = v;
		shiftUp(currentSize - 1);
	}
}

HuffmanNode* MinHeap::top()
{
	return nodes[0];
}

void MinHeap::removeRoot()
{
	nodes[0] = nodes[currentSize - 1];
	currentSize--;
	shiftDown(0);
}

void MinHeap::shiftUp(int index)
{
	int parIndex;
	HuffmanNode* tmp;
	while(index != 0)
	{
		parIndex = (index - 1) / 2;
		if(*(nodes[index]) < *(nodes[parIndex]))
		{
			tmp = nodes[index];
			nodes[index] = nodes[parIndex];
			nodes[parIndex] = tmp;
			index = parIndex;
		}
		else
		{
			break;
		}		
	}
}

void MinHeap::shiftDown(int index)
{
	int leftIndex, rightIndex;
	HuffmanNode* tmp;
	while(index < currentSize)
	{
		leftIndex = index * 2 + 1;
		rightIndex = index * 2 + 2;
		if(leftIndex < currentSize && rightIndex < currentSize)	//������������
		{
			if(*nodes[index] <= *nodes[leftIndex] && *nodes[index] <= *nodes[rightIndex])
			{
				break;
			}
			else if(*nodes[index] > *nodes[leftIndex] && 
				*nodes[leftIndex] <= *nodes[rightIndex]) //��Сֵ��������
			{
				tmp = nodes[index];
				nodes[index] = nodes[leftIndex];
				nodes[leftIndex] = tmp;
				index = leftIndex;
			}
			else if(*nodes[index] > *nodes[rightIndex] && 
				*nodes[rightIndex] <= *nodes[leftIndex])	//��Сֵ��������
			{
				tmp = nodes[index];
				nodes[index] = nodes[rightIndex];
				nodes[rightIndex] = tmp;
				index = rightIndex;
			}
		}
		else if(leftIndex < currentSize && rightIndex > currentSize && 
			*nodes[index] < *nodes[leftIndex])		//ֻ�����������ҵ�ǰ���ֵ��������С
		{
			tmp = nodes[index];
			nodes[index] = nodes[leftIndex];
			nodes[leftIndex] = tmp;
			break;
		}
		else 
		{
			break;
		}
	}
}

int MinHeap::size()
{
	return currentSize;
}

#endif