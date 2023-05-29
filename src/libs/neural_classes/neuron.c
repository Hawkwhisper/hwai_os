typedef struct Neuron {
    __dspace position;
    // ^ We use positions to dampen / increase signal between connected neurons
    Node *output_nodes;
    Node *input_nodes;
    float energy;
    int type; // NT_SCANNER, etc... see readme for more
    float adv_signal; //The advanced signal provided by the algorithm in readme.md
} Neuron;

//Worker thread to update the neuron
void *UpdateNeuron(void *vargp) {
    Neuron *neuron = (Neuron *) &vargp;

    neuron->energy+=randfb(0, .025);

    if(neuron->energy>1) {

    }
}