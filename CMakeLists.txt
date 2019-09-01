project( sixtracklib_cxxtmpl LANGUAGES C CXX )

cmake_minimum_required( VERSION 3.8 FATAL_ERROR )

message( STATUS "---- Project sixtracklib_cxxtmpl" )
message( STATUS "---- Inside main CMakeLists.txt" )

set( PATH_TO_LOCAL_SETTINGS_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Settings.cmake" )

include( ${PATH_TO_LOCAL_SETTINGS_FILE} OPTIONAL
         RESULT_VARIABLE STATUS_INCLUDE_LOCAL_SETTINGS_FILE )

if( STATUS_INCLUDE_LOCAL_SETTINGS_FILE )
    message( STATUS "---- Loaded settings file ${PATH_TO_LOCAL_SETTINGS_FILE}" )
endif()

find_package( SixTracklib REQUIRED )

if( SixTracklib_FOUND )
    message( STATUS "---- SixTracklib found" )
endif()

find_package( Clang REQUIRED )

if( Clang_FOUND )
    message( STATUS "---- Clang found : ${CLANG_CMAKE_DIR}" )
endif()

if( SIXTRL_CXX_ENABLE_XSIMD )
    find_package( xsimd REQUIRED )
    message( STATUS "---- xsimd found : ${xsimd_INCLUDE_DIRS}" )
endif()

if( SIXTRL_CXX_ENABLE_VC )
    find_package( Vc REQUIRED )
    message( STATUS "---- Vc found    : ${Vc_INCLUDE_DIR}" )
endif()

if( SIXTRL_CXX_ENABLE_BOOST )
    set( Boost_NO_SYSTEM_PATHS ON )
    find_package( Boost REQUIRED )
    message( STATUS "---- Boost found : ${Boost_INCLUDE_DIRS}" )
endif()

include_directories( ${CMAKE_SOURCE_DIR} )

add_subdirectory( cxx )
#add_subdirectory( generators )

add_subdirectory( examples )

# end: CMakeLists.txt
