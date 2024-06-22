#include "MyLabel.h"

MyLabel::MyLabel(QWidget* parent) : QLabel(parent)
{
	setAcceptDrops(true);
}

void MyLabel::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->hasUrls())
	{
		event->acceptProposedAction();
	}
	else event->ignore();
}

void MyLabel::dropEvent(QDropEvent* event)
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