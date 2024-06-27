#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classes.h"

int ind;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_4->setVisible(0);
    ui->lineEdit_5->setVisible(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    if(index == 0){
        ind = index;
        ui->label->setText("enter number: ");
        ui->label_4->setText("prime number");
        ui->label_3->setText("");
        ui->label_2->setText("");
        ui->lineEdit_4->setVisible(0);
        ui->lineEdit_5->setVisible(0);
        ui->lineEdit->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("");
    }
    else if(index == 1){
        ind = index;
        ui->label->setText("enter number: ");
        ui->label_2->setText("enter epsillon: ");
        ui->label_3->setText("");
        ui->label_4->setText("taylor series ");
        ui->lineEdit_4->setVisible(1);
        ui->lineEdit_5->setVisible(0);
        ui->lineEdit->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("");
    }
    else if(index == 2){
        ind = index;
        ui->label->setText("enter a: ");
        ui->label_2->setText("enter b: ");
        ui->label_3->setText("enter c: ");
        ui->lineEdit_4->setVisible(1);
        ui->lineEdit_5->setVisible(1);
        ui->label_4->setText("ax^2 + bx + c");
        ui->lineEdit->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("");
    }


}




void MainWindow::on_pushButton_clicked()
{
    if(ind == 0){
        int num = ui->lineEdit->text().toInt();
        prime x;
        QString res = "";

        if(x.isprime(num)){
            res += "Number is prime!";
        }
        else if(num == 1){
            res += "1 is not prime and not complex!";
        }
        else{
            res += "Number is not prime. Here are multipliers of " + QString::number(num) + ": \n ";
            vector<int> mult = x.factorize(num);
            for(int i: mult){
                res += QString::number(i)+ "; ";
            }
        }
        ui->textBrowser->setText(res);
    }
    else if(ind == 1){
        double num, eps;
        num = ui->lineEdit->text().toDouble();
        eps = ui->lineEdit_4->text().toDouble();
        QString res= "";
        taylor x;
        QString sin = QString::number(x.series(num ,eps));
        res +="sin(" + QString::number(num) + ") = " + sin;
        ui->textBrowser->setText(res);

    }
    else{
        double a, b, c;
        a = ui->lineEdit->text().toDouble();
        b = ui->lineEdit_4->text().toDouble();
        c = ui->lineEdit_5->text().toDouble();
        sq_eq x;
        QString res = "";
        vector<double> sol = x.solve(a, b, c);
        res +="Here are real roots: \n";
        for(int i: sol){
            res += QString::number(i) + "; ";
        }
        ui->textBrowser->setText(res);
    }
}

