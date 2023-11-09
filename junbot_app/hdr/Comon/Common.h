#ifndef COMMON_H
#define COMMON_H

#include <QDebug>
#include <QMap>
#include <QString>

#define LOG_DBG qDebug().nospace().noquote() << "[DEBUG][" << __PRETTY_FUNCTION__ << "] "
#define LOG_INF qInfo().nospace().noquote() << "[INFO][" << __PRETTY_FUNCTION__ << "] "
#define LOG_WRN qWarning().nospace().noquote() << "[WARN][" << __PRETTY_FUNCTION__ << "] "
#define LOG_ERR qCritical().nospace().noquote() << "[ERROR][" << __PRETTY_FUNCTION__ << "] "

struct NodeLocation {
    float x;
    float y;
    float z;
};

extern const QMap<QString, NodeLocation> nodeMaps;

#endif // COMMON_H
