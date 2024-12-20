#ifndef __LAYER__
#define __LAYER__

#include<vector>

#include "dataTypes.h"
#include "Neuron.h"

class Layer
{
private:
	Neuron* cell;
	t_membrane* weight;
	unsigned int cellCnt;
	std::vector<Neurotransmitter> record;

public:
	Layer(unsigned int _cellCnt);
	~Layer();

	Neurotransmitter forward(Neurotransmitter input);
	Neurotransmitter inference(Neurotransmitter input);
	Neurotransmitter backward(Neurotransmitter lable);
};

#endif