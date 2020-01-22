#include "guid_hppplugin.h"
#include "guid_hppconstants.h"

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
#include <QUuid>
#include <QKeyEvent>
#include <QApplication>
#include <QClipboard>

namespace GUID_HPP {
   namespace Internal {

      GUID_HPPPlugin::GUID_HPPPlugin()
      {
         // Create your members
      }

      GUID_HPPPlugin::~GUID_HPPPlugin()
      {
         // Unregister objects from the plugin manager's object pool
         // Delete members
      }

      bool GUID_HPPPlugin::initialize(const QStringList &arguments, QString *errorString)
      {
         // Register objects in the plugin manager's object pool
         // Load settings
         // Add actions to menus
         // Connect to other plugins' signals
         // In the initialize function, a plugin can be sure that the plugins it
         // depends on have initialized their members.

         Q_UNUSED(arguments)
         Q_UNUSED(errorString)

         auto action = new QAction(tr("GUID_HPP Action"), this);
         Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                                  Core::Context(Core::Constants::C_GLOBAL));
         cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Shift+A")));
         connect(action, &QAction::triggered, this, &GUID_HPPPlugin::triggerAction);

         Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
         menu->menu()->setTitle(tr("GUID_HPP"));
         menu->addAction(cmd);
         Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

         return true;
      }

      void GUID_HPPPlugin::extensionsInitialized()
      {
         // Retrieve objects from the plugin manager's object pool
         // In the extensionsInitialized function, a plugin can be sure that all
         // plugins that depend on it are completely initialized.
      }

      ExtensionSystem::IPlugin::ShutdownFlag GUID_HPPPlugin::aboutToShutdown()
      {
         // Save settings
         // Disconnect from signals that are not needed during shutdown
         // Hide UI (if you add UI that is not in the main window directly)
         return SynchronousShutdown;
      }

      void GUID_HPPPlugin::triggerAction()
      {
         auto ret = QUuid::createUuid().toString();
         ret = ret.replace('{', '_');
         ret = ret.replace('}', '_');
         ret = ret.replace('-', '_');

         auto clipboard = QApplication::clipboard();
         clipboard->setText( ret );

         QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_V, Qt::ControlModifier );
         QCoreApplication::postEvent( QApplication::focusWidget(), event);
      }
   } // namespace Internal
} // namespace GUID_HPP
