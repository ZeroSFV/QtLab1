#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "QPushButton"
#include "QLineEdit"

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QPushButton* button4;
    QPushButton* button5;
    QPushButton* button6;
    QPushButton* button7;
    QPushButton* button8;
    QPushButton* button9;
    QPushButton* button0;

    QPushButton* buttonPlus;
    QPushButton* buttonMinus;
    QPushButton* buttonMultiply;
    QPushButton* buttonDivide;
    QPushButton* buttonClear;
    QPushButton* buttonCalculate;

    QLineEdit* lineEditCalculator;

private slots:
    void ClickNumber();
    void ClickOperation();
    void ClickCalculate();
    void ClickClear();
};

#endif // CALCULATOR_H
