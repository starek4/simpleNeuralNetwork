#include "network.h"

void Network::Create()
{
    ClearGui();
    learningRate = random.GetRandomLearningRate();
    learningRateLabel->setText(QString::number(learningRate));
    alpha = random.GetRandomAlpha();
    alphaLabel->setText(QString::number(alpha));

    iteration = 0;

    hiddenLayer.clear();
    outputLayer.clear();

    // Hidden layer
    for (int i = 0; i < 2; i++)
        hiddenLayer.push_back(Neuron(learningRate));

    // Output layer
    for (int i = 0; i < 1; i++)
        outputLayer.push_back(Neuron(learningRate));
}

void Network::OneCycle()
{
    iteration++;
    traineeSetIndex++;
    int index = traineeSetIndex % desiredOutput->size();

    // 1) Forward propagation (calculates output)
    hiddenLayer[0].inputs[0] = xValues[index];
    hiddenLayer[0].inputs[1] = yValues[index];
    hiddenLayer[1].inputs[0] = xValues[index];
    hiddenLayer[1].inputs[1] = yValues[index];

    outputLayer[0].inputs[0] = hiddenLayer[0].Output();
    outputLayer[0].inputs[1] = hiddenLayer[1].Output();

    actualOutput[index] = outputLayer[0].Output();

    // 2) Back propagation (adjusts weights according selected algorithm)
    outputLayer[0].error = outputLayer[0].DerivateOutput() * (desiredOutput->at(index) - outputLayer[0].Output());
    outputLayer[0].AdjustWeights(algo, alpha);

    hiddenLayer[0].error = hiddenLayer[0].DerivateOutput() * outputLayer[0].error * outputLayer[0].weights[0];
    hiddenLayer[1].error = hiddenLayer[1].DerivateOutput() * outputLayer[0].error * outputLayer[0].weights[1];
    hiddenLayer[0].AdjustWeights(algo, alpha);
    hiddenLayer[1].AdjustWeights(algo, alpha);
}

void Network::GuiSetArrow()
{
    for(int i = 0; i < (int)arrowLabels.size(); i++)
    {
        if (i == GetRelativeIndex())
            arrowLabels.at(i)->setVisible(true);
        else
            arrowLabels.at(i)->setVisible(false);
    }
}

void Network::Learn(int iterations)
{
    for (int iteration = 0; iteration < iterations; iteration++)
    {
        OneCycle();
    }
    UpdateFlow();
}

void Network::UpdateFlow()
{
    iterationLabel->setText(QString::number(iteration));
    for (unsigned i = 0; i < desiredOutput->size(); i++)
    {
        QString text;
        text.sprintf("%.5f", actualOutput[i]);
        outputTableLabels.at(i)->setText(text);
    }
    GuiSetArrow();
    GuiSetInputs();
    GuiSetWeights();
    GuiSetErrors();
    GuiSetOutputs();
}

void Network::GuiSetWeights()
{
    weightsLabels.at(0)->setText(DoubleToStringPrecisionOne(hiddenLayer.at(0).weights.at(0), 2));
    weightsLabels.at(1)->setText(DoubleToStringPrecisionOne(hiddenLayer.at(1).weights.at(0), 2));
    weightsLabels.at(2)->setText(DoubleToStringPrecisionOne(hiddenLayer.at(0).weights.at(1), 2));
    weightsLabels.at(3)->setText(DoubleToStringPrecisionOne(hiddenLayer.at(1).weights.at(1), 2));
    weightsLabels.at(4)->setText(DoubleToStringPrecisionOne(outputLayer.at(0).weights.at(0), 2));
    weightsLabels.at(5)->setText(DoubleToStringPrecisionOne(outputLayer.at(0).weights.at(1), 2));
    weightsLabels.at(6)->setText(DoubleToStringPrecisionOne(hiddenLayer.at(0).bias, 2));
    weightsLabels.at(7)->setText(DoubleToStringPrecisionOne(outputLayer.at(0).bias, 2));
    weightsLabels.at(8)->setText(DoubleToStringPrecisionOne(hiddenLayer.at(1).bias, 2));
}

void Network::GuiSetErrors()
{
    errorLabels.at(0)->setText(DoubleToStringPrecisionOne(hiddenLayer[0].error, 4));
    errorLabels.at(1)->setText(DoubleToStringPrecisionOne(hiddenLayer[1].error, 4));
    outputNetworkLabelError->setText(DoubleToStringPrecisionOne(outputLayer[0].error, 5));
}

void Network::GuiSetOutputs()
{
    outputLabels.at(0)->setText(DoubleToStringPrecisionOne(hiddenLayer[0].Output(), 4));
    outputLabels.at(1)->setText(DoubleToStringPrecisionOne(hiddenLayer[1].Output(), 4));
    outputNetworkLabel->setText(DoubleToStringPrecisionOne(GetResult(), 5));
}

QString Network::DoubleToStringPrecisionOne(double number, int precision)
{
    char precisionChar[2];
    sprintf(precisionChar, "%d", precision);
    char format[6] = "%.";
    strcat(format, precisionChar);
    strcat(format, "f");
    QString text;
    text.sprintf(format, number);
    return text;
}

void Network::GuiSetInputs()
{
    inputsLabels.at(0)->setText(QString::number(xValues.at(GetRelativeIndex())));
    inputsLabels.at(1)->setText(QString::number(yValues.at(GetRelativeIndex())));
}

int Network::GetRelativeIndex()
{
    return traineeSetIndex % desiredOutput->size();
}

double Network::GetResult()
{
    return outputLayer[0].Output();
}

void Network::ClearGui()
{
    traineeSetIndex = -1;
    outputNetworkLabel->setText("0");
    outputNetworkLabelError->setText("0");
    iterationLabel->setText("0");
    for (unsigned i = 0; i < arrowLabels.size(); i++)
    {
        arrowLabels.at(i)->setVisible(false);
        outputTableLabels.at(i)->setText("0");
    }
    for (unsigned i = 0; i < inputsLabels.size(); i++)
    {
        inputsLabels.at(i)->setText("0");
    }

    for (unsigned i = 0; i < weightsLabels.size(); i++)
    {
        weightsLabels.at(i)->setText("0");
    }

    for (unsigned i = 0; i < outputLabels.size(); i++)
    {
        outputLabels.at(i)->setText("0");
    }
    for (unsigned i = 0; i < errorLabels.size(); i++)
    {
        errorLabels.at(i)->setText("0");
    }
}
