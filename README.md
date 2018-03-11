# qt-creator-hide-menu

This plugin adds the ability to hide/show the menu bar of the main window of Qt Creator.

## Build instructions

1. `cd $SOME_DIR`
1. `git clone https://github.com/qt-creator/qt-creator.git`
1. `cd qt-creator`
1. check out the branch or tag that corresponds to your Qt Creator version. For example: `git checkout v4.5.0` if you are
running Qt Creator 4.5.0
1. `qmake`   # you only need to run qmake in the qt-creator source tree, full build is not required
1. `cd $SOME_DIR`
1. `git clone git@github.com:ileonte/qt-creator-hide-menu.git`
1. `cd qt-creator-hide-menu`
1. `qmake IDE_SOURCE_TREE=${SOME_DIR}/qt-creator`
1. `make`

The plugin is automatically placed in `${HOME}/.local/share/data/QtProject/qtcreator/plugins/${QTCREATOR_VERSION}` and it 
should be automatically picked-up by Qt Creator (you will need to close existing instances and restart Qt Creator though).

When the plugin is activated a new option (`Hide main menu`) will be added to the `Window` menu. The default keyboard shortcut for activating this option is `Ctrl+Meta+Alt+M`. You can change it via the configuration dialog
(`Tools` -> `Options` -> `Environment` -> `Keyboard` - search for `menuhide`).
