#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialooog.h"
#include <QPixmap>
#include <QPalette>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QGraphicsVideoItem>
#include <QVBoxLayout>
#include "QStringListModel"
#include <QFile>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("ROS UI SDK");

    timer = new QTimer();
    cnt = new QTimer();
    counter = 0;

    //text
    proc1 = new QProcess();
    proc2 = new QProcess();
    proc3 = new QProcess();
    proc4 = new QProcess();

    proc_1 = new QProcess();
    proc_2 = new QProcess();
    proc_3 = new QProcess();
    proc_4 = new QProcess();
    proc_5 = new QProcess();
    proc_6 = new QProcess();
    proc_7 = new QProcess();
    proc_8 = new QProcess();
    proc_9 = new QProcess();
    proc_10 = new QProcess();


    dialog = new upload_commands();
    //setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);

    mediaPlayer = new QMediaPlayer();
    videoItem = new QGraphicsVideoItem;
    videoItem->setSize(QSizeF(850,470));
    scene = new QGraphicsScene(this);
    graphicsView = new QGraphicsView(scene);
    playlist = new QMediaPlaylist();

    m_timer = new QTimer();
    connect(m_timer,SIGNAL(timeout()),this,SLOT(startvideo()));
    m_timer->start(1000);

    ctr = 0;

    initializeVideo();

    QVBoxLayout * const layout = new QVBoxLayout(ui->scrollAreaWidgetContents);

    {
      layout->addWidget(ui->btn_face);
      layout->addWidget(ui->btn_slam);
      layout->addWidget(ui->btn_text);
      layout->addWidget(ui->btn_speech);
      layout->addWidget(ui->btn_gesture);
      layout->addWidget(ui->btn_rfid);
      layout->addWidget(ui->btn_barcode);

    }

    QPixmap background("/home/ubuntu/RosUiSDK/icon/bg.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    MainWindow::setPalette(palette);

    QPixmap pixmapxyz("/home/ubuntu/RosUiSDK/logo.png");
    ui->label->setPixmap(pixmapxyz);

    QPixmap pixmapFace("/home/ubuntu/RosUiSDK/icon/facerecognition.png");
    QIcon buttonIconFace(pixmapFace);
    ui->btn_face->setIcon(buttonIconFace);
    ui->btn_face->setIconSize(QSize(350,350));

    QPixmap pixmapSlam("/home/ubuntu/RosUiSDK/icon/slamt.png");
    QIcon buttonIconSlam(pixmapSlam);
    ui->btn_slam->setIcon(buttonIconSlam);
    ui->btn_slam->setIconSize(QSize(350,350));

    QPixmap pixmapText("/home/ubuntu/RosUiSDK/icon/textrecognition.png");
    QIcon buttonIconText(pixmapText);
    ui->btn_text->setIcon(buttonIconText);
    ui->btn_text->setIconSize(QSize(350,350));

    QPixmap pixmapSpeech("/home/ubuntu/RosUiSDK/icon/speechrecognition.png");
    QIcon buttonIconSpeech(pixmapSpeech);
    ui->btn_speech->setIcon(buttonIconSpeech);
    ui->btn_speech->setIconSize(QSize(350,350));

    QPixmap pixmapGesture("/home/ubuntu/RosUiSDK/icon/gesture.png");
    QIcon buttonIconGesture(pixmapGesture);
    ui->btn_gesture->setIcon(buttonIconGesture);
    ui->btn_gesture->setIconSize(QSize(350,350));

    QPixmap pixmapRfid("/home/ubuntu/RosUiSDK/icon/rfid.png");
    QIcon buttonIconRfid(pixmapRfid);
    ui->btn_rfid->setIcon(buttonIconRfid);
    ui->btn_rfid->setIconSize(QSize(350,350));

    QPixmap pixmapBarcode("/home/ubuntu/RosUiSDK/icon/barcode.png");
    QIcon buttonIconBarcode(pixmapBarcode);
    ui->btn_barcode->setIcon(buttonIconBarcode);
    ui->btn_barcode->setIconSize(QSize(350,350));

    QPixmap pixmapSetting("/home/ubuntu/RosUiSDK/icon/setting.png");
    QIcon buttonIconSetting(pixmapSetting);
    ui->btn_setting->setIcon(buttonIconSetting);
    ui->btn_setting->setIconSize(QSize(50,50));

    QPixmap pixmapbanner1("/home/ubuntu/RosUiSDK/banner/banner1.png");
    QIcon buttonIconbanner1(pixmapbanner1);
    ui->btn_banner1->setIcon(buttonIconbanner1);
    ui->btn_banner1->setIconSize(QSize(1058,262));

    QPixmap pixmapbanner2("/home/ubuntu/RosUiSDK/banner/banner2.png");
    QIcon buttonIconbanner2(pixmapbanner2);
    ui->btn_banner2->setIcon(buttonIconbanner2);
    ui->btn_banner2->setIconSize(QSize(1058,262));

    QPixmap pixmapbanner3("/home/ubuntu/RosUiSDK/banner/banner3.png");
    QIcon buttonIconbanner3(pixmapbanner3);
    ui->btn_banner3->setIcon(buttonIconbanner3);
    ui->btn_banner3->setIconSize(QSize(1058,262));

    QPixmap pixmapbanner4("/home/ubuntu/RosUiSDK/banner/banner4.png");
    QIcon buttonIconbanner4(pixmapbanner4);
    ui->btn_banner4->setIcon(buttonIconbanner4);
    ui->btn_banner4->setIconSize(QSize(1058,262));

    QPixmap pixmapbanner5("/home/ubuntu/RosUiSDK/banner/banner5.png");
    QIcon buttonIconbanner5(pixmapbanner5);
    ui->btn_banner5->setIcon(buttonIconbanner5);
    ui->btn_banner5->setIconSize(QSize(1058,262));

    QPixmap pixmapbanner6("/home/ubuntu/RosUiSDK/banner/banner6.png");
    QIcon buttonIconbanner6(pixmapbanner6);
    ui->btn_banner6->setIcon(buttonIconbanner6);
    ui->btn_banner6->setIconSize(QSize(1058,262));

if(timer->isActive()){
            timer->stop();

        }else{
            connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));

        }
         timer->start(1000);

    }


void MainWindow::timeout(){


        if(ui->banner->currentIndex() == 0){
            ui->banner->setCurrentIndex(1);
        }else if(ui->banner->currentIndex() == 1){

            ui->banner->setCurrentIndex(2);
        }else if(ui->banner->currentIndex()==2){

            ui->banner->setCurrentIndex(3);
        }else if(ui->banner->currentIndex()==3){

            ui->banner->setCurrentIndex(4);
        }else if(ui->banner->currentIndex()==4){

            ui->banner->setCurrentIndex(5);
        }else if(counter%2){
            ui->banner->setCurrentIndex(0);
        }
        counter++;
    }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_face_clicked()
{
    QPixmap pixmapFace("/home/ubuntu/RosUiSDK/icon/facerecognition_2.png");
    QIcon buttonIconFace(pixmapFace);
    ui->btn_face->setIcon(buttonIconFace);
    ui->btn_face->setIconSize(QSize(350,350));

    QPixmap pixmapSlam("/home/ubuntu/RosUiSDK/icon/slamt.png");
    QIcon buttonIconSlam(pixmapSlam);
    ui->btn_slam->setIcon(buttonIconSlam);
    ui->btn_slam->setIconSize(QSize(350,350));

    QPixmap pixmapText("/home/ubuntu/RosUiSDK/icon/textrecognition.png");
    QIcon buttonIconText(pixmapText);
    ui->btn_text->setIcon(buttonIconText);
    ui->btn_text->setIconSize(QSize(350,350));

    QPixmap pixmapSpeech("/home/ubuntu/RosUiSDK/icon/speechrecognition.png");
    QIcon buttonIconSpeech(pixmapSpeech);
    ui->btn_speech->setIcon(buttonIconSpeech);
    ui->btn_speech->setIconSize(QSize(350,350));

    QPixmap pixmapGesture("/home/ubuntu/RosUiSDK/icon/gesture.png");
    QIcon buttonIconGesture(pixmapGesture);
    ui->btn_gesture->setIcon(buttonIconGesture);
    ui->btn_gesture->setIconSize(QSize(350,350));

    QPixmap pixmapRfid("/home/ubuntu/RosUiSDK/icon/rfid.png");
    QIcon buttonIconRfid(pixmapRfid);
    ui->btn_rfid->setIcon(buttonIconRfid);
    ui->btn_rfid->setIconSize(QSize(350,350));

    QPixmap pixmapBarcode("/home/ubuntu/RosUiSDK/icon/barcode.png");
    QIcon buttonIconBarcode(pixmapBarcode);
    ui->btn_barcode->setIcon(buttonIconBarcode);
    ui->btn_barcode->setIconSize(QSize(350,350));

    initializeFaceRecognition();
    ui->recognition->setCurrentIndex(1);



    QFile checkFile("../speechSDK/scripts/stop_talk");
    ui->command_label->setVisible(true);
    hider();
    if(checkFile.exists()==true)
    {
        proc_5->start("../speechSDK/scripts/stop_talk");
        ui->start->setEnabled(true);
        ui->commandlist->setEnabled(false);
        ui->add_edit->setEnabled(true);
        ui->status->setText("Standby...");
    }
    else
    {

    }

    proc4->start("/bin/bash",QStringList()<<"-c"<<"terminal_exit");

}

void MainWindow::on_btn_slam_clicked()
{
    QPixmap pixmapFace("/home/ubuntu/RosUiSDK/icon/facerecognition.png");
    QIcon buttonIconFace(pixmapFace);
    ui->btn_face->setIcon(buttonIconFace);
    ui->btn_face->setIconSize(QSize(350,350));

    QPixmap pixmapSlam("/home/ubuntu/RosUiSDK/icon/slamt_2.png");
    QIcon buttonIconSlam(pixmapSlam);
    ui->btn_slam->setIcon(buttonIconSlam);
    ui->btn_slam->setIconSize(QSize(350,350));

    QPixmap pixmapText("/home/ubuntu/RosUiSDK/icon/textrecognition.png");
    QIcon buttonIconText(pixmapText);
    ui->btn_text->setIcon(buttonIconText);
    ui->btn_text->setIconSize(QSize(350,350));

    QPixmap pixmapSpeech("/home/ubuntu/RosUiSDK/icon/speechrecognition.png");
    QIcon buttonIconSpeech(pixmapSpeech);
    ui->btn_speech->setIcon(buttonIconSpeech);
    ui->btn_speech->setIconSize(QSize(350,350));

    QPixmap pixmapGesture("/home/ubuntu/RosUiSDK/icon/gesture.png");
    QIcon buttonIconGesture(pixmapGesture);
    ui->btn_gesture->setIcon(buttonIconGesture);
    ui->btn_gesture->setIconSize(QSize(350,350));

    QPixmap pixmapRfid("/home/ubuntu/RosUiSDK/icon/rfid.png");
    QIcon buttonIconRfid(pixmapRfid);
    ui->btn_rfid->setIcon(buttonIconRfid);
    ui->btn_rfid->setIconSize(QSize(350,350));

    QPixmap pixmapBarcode("/home/ubuntu/RosUiSDK/icon/barcode.png");
    QIcon buttonIconBarcode(pixmapBarcode);
    ui->btn_barcode->setIcon(buttonIconBarcode);
    ui->btn_barcode->setIconSize(QSize(350,350));

    initializeSlam();
    ui->recognition->setCurrentIndex(2);

    QFile checkFile("../speechSDK/scripts/stop_talk");
    ui->command_label->setVisible(true);
    hider();
    if(checkFile.exists()==true)
    {
        proc_5->start("../speechSDK/scripts/stop_talk");
        ui->start->setEnabled(true);
        ui->commandlist->setEnabled(false);
        ui->add_edit->setEnabled(true);
        ui->status->setText("Standby...");

    }
    else
    {

    }
    proc4->start("/bin/bash",QStringList()<<"-c"<<"terminal_exit");

}

void MainWindow::on_btn_text_clicked()
{
    QPixmap pixmapFace("/home/ubuntu/RosUiSDK/icon/facerecognition.png");
    QIcon buttonIconFace(pixmapFace);
    ui->btn_face->setIcon(buttonIconFace);
    ui->btn_face->setIconSize(QSize(350,350));

    QPixmap pixmapSlam("/home/ubuntu/RosUiSDK/icon/slamt.png");
    QIcon buttonIconSlam(pixmapSlam);
    ui->btn_slam->setIcon(buttonIconSlam);
    ui->btn_slam->setIconSize(QSize(350,350));
    QPixmap pixmapText("/home/ubuntu/RosUiSDK/icon/textrecognition_2.png");
    QIcon buttonIconText(pixmapText);
    ui->btn_text->setIcon(buttonIconText);
    ui->btn_text->setIconSize(QSize(350,350));

    QPixmap pixmapSpeech("/home/ubuntu/RosUiSDK/icon/speechrecognition.png");
    QIcon buttonIconSpeech(pixmapSpeech);
    ui->btn_speech->setIcon(buttonIconSpeech);
    ui->btn_speech->setIconSize(QSize(350,350));

    QPixmap pixmapGesture("/home/ubuntu/RosUiSDK/icon/gesture.png");
    QIcon buttonIconGesture(pixmapGesture);
    ui->btn_gesture->setIcon(buttonIconGesture);
    ui->btn_gesture->setIconSize(QSize(350,350));

    QPixmap pixmapRfid("/home/ubuntu/RosUiSDK/icon/rfid.png");
    QIcon buttonIconRfid(pixmapRfid);
    ui->btn_rfid->setIcon(buttonIconRfid);
    ui->btn_rfid->setIconSize(QSize(350,350));

    QPixmap pixmapBarcode("/home/ubuntu/RosUiSDK/icon/barcode.png");
    QIcon buttonIconBarcode(pixmapBarcode);
    ui->btn_barcode->setIcon(buttonIconBarcode);
    ui->btn_barcode->setIconSize(QSize(350,350));

    initializeTextRecognition();
    ui->recognition->setCurrentIndex(3);

     proc1->start("/bin/bash",QStringList()<<"-c"<<"start_ros");

    QFile checkFile("../speechSDK/scripts/stop_talk");
    ui->command_label->setVisible(true);
    hider();
    if(checkFile.exists()==true)
    {
        proc_5->start("../speechSDK/scripts/stop_talk");
        ui->start->setEnabled(true);
        ui->commandlist->setEnabled(false);
        ui->add_edit->setEnabled(true);
        ui->status->setText("Standby...");
    }
    else
    {

    }
}

void MainWindow::on_btn_speech_clicked()
{
    QPixmap pixmapFace("/home/ubuntu/RosUiSDK/icon/facerecognition.png");
    QIcon buttonIconFace(pixmapFace);
    ui->btn_face->setIcon(buttonIconFace);
    ui->btn_face->setIconSize(QSize(350,350));

    QPixmap pixmapSlam("/home/ubuntu/RosUiSDK/icon/slamt.png");
    QIcon buttonIconSlam(pixmapSlam);
    ui->btn_slam->setIcon(buttonIconSlam);
    ui->btn_slam->setIconSize(QSize(350,350));

    QPixmap pixmapText("/home/ubuntu/RosUiSDK/icon/textrecognition.png");
    QIcon buttonIconText(pixmapText);
    ui->btn_text->setIcon(buttonIconText);
    ui->btn_text->setIconSize(QSize(350,350));

    QPixmap pixmapSpeech("/home/ubuntu/RosUiSDK/icon/speechrecognition_2.png");
    QIcon buttonIconSpeech(pixmapSpeech);
    ui->btn_speech->setIcon(buttonIconSpeech);
    ui->btn_speech->setIconSize(QSize(350,350));

    QPixmap pixmapGesture("/home/ubuntu/RosUiSDK/icon/gesture.png");
    QIcon buttonIconGesture(pixmapGesture);
    ui->btn_gesture->setIcon(buttonIconGesture);
    ui->btn_gesture->setIconSize(QSize(350,350));

    QPixmap pixmapRfid("/home/ubuntu/RosUiSDK/icon/rfid.png");
    QIcon buttonIconRfid(pixmapRfid);
    ui->btn_rfid->setIcon(buttonIconRfid);
    ui->btn_rfid->setIconSize(QSize(350,350));

    QPixmap pixmapBarcode("/home/ubuntu/RosUiSDK/icon/barcode.png");
    QIcon buttonIconBarcode(pixmapBarcode);
    ui->btn_barcode->setIcon(buttonIconBarcode);
    ui->btn_barcode->setIconSize(QSize(350,350));

    initializeSpeechRecognition();
    ui->recognition->setCurrentIndex(4);

    proc4->start("/bin/bash",QStringList()<<"-c"<<"terminal_exit");
}

void MainWindow::initializeFaceRecognition(){

    ctr = 0;

    QPixmap pixmapfacebg("/home/ubuntu/RosUiSDK/face/face_bg.png");
    ui->lbl_facebg->setPixmap(pixmapfacebg);

}

void MainWindow::initializeSlam(){

    ctr = 0;

    QPixmap pixmapslambg("/home/ubuntu/RosUiSDK/slam/slam_bg.png");
    ui->lbl_slambg->setPixmap(pixmapslambg);

}

void MainWindow::initializeTextRecognition(){

    ctr = 0;
}


void MainWindow::on_btn_1_clicked()
{
    proc2->start("/bin/bash",QStringList()<<"-c"<<"start_sound");
}

void MainWindow::on_btn_2_clicked()
{
    proc3->start("gnome-terminal",QStringList()<<"-e"<<"sound_edit");
}

void MainWindow::initializeSpeechRecognition(){

    ctr = 0;

    if(ui->recognition->currentIndex()==4)
    {
        QFile checkFile("../speechSDK/scripts/start_talk");

        if(checkFile.exists()==true)
        {
            ui->start->setEnabled(true);
            ui->start->setEnabled(true);
        }
        else
        {
            ui->start->setEnabled(false);
            ui->add_edit->setEnabled(false);
            QMessageBox::StandardButton reply2;
            reply2 = QMessageBox::information(this,"Alert","SpeechSDK is not yet configured in this machine. \n\nPlease click 'Auto Setup SDK' Button to configure it automatically.", QMessageBox::Ok);


        }
    }

}

void MainWindow::refresher()
{
    //listview
    model = new QStringListModel(this);

    QStringList stringList;

    // open the file
    QFile textFile("../speechSDK/src/pocketsphinx/config/nav_commands.sent");
    if(!textFile.open(QIODevice::ReadOnly)) {

    }

    // teststream to read from file
    QTextStream textStream(&textFile);
    while (true)
    {
        QString line = textStream.readLine();
        if (line.isNull())
            break;
        else
            line.replace("<s>","");
        line.replace("</s>","");
        stringList.append(line); // populate the stringlist
    }

    // Populate the model
    model->setStringList(QStringList{});
    model->setStringList(stringList);

    // Glue model and view together
    ui->commandlist->setModel(model);


    // if you want to add additional feature to listview.
    ui->commandlist->
            setEditTriggers(QAbstractItemView::NoEditTriggers);

    //end


}
void MainWindow::hider()
{
    //listview
    model = new QStringListModel(this);


    // Populate the model
    model->setStringList(QStringList{});

    // Glue model and view together
    ui->commandlist->setModel(model);


    // if you want to add additional feature to listview.
    ui->commandlist->
            setEditTriggers(QAbstractItemView::NoEditTriggers);

    //end


}

void MainWindow::on_add_edit_clicked()
{
    connect(dialog, SIGNAL(destroyed(QObject*)), this, SLOT(refresher()));
    connect(dialog, SIGNAL(makeChange()), this, SLOT(hider()));

    dialog->setModal(true);
    dialog->exec();
}

void MainWindow::on_start_clicked()
{
    QFile checkFile("../speechSDK/scripts/start_talk");
    QFile checkFile2("../speechSDK/src/pocketsphinx");
    ui->command_label->setVisible(false);
    refresher();
    if(checkFile.exists()==true && checkFile2.exists()==true)
    {
        proc_4->start("../speechSDK/scripts/start_talk");
        ui->commandlist->setEnabled(true);
        ui->add_edit->setEnabled(false);
        ui->start->setEnabled(false);
        // ui->start->setStyleSheet("QPushButton{border:1px solid #aa000000;border-radius: 15px; background: #3cb0fd;background-image: -webkit-linear-gradient(top, #3cb0fd, #3498db);background-image: -moz-linear-gradient(top, #3cb0fd, #3498db);background-image: -ms-linear-gradient(top, #3cb0fd, #3498db);background-image: -o-linear-gradient(top, #3cb0fd, #3498db);background-image: linear-gradient(to bottom, #3cb0fd, #3498db);text-decoration: none;}");
        ui->status->setText("Running...");
    }
    else
    {
        QMessageBox::StandardButton reply2;
        reply2 = QMessageBox::information(this,"Alert","SpeechSDK is not properly configured in this machine. \n\nPossible reason is your internet connection.\n\nPlease check and click again the 'Auto Setup SDK' button to configure it automatically.", QMessageBox::Ok);
    }
}

void MainWindow::on_stop_clicked()
{
    QFile checkFile("../speechSDK/scripts/stop_talk");
    ui->command_label->setVisible(true);
    hider();
    if(checkFile.exists()==true)
    {
        proc_5->start("../speechSDK/scripts/stop_talk");
        ui->start->setEnabled(true);
        ui->commandlist->setEnabled(false);
        ui->add_edit->setEnabled(true);
        ui->status->setText("Stopped...");
    }
    else
    {

    }
}

void MainWindow::on_autosetup_clicked()
{
    QFile checkFile("../speechSDK/scripts/start_talk");
    QFile checkFile2("../integrating_speech");
    QFile checkFile3("../speechSDK/src/pocketsphinx");


    if(checkFile.exists()==true && checkFile3.exists()==false)
    {
        if(checkFile2.exists())
        {
            proc_10->start("gnome-terminal",QStringList()<<"-e"<<"rm ../integrating_speech");

        }
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this,"Auto Setup SDK","SpeechSDK will be automatically setup to this machine. \n\nThis will need your internet connection and machine password. \n\nDo you want to proceed?", QMessageBox::Yes | QMessageBox::No);

        if(reply == QMessageBox::Yes)
        {
            proc_1->start("gnome-terminal",QStringList()<<"-e"<<"wget --no-check-certificate 'https://docs.google.com/uc?export=download&id=0BwVZjNg0kZCYZ1dQTzJhR1UtdDQ'    -O ../integrating_speech --user-agent 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.22(KHTML, like Gecko) Ubuntu Chromium/25.0.1364.160 Chrome/25.0.1364.160 Safari/537.22'");
            proc_1->waitForStarted(30000);
            proc_1->waitForFinished(60000);


            QFile checkFile3("../integrating_speech");


            if (!(proc_1->waitForStarted()==true && checkFile3.exists()==true))
            {
                proc_2->waitForStarted();
                proc_2->start("gnome-terminal",QStringList()<<"-e"<<"chmod 755 ../integrating_speech");
                proc_2->waitForFinished();

                if(!proc_2->waitForFinished()==true)
                {
                    proc_3->waitForStarted();
                    proc_3->start("gnome-terminal",QStringList()<<"-e"<<"../integrating_speech");
                    proc_3->waitForFinished();
                    //refresher();
                    ui->start->setEnabled(true);
                }
            }

        }



    }else if(checkFile.exists()==false && checkFile3.exists()==false)
    {
        if(checkFile2.exists())
        {
            proc_10->start("gnome-terminal",QStringList()<<"-e"<<"rm ../integrating_speech");

        }
        QMessageBox::StandardButton reply;
        reply = QMessageBox::information(this,"Auto Setup SDK","SpeechSDK will be automatically setup to this machine. \n\nThis will need your internet connection and machine password. \n\nDo you want to proceed?", QMessageBox::Yes | QMessageBox::No);

        if(reply == QMessageBox::Yes)
        {
            proc_1->start("gnome-terminal",QStringList()<<"-e"<<"wget --no-check-certificate 'https://docs.google.com/uc?export=download&id=0BwVZjNg0kZCYZ1dQTzJhR1UtdDQ'    -O ../integrating_speech --user-agent 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.22(KHTML, like Gecko) Ubuntu Chromium/25.0.1364.160 Chrome/25.0.1364.160 Safari/537.22'");
            proc_1->waitForStarted(30000);
            proc_1->waitForFinished(60000);


            QFile checkFile3("../integrating_speech");


            if (!(proc_1->waitForStarted()==true && checkFile3.exists()==true))
            {
                proc_2->waitForStarted();
                proc_2->start("gnome-terminal",QStringList()<<"-e"<<"chmod 755 ../integrating_speech");
                proc_2->waitForFinished();

                if(!proc_2->waitForFinished()==true)
                {
                    proc_3->waitForStarted();
                    proc_3->start("gnome-terminal",QStringList()<<"-e"<<"../integrating_speech");
                    proc_3->waitForFinished();
                    //refresher();
                    ui->start->setEnabled(true);
                }
            }

        }

    }
    else
    {
        QMessageBox::StandardButton reply2;
        reply2 = QMessageBox::information(this,"Auto Setup SDK","SpeechSDK is properly configured in this machine.", QMessageBox::Ok);

    }

}

void MainWindow::closeEvent(QCloseEvent *event) {
    // do some data saves or something else
    proc_9->start("../speechSDK/scripts/stop_talk");

}
void MainWindow::initializeGesture(){

    ctr = 0;

    QPixmap pixmapgesturebg("/home/ubuntu/RosUiSDK/gesture/gesture_bg.jpg");
    ui->lbl_gesturebg->setPixmap(pixmapgesturebg);

}

void MainWindow::on_btn_gesture_clicked()
{
    QPixmap pixmapFace("/home/ubuntu/RosUiSDK/icon/facerecognition.png");
    QIcon buttonIconFace(pixmapFace);
    ui->btn_face->setIcon(buttonIconFace);
    ui->btn_face->setIconSize(QSize(350,350));

    QPixmap pixmapSlam("/home/ubuntu/RosUiSDK/icon/slamt.png");
    QIcon buttonIconSlam(pixmapSlam);
    ui->btn_slam->setIcon(buttonIconSlam);
    ui->btn_slam->setIconSize(QSize(350,350));

    QPixmap pixmapText("/home/ubuntu/RosUiSDK/icon/textrecognition.png");
    QIcon buttonIconText(pixmapText);
    ui->btn_text->setIcon(buttonIconText);
    ui->btn_text->setIconSize(QSize(350,350));

    QPixmap pixmapSpeech("/home/ubuntu/RosUiSDK/icon/speechrecognition.png");
    QIcon buttonIconSpeech(pixmapSpeech);
    ui->btn_speech->setIcon(buttonIconSpeech);
    ui->btn_speech->setIconSize(QSize(350,350));

    QPixmap pixmapGesture("/home/ubuntu/RosUiSDK/icon/gesture_2.png");
    QIcon buttonIconGesture(pixmapGesture);
    ui->btn_gesture->setIcon(buttonIconGesture);
    ui->btn_gesture->setIconSize(QSize(350,350));

    QPixmap pixmapRfid("/home/ubuntu/RosUiSDK/icon/rfid.png");
    QIcon buttonIconRfid(pixmapRfid);
    ui->btn_rfid->setIcon(buttonIconRfid);
    ui->btn_rfid->setIconSize(QSize(350,350));

    QPixmap pixmapBarcode("/home/ubuntu/RosUiSDK/icon/barcode.png");
    QIcon buttonIconBarcode(pixmapBarcode);
    ui->btn_barcode->setIcon(buttonIconBarcode);
    ui->btn_barcode->setIconSize(QSize(350,350));

    initializeGesture();
    ui->recognition->setCurrentIndex(5);

    QFile checkFile("../speechSDK/scripts/stop_talk");
    ui->command_label->setVisible(true);
    hider();
    if(checkFile.exists()==true)
    {
        proc_5->start("../speechSDK/scripts/stop_talk");
        ui->start->setEnabled(true);
        ui->commandlist->setEnabled(false);
        ui->add_edit->setEnabled(true);
        ui->status->setText("Standby...");
    }
    else
    {

    }

    proc4->start("/bin/bash",QStringList()<<"-c"<<"terminal_exit");
}

void MainWindow::initializeRfid()
{
    ctr = 0;

    QPixmap pixmaprfidbg("/home/ubuntu/RosUiSDK/rfid/rfid_bg.png");
    ui->lbl_rfidbg->setPixmap(pixmaprfidbg);
}

void MainWindow::on_btn_rfid_clicked()
{
    QPixmap pixmapFace("/home/ubuntu/RosUiSDK/icon/facerecognition.png");
    QIcon buttonIconFace(pixmapFace);
    ui->btn_face->setIcon(buttonIconFace);
    ui->btn_face->setIconSize(QSize(350,350));

    QPixmap pixmapSlam("/home/ubuntu/RosUiSDK/icon/slamt.png");
    QIcon buttonIconSlam(pixmapSlam);
    ui->btn_slam->setIcon(buttonIconSlam);
    ui->btn_slam->setIconSize(QSize(350,350));

    QPixmap pixmapText("/home/ubuntu/RosUiSDK/icon/textrecognition.png");
    QIcon buttonIconText(pixmapText);
    ui->btn_text->setIcon(buttonIconText);
    ui->btn_text->setIconSize(QSize(350,350));

    QPixmap pixmapSpeech("/home/ubuntu/RosUiSDK/icon/speechrecognition.png");
    QIcon buttonIconSpeech(pixmapSpeech);
    ui->btn_speech->setIcon(buttonIconSpeech);
    ui->btn_speech->setIconSize(QSize(350,350));

    QPixmap pixmapGesture("/home/ubuntu/RosUiSDK/icon/gesture.png");
    QIcon buttonIconGesture(pixmapGesture);
    ui->btn_gesture->setIcon(buttonIconGesture);
    ui->btn_gesture->setIconSize(QSize(350,350));

    QPixmap pixmapRfid("/home/ubuntu/RosUiSDK/icon/rfid_2.png");
    QIcon buttonIconRfid(pixmapRfid);
    ui->btn_rfid->setIcon(buttonIconRfid);
    ui->btn_rfid->setIconSize(QSize(350,350));

    QPixmap pixmapBarcode("/home/ubuntu/RosUiSDK/icon/barcode.png");
    QIcon buttonIconBarcode(pixmapBarcode);
    ui->btn_barcode->setIcon(buttonIconBarcode);
    ui->btn_barcode->setIconSize(QSize(350,350));

    initializeRfid();
    ui->recognition->setCurrentIndex(6);

    QFile checkFile("../speechSDK/scripts/stop_talk");
    ui->command_label->setVisible(true);
    hider();
    if(checkFile.exists()==true)
    {
        proc_5->start("../speechSDK/scripts/stop_talk");
        ui->start->setEnabled(true);
        ui->commandlist->setEnabled(false);
        ui->add_edit->setEnabled(true);
        ui->status->setText("Standby...");
    }
    else
    {

    }

    proc4->start("/bin/bash",QStringList()<<"-c"<<"terminal_exit");
}

void MainWindow::initializeBarcode(){

    ctr = 0;

    QPixmap pixmapbarcodebg("/home/ubuntu/RosUiSDK/barcode/barcode_bg.jpg");
    ui->lbl_barcodebg->setPixmap(pixmapbarcodebg);

}

void MainWindow::on_btn_barcode_clicked()
{
    QPixmap pixmapFace("/home/ubuntu/RosUiSDK/icon/facerecognition.png");
    QIcon buttonIconFace(pixmapFace);
    ui->btn_face->setIcon(buttonIconFace);
    ui->btn_face->setIconSize(QSize(350,350));

    QPixmap pixmapSlam("/home/ubuntu/RosUiSDK/icon/slamt.png");
    QIcon buttonIconSlam(pixmapSlam);
    ui->btn_slam->setIcon(buttonIconSlam);
    ui->btn_slam->setIconSize(QSize(350,350));

    QPixmap pixmapText("/home/ubuntu/RosUiSDK/icon/textrecognition.png");
    QIcon buttonIconText(pixmapText);
    ui->btn_text->setIcon(buttonIconText);
    ui->btn_text->setIconSize(QSize(350,350));

    QPixmap pixmapSpeech("/home/ubuntu/RosUiSDK/icon/speechrecognition.png");
    QIcon buttonIconSpeech(pixmapSpeech);
    ui->btn_speech->setIcon(buttonIconSpeech);
    ui->btn_speech->setIconSize(QSize(350,350));

    QPixmap pixmapGesture("/home/ubuntu/RosUiSDK/icon/gesture.png");
    QIcon buttonIconGesture(pixmapGesture);
    ui->btn_gesture->setIcon(buttonIconGesture);
    ui->btn_gesture->setIconSize(QSize(350,350));

    QPixmap pixmapRfid("/home/ubuntu/RosUiSDK/icon/rfid.png");
    QIcon buttonIconRfid(pixmapRfid);
    ui->btn_rfid->setIcon(buttonIconRfid);
    ui->btn_rfid->setIconSize(QSize(350,350));

    QPixmap pixmapBarcode("/home/ubuntu/RosUiSDK/icon/barcode_2.png");
    QIcon buttonIconBarcode(pixmapBarcode);
    ui->btn_barcode->setIcon(buttonIconBarcode);
    ui->btn_barcode->setIconSize(QSize(350,350));

    initializeBarcode();
    ui->recognition->setCurrentIndex(7);

    QFile checkFile("../speechSDK/scripts/stop_talk");
    ui->command_label->setVisible(true);
    hider();
    if(checkFile.exists()==true)
    {
        proc_5->start("../speechSDK/scripts/stop_talk");
        ui->start->setEnabled(true);
        ui->commandlist->setEnabled(false);
        ui->add_edit->setEnabled(true);
        ui->status->setText("Standby...");
    }
    else
    {

    }

    proc4->start("/bin/bash",QStringList()<<"-c"<<"terminal_exit");
}



void MainWindow::on_btn_setting_clicked()
{
   dialooog dialog;
   dialog.setModal(true);
   dialog.exec();
}


void MainWindow::stopVideo(){
    mediaPlayer->pause();
    m_timer->stop();
    m_timer->start(1000);
}

void MainWindow::startvideo(){
    if(ctr == 300){
        initializeVideo();
    }
    ctr++;
}

void MainWindow::initializeVideo(){

    connect (ui->btn_face,SIGNAL(clicked(bool)),this,SLOT(stopVideo()));
    connect (ui->btn_slam,SIGNAL(clicked(bool)),this,SLOT(stopVideo()));
    connect (ui->btn_text,SIGNAL(clicked(bool)),this,SLOT(stopVideo()));
    connect (ui->btn_speech,SIGNAL(clicked(bool)),this,SLOT(stopVideo()));
    connect (ui->btn_gesture,SIGNAL(clicked(bool)),this,SLOT(stopVideo()));
    connect (ui->btn_rfid,SIGNAL(clicked(bool)),this,SLOT(stopVideo()));
    connect (ui->btn_barcode,SIGNAL(clicked(bool)),this,SLOT(stopVideo()));
    if(mediaPlayer->state() != QMediaPlayer::PlayingState){
        ui->recognition->setCurrentIndex(0);
        ui->graphicsView->setScene(scene);
        scene->addItem(videoItem);
        mediaPlayer->setVideoOutput(videoItem);
        ui->graphicsView->scene()->addItem(videoItem);
        playlist->addMedia(QUrl::fromLocalFile("/home/ubuntu/RosUiSDK/video/xyz_home_vid.3gp"));
        mediaPlayer->setPlaylist(playlist);
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        mediaPlayer->play();

        QPixmap pixmapFace("/home/ubuntu/RosUiSDK/icon/facerecognition.png");
        QIcon buttonIconFace(pixmapFace);
        ui->btn_face->setIcon(buttonIconFace);
        ui->btn_face->setIconSize(QSize(350,350));

        QPixmap pixmapSlam("/home/ubuntu/RosUiSDK/icon/slamt.png");
        QIcon buttonIconSlam(pixmapSlam);
        ui->btn_slam->setIcon(buttonIconSlam);
        ui->btn_slam->setIconSize(QSize(350,350));

        QPixmap pixmapText("/home/ubuntu/RosUiSDK/icon/textrecognition.png");
        QIcon buttonIconText(pixmapText);
        ui->btn_text->setIcon(buttonIconText);
        ui->btn_text->setIconSize(QSize(350,350));

        QPixmap pixmapSpeech("/home/ubuntu/RosUiSDK/icon/speechrecognition.png");
        QIcon buttonIconSpeech(pixmapSpeech);
        ui->btn_speech->setIcon(buttonIconSpeech);
        ui->btn_speech->setIconSize(QSize(350,350));

        QPixmap pixmapGesture("/home/ubuntu/RosUiSDK/icon/gesture.png");
        QIcon buttonIconGesture(pixmapGesture);
        ui->btn_gesture->setIcon(buttonIconGesture);
        ui->btn_gesture->setIconSize(QSize(350,350));

        QPixmap pixmapRfid("/home/ubuntu/RosUiSDK/icon/rfid.png");
        QIcon buttonIconRfid(pixmapRfid);
        ui->btn_rfid->setIcon(buttonIconRfid);
        ui->btn_rfid->setIconSize(QSize(350,350));

        QPixmap pixmapBarcode("/home/ubuntu/RosUiSDK/icon/barcode.png");
        QIcon buttonIconBarcode(pixmapBarcode);
        ui->btn_barcode->setIcon(buttonIconBarcode);
        ui->btn_barcode->setIconSize(QSize(350,350));

}
}

