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
    QGroupBox *groupBox_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QLabel *Name;
    QLabel *ID;
    QLabel *AccName;
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
        stackedWidget->setGeometry(QRect(0, -40, 900, 900));
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
        BookDes->setGeometry(QRect(20, 180, 660, 100));
        scrollArea->setWidget(scrollAreaWidgetContents);
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 0, 340, 150));
        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 10, 331, 131));
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

        stackedWidget->addWidget(page_2);
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

        stackedWidget->setCurrentIndex(1);


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
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        Name->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        ID->setText(QApplication::translate("MainWindow", "ID:", Q_NULLPTR));
        AccName->setText(QApplication::translate("MainWindow", "Account:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
