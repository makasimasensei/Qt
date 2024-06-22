#include "MyProject.h"
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>

MyProject::MyProject(QWidget* parent) : QWidget(parent), ui(this)
{
	ui.setupUi();
	connect(ui.closeButton, &QPushButton::clicked, this, &QWidget::close);
	connect(ui.minimizeButton, &QPushButton::clicked, this, &QWidget::showMinimized);
}

MyProject::~MyProject()
{
}

/*
paintEvent是 Qt中 QWidget类的一个事件处理函数，用于处理窗口的绘制事件。
当窗口需要被重新绘制时（如窗口被显示、大小改变等），Qt会自动发送一个绘制事件给窗口，此时窗口会调用其 paintEvent函数进行绘制。
*/
void MyProject::paintEvent(QPaintEvent* event)
{
	QLinearGradient gradient(0, 0, 400, 0);  //线性渐变的起始点和结束点的坐标
	gradient.setColorAt(0, QColor(31, 72, 132, 240));  //添加颜色点
	gradient.setColorAt(1, QColor(214, 238, 245));

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);  //在绘图时启用抗锯齿效果
	painter.setBrush(QBrush(gradient));  //将这个画刷颜色设置到 QPainter对象中
	painter.setPen(QColor(31, 72, 132, 230));  //设置绘图时的画笔颜色

	//    QRect rect = this->rect().adjusted(0, 0, -600, 0);  //调整矩形区域大小
	//    painter.drawRoundedRect(rect, 25, 25);  //绘制一个带有圆角的矩形

	int cornerSize = 50;  //矩形大小
	int arcR = cornerSize / 2;  //圆弧半径

	QPainterPath pathLeft;  //用于描述和绘制复杂路径的类
	QRect rectLeft(0, 0, 401, 630);

	pathLeft.moveTo(rectLeft.left() + arcR, rectLeft.top());  //移动到左上角
	pathLeft.arcTo(rectLeft.left(), rectLeft.top(), cornerSize, cornerSize, 90.0f, 90.0f);  //向逆时针方向以半径为 arcR，绘制 90度的圆弧

	pathLeft.lineTo(rectLeft.left(), rectLeft.bottom() - arcR);  //移动到左下角
	pathLeft.arcTo(rectLeft.left(), rectLeft.bottom() - cornerSize, cornerSize, cornerSize, 180.0f, 90.0f);  //向逆时针方向以半径为 arcR，绘制 90度的圆弧

	pathLeft.lineTo(rectLeft.bottomRight());  //移动到右下角

	pathLeft.lineTo(rectLeft.topRight());  //移动到右上角

	painter.fillPath(pathLeft, painter.brush());  //使用 painter中画刷填充路径


	QPainterPath pathRight;
	QRect rectRight(400, 0, 771, 630);

	painter.setPen(QColor(238, 240, 247));

	pathRight.moveTo(rectRight.topLeft());
	pathRight.lineTo(rectRight.bottomLeft());

	pathRight.lineTo(rectRight.right() - arcR, rectRight.bottom());
	pathRight.arcTo(rectRight.right() - cornerSize, rectRight.bottom() - cornerSize, cornerSize, cornerSize, -90.0f, 90.0f);

	pathRight.lineTo(rectRight.right(), rectRight.top() - arcR);
	pathRight.arcTo(rectRight.right() - cornerSize, rectRight.top(), cornerSize, cornerSize, 0.0f, 90.0f);

	painter.fillPath(pathRight, QBrush(QColor(214, 238, 245)));
}

void MyProject::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_dragPos = event->globalPos() - frameGeometry().topLeft();  // 记录鼠标按下时的位置和窗口位置
		event->accept();  //接受当前事件，表示事件已经被处理
	}
}

void MyProject::mouseMoveEvent(QMouseEvent* event)
{
	if ((event->buttons() & Qt::LeftButton) && MyProject::isTitleBar())
	{
		move(event->globalPos() - m_dragPos);  // 移动窗口到新位置
		event->accept();
	}
}

bool MyProject::isTitleBar()
{
	return (m_dragPos.x() > 0 && m_dragPos.x() < 1150) && (m_dragPos.y() > 0 && m_dragPos.y() < 100);
}
