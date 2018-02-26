/********************************************************************************
** Form generated from reading UI file 'admincomfirm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINCOMFIRM_H
#define UI_ADMINCOMFIRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_admincomfirm
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *admincomfirm)
    {
        if (admincomfirm->objectName().isEmpty())
            admincomfirm->setObjectName(QStringLiteral("admincomfirm"));
        admincomfirm->resize(300, 60);
        label = new QLabel(admincomfirm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 100, 30));
        lineEdit = new QLineEdit(admincomfirm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 0, 200, 30));
        pushButton = new QPushButton(admincomfirm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 30, 300, 30));

        retranslateUi(admincomfirm);

        QMetaObject::connectSlotsByName(admincomfirm);
    } // setupUi

    void retranslateUi(QDialog *admincomfirm)
    {
        admincomfirm->setWindowTitle(QApplication::translate("admincomfirm", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("admincomfirm", "Admin Password:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("admincomfirm", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class admincomfirm: public Ui_admincomfirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINCOMFIRM_H
