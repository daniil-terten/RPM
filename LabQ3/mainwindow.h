#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QTimer>
#include <QEventLoop>
#include <QUrl>
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <ui_mainwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QString token = "9f3ecd5d9f3ecd5d9f3ecd5d349f4e444e99f3e9f3ecd5dc1455d52725a8d57db27f2f3";

    QNetworkAccessManager networkManager;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getInfo()
    {
        /**
         * @brief Получение информации и пользователе
         */
        QNetworkRequest requestUser(QUrl("https://api.vk.com/method/users.get?user_ids=" + ui->idLineEdit->text() + "&fields=bdate,nickname,sex,photo_100&lang=3&access_token=" + token + "&v=5.103"));
        QNetworkReply *response = networkManager.get(requestUser);

        QEventLoop event;
        connect(response,SIGNAL(finished()),&event,SLOT(quit()));
        event.exec();
        disconnect(response,SIGNAL(finished()),&event,SLOT(quit()));

        QJsonArray itemArray = QJsonDocument::fromJson(response->readAll()).object()["response"].toArray();
        QJsonObject obj = itemArray.at(0).toObject();

        getPhoto(obj.value("photo_100").toString());
        ui->surnameLabel->setText("Фамилия: " + obj.value("last_name").toString());
        ui->nameLabel->setText("Имя: " + obj.value("first_name").toString());
        ui->nicknameLabel->setText("Никнейм: " + obj.value("nickname").toString());
        ui->birthdayLabel->setText("День рождения: " + obj.value("bdate").toString());

        int sex = obj.value("sex").toInt();
        if(sex==1)
            ui->sexLabel->setText("Пол: женский");
        else if(sex==2)
            ui->sexLabel->setText("Пол: мужской");
        else ui->sexLabel->setText("Пол: не указан");

        delete response;
   }

    void getFrinds(){
        /**
         * @brief Получение списка друзей пользователей
         */
        QNetworkRequest requestFriends(QUrl("https://api.vk.com/method/friends.get?user_id=" + ui->idLineEdit->text() + "&fields=&lang=3&access_token=" + token + "&v=5.103"));
        QNetworkReply *response = networkManager.get(requestFriends);

        QEventLoop event;
        connect(response,SIGNAL(finished()),&event,SLOT(quit()));
        event.exec();
        disconnect(response,SIGNAL(finished()),&event,SLOT(quit()));

        QJsonArray itemArray = QJsonDocument::fromJson(response->readAll())["response"].toObject().value("items").toArray();

        QJsonDocument doc;
        doc.setArray(itemArray);
        QString friends(doc.toJson());
        qDebug() << friends;
        friends.remove('\n').remove('[').remove(']');

        if(friends == "")
            ui->friendsLabel->setText("Друзей нет или они скрыты настройками приватности");
        else ui->friendsLabel->setText("Друзья: " + friends);

        delete response;
    }

    void getPhoto(QString photoURL){
        /**
         * @brief Загрузка изображения профиля пользователя
         * @param Ссылка на изображение профиля
         */
        QUrl getURL = QUrl(photoURL);
        QNetworkRequest requestPhoto(getURL);

        QNetworkReply *response = networkManager.get(requestPhoto);
        QEventLoop event;
        connect(response,SIGNAL(finished()),&event,SLOT(quit()));
        event.exec();\
        disconnect(response,SIGNAL(finished()),&event,SLOT(quit()));

        QFile picture("picture.jpg");
        picture.open(QIODevice::WriteOnly);
        picture.write(response->readAll());
        picture.close();
        QPixmap pixmap("picture.jpg");
        ui->pictureLabel->setPixmap(pixmap);
        delete response;
    }
};
#endif // MAINWINDOW_H
