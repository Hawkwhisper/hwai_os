
NeuralStructure newNeuron(unsigned char input_node_count, unsigned char output_node_count, int type, Brain *brain) {
    Neuron neuron;
    NeuralStructure tmp;
    tmp.neuron = neuron;
    tmp.brain = *(struct Brain *)&brain;
    tmp.created = true;
    //^ This links a brain to the neural structure
    return tmp; //neuron/brain;
}