#ifndef VALIDATESCREEN_H
#define VALIDATESCREEN_H

#include <QQuickItem>

#include "chttpreader.h"

class ValidateScreen : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString keyId READ keyId WRITE setKeyId NOTIFY keyIdChanged)
    Q_PROPERTY(bool isValid READ isValid WRITE setIsValid NOTIFY isValidChanged)
public:
    ValidateScreen();

    QString keyId();
    Q_INVOKABLE void setKeyId(QString);

    Q_INVOKABLE bool isValid();
    void setIsValid(bool);

signals:
    void keyIdChanged();
    void valid();
    void isValidChanged();

public slots:
    void onValidOk();

private:
    QString m_keyId;
    bool m_isValid;
};

#endif // VALIDATESCREEN_H
