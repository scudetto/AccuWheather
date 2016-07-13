#include "jsondatareader.h"
#include "chttpreader.h"

JsonDataReader::JsonDataReader()
{

}

void JsonDataReader::saveData()
{
    QByteArray byteArray;

    byteArray = CHttpReader::getInstance().getReply()->readAll();

    if(!byteArray.isEmpty())
    {
        m_document = QJsonDocument::fromJson(byteArray);
    }

}
