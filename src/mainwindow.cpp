#include "mainwindow.h"
#include "network.h"
#include <QPainter>
#include <QRectF>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    validator = new QIntValidator(1, 1000000, this);

    network.desiredOutput = &network.andOutput;

    network.outputNetworkLabel = ui->outputNeuron;
    network.outputNetworkLabelError = ui->outputNeuronError;

    connect(ui->simulateButton, SIGNAL(released()), this, SLOT(Simulate()));
    connect(ui->stepButton, SIGNAL(released()), this, SLOT(Step()));
    connect(ui->resetButton, SIGNAL(released()), this, SLOT(Reset()));
    connect(ui->andButton, SIGNAL(released()), this, SLOT(ChangeToAnd()));
    connect(ui->orButton, SIGNAL(released()), this, SLOT(ChangeToOr()));
    connect(ui->xorButton, SIGNAL(released()), this, SLOT(ChangeToXor()));
    connect(ui->classicButton, SIGNAL(released()), this, SLOT(SetClassic()));
    connect(ui->momentumButton, SIGNAL(released()), this, SLOT(SetMomentum()));

    network.weightsLabels.push_back(ui->w1Label);
    network.weightsLabels.push_back(ui->w2Label);
    network.weightsLabels.push_back(ui->w3Label);
    network.weightsLabels.push_back(ui->w4Label);
    network.weightsLabels.push_back(ui->w5Label);
    network.weightsLabels.push_back(ui->w6Label);
    network.weightsLabels.push_back(ui->w7Label);
    network.weightsLabels.push_back(ui->w8Label);
    network.weightsLabels.push_back(ui->w9Label);

    network.errorLabels.push_back(ui->e1Label);
    network.errorLabels.push_back(ui->e2Label);

    network.learningRateLabel = ui->learningRateLabel;
    network.alphaLabel = ui->alphaLabel;
    network.iterationLabel = ui->iterationsValueLabel;

    network.inputsLabels.push_back(ui->input1Label);
    network.inputsLabels.push_back(ui->input2Label);

    network.outputTableLabels.push_back(ui->res1Label);
    network.outputTableLabels.push_back(ui->res2Label);
    network.outputTableLabels.push_back(ui->res3Label);
    network.outputTableLabels.push_back(ui->res4Label);

    network.outputLabels.push_back(ui->o1Label);
    network.outputLabels.push_back(ui->o2Label);

    ui->arrow1Label->setVisible(false);
    ui->arrow2Label->setVisible(false);
    ui->arrow3Label->setVisible(false);
    ui->arrow4Label->setVisible(false);

    network.arrowLabels.push_back(ui->arrow1Label);
    network.arrowLabels.push_back(ui->arrow2Label);
    network.arrowLabels.push_back(ui->arrow3Label);
    network.arrowLabels.push_back(ui->arrow4Label);

    ui->editIterations->setValidator(validator);
    ui->editIterations->setText("100000");

    network.Create();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete validator;
}

void MainWindow::SetClassic()
{
    ui->programNameLabel->setText("Classic BP");
    ui->alphaLabel->setVisible(false);
    ui->alphaTextLabel->setVisible(false);
    network.algo = classic;
    network.Create();
}

void MainWindow::SetMomentum()
{
    ui->programNameLabel->setText("Momentum term");
    ui->alphaLabel->setVisible(true);
    ui->alphaTextLabel->setVisible(true);
    network.algo = momentum;
    network.Create();
}

void MainWindow::ChangeToAnd()
{
    network.Create();
    network.desiredOutput = &network.andOutput;
    ui->op1Label->setText("AND"); ui->op2Label->setText("AND"); ui->op3Label->setText("AND"); ui->op4Label->setText("AND"); ui->operationLabel->setText("AND");
}

void MainWindow::ChangeToOr()
{
    network.Create();
    network.desiredOutput = &network.orOutput;
    ui->op1Label->setText("OR"); ui->op2Label->setText("OR"); ui->op3Label->setText("OR"); ui->op4Label->setText("OR"); ui->operationLabel->setText("OR");
}

void MainWindow::ChangeToXor()
{
    network.Create();
    network.desiredOutput = &network.xorOutput;
    ui->op1Label->setText("XOR"); ui->op2Label->setText("XOR"); ui->op3Label->setText("XOR"); ui->op4Label->setText("XOR"); ui->operationLabel->setText("XOR");
}

void MainWindow::Simulate()
{
    int iterations = ui->editIterations->text().toInt();

    if (iterations < 1 || iterations > 1000000)    // Less then 1 or more than 1 000 000
    {
        ui->errorLabel->setText("Please fill between 1 and 1 000 000 iterations.");
        return;
    }
    else
        ui->errorLabel->setText("");
    network.Learn(iterations);
}

void MainWindow::Step()
{
    network.OneCycle();
    network.UpdateFlow();
}

void MainWindow::Reset()
{
    network.Create();
}
