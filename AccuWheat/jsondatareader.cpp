#include "jsondatareader.h"
#include "chttpreader.h"

JsonDataReader::JsonDataReader()
{
    saveData();
}

void JsonDataReader::saveData()
{
    QByteArray byteArray;

    byteArray = CHttpReader::getInstance().getReply()->readAll();

    if(!byteArray.isEmpty())
    {
        m_document = QJsonDocument::fromJson(byteArray);
    }
    qDebug()<<"save data"<<endl;

}

QJsonDocument JsonDataReader::getDocument()
{
    saveData();
    return m_document;
}

JsonDataReader::~JsonDataReader()
{

}
