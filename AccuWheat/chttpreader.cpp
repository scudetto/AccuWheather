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
    m_manager->get(QNetworkRequest(QUrl("http://dataservice.accuweather.com/forecasts/v1/daily/1day/41?apikey=" + m_appKey)));
}

bool CHttpReader::isAppKeyValid()
{
    return m_bAppValid;
}

void CHttpReader::validateAppKey(QNetworkReply *reply)
{
    if(!(reply->error() == QNetworkReply::NoError))
    {
        m_bAppValid = false;
        emit appValidFailed();
    }
    else
    {
        m_bAppValid = true;
        emit appValidOk();
    }

}
