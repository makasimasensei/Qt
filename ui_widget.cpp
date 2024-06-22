#include "ui_widget.h"
#include <QDebug>


/*构造函数*/
Ui_Widget::Ui_Widget(QWidget* w)
{
	Widget = w;
	closeButton = new QPushButton(Widget);
	minimizeButton = new QPushButton(Widget);

	pageButton_1 = new QPushButton(Widget);
	pageButton_2 = new QPushButton(Widget);
	pageButton_3 = new QPushButton(Widget);
	buttonStyle = QString::fromUtf8(
		"QPushButton{background-color: #f9f6f9;border: 1px;border-style: outset;border-color: #737373;border-radius: 9px;}\n"
		"QPushButton:hover{ background-color: #c9d4e3;}\n"
		"QPushButton:pressed {background-color: #8fb2e5;}"
	);
	tabWidget = new QTabWidget(Widget);

	ui_1 = new  QWidget();
	ui_1_picLabel = new QLabel(ui_1);
	ui_1_label_1 = new QLabel(ui_1);
	ui_1_label_2 = new QLabel(ui_1);
	ui_1_label_3 = new QLabel(ui_1);
	ui_1_pushButton = new QPushButton(ui_1);

	ui_2 = new  QWidget();
	ui_2_scrollArea = new MyScrollArea(ui_2);
	ui_2_scrollLabel = new MyLabel(ui_2_scrollArea);
	scrollWidget = new  QWidget(ui_2_scrollArea);
	scrollLayout = new QGridLayout(scrollWidget);
	ui_2_label_1 = new QLabel(ui_2);
	ui_2_lineEdit = new QLineEdit(ui_2);
	ui_2_documentButton = new QPushButton(ui_2);
	ui_2_label_2 = new QLabel(ui_2);
	ui_2_comboBox = new QComboBox(ui_2);
	ui_2_label_3 = new QLabel(ui_2);

	ui_3 = new  QWidget();
}

/*析构函数*/
Ui_Widget::~Ui_Widget()
{

}

/*初始化界面*/
void Ui_Widget::setupWidget()
{
	if (Widget->objectName().isEmpty())
		Widget->setObjectName(QString::fromUtf8("Widget"));
	Widget->resize(1170, 630);
	//Widget->setStyleSheet(QString::fromUtf8(""));
}

void Ui_Widget::setupCloseButton()
{
	QFont font;
	font.setPointSize(14);
	closeButton->setObjectName(QString::fromUtf8("closeButton"));
	closeButton->setGeometry(QRect(1120, 0, 50, 30));
	closeButton->setFont(font);
	closeButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#d6eef5;border-top-right-radius: 25px;border-bottom-left-radius: 10px;}\n"
		"QPushButton:hover{ background-color: #bed7df;}"));
}

void Ui_Widget::setupMinimizeButton()
{
	QFont font;
	font.setPointSize(14);
	minimizeButton->setObjectName(QString::fromUtf8("minimizeButton"));
	minimizeButton->setGeometry(QRect(1070, 0, 50, 30));
	minimizeButton->setFont(font);
	minimizeButton->setStyleSheet(QString::fromUtf8("QPushButton{background-color:#d6eef5;border-bottom-left-radius: 10px;border-bottom-right-radius: 10px}\n"
		"QPushButton:hover{ background-color: #bed7df;}"));
}

/*左侧导航栏*/
void Ui_Widget::setupPageButton_1()
{
	QFont font;
	font.setFamily("KaiTi");
	font.setPointSize(12);
	pageButton_1->setGeometry(QRect(10, 50, 90, 40));
	pageButton_1->setFont(font);
	pageButton_1->setStyleSheet(buttonStyle);
}

void Ui_Widget::setupPageButton_2()
{
	QFont font;
	font.setFamily("KaiTi");
	font.setPointSize(12);
	pageButton_2->setGeometry(QRect(10, 90, 90, 40));
	pageButton_2->setFont(font);
	pageButton_2->setStyleSheet(buttonStyle);
}

void Ui_Widget::setupPageButton_3()
{
	QFont font;
	font.setFamily("KaiTi");
	font.setPointSize(12);
	pageButton_3->setGeometry(QRect(10, 130, 90, 40));
	pageButton_3->setFont(font);
	pageButton_3->setStyleSheet(buttonStyle);
}

void Ui_Widget::setupTabWidget()
{
	tabWidget->setTabPosition(QTabWidget::West);
	tabWidget->setCurrentIndex(0);
	tabWidget->setStyleSheet(
		"QTabBar::tab{width: 0;height: 0;margin: 0;padding: 0;border: none;}\n"
		"QTabWidget::pane {border: 3px solid #ff4242;border-radius: 12px;border-style: outset;}"
	);
	tabWidget->setGeometry(QRect(90, 40, 1050, 560));
	tabWidget->addTab(ui_1, "1");
	tabWidget->addTab(ui_2, "2");
	tabWidget->addTab(ui_3, "3");
}

/*Ui界面1*/
void Ui_Widget::setupUi_1()
{
	ui_1->setStyleSheet(QString("QWidget{background-color:#e4f2f7;border: 2px;border-color: #000000;border-radius: 12px;}"));
}

void Ui_Widget::setupUi1Font_1()
{
	ui_1_font1.setFamily("KaiTi");
	ui_1_font1.setPointSize(24);
	ui_1_font1.setBold(true);
}

void Ui_Widget::setupUi1Font_2()
{
	ui_1_font2.setFamily("KaiTi");
	ui_1_font2.setPointSize(16);
}

void Ui_Widget::setupUi1PicLabel()
{
	ui_1_picLabel->setObjectName("ui_1_picLabel");
	QPixmap pixmap(":/image/rounded_image.png");
	ui_1_picLabel->setPixmap(pixmap);
	ui_1_picLabel->setGeometry(0, 0, 560, 560);
	ui_1_picLabel->resize(pixmap.size());
	ui_1_picLabel->show();
}

void Ui_Widget::setupUi1Label_1()
{
	ui_1_label_1->setGeometry(QRect(625, 210, 400, 30));
	ui_1_label_1->setFont(ui_1_font1);
	ui_1_label_1->setAlignment(Qt::AlignCenter);
	ui_1_label_1->setObjectName("ui_1_label_1");
}

void Ui_Widget::setupUi1Label_2()
{
	ui_1_label_2->setGeometry(QRect(625, 270, 400, 30));
	ui_1_label_2->setFont(ui_1_font1);
	ui_1_label_2->setAlignment(Qt::AlignCenter);
	ui_1_label_2->setObjectName("ui_1_label_2");
}

void Ui_Widget::setupUi1Label_3()
{
	ui_1_label_3->setGeometry(QRect(625, 330, 400, 30));
	ui_1_label_3->setFont(ui_1_font2);
	ui_1_label_3->setAlignment(Qt::AlignCenter);
	ui_1_label_3->setObjectName("ui_1_label_3");
}

void Ui_Widget::setupUi1PushButton()
{
	ui_1_pushButton->setGeometry(QRect(775, 400, 100, 40));
	ui_1_pushButton->setFont(ui_1_font2);
	QString ui_1_pageButtonstyle = (
		"QPushButton{background-color: #f9f6f9;border: 1px;border-style: outset;border-color: #737373;border-radius: 14px;}"
		"QPushButton:pressed {background-color: #c6c2c8;}"
		);
	ui_1_pushButton->setStyleSheet(ui_1_pageButtonstyle);
}

/*Ui界面2*/
void Ui_Widget::setupUi_2()
{
	ui_2->setStyleSheet(QString("QWidget{background-color:#e4f2f7;border: 2px;border-color: #000000;border-radius: 12px;}"));
}

void Ui_Widget::setupUi2ScrollArea()
{
	ui_2_scrollArea->setGeometry(QRect(10, 10, 500, 500));
	ui_2_scrollArea->setStyleSheet("QScrollArea{background-color:#ededed;border: 2px dashed black;border-color: #000000;padding: 5px;border-radius: 12px;}");
	ui_2_scrollArea->setObjectName("ui_2_scrollArea");
	ui_2_scrollArea->setWidgetResizable(true);
}

void Ui_Widget::setupUi2ScrollLabel()
{
	int parentWidth = ui_2_scrollArea->width();
	int parentHeight = ui_2_scrollArea->height();
	int childWidth = 200;
	int childHeight = 200;
	int childX = (parentWidth - childWidth) / 2;
	int childY = (parentHeight - childHeight) / 2;
	ui_2_scrollLabel->setGeometry(childX, childY, childWidth, childHeight);
	QPalette palette = ui_2_scrollLabel->palette();
	palette.setColor(QPalette::WindowText, QColor("#888888"));
	ui_2_scrollLabel->setPalette(palette);
	QFont	scrollLabelfont = QFont();
	scrollLabelfont.setFamily("KaiTi");
	scrollLabelfont.setPointSize(14);
	ui_2_scrollLabel->setFont(scrollLabelfont);
	ui_2_scrollLabel->setAlignment(Qt::AlignCenter);
}

void Ui_Widget::setupUi2ScrollWidget()
{
	scrollWidget->setLayout(scrollLayout);
	ui_2_scrollArea->setWidget(scrollWidget);
}

void Ui_Widget::setupUi2Label_1()
{
	ui_2_label_1->setGeometry(QRect(622, 40, 100, 15));
	QFont ui_2_font;
	ui_2_font.setFamily("KaiTi");
	ui_2_font.setPointSize(12);
	ui_2_label_1->setFont(ui_2_font);
	ui_2_label_1->setObjectName("ui_2_label_1");
}

void Ui_Widget::setupUi2LineEdit()
{
	ui_2_lineEdit->setGeometry(QRect(622, 60, 330, 40));
	QFont ui_2_line_font;
	ui_2_line_font.setFamily("Times New Roman");
	ui_2_line_font.setPointSize(14);
	ui_2_lineEdit->setFont(ui_2_line_font);
	ui_2_lineEdit->setStyleSheet("QLineEdit{background-color:#ffffff;border: 1px;border-style: outset;border-color: #737373;border-radius: 9px;}");
	ui_2_lineEdit->setObjectName("lineEdit");
	ui_2_lineEdit->setPlaceholderText("C:/Users/14485/Pictures/Screenshots/gt_0.jpg");
}

void Ui_Widget::setupUi2DocumentButton()
{
	ui_2_documentButton->setGeometry(QRect(975, 60, 40, 40));
	ui_2_documentButton->setStyleSheet("QPushButton{background-color:#ffffff;border: 1px;border-style: outset;border-color: #737373;border-radius: 9px;}"
		"QPushButton:pressed {background-color: #efefef;}");
	ui_2_documentButton->setObjectName("ui_2_documentButton");
	ui_2_documentButton->setIcon(QIcon(":/image/document.png"));
	ui_2_documentButton->setIconSize(QSize(30, 30));
}

void Ui_Widget::setupUi2Label_2()
{
	ui_2_label_2->setGeometry(QRect(622, 110, 100, 15));
	QFont ui_2_font;
	ui_2_font.setFamily("KaiTi");
	ui_2_font.setPointSize(12);
	ui_2_label_2->setFont(ui_2_font);
	ui_2_label_2->setObjectName("ui_2_label_2");
}

void Ui_Widget::setupUi2ComboBox()
{
	ui_2_comboBox->setView(new QListView());
	ui_2_comboBox->setGeometry(QRect(622, 130, 210, 40));
	ui_2_comboBox->setAcceptDrops(false);
	ui_2_comboBox->setStyleSheet(
		"QComboBox{border:1px solid;border-color:#737373;border-radius:9px;background-color: #ffffff;font: 16px\'Times New Roman\'}"
		"QComboBox:hover{background-color: rgba(249, 249, 249, 0.5)}"
		"ComboBox:pressed{background-color: rgba(249, 249, 249, 0.3);border-bottom: 1px solid rgba(0, 0, 0, 0.073);color: rgba(0, 0, 0, 0.63);}"
		"QComboBox::drop-down{border: none;}"
		"QComboBox::down-arrow{image: url(:/image/pulldown.png);}"
		"QComboBox QAbstractItemView{border:1px solid;border-color:#737373;border-radius:9px;background:rgba(255,255,255,0);background-color: #ffffff;outline: 0px;font-size:14px;}"
	);
	ui_2_comboBox->setObjectName("ComboBox");
	ui_2_comboBox->addItem("ResNet");
	ui_2_comboBox->addItem("MobileNet");
	ui_2_comboBox->addItem("ESNet");
}

void Ui_Widget::setupUi2Label_3()
{
	ui_2_label_3->setGeometry(QRect(622, 180, 100, 15));
	QFont ui_2_font;
	ui_2_font.setFamily("KaiTi");
	ui_2_font.setPointSize(12);
	ui_2_label_3->setFont(ui_2_font);
	ui_2_label_3->setObjectName("ui_2_label_3");
}

/*Ui界面3*/
void Ui_Widget::setupUi_3()
{
	ui_3->setStyleSheet(QString("QWidget{background-color:#e4f2f7;border: 2px;border-color: #000000;border-radius: 12px;}"));
}

/*槽函数*/
void Ui_Widget::pageButtonClick_1()
{
	tabWidget->setCurrentIndex(0);
}

void Ui_Widget::pageButtonClick_2()
{
	tabWidget->setCurrentIndex(1);
}

void Ui_Widget::pageButtonClick_3()
{
	tabWidget->setCurrentIndex(2);
}

void Ui_Widget::openUrl()
{
	QUrl url("https://pan.baidu.com/s/1DfO9-ip1t-QmPZ2CSZvwxQ?pwd=sh79");
	QDesktopServices::openUrl(url);
}

void Ui_Widget::handleFileDropped(QList<QString> stringList)
{
	QString file_paths;
	std::filesystem::path currentPath = std::filesystem::current_path();

	QList<QLabel*> children = ui_2_scrollArea->findChildren<QLabel*>();
	for (QWidget* child : children)
	{
		delete child;
	}

	for (int a = 1; a <= stringList.size(); a++)
	{
		QLabel* label = new QLabel(QString("Label %1").arg(a), ui_2_scrollArea);
		label->setStyleSheet("QLabel{border: None;}");
		label->setAlignment(Qt::AlignCenter);

		int row = (a - 1) / 4;
		int cloumn = (a - 1) % 4;
		scrollLayout->addWidget(label, row, cloumn);

		if (file_paths.isEmpty())file_paths = stringList[a - 1];
		else file_paths = file_paths + '\t' + stringList[a - 1];
		cv::Mat img = cv::imread(stringList[a - 1].toStdString());
		cv::resize(img, img, cv::Size(100, 100));
		std::ostringstream oss;
		oss << currentPath.string() << "\\image\\temp" << a << ".jpg";
		std::string path = oss.str();
		cv::imwrite(path, img);
		QPixmap pixmap = QPixmap(QString::fromStdString(path));
		label->setPixmap(pixmap);
		label->show();
		std::filesystem::remove(path);
	}
	ui_2_lineEdit->setText(file_paths);
}

void Ui_Widget::handleReturnPressed()
{
	QString text = ui_2_lineEdit->text();
	if (text.isEmpty()) {
		ui_2_lineEdit->setText("C:/Users/14485/Pictures/Screenshots/gt_0.jpg");
	}
}

void Ui_Widget::documentClicked()
{
	QStringList file_paths = QFileDialog::getOpenFileNames(nullptr, QString("Select one or more files to open"), "", "All Files (*)");
	if (!file_paths.isEmpty())
	{
		QString string;
		for (QString file_path : file_paths)
		{
			if (string.isEmpty())string += file_path;
			else string += '\t' + file_path;
		}
		ui_2_lineEdit->setText(string);
	}
}

/*构建UI*/
void Ui_Widget::setupUi()
{
	/*初始化界面*/
	setupWidget();
	setupCloseButton();
	setupMinimizeButton();

	/*左侧导航栏*/
	setupPageButton_1();
	setupPageButton_2();
	setupPageButton_3();
	setupTabWidget();

	/*Ui界面1*/
	setupUi_1();
	setupUi1Font_1();
	setupUi1Font_2();
	setupUi1PicLabel();
	setupUi1Label_1();
	setupUi1Label_2();
	setupUi1Label_3();
	setupUi1PushButton();

	/*Ui界面2*/
	setupUi_2();
	setupUi2ScrollArea();
	setupUi2ScrollLabel();
	setupUi2ScrollWidget();
	setupUi2Label_1();
	setupUi2LineEdit();
	setupUi2DocumentButton();
	setupUi2Label_2();
	setupUi2ComboBox();
	setupUi2Label_3();

	/*Ui界面3*/
	setupUi_3();

	/*槽函数*/
	connect(this->pageButton_1, &QPushButton::clicked, this, &Ui_Widget::pageButtonClick_1);
	connect(this->pageButton_2, &QPushButton::clicked, this, &Ui_Widget::pageButtonClick_2);
	connect(this->pageButton_3, &QPushButton::clicked, this, &Ui_Widget::pageButtonClick_3);
	connect(this->ui_1_pushButton, &QPushButton::clicked, this, &Ui_Widget::openUrl);
	connect(this->ui_2_scrollArea, &MyScrollArea::messageEmit, this, &Ui_Widget::handleFileDropped);
	connect(this->ui_2_scrollLabel, &MyLabel::messageEmit, this, &Ui_Widget::handleFileDropped);
	connect(this->ui_2_lineEdit, &QLineEdit::returnPressed, this, &Ui_Widget::handleReturnPressed);
	connect(this->ui_2_documentButton, &QPushButton::clicked, this, &Ui_Widget::documentClicked);

	retranslateUi();
}

/*生成文本*/
void  Ui_Widget::retranslateUi()
{
	Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
	closeButton->setText(QApplication::translate("Widget", "\303\227", nullptr));
	minimizeButton->setText(QApplication::translate("Widget", "_", nullptr));
	pageButton_1->setText(QApplication::translate("Widget", "\xe7\xae\x80\xe4\xbb\x8b", nullptr));
	pageButton_2->setText(QApplication::translate("Widget", "\xe5\x8f\x82\xe6\x95\xb0\xe8\xae\xbe\xe7\xbd\xae", nullptr));
	pageButton_3->setText(QApplication::translate("Widget", "\xe6\xa3\x80\xe6\xb5\x8b\xe7\xbb\x93\xe6\x9e\x9c", nullptr));
	ui_1_label_1->setText(QApplication::translate("Widget", "\xe5\x9c\xba\xe6\x99\xaf\xe6\x96\x87\xe6\x9c\xac\xe6\xa3\x80\xe6\xb5\x8b\xe4\xb8\x8e\xe8\xaf\x86\xe5\x88\xab\xe8\xbd\xaf\xe4\xbb\xb6", nullptr));
	ui_1_label_2->setText(QApplication::translate("Widget", "V1.0", nullptr));
	ui_1_label_3->setText(QApplication::translate("Widget", "\xe8\xbd\xaf\xe4\xbb\xb6\xe8\xaf\xa6\xe6\x83\x85\xe8\xaf\xb7\xe6\x9f\xa5\xe7\x9c\x8b\xe4\xbd\xbf\xe7\x94\xa8\xe8\xaf\xb4\xe6\x98\x8e", nullptr));
	ui_1_pushButton->setText(QApplication::translate("Widget", "\xe4\xbd\xbf\xe7\x94\xa8\xe8\xaf\xb4\xe6\x98\x8e", nullptr));
	ui_2_scrollLabel->setText(QApplication::translate("Widget", "\xe6\x8b\x96\xe6\x8b\xbd\xe5\x9b\xbe\xe7\x89\x87\xe5\x88\xb0\xe6\xad\xa4\xe5\xa4\x84", nullptr));
	ui_2_label_1->setText(QApplication::translate("Widget", "\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84", nullptr));
	ui_2_label_2->setText(QApplication::translate("Widget", "\xe9\xaa\xa8\xe5\xb9\xb2\xe7\xbd\x91\xe7\xbb\x9c", nullptr));
	ui_2_label_3->setText(QApplication::translate("Widget", "\xe7\x89\xb9\xe5\xbe\x81\xe8\x9e\x8d\xe5\x90\x88\xe7\xbd\x91\xe7\xbb\x9c", nullptr));
}