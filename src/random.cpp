#include "random.h"

Random::Random()
{
    srand(time(NULL));
}

double Random::GetRandom(double min, double max)
{
    return min + ((double)rand() / RAND_MAX)  * (max - min);
}

double Random::GetRandomWeight()
{
    return GetRandom(-0.5, 0.5);
}

double Random::GetRandomLearningRate()
{
    return GetRandom(0.5, 0.9);
}

double Random::GetRandomAlpha()
{
    return GetRandom(0.5, 0.99);
}
