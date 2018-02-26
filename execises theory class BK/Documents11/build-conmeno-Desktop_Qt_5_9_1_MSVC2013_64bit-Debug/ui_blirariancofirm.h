/********************************************************************************
** Form generated from reading UI file 'blirariancofirm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLIRARIANCOFIRM_H
#define UI_BLIRARIANCOFIRM_H

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

class Ui_blirariancofirm
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *blirariancofirm)
    {
        if (blirariancofirm->objectName().isEmpty())
            blirariancofirm->setObjectName(QStringLiteral("blirariancofirm"));
        blirariancofirm->resize(300, 60);
        label = new QLabel(blirariancofirm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 100, 30));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Calligraphy"));
        label->setFont(font);
        lineEdit = new QLineEdit(blirariancofirm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 0, 200, 30));
        pushButton = new QPushButton(blirariancofirm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 30, 300, 30));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));

        retranslateUi(blirariancofirm);

        QMetaObject::connectSlotsByName(blirariancofirm);
    } // setupUi

    void retranslateUi(QDialog *blirariancofirm)
    {
        blirariancofirm->setWindowTitle(QApplication::translate("blirariancofirm", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("blirariancofirm", "Blirarian Code", Q_NULLPTR));
        pushButton->setText(QApplication::translate("blirariancofirm", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class blirariancofirm: public Ui_blirariancofirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLIRARIANCOFIRM_H
