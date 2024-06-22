#include "MyProject.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);  //���ø� DPI ����
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);  //�ڸ� DPI ��ʾ����ʹ�ø� DPI ��ͼ��
    QApplication a(argc, argv);
    MyProject w;
    w.setAttribute(Qt::WA_TranslucentBackground);  //����͸���ı���
    w.setWindowFlags(Qt::FramelessWindowHint); //�ޱ߿򴰿�
    w.show();
    return a.exec();
}
