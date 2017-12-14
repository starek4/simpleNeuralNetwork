#ifndef NEURON_H
#define NEURON_H

#include "random.h"
#include "algorithms.h"

#include <string>
#include <iostream>
#include <vector>

class Neuron
{
public:
    std::vector<double> inputs;
    std::vector<double> weights;
    double bias;
    double error = 0.0;
    double learningRate;
    Neuron(double learningRate);
    double Output();
    double DerivateOutput();
    void AdjustWeights(Algorithms algo, double alpha);

private:
    double sum = 0.0;
    double previousBiasChange = 0.0;
    std::vector<double> previousWeightsChanges;
    void CalculateSum();
};

#endif // NEURON_H
