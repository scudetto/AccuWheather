#ifndef WHEATHERVIEW_H
#define WHEATHERVIEW_H

#include <QQuickItem>
#include "jsondatareader.h"

class WheatherView : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString locKey READ locKey WRITE setLocKey NOTIFY locKeyChanged)
    Q_PROPERTY(QString locStr READ locStr WRITE setLocStr NOTIFY locStrChanged)
public:
    WheatherView();
    ~WheatherView();

    Q_INVOKABLE void printText();
    QString locKey();
    void setLocKey(QString key);

    void setLocStr(QString str);
    Q_INVOKABLE QString locStr();

signals:
    void locKeyChanged();
    void locStrChanged();

public slots:

private:
    JsonDataReader* m_reader;
    QJsonDocument m_doc;
    QString m_locKey;
    QString m_locStr;
};

#endif // WHEATHERVIEW_H
