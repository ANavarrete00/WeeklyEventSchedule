#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionImport_triggered();

private:
    Ui::MainWindow* ui;
    QGraphicsView* graphicsView = new QGraphicsView(this);
    QGraphicsScene* scene = new QGraphicsScene(this);
    QGraphicsPixmapItem* background;
    QGraphicsTextItem* title;
    QGraphicsTextItem* times;

};
#endif // MAINWINDOW_H
