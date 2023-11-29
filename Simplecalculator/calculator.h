#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();

private slots:
    void on_addButton_clicked();

    void on_subtractButton_clicked();

    void on_multiplyButton_clicked();

    void on_divideButton_clicked();

private:
    Ui::calculator *ui;
};
#endif // CALCULATOR_H
