#ifndef COMMON_H
#define COMMON_H

#include <QDebug>

#define LOG_DBG qDebug().nospace() << "[DEBUG][" << __PRETTY_FUNCTION__ << "] "
#define LOG_INF qInfo().nospace() << "[INFO][" << __PRETTY_FUNCTION__ << "] "
#define LOG_WRN qWarning().nospace() << "[WARN][" << __PRETTY_FUNCTION__ << "] "
#define LOG_ERR qCritical().nospace() << "[ERROR][" << __PRETTY_FUNCTION__ << "] "

#endif // COMMON_H
