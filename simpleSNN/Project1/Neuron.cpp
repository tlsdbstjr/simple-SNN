#include "Neuron.h"

Neuron::Neuron() : 
	membrane(0), 
	decayRate(1)
{
}

Neuron::~Neuron()
{
}

bool Neuron::Update(t_membrane input)
{
	membrane -= membrane >> decayRate;
	t_membrane next = membrane + input;
	bool out = next < 0 && membrane > 0;
	membrane = next;
	return out;
}
