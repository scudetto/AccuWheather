#include "wheatherview.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QVariantMap>

WheatherView::WheatherView()
{
    m_reader = new JsonDataReader;
    /*
    m_doc = m_reader->getDocument();

    QJsonObject obj = m_doc.object();
    QJsonObject obj1 = obj["Headline"].toObject();
    QJsonArray array = obj["DailyForecasts"].toArray();
    QJsonObject obj2 = array[0].toObject();

    QJsonObject obj3 = obj2["Day"].toObject();
    QJsonObject obj4 = obj3["Icon"].toObject();

    QJsonValue val = obj3.take("IconPhrase");
    qDebug()<<"array = "<<val.toString();

    QVariantMap map = obj4.toVariantMap();

    for(QVariantMap::const_iterator it=map.begin(); it!=map.end();++it)
    {
        qDebug()<<"key = "<<it.key()<<" val= "<<it.value().type();
    }
    */

}

WheatherView::~WheatherView()
{
    delete m_reader;
    m_reader = 0;
}

void WheatherView::printText()
{
    m_doc = m_reader->getDocument();

    QJsonArray array = m_doc.array();

    QJsonObject obj2 = array[0].toObject();

    m_locKey = obj2.take("Key").toString();
}

