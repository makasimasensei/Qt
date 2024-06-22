#pragma once

#include <QScrollArea>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

class MyScrollArea :public QScrollArea
{
	Q_OBJECT

public:
	explicit MyScrollArea(QWidget* parent = nullptr);
	~MyScrollArea();
	MyScrollArea& operator=(MyScrollArea& copy);

	void dragEnterEvent(QDragEnterEvent* event) override;
	void dropEvent(QDropEvent* event) override;

signals:
	void messageEmit(const QList<QString>& stringList);
};

