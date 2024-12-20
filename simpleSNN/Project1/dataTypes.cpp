#include "dataTypes.h"

Neurotransmitter::Neurotransmitter(unsigned int _channelCnt)
{
	channelCnt = _channelCnt;
	dataCnt = 1 + _channelCnt / INT_BIT;
	data = new int[dataCnt];
	std::fill(data, data + dataCnt, 0);
}

Neurotransmitter::Neurotransmitter(const Neurotransmitter& obj)
{
	channelCnt = obj.channelCnt;
	dataCnt = obj.dataCnt;
	data = new int[dataCnt];
	std::copy(obj.data, obj.data + dataCnt, data);
}

Neurotransmitter::~Neurotransmitter()
{
	if (dataCnt > 1)
		delete[] data;
	else
		delete data;
}

bool Neurotransmitter::isSpike(unsigned int i) const
{
	return data[i / INT_BIT] & (1 << (i % INT_BIT));
}

void Neurotransmitter::setSpike(unsigned int i)
{
	data[i / INT_BIT] |= (1 << (i % INT_BIT));
}
