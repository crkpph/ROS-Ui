#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QProcess>
#include <QComboBox>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
#include <QGraphicsView>
#include <QStringListModel>
#include <upload_commands.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initializeFaceRecognition();
    void initializeSlam();
    void initializeTextRecognition();
    void initializeSpeechRecognition();
    void initializeVideo();
    void initializeGesture();
    void initializeRfid();
    void initializeBarcode();



private slots:
    void on_btn_face_clicked();

    void on_btn_slam_clicked();

    void on_btn_text_clicked();

    void on_btn_speech_clicked();

    void timeout();

    void stopVideo();

    void startvideo();

    void on_btn_1_clicked();

    void on_btn_2_clicked();

    void on_btn_setting_clicked();

    void on_btn_gesture_clicked();

    void on_btn_rfid_clicked();

    void on_btn_barcode_clicked();

    void refresher();
    void hider();
    void closeEvent(QCloseEvent *event);

    void on_autosetup_clicked();

    void on_add_edit_clicked();

    void on_start_clicked();

    void on_stop_clicked();

signals:
    void makeChange();
    void accepted();

private:
    Ui::MainWindow *ui;

    QTimer *m_timer;
    QTimer *timer;
    QTimer *cnt;
    QMediaPlayer *mediaPlayer;
    QMediaPlaylist *playlist;
    QGraphicsVideoItem *videoItem;
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    QGraphicsProxyWidget *proxy;

    int counter;
    int ctr;

    QProcess *proc1;
    QProcess *proc2;
    QProcess *proc3;
    QProcess *proc4;


    QProcess *proc_1;
    QProcess *proc_2;
    QProcess *proc_3;
    QProcess *proc_4;
    QProcess *proc_5;
    QProcess *proc_6;
    QProcess *proc_7;
    QProcess *proc_8;
    QProcess *proc_9;
    QProcess *proc_10;
    QStringListModel *model;
    upload_commands *dialog;


};

#endif // MAINWINDOW_H
