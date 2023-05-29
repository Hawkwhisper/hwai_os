#ifndef nclasses
#define nclasses

//Used for cross-communication since you can't
//define a struct that has another stuct that has itself
// e.g, brain contains neurons, and the neurons have a brain
// value telling them what brain they belong to, etc
unsigned long neural_uid;
unsigned long brain_uid;
unsigned long lifeform_uid;

#include "dspace.c"
#include "node.c"
#include "neuron.c"
#include "brain.c"

typedef struct NeuralStructure {
    Neuron neuron;
    Brain brain;
    bool created;
}NeuralStructure;
#include "func.c"



#endif