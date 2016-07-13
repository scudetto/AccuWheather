#include "validatescreen.h"

ValidateScreen::ValidateScreen(): m_isValid(false)
{
    connect(&CHttpReader::getInstance(),SIGNAL(appValidOk()),this,SLOT(onValidOk()));
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

bool ValidateScreen::isValid()
{
    return m_isValid;
}

void ValidateScreen::setIsValid(bool valid)
{
    m_isValid = valid;
}

void ValidateScreen::onValidOk()
{
    setIsValid(true);
    emit isValidChanged();
}
