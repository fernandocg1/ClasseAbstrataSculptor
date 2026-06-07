cmake_minimum_required(VERSION 3.16)

project(ClasseAbstrataSculptor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ClasseAbstrataSculptor main.cpp
    FiguraGeometrica.h FiguraGeometrica.cpp
    Sculptor.h Sculptor.cpp
    putBox.h putBox.cpp
    cutBox.h cutBox.cpp
    putSphere.h putSphere.cpp
    cutSphere.h cutSphere.cpp
    putVoxel.h putVoxel.cpp
    cutVoxel.h cutVoxel.cpp
    LeitorArquivos.h LeitorArquivos.cpp
    putEllipsoid.h putEllipsoid.cpp
    cutEllipsoid.h cutEllipsoid.cpp
    Voxel.h)

include(GNUInstallDirs)
install(TARGETS ClasseAbstrataSculptor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
