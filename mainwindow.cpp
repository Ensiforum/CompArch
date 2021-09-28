#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "converter.h"
#include <QDebug>
#include <QString>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    Converter a(2, "101");
//    qDebug() << a.convertTo(10).c_str();
    connect(ui->buttonExchange, &QPushButton::released,
            this, [=]()
                        {
                            int from = ui->spinBoxFrom->value();
                            int to = ui->spinBoxTo->value();
                            std::swap(from, to);
                            ui->spinBoxFrom->setValue(from);
                            ui->spinBoxTo->setValue(to);
                        });
    connect(ui->buttonTranslate, &QPushButton::released,
            this, [=]()
                        {
                            QString num = ui->textInNumber->toPlainText();
                            if(num != "")
                            {
                                int in_sys = ui->spinBoxFrom->value();
                                int out_sys = ui->spinBoxTo->value();
                                Converter conv(in_sys, num.toStdString());
                                QString ans = conv.convertTo(out_sys).c_str();
                                ui->textOutNumber->setText(ans);
                            }
                        });
}

MainWindow::~MainWindow()
{
    delete ui;
}

