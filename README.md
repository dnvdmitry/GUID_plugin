# GUID_plugin
Qt Creator plugin to insert C++ header guard name based on GUID.

For example :

#ifndef _f6198c0e_13c3_4641_af52_140d11befb93_
#define _f6198c0e_13c3_4641_af52_140d11befb93_
#endif


Output plugin name is "libGUID_HPP.so"

Installation
Plugin must be put at "Qt/Tools/QtCreator/lib/qtcreator/plugins" directory ( standard path in case of official installation package of Qt ).

When Qt Creator starts you can find a new menu at Tools->GUID_HPP. As a shortcut you can use Ctrl+Shift+A to generate GUID string inside the editor.

Tested withing Qt Creator 4.11.0
