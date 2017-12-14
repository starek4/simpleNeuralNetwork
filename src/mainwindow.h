#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "network.h"
#include <QMainWindow>
#include "ui_mainwindow.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   Network network;

private:
    Ui::MainWindow *ui;
    QIntValidator *validator;

private slots:
    void Simulate();
    void Step();
    void ChangeToOr();
    void ChangeToAnd();
    void ChangeToXor();
    void Reset();
    void SetClassic();
    void SetMomentum();
};

#endif // MAINWINDOW_H
