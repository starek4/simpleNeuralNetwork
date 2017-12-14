#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <QTextEdit>
#include <QLabel>

#include "neuron.h"
#include "algorithms.h"
#include "random.h"

class Network
{
private:
    std::vector<Neuron> hiddenLayer;
    std::vector<Neuron> outputLayer;
    double learningRate;
    double alpha;
    Random random;
    std::vector<double> xValues {0.0, 0.0, 1.0, 1.0};
    std::vector<double> yValues {0.0, 1.0, 0.0, 1.0};
    int traineeSetIndex = -1;
    int iteration = 0;
    QString DoubleToStringPrecisionOne(double number, int precision);
    void GuiSetArrow();
    void GuiSetInputs();
    void GuiSetWeights();
    void GuiSetOutputs();
    void GuiSetErrors();
    double GetResult();
    int GetRelativeIndex();
    void ClearGui();

public:
    std::vector<double> *desiredOutput;
    std::vector<double> andOutput {0.0, 0.0, 0.0, 1.0};
    std::vector<double> orOutput {0.0, 1.0, 1.0, 1.0};
    std::vector<double> xorOutput {0.0, 1.0, 1.0, 0.0};
    std::vector<double> actualOutput {0.0, 0.0, 0.0, 0.0};
    void UpdateFlow();
    void OneCycle();
    void Learn(int iterations);
    void Create();
    Algorithms algo = momentum;

    // GUI members
    QLabel *outputNetworkLabel;
    QLabel *outputNetworkLabelError;
    std::vector<QLabel*> outputTableLabels;
    std::vector<QLabel*> arrowLabels;
    std::vector<QLabel*> inputsLabels;
    QLabel *learningRateLabel;
    QLabel *alphaLabel;
    QLabel *iterationLabel;
    std::vector<QLabel*> weightsLabels;
    std::vector<QLabel*> outputLabels;
    std::vector<QLabel*> errorLabels;
};

#endif // NETWORK_H
