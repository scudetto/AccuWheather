#include "wheatherview.h"
#include <QJsonArray>

WheatherView::WheatherView()
{
    m_reader = new JsonDataReader;
    m_doc = m_reader->getDocument();

    QJsonArray array = m_doc.array("DailyForecast");
    qDebug()<<m_d;
}

WheatherView::~WheatherView()
{
    delete m_reader;
    m_reader = 0;
}

