#ifndef GUID_HPP_GLOBAL_H
#define GUID_HPP_GLOBAL_H

#include <QtGlobal>

#if defined(GUID_HPP_LIBRARY)
#  define GUID_HPPSHARED_EXPORT Q_DECL_EXPORT
#else
#  define GUID_HPPSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // GUID_HPP_GLOBAL_H
