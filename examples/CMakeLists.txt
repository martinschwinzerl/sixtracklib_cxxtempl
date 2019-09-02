if( SIXTRL_CXX_ENABLE_XSIMD AND xsimd_FOUND )
    include_directories( ${xsimd_INCLUDE_DIRS} )
endif()

if( SIXTRL_CXX_ENABLE_BOOST AND Boost_FOUND )
    include_directories( ${Boost_INCLUDE_DIRS} )
endif()

add_executable( test_particles test_particles.cpp )
target_link_libraries( test_particles SixTracklib::sixtrack )
set_property( TARGET test_particles PROPERTY CXX_STANDARD 11 )
set_property( TARGET test_particles PROPERTY CXX_STANDARD_REQUIRED ON )
set_property( TARGET test_particles PROPERTY COMPILE_OPTIONS -Wall  )

add_executable( test_xsimd test_xsimd.cpp )
target_link_libraries( test_xsimd SixTracklib::sixtrack )
set_target_properties( test_xsimd PROPERTIES CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON COMPILE_OPTIONS -Wall -Werror -pedantic )
target_compile_options( test_xsimd PRIVATE "-march=haswell" )


add_executable( test_track_drift test_track_drift.cpp )
target_link_libraries( test_track_drift SixTracklib::sixtrack )
set_target_properties( test_track_drift PROPERTIES CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON COMPILE_OPTIONS -Wall -Werror -pedantic )
target_compile_options( test_track_drift PRIVATE "-march=haswell" )
