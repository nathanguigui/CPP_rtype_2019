cmake_minimum_required(VERSION 3.1.0)

project(CPP_rtype_2019)

include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()
INCLUDE_DIRECTORIES(${CONAN_INCLUDE_DIRS})

include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)
INCLUDE_DIRECTORIES(${CONAN_INCLUDE_DIRS})

if ( MSVC )
    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
    set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})

    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}")
    #set(CMAKE_CXX_FLAGS_MINSIZEREL ${CMAKE_CXX_FLAGS_MINSIZEREL})

    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE  "${CMAKE_C_FLAGS_RELEASE}_INIT")
    set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})

    string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
    #set(CMAKE_CXX_FLAGS_RELWITHDEBINFO ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})

    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
    set(CMAKE_C_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})

    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL}")
    #set(CMAKE_C_FLAGS_MINSIZEREL ${CMAKE_C_FLAGS_MINSIZEREL})

    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")
    set(CMAKE_C_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})

    string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO}")
    #set(CMAKE_C_FLAGS_RELWITHDEBINFO ${CMAKE_C_FLAGS_RELWITHDEBINFO})
endif ( MSVC )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio")

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)
     

set(CLIENT_SRC
        client/src/main.cpp
        client/src/core/WindowManager/WindowManager.cpp
        client/src/core/WindowManager/WindowManager.hpp
        client/src/core/Event/Event.cpp client/src/core/Event/Event.hpp
        client/src/core/SplashScreen/SplashScreen.cpp
        client/src/core/SplashScreen/SplashScreen.hpp
        client/src/core/Logger/Logger.cpp
        client/src/core/Logger/Logger.h
        client/src/core/WindowState/WindowState.cpp
        client/src/core/WindowState/WindowState.hpp
        client/src/core/Settings/Settings.cpp
        client/src/core/Settings/Settings.hpp
        client/src/core/EventableObject/EventableObject.hpp
        client/src/core/Menus/MainMenu/MainMenu.cpp
        client/src/core/Menus/MainMenu/MainMenu.hpp
        client/src/core/Scene/Scene.cpp
        client/src/core/Scene/Scene.hpp
        client/src/core/SceneObject/SceneObject.hpp
        client/src/core/Gui/Tools.cpp
        client/src/core/Gui/Tools.hpp
        client/src/core/EventableSceneObject/EventableSceneObject.cpp
        client/src/core/EventableSceneObject/EventableSceneObject.hpp
        client/src/core/SceneManager/SceneManager.cpp
        client/src/core/SceneManager/SceneManager.hpp
        client/src/core/Player/Player.cpp
        client/src/core/Player/Player.hpp
        client/src/core/CoreObject/CoreObject.hpp
        client/src/core/Power/Power.cpp
        client/src/core/Power/Power.hpp
        client/src/core/PowerUp/PowerUp.hpp
        client/src/game/PowerUp/DefaultPowerUp/DefaultPowerUp.cpp
        client/src/game/PowerUp/DefaultPowerUp/DefaultPowerUp.hpp
        client/src/core/PowerManager/PowerManager.cpp
        client/src/core/PowerManager/PowerManager.hpp
        client/src/core/Power/PowerEnum.hpp
        client/src/core/Scene/IScene.hpp
        client/src/game/Bullets/BulletsShoot/SimpleBullet/SimpleBullet.cpp
        client/src/game/Bullets/BulletsShoot/SimpleBullet/SimpleBullet.h
        client/src/game/Bullets/BulletTouch/SimpleKill/SimpleKill.cpp
        client/src/game/Bullets/BulletTouch/SimpleKill/SimpleKill.h
        client/src/core/PowerManager/PowerManager.hpp
        client/src/core/Power/PowerEnum.hpp
        client/src/core/Scene/IScene.hpp
        client/src/core/Loading/Loading.cpp
        client/src/core/Loading/Loading.hpp)


include_directories("${PROJECT_BINARY_DIR}")

add_executable(rtype_client ${CLIENT_SRC})
add_custom_target(copy-files ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/client/src/assets/
        ${CMAKE_BINARY_DIR}/assets/
)
target_link_libraries(rtype_client ${CONAN_LIBS})


set(SERVER_SRC
        server/src/main.cpp server/src/Server_TCP.cpp server/src/connection_manager.cpp server/src/connection_handler_TCP.cpp)
set (SERVER_HEADERS
        server/src/connection_handler_TCP.hpp server/src/Server_TCP.hpp)
add_executable(rtype_server ${SERVER_SRC})
target_link_libraries(rtype_server ${CONAN_LIBS})