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
    Q_PROPERTY(int requestType READ requestType WRITE setRequestType NOTIFY requestTypeChanged)
public:
    ValidateScreen();

    QString keyId();
    Q_INVOKABLE void setKeyId(QString);

    Q_INVOKABLE int isValid();
    void setIsValid(int);

    Q_INVOKABLE void setLocation(QString loc);
    Q_INVOKABLE QString location();

    Q_INVOKABLE void setRequestType(int);
    Q_INVOKABLE int requestType();

signals:
    void keyIdChanged();
    void valid();
    void isValidChanged();
    void locationChanged();
    void requestTypeChanged();
    void validLocation();

public slots:
    void onValidOk(int reqType);
    void onValidFailed(int reqType);

private:
    QString m_keyId;
    int m_isValid;
    QString m_location;
    int m_requestType;
};

#endif // VALIDATESCREEN_H
