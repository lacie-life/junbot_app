cmake_minimum_required(VERSION 3.5)

project(junbot_app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(JSON_BuildTests OFF CACHE INTERNAL "")

find_package(QT NAMES Qt5 COMPONENTS Core Quick Mqtt Widgets Charts REQUIRED)
find_package(Qt5 COMPONENTS Core Quick Mqtt Widgets Charts REQUIRED)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QT_INCLUDES} ${QtQml_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/hdr/)

include_directories("/usr/local/lib")

add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})

file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/hdr/*.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/hdr/Comon/*.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/hdr/Handler/*.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/hdr/Model/*.h
                  ${CMAKE_CURRENT_SOURCE_DIR}/hdr/View/*.h)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/src/Comon/*.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/src/Handler/*.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/src/Model/*.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/src/View/*.cpp)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/hdr
                     ${CMAKE_CURRENT_SOURCE_DIR}/hdr/Comon
                     ${CMAKE_CURRENT_SOURCE_DIR}/hdr/Handler
                     ${CMAKE_CURRENT_SOURCE_DIR}/hdr/Model
                     ${CMAKE_CURRENT_SOURCE_DIR}/hdr/View)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

qt5_add_resources(QT_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/qml.qrc)
qt5_add_resources(QT_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/res.qrc)
qt5_add_resources(QT_RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/config.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(junbot_app
            ${HEADERS}
            ${SOURCES}
            ${QT_RESOURCES}
    )
else()
    if(ANDROID)
        add_library(junbot_app SHARED
                ${HEADERS}
                ${SOURCES}
                ${QT_RESOURCES}
        )
    else()
        add_executable(junbot_app
                ${HEADERS}
                ${SOURCES}
                ${QT_RESOURCES}
                hdr/Comon/Common.h
                hdr/Model/RobotModel.h src/Model/RobotModel.cpp
        )
    endif()
endif()

target_compile_definitions(junbot_app
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(junbot_app
 # PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Mqtt ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES})
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Mqtt Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts)
# PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/share
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


