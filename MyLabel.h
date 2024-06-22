#pragma once
#include <QLabel>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

class MyLabel :public QLabel
{
	Q_OBJECT

public:
	MyLabel(QWidget* parent = nullptr);

	void dragEnterEvent(QDragEnterEvent* event) override;
	void dropEvent(QDropEvent* event) override;

signals:
	void messageEmit(const QList<QString>& stringList);
};

