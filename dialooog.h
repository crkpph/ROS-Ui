#ifndef DIALOOOG_H
#define DIALOOOG_H

#include <QDialog>


namespace Ui {
class dialooog;
}

class dialooog : public QDialog
{
    Q_OBJECT

public:
    explicit dialooog(QWidget *parent = 0);
    ~dialooog();

private slots:
    void on_btn_update_clicked();

    void on_btn_skype_clicked();

private:
    Ui::dialooog *ui;
};

#endif // DIALOOOG_H
