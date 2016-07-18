#ifndef VALIDATESCREEN_H
#define VALIDATESCREEN_H

#include <QQuickItem>

#include "chttpreader.h"

class ValidateScreen : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString keyId READ keyId WRITE setKeyId NOTIFY keyIdChanged)
    Q_PROPERTY(int isValid READ isValid WRITE setIsValid NOTIFY isValidChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY locationChanged)
public:
    ValidateScreen();

    QString keyId();
    Q_INVOKABLE void setKeyId(QString);

    Q_INVOKABLE int isValid();
    void setIsValid(int);

    Q_INVOKABLE void setLocation(QString loc);
    Q_INVOKABLE QString location();

signals:
    void keyIdChanged();
    void valid();
    void isValidChanged();
    void locationChanged();

public slots:
    void onValidOk();
    void onValidFailed();

private:
    QString m_keyId;
    int m_isValid;
    QString m_location;
};

#endif // VALIDATESCREEN_H
