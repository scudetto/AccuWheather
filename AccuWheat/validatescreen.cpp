#include "validatescreen.h"

ValidateScreen::ValidateScreen(): m_isValid(-1)
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

void ValidateScreen::onValidOk()
{
    setIsValid(1);
    emit isValidChanged();
}

void ValidateScreen::onValidFailed()
{
    setIsValid(0);
    emit isValidChanged();
}
