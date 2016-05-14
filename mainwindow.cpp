#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hangman.h"
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
        _btnLetters.push_back(btn);
        connect(btn, &QPushButton::clicked, this, &MainWindow::onLetterClicked);

    }

    _frmGallows->setStyleSheet(QString::fromStdString(_hangman.displayGallows()));
    _frmGallows->setMinimumWidth(300);
    _frmGallows->setMaximumWidth(300);
    _frmGallows->setMinimumHeight(300);
    _frmGallows->setMaximumHeight(300);
    _lblWorkingPhrase->setText(QString::fromStdString(_hangman.workingPhrase()));

    vlMain->addWidget(_frmGallows);
    vlMain->addWidget(_lblWorkingPhrase);
    vlMain->addLayout(glLetters);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw()
{


    for ( auto b : _btnLetters)
    {
        if (_hangman.isGuessed(b->text().toStdString().c_str()[0]))
        {

            b->setEnabled(false);
        }
        else
        {
            b->setEnabled(true);

        }
    }
     // based on model state
     _frmGallows->setStyleSheet(QStringLiteral("Border-image:url(:/new/prefix1/HangMan Images/hangman%1.png)").arg(_hangman.wrongGuesses()));
     _lblWorkingPhrase->setText(QString::fromStdString(_hangman.workingPhrase()));
     // draw working phrase


}
void MainWindow::onLetterClicked()
{
    //
    // update the model
    //


    // Sender must be a QPushButton so
    // downcast is safe
    QPushButton* btn = dynamic_cast<QPushButton*>(sender());

    // Update Model
    QString letter = btn->text();
    std::string str = letter.toLocal8Bit().constData();

    _hangman.processGuess(str[0]);

    qWarning() << btn->text();

    //
    // redraw the view
    //
    draw();
}
