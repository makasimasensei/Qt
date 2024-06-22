#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QTabWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <string>
#include <sstream>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPainter>
#include <QComboBox>
#include <QComboBox>
#include <QAbstractItemView>
#include <QListView>
#include "MyLabel.h"
#include "MyScrollArea.h"

QT_BEGIN_NAMESPACE

class Ui_Widget :public QObject
{
public:
	/*构造函数*/
	Ui_Widget(QWidget* Widget);
	/*析构函数*/
	~Ui_Widget();

	/*初始化界面*/
	QWidget* Widget;
	QPushButton* closeButton;
	QPushButton* minimizeButton;

	/*左侧导航栏*/
	QPushButton* pageButton_1, * pageButton_2, * pageButton_3;
	QString buttonStyle;
	QTabWidget* tabWidget;

	QWidget* ui_1, * ui_2, * ui_3;

	/*Ui界面1*/
	QFont ui_1_font1, ui_1_font2;
	QLabel* ui_1_picLabel;
	QLabel* ui_1_label_1, * ui_1_label_2, * ui_1_label_3;
	QPushButton* ui_1_pushButton;

	/*Ui界面2*/
	MyScrollArea* ui_2_scrollArea;
	QWidget* scrollWidget;
	MyLabel* ui_2_scrollLabel;
	QGridLayout* scrollLayout;
	QLabel* ui_2_label_1;
	QLineEdit* ui_2_lineEdit;
	QPushButton* ui_2_documentButton;
	QLabel* ui_2_label_2;
	QComboBox* ui_2_comboBox;
	QLabel* ui_2_label_3;

	/*初始化界面*/
	void setupWidget();
	void setupCloseButton();
	void setupMinimizeButton();

	/*左侧导航栏*/
	void setupPageButton_1();
	void setupPageButton_2();
	void setupPageButton_3();
	void setupTabWidget();

	/*Ui界面1*/
	void setupUi_1();
	void setupUi1Font_1();
	void setupUi1Font_2();
	void setupUi1PicLabel();
	void setupUi1Label_1();
	void setupUi1Label_2();
	void setupUi1Label_3();
	void setupUi1PushButton();

	/*Ui界面2*/
	void setupUi_2();
	void setupUi2ScrollArea();
	void setupUi2ScrollLabel();
	void setupUi2ScrollWidget();
	void setupUi2Label_1();
	void setupUi2LineEdit();
	void setupUi2DocumentButton();
	void setupUi2Label_2();
	void setupUi2ComboBox();
	void setupUi2Label_3();

	/*Ui界面3*/
	void setupUi_3();

	/*构建UI*/
	void retranslateUi();
	/*生成文本*/
	void setupUi();


	/*槽函数*/
public	slots:
	void pageButtonClick_1();
	void pageButtonClick_2();
	void pageButtonClick_3();
	void openUrl();
	void handleFileDropped(QList<QString> stringList);
	void handleReturnPressed();
	void documentClicked();

};

namespace Ui {
	class Widget : public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE
