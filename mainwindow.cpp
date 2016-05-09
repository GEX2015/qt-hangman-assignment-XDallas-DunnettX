#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVboxlayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto vlMain = new QVBoxLayout(ui->centralWidget);
    auto glLetters = new QGridLayout();
     // Letters //
    for(char c = 'a'; c <= 'z'; c++)
    {

        auto btn = new QPushButton();
        btn->setMinimumSize(25, 25);
        btn->setMaximumSize(25, 25);
        btn->setText(QString(c));

        int idx = c - 'a';
        glLetters->addWidget(btn, idx / 6, idx % 6);

        connect(btn, &QPushButton::clicked, this, &MainWindow::onLetterClicked);

    }
    vlMain->addLayout(glLetters);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLetterClicked()
{
    // Sender must be a QPushButton so
    // downcast is safe
    QPushButton* btn = dynamic_cast<QPushButton*>(sender());

    // Update Model
    // _hangman.processGuess(btn->text())
    // Draw()
    btn->setEnabled(false);
    qWarning() << btn->text();

}
