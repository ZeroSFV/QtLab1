#include "calculator.h"
#include "ui_calculator.h"
#include "QPushButton"
#include "QLineEdit"
#include "QGridLayout"

int currentLineValue = 0; // Текущее значение в поле ввода
const int numbersCount = 10; // Количество кнопок для ввода на экране

bool PlusActive = false; // Обозначает нажатие "+"
bool MinusActive = false; // Обозначает нажатие "-"
bool MultiplyActive = false; // Обозначает нажатие "*"
bool DivideActive = false; // Обозначает нажатие "/"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    QPushButton *numbers[numbersCount];
    for(int i = 0; i < numbersCount; i++){
        numbers[i] = Calculator::findChild<QPushButton*>("button" + QString::number(i));
        connect(numbers[i], SIGNAL(released()), this, SLOT(ClickNumber()));
    }
    ui->lineEditCalculator->setText(QString::number(currentLineValue));

    connect(ui->buttonPlus, SIGNAL(released()), this, SLOT(ClickOperation()));
    connect(ui->buttonMinus, SIGNAL(released()), this, SLOT(ClickOperation()));
    connect(ui->buttonMultiply, SIGNAL(released()), this, SLOT(ClickOperation()));
    connect(ui->buttonDivide, SIGNAL(released()), this, SLOT(ClickOperation()));
    connect(ui->buttonCalculate, SIGNAL(released()), this, SLOT(ClickCalculate()));
    connect(ui->buttonClear, SIGNAL(released()), this, SLOT(ClickClear()));

}

void Calculator::ClickNumber(){
    QString currentNumber = ui->lineEditCalculator->text();

    QPushButton *button = (QPushButton*)sender();

    if(currentNumber.toInt() == 0){
        ui->lineEditCalculator->setText(button->text());
    }
    else{
        ui->lineEditCalculator->setText(currentNumber+ button->text());
    }
}

void Calculator::ClickCalculate(){
    int currentNumber = ui->lineEditCalculator->text().toInt();
    int result = 0;
    //Проверка выбранного действия
    if(PlusActive){
        result = currentLineValue + currentNumber;
    }
    else if(MinusActive){
        result = currentLineValue - currentNumber;
    }
    else if(MultiplyActive){
        result = currentLineValue * currentNumber;
    }
    else if(DivideActive && currentNumber != 0){
        result = currentLineValue / currentNumber;
    }
    else{
        ui->lineEditCalculator->setText("No operations");
    }
    ui->lineEditCalculator->setText(QString::number(result));
}

void Calculator::ClickOperation(){
    PlusActive = false;
    MinusActive = false;
    MultiplyActive = false;
    DivideActive = false;
    currentLineValue = (ui->lineEditCalculator->text()).toInt();

    QPushButton* pressedButton = (QPushButton*)sender();
    QString operation = pressedButton->text();
    if(QString::compare(operation, "+") == 0){ //0 если равны
        PlusActive = true;
    }
    else if(QString::compare(operation, "-") == 0){ //0 если равны
        MinusActive = true;
    }
    else if(QString::compare(operation, "*") == 0){ //0 если равны
        MultiplyActive = true;
    }
    else if(QString::compare(operation, "/") == 0){ //0 если равны
        DivideActive = true;
    }
    ui->lineEditCalculator->setText("");
}

void Calculator::ClickClear(){
    ui->lineEditCalculator->setText("");
    currentLineValue = 0;
}


Calculator::~Calculator()
{
    delete ui;
}

