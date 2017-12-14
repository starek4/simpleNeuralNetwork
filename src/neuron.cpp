#include "neuron.h"

#include <cmath>

Neuron::Neuron(double learningRate)
{
    Random random = Random();
    for (int i = 0; i < 2; i++)
    {
        inputs.push_back(0.0);
        weights.push_back(random.GetRandomWeight());
        previousWeightsChanges.push_back(0.0);
    }
    bias = random.GetRandomWeight();
    this->learningRate = learningRate;
}

void Neuron::AdjustWeights(Algorithms algo, double alpha)
{
    if (algo == classic)
    {
        // Back propagation - classic
        for (unsigned int i = 0; i < weights.size(); i++)
        {
            weights[i] += error * inputs[i] * learningRate;
        }
        bias += error * learningRate;
    }
    else if (algo == momentum)
    {
        // Back propagation - momentum
        for (unsigned int i = 0; i < weights.size(); i++)
        {
            double weightChange = (error * inputs[i] * learningRate) + (previousWeightsChanges[i] * alpha);
            weights[i] += weightChange;
            previousWeightsChanges[i] = weightChange;
        }
        double biasChange = (error * learningRate) + (previousBiasChange * alpha);
        bias += biasChange;
        previousBiasChange = biasChange;
    }
}

void Neuron::CalculateSum()
{
    sum = 0.0;
    for(unsigned int i = 0; i < weights.size(); i++)
    {
        sum += weights[i] * inputs[i];
    }
    sum += bias;
}

double Neuron::Output()
{
    CalculateSum();
    double output = 1.0 / (1.0 + std::exp(-sum));
    return output;
}

double Neuron::DerivateOutput()
{
    double out = Output();
    return out * (1 - out);
}
