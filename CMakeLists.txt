cmake_minimum_required(VERSION 3.24)
project(gravity_defied_cpp C CXX)

unset(ENV{PKG_CONFIG_PATH})

set(BUILD_SHARED_LIBS FALSE)
set(SFML_BUILD_AUDIO FALSE)
set(SFML_BUILD_NETWORK FALSE)
add_subdirectory(SFML)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/utils/Time.cpp
    src/utils/EmbedFileStream.cpp
    src/main.cpp
    src/MathF16.cpp
    src/GameCanvas.cpp
    src/GamePhysics.cpp
    src/TimerOrMotoPartOrMenuElem.cpp
    src/class_10.cpp
    src/GameLevel.cpp
    src/LevelLoader.cpp
    src/Micro.cpp
    src/TextRender.cpp
    src/GameMenu.cpp
    src/SettingsStringRender.cpp
    src/MenuManager.cpp
    src/RecordManager.cpp
    src/Timer.cpp
    src/lcdui/CanvasImpl.cpp
    src/lcdui/Canvas.cpp
    src/lcdui/Graphics.cpp
    src/lcdui/Image.cpp
    src/lcdui/Font.cpp
    src/lcdui/Command.cpp
    src/lcdui/FontStorage.cpp
    src/rms/RecordEnumerationImpl.cpp
    src/rms/RecordStore.cpp
)

include(cmake/CMakeRC.cmake)

cmrc_add_resource_library(Assets
    NAMESPACE assets
    ALIAS Assets::Assets
    WHENCE assets
    assets/bluearm.png
    assets/helmet.png
    assets/sprites.png
    assets/blueleg.png
    assets/bluebody.png
    assets/logo.png
    assets/fender.png
    assets/levels.mrg
    assets/engine.png
    assets/splash.png
    assets/raster.png
    assets/icon.png
    assets/FontSansSerif.ttf
)

# Compile resources when building for Windows.
if(WIN32)
    enable_language(RC)
    list(APPEND SOURCES winres/res.rc)
endif()

add_executable(GravityDefied ${SOURCES})

target_compile_features(GravityDefied PRIVATE cxx_std_17)

target_link_libraries(GravityDefied SFML::Graphics SFML::Window)
target_link_libraries(GravityDefied Assets::Assets)


# Copy assets to the build directory
file(COPY assets/levels.mrg DESTINATION ${CMAKE_BINARY_DIR})
