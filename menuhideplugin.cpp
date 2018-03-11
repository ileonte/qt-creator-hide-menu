#include "menuhideplugin.h"
#include "menuhideconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>

namespace menuhide {
namespace Internal {

menuhidePlugin::menuhidePlugin()
{
}

menuhidePlugin::~menuhidePlugin()
{
}

bool menuhidePlugin::initialize(const QStringList &arguments, QString *errorString)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    auto action = new QAction(tr("Hide main menu"), this);
    action->setCheckable(true);
    action->setChecked(false);
    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                             Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+M")));
    connect(action, &QAction::triggered, this, &menuhidePlugin::triggerAction);

    Core::ActionManager::actionContainer(Core::Constants::M_WINDOW)->addAction(cmd);

    return true;
}

void menuhidePlugin::extensionsInitialized()
{
}

ExtensionSystem::IPlugin::ShutdownFlag menuhidePlugin::aboutToShutdown()
{
    return SynchronousShutdown;
}

void menuhidePlugin::triggerAction()
{
    Core::ActionContainer *menubar_ac = Core::ActionManager::actionContainer(Core::Constants::MENU_BAR);
    if (menubar_ac) {
        QMenuBar *mb = menubar_ac->menuBar();
        if (mb) {
            mb->setVisible(!mb->isVisible());
        } else {
            QMessageBox::critical(Core::ICore::mainWindow(),
                                  tr("Hide main menu"),
                                  tr("Failed to get QMenuBar from ActionContainer."));
        }
    } else {
        QMessageBox::critical(Core::ICore::mainWindow(),
                              tr("Hide main menu"),
                              tr("Failed to get menubar ActionContainer."));
    }
}

} // namespace Internal
} // namespace menuhide
