#ifndef RANDOM_H
#define RANDOM_H

#include <ctime>
#include <iostream>

class Random
{
public:
    Random();
    double GetRandomWeight();
    double GetRandomLearningRate();
    double GetRandomAlpha();

private:
    double GetRandom(double min, double max);
};

#endif // RANDOM_H
