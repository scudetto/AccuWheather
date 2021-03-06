#include "chttpreader.h"

#include <iostream>
#include <string>

CHttpReader::CHttpReader(QObject *parent): QObject(parent), m_bAppValid(false)
{
    m_manager = new QNetworkAccessManager(this);
    connect(m_manager,SIGNAL(finished(QNetworkReply*)),this, SLOT(validateAppKey(QNetworkReply*)));
}

CHttpReader& CHttpReader::getInstance()
{
    if(!m_instance)
    {
        m_instance = new CHttpReader(0);
    }
    return *m_instance;
}

CHttpReader::~CHttpReader()
{
    delete m_instance;
    m_instance = 0;
    delete m_manager;
    m_manager = 0;
}

QNetworkAccessManager &CHttpReader::getNAM()
{
    return *m_manager;
}

void CHttpReader::setAppKey(QString appKey)
{
    m_appKey = appKey;
    checkAppKey();
}

bool CHttpReader::isAppKeyValid()
{
    return m_bAppValid;
}

QNetworkReply *CHttpReader::getReply()
{
    return m_reply;
}

void CHttpReader::checkAppKey()
{
    m_reqType = 0;
    m_manager->get(QNetworkRequest(QUrl("http://dataservice.accuweather.com/forecasts/v1/daily/1day/41?apikey=" + m_appKey)));
}

void CHttpReader::getLocation(QString loc)
{
    m_reqType = 1;
    m_locationStr = loc;
    m_manager->get(QNetworkRequest(QUrl("http://dataservice.accuweather.com/locations/v1/search?apikey=" + m_appKey + "&q=" + loc)));
}

QString CHttpReader::getLocationStr()
{
    return m_locationStr;
}

void CHttpReader::validateAppKey(QNetworkReply *reply)
{
    m_reply = reply;

    if(!(m_reply->error() == QNetworkReply::NoError))
    {
        m_bAppValid = false;
        emit appValidFailed(m_reqType);
    }
    else
    {
        m_bAppValid = true;
        emit appValidOk(m_reqType);
    }

}
