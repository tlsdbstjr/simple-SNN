#ifndef __TYPE__
#define __TYPE__

#include <algorithm>

const int INT_BIT = sizeof(int) << 3;

typedef int t_membrane;	// 32-bit approach
//typedef long long t_membrane;	// 64-bit approach

class Neurotransmitter
{
private:
	int* data;
	unsigned int dataCnt;
	unsigned int channelCnt;

public:
	Neurotransmitter(unsigned int channelCnt);
	Neurotransmitter(const Neurotransmitter& obj);
	~Neurotransmitter();

	bool isSpike(unsigned int i) const;
	void setSpike(unsigned int i);
};


#endif
