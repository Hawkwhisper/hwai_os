typedef struct Neuron {
    __dspace position;
    // ^ We use positions to dampen / increase signal between connected neurons
    Node *output_nodes;
    Node *input_nodes;

    float energy;
} Neuron;

//Worker thread to update the neuron
void *UpdateNeuron(void *vargp) {
    Neuron *neuron = (Neuron *) &vargp;

    neuron->energy+=randfb(0, .025);
    //Neural calculation: see the README.md
}