/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *ptn_ok;
    QLabel *le_name;
    QLabel *label_6;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLCDNumber *lcdTimer;
    QComboBox *co_s;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *xy;
    QLabel *label_9;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *tj;
    QCheckBox *bj;
    QCheckBox *jn;
    QCheckBox *sh;
    QCheckBox *km;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *gz;
    QCheckBox *gy;
    QCheckBox *wh;
    QCheckBox *sy;
    QCheckBox *hf;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *cd;
    QCheckBox *lz;
    QCheckBox *xn;
    QCheckBox *xa;
    QCheckBox *xm;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *heb;
    QCheckBox *sjz;
    QCheckBox *cs;
    QCheckBox *nn;
    QCheckBox *hhht;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QComboBox *co_p;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QComboBox *co_e;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1491, 985);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(1229, 6, 256, 192));
        ptn_ok = new QPushButton(centralWidget);
        ptn_ok->setObjectName(QString::fromUtf8("ptn_ok"));
        ptn_ok->setGeometry(QRect(240, 280, 80, 23));
        ptn_ok->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        le_name = new QLabel(centralWidget);
        le_name->setObjectName(QString::fromUtf8("le_name"));
        le_name->setGeometry(QRect(277, 88, 16, 17));
        le_name->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(7, 7, 336, 29));
        label_6->setStyleSheet(QString::fromUtf8("font: 28pt \"\345\215\216\346\226\207\351\232\266\344\271\246\";"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(40, 370, 395, 147));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 210, 33));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_6->addWidget(label);

        lcdTimer = new QLCDNumber(layoutWidget);
        lcdTimer->setObjectName(QString::fromUtf8("lcdTimer"));

        horizontalLayout_6->addWidget(lcdTimer);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 1);

        horizontalLayout_9->addLayout(horizontalLayout_6);

        co_s = new QComboBox(centralWidget);
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->addItem(QString());
        co_s->setObjectName(QString::fromUtf8("co_s"));
        co_s->setGeometry(QRect(94, 88, 54, 22));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 88, 80, 17));
        label_2->setContextMenuPolicy(Qt::PreventContextMenu);
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(224, 133, 112, 17));
        label_4->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(340, 60, 48, 17));
        label_8->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 172, 112, 17));
        label_7->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(149, 172, 68, 22));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(230, 108, 78, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        xy = new QLabel(layoutWidget1);
        xy->setObjectName(QString::fromUtf8("xy"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(xy->sizePolicy().hasHeightForWidth());
        xy->setSizePolicy(sizePolicy);
        xy->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout->addWidget(xy);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout->addWidget(label_9);

        horizontalLayout->setStretch(0, 3);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(400, 140, 317, 133));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tj = new QCheckBox(layoutWidget2);
        tj->setObjectName(QString::fromUtf8("tj"));

        horizontalLayout_2->addWidget(tj);

        bj = new QCheckBox(layoutWidget2);
        bj->setObjectName(QString::fromUtf8("bj"));

        horizontalLayout_2->addWidget(bj);

        jn = new QCheckBox(layoutWidget2);
        jn->setObjectName(QString::fromUtf8("jn"));

        horizontalLayout_2->addWidget(jn);

        sh = new QCheckBox(layoutWidget2);
        sh->setObjectName(QString::fromUtf8("sh"));

        horizontalLayout_2->addWidget(sh);

        km = new QCheckBox(layoutWidget2);
        km->setObjectName(QString::fromUtf8("km"));

        horizontalLayout_2->addWidget(km);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gz = new QCheckBox(layoutWidget2);
        gz->setObjectName(QString::fromUtf8("gz"));

        horizontalLayout_3->addWidget(gz);

        gy = new QCheckBox(layoutWidget2);
        gy->setObjectName(QString::fromUtf8("gy"));

        horizontalLayout_3->addWidget(gy);

        wh = new QCheckBox(layoutWidget2);
        wh->setObjectName(QString::fromUtf8("wh"));

        horizontalLayout_3->addWidget(wh);

        sy = new QCheckBox(layoutWidget2);
        sy->setObjectName(QString::fromUtf8("sy"));

        horizontalLayout_3->addWidget(sy);

        hf = new QCheckBox(layoutWidget2);
        hf->setObjectName(QString::fromUtf8("hf"));

        horizontalLayout_3->addWidget(hf);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        cd = new QCheckBox(layoutWidget2);
        cd->setObjectName(QString::fromUtf8("cd"));

        horizontalLayout_4->addWidget(cd);

        lz = new QCheckBox(layoutWidget2);
        lz->setObjectName(QString::fromUtf8("lz"));

        horizontalLayout_4->addWidget(lz);

        xn = new QCheckBox(layoutWidget2);
        xn->setObjectName(QString::fromUtf8("xn"));

        horizontalLayout_4->addWidget(xn);

        xa = new QCheckBox(layoutWidget2);
        xa->setObjectName(QString::fromUtf8("xa"));

        horizontalLayout_4->addWidget(xa);

        xm = new QCheckBox(layoutWidget2);
        xm->setObjectName(QString::fromUtf8("xm"));

        horizontalLayout_4->addWidget(xm);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        heb = new QCheckBox(layoutWidget2);
        heb->setObjectName(QString::fromUtf8("heb"));

        horizontalLayout_5->addWidget(heb);

        sjz = new QCheckBox(layoutWidget2);
        sjz->setObjectName(QString::fromUtf8("sjz"));

        horizontalLayout_5->addWidget(sjz);

        cs = new QCheckBox(layoutWidget2);
        cs->setObjectName(QString::fromUtf8("cs"));

        horizontalLayout_5->addWidget(cs);

        nn = new QCheckBox(layoutWidget2);
        nn->setObjectName(QString::fromUtf8("nn"));

        horizontalLayout_5->addWidget(nn);


        verticalLayout->addLayout(horizontalLayout_5);

        hhht = new QCheckBox(layoutWidget2);
        hhht->setObjectName(QString::fromUtf8("hhht"));

        verticalLayout->addWidget(hhht);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 144, 324, 31));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_7->addWidget(label_5);

        co_p = new QComboBox(layoutWidget3);
        co_p->addItem(QString());
        co_p->addItem(QString());
        co_p->addItem(QString());
        co_p->setObjectName(QString::fromUtf8("co_p"));

        horizontalLayout_7->addWidget(co_p);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 116, 234, 31));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_8->addWidget(label_3);

        co_e = new QComboBox(layoutWidget4);
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->addItem(QString());
        co_e->setObjectName(QString::fromUtf8("co_e"));

        horizontalLayout_8->addWidget(co_e);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1491, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        ptn_ok->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        le_name->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "\346\254\242\350\277\216\347\231\273\351\231\206\346\250\241\346\213\237\346\227\205\350\241\214\346\237\245\350\257\242\347\263\273\347\273\237", nullptr));
        label->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
        co_s->setItemText(0, QApplication::translate("MainWindow", "\345\214\227\344\272\254", nullptr));
        co_s->setItemText(1, QApplication::translate("MainWindow", "\344\270\212\346\265\267", nullptr));
        co_s->setItemText(2, QApplication::translate("MainWindow", "\345\271\277\345\267\236", nullptr));
        co_s->setItemText(3, QApplication::translate("MainWindow", "\345\223\210\345\260\224\346\273\250", nullptr));
        co_s->setItemText(4, QApplication::translate("MainWindow", "\346\262\210\351\230\263", nullptr));
        co_s->setItemText(5, QApplication::translate("MainWindow", "\345\244\251\346\264\245", nullptr));
        co_s->setItemText(6, QApplication::translate("MainWindow", "\345\205\260\345\267\236", nullptr));
        co_s->setItemText(7, QApplication::translate("MainWindow", "\346\210\220\351\203\275", nullptr));
        co_s->setItemText(8, QApplication::translate("MainWindow", "\350\264\265\351\230\263", nullptr));
        co_s->setItemText(9, QApplication::translate("MainWindow", "\346\255\246\346\261\211", nullptr));
        co_s->setItemText(10, QApplication::translate("MainWindow", "\346\265\216\345\215\227", nullptr));
        co_s->setItemText(11, QApplication::translate("MainWindow", "\350\245\277\345\256\201", nullptr));
        co_s->setItemText(12, QApplication::translate("MainWindow", "\346\230\206\346\230\216", nullptr));
        co_s->setItemText(13, QApplication::translate("MainWindow", "\345\220\210\350\202\245", nullptr));
        co_s->setItemText(14, QApplication::translate("MainWindow", "\350\245\277\345\256\211", nullptr));
        co_s->setItemText(15, QApplication::translate("MainWindow", "\347\237\263\345\256\266\345\272\204", nullptr));
        co_s->setItemText(16, QApplication::translate("MainWindow", "\345\221\274\345\222\214\346\265\251\347\211\271", nullptr));
        co_s->setItemText(17, QApplication::translate("MainWindow", "\345\216\246\351\227\250", nullptr));
        co_s->setItemText(18, QApplication::translate("MainWindow", "\351\225\277\346\262\231", nullptr));
        co_s->setItemText(19, QApplication::translate("MainWindow", "\345\215\227\345\256\201", nullptr));
        co_s->setItemText(20, QApplication::translate("MainWindow", "\351\225\277\346\230\245", nullptr));

        label_2->setText(QApplication::translate("MainWindow", "\345\207\272\345\217\221\345\237\216\345\270\202\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\347\273\217\345\201\234\345\237\216\345\270\202\357\274\232", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\357\274\232", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\351\231\220\345\256\232\346\227\266\351\227\264", nullptr));
        xy->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "\344\275\215\347\275\256 ", nullptr));
        tj->setText(QApplication::translate("MainWindow", "\345\244\251\346\264\245", nullptr));
        bj->setText(QApplication::translate("MainWindow", "\345\214\227\344\272\254", nullptr));
        jn->setText(QApplication::translate("MainWindow", "\346\265\216\345\215\227", nullptr));
        sh->setText(QApplication::translate("MainWindow", "\344\270\212\346\265\267", nullptr));
        km->setText(QApplication::translate("MainWindow", "\346\230\206\346\230\216", nullptr));
        gz->setText(QApplication::translate("MainWindow", "\345\271\277\345\267\236", nullptr));
        gy->setText(QApplication::translate("MainWindow", "\350\264\265\351\230\263", nullptr));
        wh->setText(QApplication::translate("MainWindow", "\346\255\246\346\261\211", nullptr));
        sy->setText(QApplication::translate("MainWindow", "\346\262\210\351\230\263", nullptr));
        hf->setText(QApplication::translate("MainWindow", "\345\220\210\350\202\245", nullptr));
        cd->setText(QApplication::translate("MainWindow", "\346\210\220\351\203\275", nullptr));
        lz->setText(QApplication::translate("MainWindow", "\345\205\260\345\267\236", nullptr));
        xn->setText(QApplication::translate("MainWindow", "\350\245\277\345\256\201", nullptr));
        xa->setText(QApplication::translate("MainWindow", "\350\245\277\345\256\211", nullptr));
        xm->setText(QApplication::translate("MainWindow", "\345\216\246\351\227\250", nullptr));
        heb->setText(QApplication::translate("MainWindow", "\345\223\210\345\260\224\346\273\250", nullptr));
        sjz->setText(QApplication::translate("MainWindow", "\347\237\263\345\256\266\345\272\204", nullptr));
        cs->setText(QApplication::translate("MainWindow", "\351\225\277\346\262\231", nullptr));
        nn->setText(QApplication::translate("MainWindow", "\345\215\227\345\256\201", nullptr));
        hhht->setText(QApplication::translate("MainWindow", "\345\221\274\345\222\214\346\265\251\347\211\271", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\271\346\241\210\357\274\232", nullptr));
        co_p->setItemText(0, QApplication::translate("MainWindow", "\346\234\200\345\260\221\350\212\261\350\264\271\347\255\226\347\225\245", nullptr));
        co_p->setItemText(1, QApplication::translate("MainWindow", "\346\234\200\347\237\255\346\227\266\351\227\264\347\255\226\347\225\245", nullptr));
        co_p->setItemText(2, QApplication::translate("MainWindow", "\351\231\220\345\256\232\346\227\266\351\227\264\346\234\200\345\260\221\350\212\261\350\264\271\347\255\226\347\225\245", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "\347\233\256\347\232\204\345\237\216\345\270\202\357\274\232", nullptr));
        co_e->setItemText(0, QApplication::translate("MainWindow", "\345\214\227\344\272\254", nullptr));
        co_e->setItemText(1, QApplication::translate("MainWindow", "\344\270\212\346\265\267", nullptr));
        co_e->setItemText(2, QApplication::translate("MainWindow", "\345\271\277\345\267\236", nullptr));
        co_e->setItemText(3, QApplication::translate("MainWindow", "\345\223\210\345\260\224\346\273\250", nullptr));
        co_e->setItemText(4, QApplication::translate("MainWindow", "\346\262\210\351\230\263", nullptr));
        co_e->setItemText(5, QApplication::translate("MainWindow", "\345\244\251\346\264\245", nullptr));
        co_e->setItemText(6, QApplication::translate("MainWindow", "\345\205\260\345\267\236", nullptr));
        co_e->setItemText(7, QApplication::translate("MainWindow", "\346\210\220\351\203\275", nullptr));
        co_e->setItemText(8, QApplication::translate("MainWindow", "\350\264\265\351\230\263", nullptr));
        co_e->setItemText(9, QApplication::translate("MainWindow", "\346\255\246\346\261\211", nullptr));
        co_e->setItemText(10, QApplication::translate("MainWindow", "\346\265\216\345\215\227", nullptr));
        co_e->setItemText(11, QApplication::translate("MainWindow", "\350\245\277\345\256\201", nullptr));
        co_e->setItemText(12, QApplication::translate("MainWindow", "\346\230\206\346\230\216", nullptr));
        co_e->setItemText(13, QApplication::translate("MainWindow", "\345\220\210\350\202\245", nullptr));
        co_e->setItemText(14, QApplication::translate("MainWindow", "\350\245\277\345\256\211", nullptr));
        co_e->setItemText(15, QApplication::translate("MainWindow", "\347\237\263\345\256\266\345\272\204", nullptr));
        co_e->setItemText(16, QApplication::translate("MainWindow", "\345\221\274\345\222\214\346\265\251\347\211\271", nullptr));
        co_e->setItemText(17, QApplication::translate("MainWindow", "\345\216\246\351\227\250", nullptr));
        co_e->setItemText(18, QApplication::translate("MainWindow", "\351\225\277\346\262\231", nullptr));
        co_e->setItemText(19, QApplication::translate("MainWindow", "\345\215\227\345\256\201", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
