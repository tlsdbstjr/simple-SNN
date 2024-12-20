#include "Layer.h"

Layer::Layer(unsigned int _cellCnt) : cellCnt(_cellCnt)
{
	cell = new Neuron[cellCnt];
	weight = new t_membrane[cellCnt];
}

Layer::Layer(const Layer& obj) : cellCnt(obj.cellCnt)
{
	cell = new Neuron[cellCnt];
	weight = new t_membrane[cellCnt];
	std::copy(obj.cell, obj.cell + cellCnt, cell);
	std::copy(obj.weight, obj.weight + cellCnt, weight);
}

Layer::~Layer()
{
	if (cellCnt > 1)
	{
		delete[] cell;
		delete[] weight;
	}
	else
	{
		delete cell;
		delete weight;
	}
}

Neurotransmitter Layer::forward(Neurotransmitter input)
{
	record.push_back(input);
	return inference(input);
}
Neurotransmitter Layer::inference(Neurotransmitter input)
{
	Neurotransmitter output(cellCnt);
	for (unsigned int i = 0; i < cellCnt; i++)
	{
		if (cell[i].Update(input.isSpike(i) ? weight[i] : 0)) output.setSpike(i);
	}
	return output;
}
Neurotransmitter Layer::backward(Neurotransmitter lable) 
{

}