#ifndef UPLOAD_COMMANDS_H
#define UPLOAD_COMMANDS_H

#include <QDialog>
#include <QDialog>
#include <QFileDialog>
#include <QProcess>

namespace Ui {
class upload_commands;
}

class upload_commands : public QDialog
{
    Q_OBJECT

public:
    explicit upload_commands(QWidget *parent = 0);
    ~upload_commands();

private slots:
    void connector();
    void connector2();
    void closeEvent(QCloseEvent *event);

    void on_btn_ok_clicked();

    void on_btn_cancel_clicked();

    void on_pushButton_3_clicked();

signals:
   void makeChange();

private:
    Ui::upload_commands *ui;
    QString *filename;
    QProcess *proc_1;
    QProcess *proc_2;
    QProcess *proc_3;
    QProcess *proc_4;
    QProcess *proc_5;
};

#endif // UPLOAD_COMMANDS_H
