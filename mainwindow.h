#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "field.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::MainWindow *ui;
    Field *field_;
};

#endif // MAINWINDOW_H
