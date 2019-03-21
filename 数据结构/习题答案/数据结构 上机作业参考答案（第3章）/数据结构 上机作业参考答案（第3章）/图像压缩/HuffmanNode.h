#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <iostream>
using namespace std;

class HuffmanNode
{
public:
	HuffmanNode()
	{
		left = NULL;
		right = NULL;
	}
	HuffmanNode(int cv, int f)
	{
		charValue = cv;	//byte�е�����
		freq = f;		//byte���ֶ�Ӧ��Ƶ��
		left = NULL;
		right = NULL;
	}
	bool operator < (HuffmanNode hn)
	{
		return freq < hn.freq;
	}
	bool operator > (HuffmanNode hn)
	{
		return freq > hn.freq;
	}
	bool operator <= (HuffmanNode hn)
	{
		return freq <= hn.freq;
	}
	bool operator >= (HuffmanNode hn)
	{
		return freq >= hn.freq;
	}
	int charValue;
	int freq;
	HuffmanNode* left;
	HuffmanNode* right;
};

#endif