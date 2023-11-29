#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include"mainmenu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_exitbtn_clicked();

    void on_loginbtn_clicked();

private:
    Ui::login *ui;
    mainmenu mainmenuUi; //menumenu object to call show()
};
#endif // LOGIN_H
