#pragma once

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include "ui_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class MyProject : public QWidget
{
    Q_OBJECT

public:
    MyProject(QWidget *parent = nullptr);
    ~MyProject();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    bool isTitleBar();

private:
    Ui::Widget::Ui_Widget ui;
    QPoint m_dragPos;
};
