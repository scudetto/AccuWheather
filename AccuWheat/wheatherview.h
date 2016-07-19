#ifndef WHEATHERVIEW_H
#define WHEATHERVIEW_H

#include <QQuickItem>
#include "jsondatareader.h"

class WheatherView : public QQuickItem
{
    Q_OBJECT
public:
    WheatherView();
    ~WheatherView();

    Q_INVOKABLE void printText();

signals:

public slots:

private:
    JsonDataReader* m_reader;
    QJsonDocument m_doc;
    QString m_locKey;
};

#endif // WHEATHERVIEW_H
