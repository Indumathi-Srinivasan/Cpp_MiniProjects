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
    void on_Ninebtn_clicked();

    void on_Clearbtn_clicked();

    void on_Resultbtn_clicked();

    void on_Addbtn_clicked();

    void on_Eightbtn_clicked();

    void on_Sevenbtn_clicked();

    void on_Sixbtn_clicked();

    void on_Subtractbtn_clicked();

    void on_Fivebtn_clicked();

    void on_Fourbtn_clicked();

    void on_Threebtn_clicked();

    void on_Multiplybtn_clicked();

    void on_Twobtn_clicked();

    void on_Onebtn_clicked();

    void on_Zerobtn_clicked();

    void on_Dividebtn_clicked();

private:
    Ui::calculator *ui;
    double num1;
    QString symbol;
};
#endif // CALCULATOR_H
