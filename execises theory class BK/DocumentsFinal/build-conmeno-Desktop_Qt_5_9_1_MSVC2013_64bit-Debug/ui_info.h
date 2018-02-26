/********************************************************************************
** Form generated from reading UI file 'info.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_H
#define UI_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_info
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *NameUser;
    QLineEdit *Job;
    QLineEdit *Email;
    QLabel *IDUser;
    QLabel *SSNUser;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *AccountName;
    QLabel *AccountID;
    QLabel *IsReader;
    QPushButton *IsBlirarian;
    QPushButton *IsAdmin;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *label_3;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *OldPass;
    QLineEdit *ComfirmPass;
    QLineEdit *NewPass;
    QPushButton *ChangeInfo;
    QPushButton *ChangePass;
    QPushButton *Ok;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QLabel *label_14;
    QLabel *History5;

    void setupUi(QDialog *info)
    {
        if (info->objectName().isEmpty())
            info->setObjectName(QStringLiteral("info"));
        info->resize(1200, 230);
        scrollArea = new QScrollArea(info);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 300, 200));
        scrollArea->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 298, 198));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 300, 30));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(9);
        sizePolicy.setVerticalStretch(14);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setTextFormat(Qt::AutoText);
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 50, 100, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Calligraphy"));
        label_4->setFont(font1);
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 80, 100, 30));
        label_5->setFont(font1);
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 110, 100, 30));
        label_6->setFont(font1);
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 140, 100, 30));
        label_7->setFont(font1);
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 170, 100, 30));
        label_8->setFont(font1);
        NameUser = new QLineEdit(scrollAreaWidgetContents);
        NameUser->setObjectName(QStringLiteral("NameUser"));
        NameUser->setGeometry(QRect(100, 50, 200, 30));
        Job = new QLineEdit(scrollAreaWidgetContents);
        Job->setObjectName(QStringLiteral("Job"));
        Job->setGeometry(QRect(100, 140, 200, 30));
        Email = new QLineEdit(scrollAreaWidgetContents);
        Email->setObjectName(QStringLiteral("Email"));
        Email->setGeometry(QRect(100, 170, 200, 30));
        IDUser = new QLabel(scrollAreaWidgetContents);
        IDUser->setObjectName(QStringLiteral("IDUser"));
        IDUser->setGeometry(QRect(100, 80, 200, 30));
        SSNUser = new QLabel(scrollAreaWidgetContents);
        SSNUser->setObjectName(QStringLiteral("SSNUser"));
        SSNUser->setGeometry(QRect(100, 110, 200, 30));
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(info);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(300, 0, 300, 200));
        scrollArea_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 298, 198));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 300, 30));
        label_2->setFont(font);
        label_9 = new QLabel(scrollAreaWidgetContents_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 50, 100, 30));
        label_9->setFont(font1);
        label_10 = new QLabel(scrollAreaWidgetContents_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 80, 100, 30));
        label_10->setFont(font1);
        label_11 = new QLabel(scrollAreaWidgetContents_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 110, 100, 30));
        label_11->setFont(font1);
        label_12 = new QLabel(scrollAreaWidgetContents_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 170, 100, 30));
        label_12->setFont(font1);
        label_13 = new QLabel(scrollAreaWidgetContents_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(0, 140, 100, 30));
        label_13->setFont(font1);
        AccountName = new QLabel(scrollAreaWidgetContents_2);
        AccountName->setObjectName(QStringLiteral("AccountName"));
        AccountName->setGeometry(QRect(100, 50, 200, 30));
        AccountID = new QLabel(scrollAreaWidgetContents_2);
        AccountID->setObjectName(QStringLiteral("AccountID"));
        AccountID->setGeometry(QRect(100, 80, 200, 30));
        IsReader = new QLabel(scrollAreaWidgetContents_2);
        IsReader->setObjectName(QStringLiteral("IsReader"));
        IsReader->setGeometry(QRect(100, 110, 200, 30));
        IsBlirarian = new QPushButton(scrollAreaWidgetContents_2);
        IsBlirarian->setObjectName(QStringLiteral("IsBlirarian"));
        IsBlirarian->setGeometry(QRect(100, 140, 200, 30));
        IsBlirarian->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        IsAdmin = new QPushButton(scrollAreaWidgetContents_2);
        IsAdmin->setObjectName(QStringLiteral("IsAdmin"));
        IsAdmin->setGeometry(QRect(100, 169, 200, 30));
        IsAdmin->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        scrollArea_3 = new QScrollArea(info);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(600, 0, 300, 200));
        scrollArea_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 298, 198));
        label_3 = new QLabel(scrollAreaWidgetContents_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 300, 30));
        label_3->setFont(font);
        label_17 = new QLabel(scrollAreaWidgetContents_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, 50, 100, 30));
        label_18 = new QLabel(scrollAreaWidgetContents_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(0, 110, 100, 30));
        label_19 = new QLabel(scrollAreaWidgetContents_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(0, 170, 100, 30));
        OldPass = new QLineEdit(scrollAreaWidgetContents_3);
        OldPass->setObjectName(QStringLiteral("OldPass"));
        OldPass->setGeometry(QRect(100, 50, 200, 30));
        OldPass->setEchoMode(QLineEdit::Password);
        ComfirmPass = new QLineEdit(scrollAreaWidgetContents_3);
        ComfirmPass->setObjectName(QStringLiteral("ComfirmPass"));
        ComfirmPass->setGeometry(QRect(100, 170, 200, 30));
        ComfirmPass->setEchoMode(QLineEdit::Password);
        NewPass = new QLineEdit(scrollAreaWidgetContents_3);
        NewPass->setObjectName(QStringLiteral("NewPass"));
        NewPass->setGeometry(QRect(100, 110, 200, 30));
        NewPass->setEchoMode(QLineEdit::Password);
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);
        ChangeInfo = new QPushButton(info);
        ChangeInfo->setObjectName(QStringLiteral("ChangeInfo"));
        ChangeInfo->setGeometry(QRect(0, 200, 300, 30));
        ChangeInfo->setFont(font);
        ChangeInfo->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        ChangePass = new QPushButton(info);
        ChangePass->setObjectName(QStringLiteral("ChangePass"));
        ChangePass->setGeometry(QRect(600, 200, 300, 30));
        ChangePass->setFont(font);
        Ok = new QPushButton(info);
        Ok->setObjectName(QStringLiteral("Ok"));
        Ok->setGeometry(QRect(300, 200, 300, 30));
        Ok->setFont(font);
        Ok->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        scrollArea_4 = new QScrollArea(info);
        scrollArea_4->setObjectName(QStringLiteral("scrollArea_4"));
        scrollArea_4->setGeometry(QRect(900, 0, 300, 300));
        scrollArea_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QStringLiteral("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 298, 298));
        label_14 = new QLabel(scrollAreaWidgetContents_4);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(0, 0, 300, 30));
        label_14->setFont(font);
        History5 = new QLabel(scrollAreaWidgetContents_4);
        History5->setObjectName(QStringLiteral("History5"));
        History5->setGeometry(QRect(0, 30, 300, 200));
        History5->setStyleSheet(QStringLiteral("alternate-background-color: rgb(255, 255, 255);"));
        scrollArea_4->setWidget(scrollAreaWidgetContents_4);

        retranslateUi(info);

        QMetaObject::connectSlotsByName(info);
    } // setupUi

    void retranslateUi(QDialog *info)
    {
        info->setWindowTitle(QApplication::translate("info", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("info", "USER", Q_NULLPTR));
        label_4->setText(QApplication::translate("info", "Name:", Q_NULLPTR));
        label_5->setText(QApplication::translate("info", "ID:", Q_NULLPTR));
        label_6->setText(QApplication::translate("info", "SSN:", Q_NULLPTR));
        label_7->setText(QApplication::translate("info", "Job:", Q_NULLPTR));
        label_8->setText(QApplication::translate("info", "Email:", Q_NULLPTR));
        IDUser->setText(QApplication::translate("info", "TextLabel", Q_NULLPTR));
        SSNUser->setText(QApplication::translate("info", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("info", "ACCOUNT", Q_NULLPTR));
        label_9->setText(QApplication::translate("info", "Name", Q_NULLPTR));
        label_10->setText(QApplication::translate("info", "ID:", Q_NULLPTR));
        label_11->setText(QApplication::translate("info", "Reader:", Q_NULLPTR));
        label_12->setText(QApplication::translate("info", "Admin", Q_NULLPTR));
        label_13->setText(QApplication::translate("info", "Blirarian:", Q_NULLPTR));
        AccountName->setText(QApplication::translate("info", "TextLabel", Q_NULLPTR));
        AccountID->setText(QApplication::translate("info", "TextLabel", Q_NULLPTR));
        IsReader->setText(QApplication::translate("info", "TextLabel", Q_NULLPTR));
        IsBlirarian->setText(QApplication::translate("info", "PushButton", Q_NULLPTR));
        IsAdmin->setText(QApplication::translate("info", "PushButton", Q_NULLPTR));
        label_3->setText(QApplication::translate("info", "PASSWORD", Q_NULLPTR));
        label_17->setText(QApplication::translate("info", "Password:", Q_NULLPTR));
        label_18->setText(QApplication::translate("info", "New password:", Q_NULLPTR));
        label_19->setText(QApplication::translate("info", "Comfirm password:", Q_NULLPTR));
        ChangeInfo->setText(QApplication::translate("info", "Change info", Q_NULLPTR));
        ChangePass->setText(QApplication::translate("info", "Change password", Q_NULLPTR));
        Ok->setText(QApplication::translate("info", "OK", Q_NULLPTR));
        label_14->setText(QApplication::translate("info", "HISTORY", Q_NULLPTR));
        History5->setText(QApplication::translate("info", "Huy", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class info: public Ui_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_H
