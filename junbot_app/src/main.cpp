#include <QGuiApplication>
#include <QApplication>
#include <string>
#include <QSurfaceFormat>
#include "AppEngine.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QSurfaceFormat fmt;
    fmt.setVersion( 1, 4 );
    fmt.setProfile( QSurfaceFormat::CoreProfile );
    QSurfaceFormat::setDefaultFormat( fmt );

    app.setOrganizationName("kms_team");
    app.setOrganizationDomain("kms_team");

    AppEngine engine;
    engine.initEngine();
    engine.startApplication();

    return app.exec();
}
