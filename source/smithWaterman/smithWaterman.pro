SOURCES   = \
            main.cpp \
    single.cpp \
    gui.cpp \
    filehandler.cpp
HEADERS   = \
    single.h \
    gui.h \
    filehandler.h

# openCl
INCLUDEPATH += /opt/AMDAPP/include/
LIBS += -L /opt/AMDAPP/lib/x86_64/ -lOpenCL

# install
target.path = $$[QT_INSTALL_EXAMPLES]/tutorials/addressbook/smithWaterman
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS smithWaterman.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/tutorials/addressbook/smithWaterman
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
maemo5: include($$QT_SOURCE_TREE/examples/maemo5pkgrules.pri)

symbian: warning(This example might not fully work on Symbian platform)
maemo5: warning(This example might not fully work on Maemo platform)
simulator: warning(This example might not fully work on Simulator platform)


