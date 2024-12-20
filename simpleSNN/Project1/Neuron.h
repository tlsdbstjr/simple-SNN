#ifndef __NEURON__
#define __NEURON__

#include "dataTypes.h"

class Neuron
{
private:
	t_membrane membrane;
	unsigned char decayRate;

public:
	Neuron();
	~Neuron();
	bool Update(t_membrane input);

};


#endif
