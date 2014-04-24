#include "widget.h"
#include "ui_widget.h"
#include <QtNetwork>
#include <QTextCodec>




Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);  //�½�QNetworkAccessManager����
    connect(manager,SIGNAL(finished(QNetworkReply*)),  //�����źźͲ�
                this,SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://www.yafeilinux.com"))); //��������


}
void Widget::replyFinished(QNetworkReply *reply)  //���ظ�������
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    //ʹ��utf8���룬�����ſ�����ʾ����
    QString all = codec->toUnicode(reply->readAll());
    ui->textBrowser->setText(all);
    reply->deleteLater();   //���Ҫ�ͷ�reply����
}

Widget::~Widget()
{
    delete ui;
}
