#pragma once

#include "menuhide_global.h"

#include <extensionsystem/iplugin.h>

namespace menuhide {
namespace Internal {

class menuhidePlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "menuhide.json")

public:
    menuhidePlugin();
    ~menuhidePlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void triggerAction();
};

} // namespace Internal
} // namespace menuhide
