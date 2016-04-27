#include "upload_commands.h"
#include "ui_upload_commands.h"
#include "mainwindow.h"
#include "QMessageBox"

upload_commands::upload_commands(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::upload_commands)
{
    ui->setupUi(this);
    filename = new QString();
    proc_1 = new QProcess();
    proc_2 = new QProcess();
    proc_3 = new QProcess();
    proc_4 = new QProcess();
    proc_5 = new QProcess();
    ui->btn_ok->setEnabled(false);
}

upload_commands::~upload_commands()
{
    delete ui;
}

void upload_commands::on_btn_ok_clicked()
{
    proc_1->start("gnome-terminal",QStringList()<<"-e"<<"tar xvzf "+ui->filepath->toPlainText()+" -C ../speechSDK");
    proc_1->waitForStarted(30000);
    proc_1->waitForFinished(30000);


    if(!proc_1->waitForStarted()==true)
    {
        proc_2->start("gnome-terminal",QStringList()<<"-e"<<"cp ../speechSDK/"+ui->dic_file->text()+".dic ../speechSDK/src/pocketsphinx/config/nav_commands.dic");
        proc_3->start("gnome-terminal",QStringList()<<"-e"<<"cp ../speechSDK/"+ui->lm_file->text()+".lm ../speechSDK/src/pocketsphinx/config/nav_commands.lm");
        proc_4->start("gnome-terminal",QStringList()<<"-e"<<"cp ../speechSDK/"+ui->sent_file->text()+".sent ../speechSDK/src/pocketsphinx/config/nav_commands.sent");

        proc_5->start("gnome-terminal",QStringList()<<"-e"<<"cp ../speechSDK/"+ui->vocab_file->text()+".vocab ../speechSDK/src/pocketsphinx/config/nav_commands.vocab");
        proc_4->waitForStarted(70000);
        proc_4->waitForFinished(60000);
        if (!proc_4->waitForStarted()==true) {

            QFile checkFile("../speechSDK/src/pocketsphinx/config/nav_commands.sent");

            if(checkFile.exists()==true)
            {
                connect(ui->btn_ok, SIGNAL(pressed()), this, SLOT(connector()));
                connect(ui->btn_ok, SIGNAL(released()), this, SLOT(connector()));
                connect(ui->btn_ok, SIGNAL(clicked(bool)), this, SLOT(connector()));
                QMessageBox::StandardButton reply2;
                reply2 = QMessageBox::information(this,"Confirmation","Commands are successfully updated", QMessageBox::Ok);
                if(reply2==QMessageBox::Ok)
                {
                    connect(ui->btn_ok, SIGNAL(pressed()), this, SLOT(connector()));
                    connect(ui->btn_ok, SIGNAL(released()), this, SLOT(connector()));
                    connect(ui->btn_ok, SIGNAL(clicked(bool)), this, SLOT(connector()));

                    ui->filepath->setPlainText("");
                    ui->btn_ok->setEnabled(false);
                    this->close();
                }
            }
            else
            {

            }
        }



    }

}

void upload_commands::on_btn_cancel_clicked()
{
    ui->filepath->setPlainText("");
    this-> close();
}

void upload_commands::on_pushButton_3_clicked()
{

    QString path = QFileDialog::getOpenFileName(this,tr("Open your Commands"), "../Downloads", tr("TGZ Files (*.tgz)"));
    if ( path.isNull() == false )
    {
        ui->filepath->setPlainText(path);
        QString getter = path.right(8);
        QString holder = getter.left(4);
        ui->dic_file->setText(holder);
        ui->lm_file->setText(holder);
        ui->vocab_file->setText(holder);
        ui->sent_file->setText(holder);
        ui->btn_ok->setEnabled(true);

    }
    else
    {
        ui->btn_ok->setEnabled(false);
    }
}
void upload_commands::connector()
{
    emit (makeChange());

}
void upload_commands::connector2()
{
    emit (destroyed());

}



void upload_commands::closeEvent(QCloseEvent *event) {
    // do some data saves or something else
    connect(ui->btn_ok, SIGNAL(pressed()), this, SLOT(connector()));
    connect(ui->btn_ok, SIGNAL(released()), this, SLOT(connector()));
    connect(ui->btn_ok, SIGNAL(clicked(bool)), this, SLOT(connector()));

}
