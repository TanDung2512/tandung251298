/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *ExitBtn;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *AccountEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *PassEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *Loginbtn;
    QPushButton *Registerbtn;
    QWidget *page_2;
    QPushButton *LogOut;
    QGroupBox *groupBox;
    QPushButton *BookShow;
    QPushButton *BookShow_2;
    QPushButton *BookShow_3;
    QPushButton *BookShow_4;
    QPushButton *BookShow_5;
    QPushButton *BookShow_6;
    QPushButton *BookShow_7;
    QPushButton *BookShow_8;
    QPushButton *BookShow_9;
    QPushButton *BookShow_10;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *BookName;
    QLabel *BookAuthor;
    QLabel *BookType;
    QLabel *BookRate;
    QLabel *BookDes;
    QLabel *BookID;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *Name;
    QLabel *ID;
    QLabel *AccName;
    QPushButton *ChangeInfo;
    QPushButton *OK;
    QPushButton *pushButton_4;
    QPushButton *AdminTab;
    QPushButton *AddCart;
    QPushButton *Cart;
    QPushButton *Search;
    QPushButton *LibrarianTab;
    QWidget *page_8;
    QPushButton *Reader_2;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *Name_4;
    QLabel *ID_4;
    QLabel *AccName_4;
    QPushButton *AddBook;
    QPushButton *DeleteBook;
    QPushButton *SearchBook;
    QListWidget *RequiredBook;
    QListWidget *RequiredBook1;
    QWidget *page_4;
    QPushButton *WatchBook_3;
    QPushButton *WatchBook_4;
    QListWidget *listWidget_4;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QLabel *BookName_4;
    QLabel *BookAuthor_4;
    QLabel *BookType_4;
    QLabel *BookRate_4;
    QLabel *BookDes_4;
    QLabel *BookID_3;
    QPushButton *Back;
    QWidget *page_3;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_8;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_6;
    QPushButton *Exit;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *Name_2;
    QLabel *ID_2;
    QLabel *AccName_2;
    QPushButton *Reader;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(900, 900);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 900, 900));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        ExitBtn = new QPushButton(page);
        ExitBtn->setObjectName(QStringLiteral("ExitBtn"));
        ExitBtn->setGeometry(QRect(790, 800, 100, 30));
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(13, 10, 881, 38));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QStringLiteral("Ravie"));
        font.setPointSize(20);
        label_3->setFont(font);

        horizontalLayout_5->addWidget(label_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        AccountEdit = new QLineEdit(layoutWidget);
        AccountEdit->setObjectName(QStringLiteral("AccountEdit"));

        horizontalLayout_3->addWidget(AccountEdit);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        PassEdit = new QLineEdit(layoutWidget);
        PassEdit->setObjectName(QStringLiteral("PassEdit"));
        PassEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(PassEdit);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Loginbtn = new QPushButton(layoutWidget);
        Loginbtn->setObjectName(QStringLiteral("Loginbtn"));

        horizontalLayout->addWidget(Loginbtn);

        Registerbtn = new QPushButton(layoutWidget);
        Registerbtn->setObjectName(QStringLiteral("Registerbtn"));

        horizontalLayout->addWidget(Registerbtn);


        horizontalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        LogOut = new QPushButton(page_2);
        LogOut->setObjectName(QStringLiteral("LogOut"));
        LogOut->setGeometry(QRect(790, 800, 100, 30));
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(100, 150, 700, 270));
        BookShow = new QPushButton(groupBox);
        BookShow->setObjectName(QStringLiteral("BookShow"));
        BookShow->setGeometry(QRect(20, 20, 310, 30));
        BookShow_2 = new QPushButton(groupBox);
        BookShow_2->setObjectName(QStringLiteral("BookShow_2"));
        BookShow_2->setGeometry(QRect(20, 60, 310, 30));
        BookShow_3 = new QPushButton(groupBox);
        BookShow_3->setObjectName(QStringLiteral("BookShow_3"));
        BookShow_3->setGeometry(QRect(20, 100, 310, 30));
        BookShow_4 = new QPushButton(groupBox);
        BookShow_4->setObjectName(QStringLiteral("BookShow_4"));
        BookShow_4->setGeometry(QRect(20, 140, 310, 30));
        BookShow_5 = new QPushButton(groupBox);
        BookShow_5->setObjectName(QStringLiteral("BookShow_5"));
        BookShow_5->setGeometry(QRect(20, 180, 310, 30));
        BookShow_6 = new QPushButton(groupBox);
        BookShow_6->setObjectName(QStringLiteral("BookShow_6"));
        BookShow_6->setGeometry(QRect(370, 20, 310, 30));
        BookShow_7 = new QPushButton(groupBox);
        BookShow_7->setObjectName(QStringLiteral("BookShow_7"));
        BookShow_7->setGeometry(QRect(370, 60, 310, 30));
        BookShow_8 = new QPushButton(groupBox);
        BookShow_8->setObjectName(QStringLiteral("BookShow_8"));
        BookShow_8->setGeometry(QRect(370, 100, 310, 30));
        BookShow_9 = new QPushButton(groupBox);
        BookShow_9->setObjectName(QStringLiteral("BookShow_9"));
        BookShow_9->setGeometry(QRect(370, 140, 310, 30));
        BookShow_10 = new QPushButton(groupBox);
        BookShow_10->setObjectName(QStringLiteral("BookShow_10"));
        BookShow_10->setGeometry(QRect(370, 180, 310, 30));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(18, 230, 661, 32));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_6->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_6->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_6->addWidget(pushButton_3);

        scrollArea = new QScrollArea(page_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(100, 450, 700, 300));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 698, 298));
        BookName = new QLabel(scrollAreaWidgetContents);
        BookName->setObjectName(QStringLiteral("BookName"));
        BookName->setGeometry(QRect(20, 20, 660, 30));
        BookAuthor = new QLabel(scrollAreaWidgetContents);
        BookAuthor->setObjectName(QStringLiteral("BookAuthor"));
        BookAuthor->setGeometry(QRect(20, 60, 660, 30));
        BookType = new QLabel(scrollAreaWidgetContents);
        BookType->setObjectName(QStringLiteral("BookType"));
        BookType->setGeometry(QRect(20, 100, 660, 30));
        BookRate = new QLabel(scrollAreaWidgetContents);
        BookRate->setObjectName(QStringLiteral("BookRate"));
        BookRate->setGeometry(QRect(20, 140, 660, 30));
        BookDes = new QLabel(scrollAreaWidgetContents);
        BookDes->setObjectName(QStringLiteral("BookDes"));
        BookDes->setGeometry(QRect(20, 200, 660, 100));
        BookID = new QLabel(scrollAreaWidgetContents);
        BookID->setObjectName(QStringLiteral("BookID"));
        BookID->setGeometry(QRect(20, 180, 660, 30));
        scrollArea->setWidget(scrollAreaWidgetContents);
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 340, 150));
        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 10, 331, 178));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Name = new QLabel(layoutWidget2);
        Name->setObjectName(QStringLiteral("Name"));

        verticalLayout->addWidget(Name);

        ID = new QLabel(layoutWidget2);
        ID->setObjectName(QStringLiteral("ID"));

        verticalLayout->addWidget(ID);

        AccName = new QLabel(layoutWidget2);
        AccName->setObjectName(QStringLiteral("AccName"));

        verticalLayout->addWidget(AccName);

        ChangeInfo = new QPushButton(layoutWidget2);
        ChangeInfo->setObjectName(QStringLiteral("ChangeInfo"));

        verticalLayout->addWidget(ChangeInfo);

        OK = new QPushButton(layoutWidget2);
        OK->setObjectName(QStringLiteral("OK"));

        verticalLayout->addWidget(OK);

        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 0, 100, 30));
        AdminTab = new QPushButton(page_2);
        AdminTab->setObjectName(QStringLiteral("AdminTab"));
        AdminTab->setGeometry(QRect(400, 30, 100, 30));
        AddCart = new QPushButton(page_2);
        AddCart->setObjectName(QStringLiteral("AddCart"));
        AddCart->setGeometry(QRect(810, 510, 91, 32));
        Cart = new QPushButton(page_2);
        Cart->setObjectName(QStringLiteral("Cart"));
        Cart->setGeometry(QRect(700, 120, 91, 32));
        Search = new QPushButton(page_2);
        Search->setObjectName(QStringLiteral("Search"));
        Search->setGeometry(QRect(520, 120, 81, 32));
        LibrarianTab = new QPushButton(page_2);
        LibrarianTab->setObjectName(QStringLiteral("LibrarianTab"));
        LibrarianTab->setGeometry(QRect(550, 30, 100, 30));
        stackedWidget->addWidget(page_2);
        page_8 = new QWidget();
        page_8->setObjectName(QStringLiteral("page_8"));
        Reader_2 = new QPushButton(page_8);
        Reader_2->setObjectName(QStringLiteral("Reader_2"));
        Reader_2->setGeometry(QRect(410, 30, 100, 30));
        layoutWidget_6 = new QWidget(page_8);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 0, 331, 131));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        Name_4 = new QLabel(layoutWidget_6);
        Name_4->setObjectName(QStringLiteral("Name_4"));

        verticalLayout_5->addWidget(Name_4);

        ID_4 = new QLabel(layoutWidget_6);
        ID_4->setObjectName(QStringLiteral("ID_4"));

        verticalLayout_5->addWidget(ID_4);

        AccName_4 = new QLabel(layoutWidget_6);
        AccName_4->setObjectName(QStringLiteral("AccName_4"));

        verticalLayout_5->addWidget(AccName_4);

        AddBook = new QPushButton(page_8);
        AddBook->setObjectName(QStringLiteral("AddBook"));
        AddBook->setGeometry(QRect(670, 80, 100, 30));
        DeleteBook = new QPushButton(page_8);
        DeleteBook->setObjectName(QStringLiteral("DeleteBook"));
        DeleteBook->setGeometry(QRect(540, 80, 100, 30));
        SearchBook = new QPushButton(page_8);
        SearchBook->setObjectName(QStringLiteral("SearchBook"));
        SearchBook->setGeometry(QRect(410, 80, 100, 30));
        RequiredBook = new QListWidget(page_8);
        RequiredBook->setObjectName(QStringLiteral("RequiredBook"));
        RequiredBook->setGeometry(QRect(30, 200, 241, 331));
        RequiredBook1 = new QListWidget(page_8);
        RequiredBook1->setObjectName(QStringLiteral("RequiredBook1"));
        RequiredBook1->setGeometry(QRect(350, 200, 231, 331));
        stackedWidget->addWidget(page_8);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        WatchBook_3 = new QPushButton(page_4);
        WatchBook_3->setObjectName(QStringLiteral("WatchBook_3"));
        WatchBook_3->setGeometry(QRect(210, 260, 113, 32));
        WatchBook_4 = new QPushButton(page_4);
        WatchBook_4->setObjectName(QStringLiteral("WatchBook_4"));
        WatchBook_4->setGeometry(QRect(360, 260, 113, 32));
        listWidget_4 = new QListWidget(page_4);
        listWidget_4->setObjectName(QStringLiteral("listWidget_4"));
        listWidget_4->setEnabled(true);
        listWidget_4->setGeometry(QRect(160, 30, 511, 221));
        scrollArea_4 = new QScrollArea(page_4);
        scrollArea_4->setObjectName(QStringLiteral("scrollArea_4"));
        scrollArea_4->setGeometry(QRect(100, 320, 571, 241));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QStringLiteral("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 569, 239));
        BookName_4 = new QLabel(scrollAreaWidgetContents_4);
        BookName_4->setObjectName(QStringLiteral("BookName_4"));
        BookName_4->setGeometry(QRect(20, 20, 660, 30));
        BookAuthor_4 = new QLabel(scrollAreaWidgetContents_4);
        BookAuthor_4->setObjectName(QStringLiteral("BookAuthor_4"));
        BookAuthor_4->setGeometry(QRect(20, 60, 660, 30));
        BookType_4 = new QLabel(scrollAreaWidgetContents_4);
        BookType_4->setObjectName(QStringLiteral("BookType_4"));
        BookType_4->setGeometry(QRect(20, 100, 660, 30));
        BookRate_4 = new QLabel(scrollAreaWidgetContents_4);
        BookRate_4->setObjectName(QStringLiteral("BookRate_4"));
        BookRate_4->setGeometry(QRect(20, 140, 660, 30));
        BookDes_4 = new QLabel(scrollAreaWidgetContents_4);
        BookDes_4->setObjectName(QStringLiteral("BookDes_4"));
        BookDes_4->setGeometry(QRect(20, 180, 660, 100));
        BookID_3 = new QLabel(scrollAreaWidgetContents_4);
        BookID_3->setObjectName(QStringLiteral("BookID_3"));
        BookID_3->setGeometry(QRect(20, 180, 660, 30));
        scrollArea_4->setWidget(scrollAreaWidgetContents_4);
        Back = new QPushButton(page_4);
        Back->setObjectName(QStringLiteral("Back"));
        Back->setGeometry(QRect(10, 40, 91, 32));
        stackedWidget->addWidget(page_4);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        groupBox_3 = new QGroupBox(page_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 150, 600, 700));
        layoutWidget3 = new QWidget(groupBox_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 10, 591, 681));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_9->addWidget(label_4);

        lineEdit = new QLineEdit(layoutWidget3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_9->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        listWidget = new QListWidget(layoutWidget3);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout_8->addWidget(listWidget);

        listWidget_2 = new QListWidget(layoutWidget3);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));

        horizontalLayout_8->addWidget(listWidget_2);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_6 = new QPushButton(layoutWidget3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_7->addWidget(pushButton_6);


        verticalLayout_2->addLayout(horizontalLayout_7);

        Exit = new QPushButton(page_3);
        Exit->setObjectName(QStringLiteral("Exit"));
        Exit->setGeometry(QRect(750, 800, 100, 30));
        groupBox_4 = new QGroupBox(page_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 0, 340, 150));
        layoutWidget_2 = new QWidget(groupBox_4);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 10, 331, 131));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        Name_2 = new QLabel(layoutWidget_2);
        Name_2->setObjectName(QStringLiteral("Name_2"));

        verticalLayout_3->addWidget(Name_2);

        ID_2 = new QLabel(layoutWidget_2);
        ID_2->setObjectName(QStringLiteral("ID_2"));

        verticalLayout_3->addWidget(ID_2);

        AccName_2 = new QLabel(layoutWidget_2);
        AccName_2->setObjectName(QStringLiteral("AccName_2"));

        verticalLayout_3->addWidget(AccName_2);

        Reader = new QPushButton(page_3);
        Reader->setObjectName(QStringLiteral("Reader"));
        Reader->setGeometry(QRect(400, 20, 100, 30));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        ExitBtn->setText(QApplication::translate("MainWindow", "EXIT", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "LIBPRO", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Account Name", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        Loginbtn->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        Registerbtn->setText(QApplication::translate("MainWindow", "Register", Q_NULLPTR));
        LogOut->setText(QApplication::translate("MainWindow", "Logout", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        BookShow->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        BookShow_2->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        BookShow_3->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        BookShow_4->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        BookShow_5->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        BookShow_6->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        BookShow_7->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        BookShow_8->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        BookShow_9->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        BookShow_10->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "HOT BOOK!", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "NEW BOOK!", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "OLD GOOD BOOK!", Q_NULLPTR));
        BookName->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        BookAuthor->setText(QApplication::translate("MainWindow", "Author:", Q_NULLPTR));
        BookType->setText(QApplication::translate("MainWindow", "Type:", Q_NULLPTR));
        BookRate->setText(QApplication::translate("MainWindow", "Rate:", Q_NULLPTR));
        BookDes->setText(QApplication::translate("MainWindow", "Describe:", Q_NULLPTR));
        BookID->setText(QApplication::translate("MainWindow", "ID Book:", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        Name->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        ID->setText(QApplication::translate("MainWindow", "ID:", Q_NULLPTR));
        AccName->setText(QApplication::translate("MainWindow", "Account:", Q_NULLPTR));
        ChangeInfo->setText(QApplication::translate("MainWindow", "Full Info", Q_NULLPTR));
        OK->setText(QApplication::translate("MainWindow", "OK", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "User Info", Q_NULLPTR));
        AdminTab->setText(QApplication::translate("MainWindow", "Admin ", Q_NULLPTR));
        AddCart->setText(QApplication::translate("MainWindow", "Add cart", Q_NULLPTR));
        Cart->setText(QApplication::translate("MainWindow", "Cart", Q_NULLPTR));
        Search->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        LibrarianTab->setText(QApplication::translate("MainWindow", "Librarian", Q_NULLPTR));
        Reader_2->setText(QApplication::translate("MainWindow", "Reader", Q_NULLPTR));
        Name_4->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        ID_4->setText(QApplication::translate("MainWindow", "ID:", Q_NULLPTR));
        AccName_4->setText(QApplication::translate("MainWindow", "Account:", Q_NULLPTR));
        AddBook->setText(QApplication::translate("MainWindow", "AddBook", Q_NULLPTR));
        DeleteBook->setText(QApplication::translate("MainWindow", "DeleteBook", Q_NULLPTR));
        SearchBook->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        WatchBook_3->setText(QApplication::translate("MainWindow", "Watch Book", Q_NULLPTR));
        WatchBook_4->setText(QApplication::translate("MainWindow", "Submit", Q_NULLPTR));
        BookName_4->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        BookAuthor_4->setText(QApplication::translate("MainWindow", "Author:", Q_NULLPTR));
        BookType_4->setText(QApplication::translate("MainWindow", "Type:", Q_NULLPTR));
        BookRate_4->setText(QApplication::translate("MainWindow", "Rate:", Q_NULLPTR));
        BookDes_4->setText(QApplication::translate("MainWindow", "Describe:", Q_NULLPTR));
        BookID_3->setText(QApplication::translate("MainWindow", "ID:", Q_NULLPTR));
        Back->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Acc", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Reset Password", Q_NULLPTR));
        Exit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        Name_2->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        ID_2->setText(QApplication::translate("MainWindow", "ID:", Q_NULLPTR));
        AccName_2->setText(QApplication::translate("MainWindow", "Account:", Q_NULLPTR));
        Reader->setText(QApplication::translate("MainWindow", "Reader", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
