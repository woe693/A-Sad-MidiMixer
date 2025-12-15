cmake_minimum_required(VERSION 3.16)

project(MidiMixer VERSION 0.1 LANGUAGES CXX)

# Pick a C++ standard explicitly (Qt 6 is happy with 17/20; 17 is a safe default)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- RtMidi as an internal library target ----
add_library(rtmidi STATIC
    external/rtmidi/RtMidi.cpp
)

target_include_directories(rtmidi PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/external/rtmidi
)

# Select RtMidi backend per platform
if (WIN32)
    target_compile_definitions(rtmidi PRIVATE __WINDOWS_MM__)
    target_link_libraries(rtmidi PRIVATE winmm)
elseif(UNIX AND NOT APPLE)
    find_package(ALSA REQUIRED)
    target_compile_definitions(rtmidi PRIVATE __LINUX_ALSA__)
    target_link_libraries(rtmidi PRIVATE ALSA::ALSA)
endif()

# ---- Qt Quick app ----
find_package(Qt6 REQUIRED COMPONENTS Quick)
qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appMidiMixer
    main.cpp
)

qt_add_qml_module(appMidiMixer
    URI MidiMixer
    QML_FILES
        Main.qml
        QML_FILES
        SOURCES
        SOURCES
        QML_FILES
        SOURCES
        QML_FILES
        QML_FILES
        QML_FILES Mixers/NanoKontrol2/NanoKontrol2.qml
        QML_FILES Mixers/NanoKontrol2/VolumeFader.qml
        SOURCES Mixers/NanoKontrol2/nanokontrol2.h Mixers/NanoKontrol2/nanokontrol2.cpp
        SOURCES
        SOURCES Commands/Command.h Commands/Command.cpp
        RESOURCES Mixers/NanoKontrol2/ButtonMap.json
)

set_target_properties(appMidiMixer PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMidiMixer
    PRIVATE
        Qt6::Quick
        rtmidi
)

include(GNUInstallDirs)
install(TARGETS appMidiMixer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
