#include "Buffer.h"

using namespace std;
Buffer::Buffer()
{

}


Buffer::~Buffer()
{
}


void Buffer::BufferInput() {
	ifstream in("Buffer.txt");
	string filename;
	string line;

	if (in) // �и��ļ�  
	{
		while (getline(in, line)) // line�в�����ÿ�еĻ��з�  
		{
			//cout << line << endl;
			buffer[++ActualSize]=stoi(line,nullptr);
		}
	}
	else // û�и��ļ�  
	{
		cout << "no such file" << endl;
	}
	//inFile >> c;
	//cout << c;

}


void Buffer::Bufferprint() {
	BufferInput();
	//cout << ActualSize << endl;
	for (int j = 0; j <= ActualSize; j++) {
		cout << buffer[j]<<endl;
	}
	//cout << endl;
}

char Buffer::GetElement()
{
	if (CurrentLoaction >= 0 && CurrentLoaction <=ActualSize) {
		return buffer[CurrentLoaction++];
	}
}
