#include "dialooog.h"
#include "ui_dialooog.h"
#include <QMessageBox>
#include <QProcess>
#include <QString>
#include <QDir>
#include <QDebug>


dialooog::dialooog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialooog)
{
    ui->setupUi(this);

    QPixmap background("/home/ubuntu/NewGuiSample/icon/bg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    dialooog::setPalette(palette);
    dialooog::setWindowTitle("Setting");

    QPixmap pixmapUpdate("/home/ubuntu/NewGuiSample/setting/update.png");
    QIcon buttonIconUpdate(pixmapUpdate);
    ui->btn_update->setIcon(buttonIconUpdate);
    ui->btn_update->setIconSize(QSize(150,150));

    QPixmap pixmapSkype("/home/ubuntu/NewGuiSample/setting/skype.png");
    QIcon buttonIconSkype(pixmapSkype);
    ui->btn_skype->setIcon(buttonIconSkype);
    ui->btn_skype->setIconSize(QSize(150,150));

}

dialooog::~dialooog()
{
    delete ui;
}

void dialooog::on_btn_update_clicked()
{
    QPixmap pixmapUpdate("/home/ubuntu/NewGuiSample/setting/update_2.png");
    QIcon buttonIconUpdate(pixmapUpdate);
    ui->btn_update->setIcon(buttonIconUpdate);
    ui->btn_update->setIconSize(QSize(150,150));

    QPixmap pixmapSkype("/home/ubuntu/NewGuiSample/setting/skype.png");
    QIcon buttonIconSkype(pixmapSkype);
    ui->btn_skype->setIcon(buttonIconSkype);
    ui->btn_skype->setIconSize(QSize(150,150));


    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Software Update","Are you sure you want to update the software?", QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        QMessageBox::information(this,"Sofware Update","Software Updated!");

        QPixmap pixmapUpdate("/home/ubuntu/NewGuiSample/setting/update.png");
        QIcon buttonIconUpdate(pixmapUpdate);
        ui->btn_update->setIcon(buttonIconUpdate);
        ui->btn_update->setIconSize(QSize(150,150));
    }
    else if(reply == QMessageBox::No)
    {
        QPixmap pixmapUpdate("/home/ubuntu/NewGuiSample/setting/update.png");
        QIcon buttonIconUpdate(pixmapUpdate);
        ui->btn_update->setIcon(buttonIconUpdate);
        ui->btn_update->setIconSize(QSize(150,150));
    }
}

void dialooog::on_btn_skype_clicked()
{

    QPixmap pixmapUpdate("/home/ubuntu/NewGuiSample/setting/update.png");
    QIcon buttonIconUpdate(pixmapUpdate);
    ui->btn_update->setIcon(buttonIconUpdate);
    ui->btn_update->setIconSize(QSize(150,150));

    QPixmap pixmapSkype("/home/ubuntu/NewGuiSample/setting/skype.png");
    QIcon buttonIconSkype(pixmapSkype);
    ui->btn_skype->setIcon(buttonIconSkype);
    ui->btn_skype->setIconSize(QSize(150,150));

    QString program = "firefox";
    QStringList arguments;

    QProcess *myProcess = new QProcess(this);
    myProcess->start(program, arguments);
    qDebug()<<myProcess->errorString();
}
