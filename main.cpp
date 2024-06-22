#include "MyProject.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);  //启用高 DPI 缩放
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);  //在高 DPI 显示器上使用高 DPI 的图像
    QApplication a(argc, argv);
    MyProject w;
    w.setAttribute(Qt::WA_TranslucentBackground);  //设置透明的背景
    w.setWindowFlags(Qt::FramelessWindowHint); //无边框窗口
    w.show();
    return a.exec();
}
