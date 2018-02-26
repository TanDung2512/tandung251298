/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QComboBox *comboBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *BookName;
    QLabel *BookAuthor;
    QLabel *BookType;
    QLabel *BookRate;
    QLabel *BookDes;
    QLabel *IDBook;
    QLineEdit *txtSearch;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *WatchBook;

    void setupUi(QDialog *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QStringLiteral("Search"));
        Search->resize(900, 900);
        comboBox = new QComboBox(Search);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(40, 20, 104, 26));
        scrollArea = new QScrollArea(Search);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(30, 270, 671, 261));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 669, 259));
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
        IDBook = new QLabel(scrollAreaWidgetContents);
        IDBook->setObjectName(QStringLiteral("IDBook"));
        IDBook->setGeometry(QRect(20, 180, 660, 30));
        scrollArea->setWidget(scrollAreaWidgetContents);
        txtSearch = new QLineEdit(Search);
        txtSearch->setObjectName(QStringLiteral("txtSearch"));
        txtSearch->setGeometry(QRect(40, 60, 491, 41));
        listWidget = new QListWidget(Search);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(40, 110, 491, 141));
        pushButton = new QPushButton(Search);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(560, 60, 113, 32));
        WatchBook = new QPushButton(Search);
        WatchBook->setObjectName(QStringLiteral("WatchBook"));
        WatchBook->setGeometry(QRect(550, 110, 113, 32));

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QDialog *Search)
    {
        Search->setWindowTitle(QApplication::translate("Search", "Dialog", Q_NULLPTR));
        BookName->setText(QApplication::translate("Search", "Name:", Q_NULLPTR));
        BookAuthor->setText(QApplication::translate("Search", "Author:", Q_NULLPTR));
        BookType->setText(QApplication::translate("Search", "Type:", Q_NULLPTR));
        BookRate->setText(QApplication::translate("Search", "Rate:", Q_NULLPTR));
        BookDes->setText(QApplication::translate("Search", "Describe:", Q_NULLPTR));
        IDBook->setText(QApplication::translate("Search", "IDBook:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Search", "search", Q_NULLPTR));
        WatchBook->setText(QApplication::translate("Search", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
