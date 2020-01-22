#ifndef GUID_HPP_H
#define GUID_HPP_H

#include "guid_hpp_global.h"

#include <extensionsystem/iplugin.h>

namespace GUID_HPP {
   namespace Internal {

      class GUID_HPPPlugin : public ExtensionSystem::IPlugin
      {
         Q_OBJECT
         Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "GUID_HPP.json")

      public:
         GUID_HPPPlugin();
         ~GUID_HPPPlugin() override;

         bool initialize(const QStringList &arguments, QString *errorString) override;
         void extensionsInitialized() override;
         ShutdownFlag aboutToShutdown() override;

      private:
         void triggerAction();
      };

   } // namespace Internal
} // namespace GUID_HPP

#endif // GUID_HPP_H
