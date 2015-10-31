#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

class AudioClassTest
{
    private:
        QString FilePath;
    public:
        void SetFilePath(QString EnteredFilePath)
        {
            FilePath = EnteredFilePath;
        }
        QString GetFilePath()
        {
            return FilePath;
        }
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);

    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_pushButton_clicked()
{
    //load file
    AudioClassTest AudioOBJ;
    AudioOBJ.SetFilePath(ui-> lineEdit->text());
    ui->label_4->setText("Path: " + AudioOBJ.GetFilePath());
    player->setMedia(QUrl::fromLocalFile(AudioOBJ.GetFilePath()));
    player->play();
    qDebug() << player->errorString();
}

void MainWindow::on_pushButton_2_clicked()
{
    player->stop();
}

void MainWindow::on_positionChanged(qint64 position)
{
    ui->horizontalSlider->setValue(position);
}

void MainWindow::on_durationChanged(qint64 position)
{
    ui->horizontalSlider->setMaximum(position);
}
