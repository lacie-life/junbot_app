#ifndef COMMON_H
#define COMMON_H

#include <QDebug>

#define LOG_DBG qDebug().nospace().noquote() << "[DEBUG][" << __PRETTY_FUNCTION__ << "] "
#define LOG_INF qInfo().nospace().noquote() << "[INFO][" << __PRETTY_FUNCTION__ << "] "
#define LOG_WRN qWarning().nospace().noquote() << "[WARN][" << __PRETTY_FUNCTION__ << "] "
#define LOG_ERR qCritical().nospace().noquote() << "[ERROR][" << __PRETTY_FUNCTION__ << "] "

#endif // COMMON_H
