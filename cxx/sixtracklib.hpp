#ifndef SIXTRACKLIB_CXX_SIXTRACKLIB_CXX_HPP__
#define SIXTRACKLIB_CXX_SIXTRACKLIB_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/ext_libs.h"
#include "cxx/common/internal/obj_store_traits.hpp"

#include "cxx/common/particles/track_particle_data.hpp"
#include "cxx/common/particles/track_particle.hpp"
#include "cxx/common/particles/track_particle.h"

#include "cxx/common/track/obj_track_traits.hpp"

#if defined( SIXTRL_EXT_LIBRARY_BOOST ) && SIXTRL_EXT_LIBRARY_BOOST == 1

    #include "cxx/boost_multiprec/track_particle_data.hpp"
    #include "cxx/boost_multiprec/track_particle.hpp"

#endif /* SIXTRL_EXT_LIBRARY_BOOST */

#if defined( SIXTRL_EXT_LIBRARY_XSIMD ) && SIXTRL_EXT_LIBRARY_XSIMD == 1

    #include "cxx/xsimd/track_particle_data.hpp"
    #include "cxx/xsimd/track_particle.hpp"

#endif /* SIXTRL_EXT_LIBRARY_XSIMD */


#endif /* SIXTRACKLIB_CXX_SIXTRACKLIB_CXX_HPP__ */

/* end: cxx/sixtracklib.hpp */
