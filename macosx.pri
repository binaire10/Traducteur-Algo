CONFIG += staticlib
QMAKE_CXXFLAGS += -stdlib=libc++ -pthread
LIBS += -stdlib=libc++
QMAKE_MAC_SDK = macosx10.11
#♠QMAKE_MACOSX_DEPLOYMENT_TARGET =
