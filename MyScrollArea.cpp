#include "MyScrollArea.h"

MyScrollArea::MyScrollArea(QWidget* parent) :QScrollArea(parent)
{
	setAcceptDrops(true);
}

MyScrollArea::~MyScrollArea()
{

}

MyScrollArea& MyScrollArea::operator=(MyScrollArea& copy)
{
	return copy;
}

void MyScrollArea::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->hasUrls())
	{
		event->acceptProposedAction();
	}
	else event->ignore();
}

void MyScrollArea::dropEvent(QDropEvent* event)
{
	if (event->mimeData()->hasUrls())
	{
		const QMimeData* mimeData = event->mimeData();
		QList<QUrl> urlList = mimeData->urls();
		if (!urlList.isEmpty())
		{
			QList<QString> stringList;
			for (QUrl url : urlList)
			{
				stringList.push_back(url.toLocalFile());
			}
			emit messageEmit(stringList);
		}
	}
}