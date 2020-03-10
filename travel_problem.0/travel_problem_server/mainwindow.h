#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "server.h"
#include "module.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void updatetimedisplay();

private slots:


    void on_le_returnPressed();

private:
    QString tempQ;
    int curruenttime;
    Server *myserver;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
