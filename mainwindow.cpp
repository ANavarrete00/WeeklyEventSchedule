#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    background = new QGraphicsPixmapItem;
    title = new QGraphicsTextItem;
    times = new QGraphicsTextItem;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionImport_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images(*.png *.jpg *.bmp)"));

    if(QString::compare(filename, QString()) != 0)
    {
        QPixmap image;
        bool valid = image.load(filename);

        if(valid)
        {

            //scene->addPixmap(image);
            background->setPixmap(image);
            scene->addItem(background);
            ui->graphicsView->fitInView(scene->itemsBoundingRect() , Qt::KeepAspectRatio);
        }
        else
        {
            //Error handling
        }
    }
}

