#ifndef CHTTPREADER_H
#define CHTTPREADER_H


#include "datareader.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <string>


class CHttpReader : public QObject
{
    Q_OBJECT
public:
    static CHttpReader& getInstance();
    ~CHttpReader();

    QNetworkAccessManager& getNAM();
    void setAppKey(QString appKey);
    Q_INVOKABLE bool isAppKeyValid();
    QNetworkReply* getReply();
    void checkAppKey();
    void getLocation(QString loc);
    QString getLocationStr();

public slots:
    void validateAppKey(QNetworkReply*);

signals:
    void appValidOk(int);
    void appValidFailed(int);

private:
    CHttpReader(QObject* parent);
    CDataReader* m_data;
    QNetworkAccessManager* m_manager;
    static CHttpReader* m_instance;
    QString m_appKey;
    QNetworkReply* m_reply;
    bool m_bAppValid;
    int m_reqType;
    QString m_locationStr;
};

#endif // CHTTPREADER_H
