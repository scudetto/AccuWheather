#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <iostream>
#include <string>
#include <QtQml>

#include "chttpreader.h"
#include "validatescreen.h"
#include "wheatherview.h"

CHttpReader* CHttpReader::m_instance = 0;

int main(int argc, char *argv[])
{
    qmlRegisterType<ValidateScreen>("Valid",1,0,"ValidScreen");
    qmlRegisterType<WheatherView>("Valid",1,0,"WheatherView");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
