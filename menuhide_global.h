#pragma once

#include <QtGlobal>

#if defined(MENUHIDE_LIBRARY)
#  define MENUHIDESHARED_EXPORT Q_DECL_EXPORT
#else
#  define MENUHIDESHARED_EXPORT Q_DECL_IMPORT
#endif
