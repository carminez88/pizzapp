find_package(Qt5 COMPONENTS Core Widgets Gui Sql Concurrent Network Xml PrintSupport REQUIRED)

include_directories( ${Qt5Core_INCLUDE_DIRS}         )
include_directories( ${Qt5Widgets_INCLUDE_DIRS}      )
include_directories( ${Qt5Gui_INCLUDE_DIRS}          )
include_directories( ${Qt5Sql_INCLUDE_DIRS}          )
include_directories( ${Qt5Network_INCLUDE_DIRS}      )
include_directories( ${Qt5Xml_INCLUDE_DIRS}          )
include_directories( ${Qt5PrintSupport_INCLUDE_DIRS} )
include_directories( ${Qt5Concurrent_INCLUDE_DIRS}   )

set(QT_LIBS Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Sql Qt5::Network Qt5::Xml Qt5::PrintSupport)
