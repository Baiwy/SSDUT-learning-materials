#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanNode.h"
#include "MinHeap.h"
#include <string>
using namespace std;

//Ϊͼ��ѹ���ر��Ƶ�HuffmanTree
class HuffmanTree
{
public:
	//����HuffmanTree
	//freqArrayΪƵ�����飬��¼ÿ���ֽ�ȡֵ���ֵĴ���
	HuffmanTree(int* freqArray)
	{
		MinHeap minHeap;
		HuffmanNode* hn, *hn1, *hn2;
		//��Ƶ�ʲ�Ϊ0�ĵ������С��
		for(int i = 0; i < 256; i++)
		{
			if(freqArray[i] == 0)
			{
				continue;
			}
			hn = new HuffmanNode(i, freqArray[i]);
			minHeap.add(hn);
		}
		//ͨ����С�ѹ���huffman��
		if(minHeap.size() == 0)		//û�н��
		{
			root = NULL;
			return;
		}
		if(minHeap.size() == 1)	//ֻ��һ�����
		{
			root = new HuffmanNode;
			root->charValue = minHeap.top()->charValue;
			root->freq = minHeap.top()->freq;
			return;
		}
		//��������ڵ���2
		//ÿ��ȡ����Ƶ����С�Ľ�㣬����huffman��
		while(minHeap.size() >= 2)	
		{
			hn1 = (minHeap.top());
			minHeap.removeRoot();
			hn2 = (minHeap.top());
			minHeap.removeRoot();
			hn = new HuffmanNode();
			hn->charValue = -1;
			hn->freq = hn1->freq + hn2->freq;
			hn->left = hn1;
			hn->right = hn2;
			minHeap.add(hn);
		}
		root = minHeap.top();
	}
	~HuffmanTree()
	{
		deleteTree(root);
	}

	/*
		����ǰhuffman��ת����Ϊhuffman�룬����codes������
	*/
	void coding(string* codes)
	{
		string code = "";
		postOrder(root, code, codes);//�Ժ��������ʽ������huffman��
	}

private:
	//�������
	void postOrder(HuffmanNode* root, string code, string* codes)
	{
		if(root == NULL)
		{
			return;
		}
		code += "0";	//������������huffman���0
		postOrder(root->left, code, codes);
		code.erase(code.length() - 1, 1);
		code += "1";	//������������huffman���1
		postOrder(root->right, code, codes);
		code.erase(code.length() - 1, 1);
		if(root->left == NULL && root->right == NULL)
		{
			codes[root->charValue] = code;
		}
	}

	//�������ɾ��huffman�����ͷ��ڴ�
	void deleteTree(HuffmanNode* root)
	{
		if(root == NULL)
		{
			return;
		}
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}

private:
	HuffmanNode* root;	//���ڵ�
};

#endif