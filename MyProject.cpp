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
paintEvent�� Qt�� QWidget���һ���¼������������ڴ����ڵĻ����¼���
��������Ҫ�����»���ʱ���細�ڱ���ʾ����С�ı�ȣ���Qt���Զ�����һ�������¼������ڣ���ʱ���ڻ������ paintEvent�������л��ơ�
*/
void MyProject::paintEvent(QPaintEvent* event)
{
	QLinearGradient gradient(0, 0, 400, 0);  //���Խ������ʼ��ͽ����������
	gradient.setColorAt(0, QColor(31, 72, 132, 240));  //�����ɫ��
	gradient.setColorAt(1, QColor(214, 238, 245));

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);  //�ڻ�ͼʱ���ÿ����Ч��
	painter.setBrush(QBrush(gradient));  //�������ˢ��ɫ���õ� QPainter������
	painter.setPen(QColor(31, 72, 132, 230));  //���û�ͼʱ�Ļ�����ɫ

	//    QRect rect = this->rect().adjusted(0, 0, -600, 0);  //�������������С
	//    painter.drawRoundedRect(rect, 25, 25);  //����һ������Բ�ǵľ���

	int cornerSize = 50;  //���δ�С
	int arcR = cornerSize / 2;  //Բ���뾶

	QPainterPath pathLeft;  //���������ͻ��Ƹ���·������
	QRect rectLeft(0, 0, 401, 630);

	pathLeft.moveTo(rectLeft.left() + arcR, rectLeft.top());  //�ƶ������Ͻ�
	pathLeft.arcTo(rectLeft.left(), rectLeft.top(), cornerSize, cornerSize, 90.0f, 90.0f);  //����ʱ�뷽���԰뾶Ϊ arcR������ 90�ȵ�Բ��

	pathLeft.lineTo(rectLeft.left(), rectLeft.bottom() - arcR);  //�ƶ������½�
	pathLeft.arcTo(rectLeft.left(), rectLeft.bottom() - cornerSize, cornerSize, cornerSize, 180.0f, 90.0f);  //����ʱ�뷽���԰뾶Ϊ arcR������ 90�ȵ�Բ��

	pathLeft.lineTo(rectLeft.bottomRight());  //�ƶ������½�

	pathLeft.lineTo(rectLeft.topRight());  //�ƶ������Ͻ�

	painter.fillPath(pathLeft, painter.brush());  //ʹ�� painter�л�ˢ���·��


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
		m_dragPos = event->globalPos() - frameGeometry().topLeft();  // ��¼��갴��ʱ��λ�úʹ���λ��
		event->accept();  //���ܵ�ǰ�¼�����ʾ�¼��Ѿ�������
	}
}

void MyProject::mouseMoveEvent(QMouseEvent* event)
{
	if ((event->buttons() & Qt::LeftButton) && MyProject::isTitleBar())
	{
		move(event->globalPos() - m_dragPos);  // �ƶ����ڵ���λ��
		event->accept();
	}
}

bool MyProject::isTitleBar()
{
	return (m_dragPos.x() > 0 && m_dragPos.x() < 1150) && (m_dragPos.y() > 0 && m_dragPos.y() < 100);
}
