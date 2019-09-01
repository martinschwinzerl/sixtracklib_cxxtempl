include_directories( ${SixTracklib_INCLUDE_DIRS} )

# Create header with external dependencies

if( SIXTRL_CXX_ENABLE_XSIMD AND xsimd_FOUND )
    set( SIXTRL_CXX_EXT_XSIMD_ENABLED "1" )
else()
    set( SIXTRL_CXX_EXT_XSIMD_ENABLED "0" )
endif()

if( SIXTRL_CXX_ENABLE_VC AND Vc_FOUND )
    set( SIXTRL_CXX_EXT_VC_ENABLED "1" )
else()
    set( SIXTRL_CXX_EXT_VC_ENABLED "0" )
endif()

if( SIXTRL_CXX_ENABLE_BOOST AND Boost_FOUND )
    set( SIXTRL_CXX_EXT_BOOST_ENABLED "1" )
else()
    set( SIXTRL_CXX_EXT_BOOST_ENABLED "0" )
endif()

configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/ext_libs.h.template"
                "${CMAKE_CURRENT_SOURCE_DIR}/ext_libs.h" @ONLY )

# ------------------------------------------------------------------------------

add_subdirectory( common )

if( SIXTRL_CXX_ENABLE_BOOST AND Boost_FOUND )
    add_subdirectory( boost_multiprec )
endif()
