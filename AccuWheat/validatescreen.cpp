#include "validatescreen.h"
#include "wheatherview.h"

ValidateScreen::ValidateScreen(): m_isValid(-1), m_location()
{
    connect(&CHttpReader::getInstance(),SIGNAL(appValidOk(int)),this,SLOT(onValidOk(int)));
    connect(&CHttpReader::getInstance(),SIGNAL(appValidFailed(int)),this,SLOT(onValidFailed(int)));
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

void ValidateScreen::setRequestType(int type)
{
    m_requestType = type;
    emit requestTypeChanged();
}

int ValidateScreen::requestType()
{
    return m_requestType;
}

void ValidateScreen::onValidOk(int reqType)
{
    setRequestType(reqType);
    setIsValid(1);
    emit isValidChanged();

    if(m_requestType && m_isValid)
    {
        emit validLocation();
    }

}

void ValidateScreen::onValidFailed(int reqType)
{
    setRequestType(reqType);
    setIsValid(0);
    emit isValidChanged();
}
