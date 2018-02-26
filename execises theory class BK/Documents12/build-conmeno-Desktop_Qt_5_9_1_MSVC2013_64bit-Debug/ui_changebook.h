/********************************************************************************
** Form generated from reading UI file 'changebook.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEBOOK_H
#define UI_CHANGEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changeBook
{
public:
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;

    void setupUi(QDialog *changeBook)
    {
        if (changeBook->objectName().isEmpty())
            changeBook->setObjectName(QStringLiteral("changeBook"));
        changeBook->resize(300, 600);
        label_4 = new QLabel(changeBook);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 350, 47, 13));
        lineEdit_4 = new QLineEdit(changeBook);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(56, 137, 251, 431));
        pushButton = new QPushButton(changeBook);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 572, 301, 31));
        widget = new QWidget(changeBook);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 301, 131));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(changeBook);

        QMetaObject::connectSlotsByName(changeBook);
    } // setupUi

    void retranslateUi(QDialog *changeBook)
    {
        changeBook->setWindowTitle(QApplication::translate("changeBook", "Dialog", Q_NULLPTR));
        label_4->setText(QApplication::translate("changeBook", "Discribe: ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("changeBook", "Change", Q_NULLPTR));
        label->setText(QApplication::translate("changeBook", "Name:", Q_NULLPTR));
        label_2->setText(QApplication::translate("changeBook", "Type: ", Q_NULLPTR));
        label_3->setText(QApplication::translate("changeBook", "Author: ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class changeBook: public Ui_changeBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEBOOK_H
