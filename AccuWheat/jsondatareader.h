#ifndef JSONDATAREADER_H
#define JSONDATAREADER_H

#include <QJsonDocument>

#include "datareader.h"

class JsonDataReader : public CDataReader
{
public:
    JsonDataReader();
    virtual void saveData();
    QJsonDocument getDocument() const;

private:
    QJsonDocument m_document;
};

#endif // JSONDATAREADER_H
