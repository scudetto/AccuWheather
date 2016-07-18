#include "validatescreen.h"
#include "wheatherview.h"

ValidateScreen::ValidateScreen(): m_isValid(-1), m_location()
{
    connect(&CHttpReader::getInstance(),SIGNAL(appValidOk()),this,SLOT(onValidOk()));
    connect(&CHttpReader::getInstance(),SIGNAL(appValidFailed()),this,SLOT(onValidFailed()));
}

QString ValidateScreen::keyId()
{
    return m_keyId;
}

void ValidateScreen::setKeyId(QString str)
{
    m_keyId = str;
    CHttpReader::getInstance().setAppKey(m_keyId);
}

int ValidateScreen::isValid()
{
    return m_isValid;
}

void ValidateScreen::setIsValid(int valid)
{
    m_isValid = valid;
}

void ValidateScreen::setLocation(QString loc)
{
    m_location = loc;
    CHttpReader::getInstance().getLocation(loc);
    emit locationChanged();
}

QString ValidateScreen::location()
{
    return m_location;
}

void ValidateScreen::onValidOk()
{
    if(m_location.isEmpty())
    {
        setIsValid(1);
        emit isValidChanged();
    }
}

void ValidateScreen::onValidFailed()
{
    setIsValid(0);
    emit isValidChanged();
}
