#include "SplashScreen.h"
#include <QtWidgets/QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("312.png");  //��������ͼƬ
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();  //ʹ������ʾ��������ʱ������Ӧ���������¼�
    SplashScreen w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
