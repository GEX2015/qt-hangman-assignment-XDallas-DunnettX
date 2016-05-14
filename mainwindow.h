#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushbutton>
#include <QLabel>
#include <QFrame>
#include "hangman.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void draw();

public slots:

    void onLetterClicked();

private:
    Ui::MainWindow *ui;
    QLabel* _lblWorkingPhrase = new QLabel;
    QLabel* wL = new QLabel;
    QFrame* _frmGallows = new QFrame;
    std::vector<QPushButton*> _btnLetters;
    Hangman _hangman;
};

#endif // MAINWINDOW_H
