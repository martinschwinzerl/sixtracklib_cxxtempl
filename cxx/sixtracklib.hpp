#ifndef SIXTRACKLIB_CXX_SIXTRACKLIB_CXX_HPP__
#define SIXTRACKLIB_CXX_SIXTRACKLIB_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/ext_libs.h"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/internal/math_constant_traits.hpp"
#include "cxx/common/internal/phys_constant_traits.hpp"

#include "cxx/common/be/cavity/be_cavity_traits.hpp"
#include "cxx/common/be/cavity/be_cavity_data.hpp"
#include "cxx/common/be/cavity/be_cavity.h"
#include "cxx/common/be/cavity/be_cavity.hpp"
#include "cxx/common/be/cavity/track.hpp"

#include "cxx/common/be/drift/be_drift_traits.hpp"
#include "cxx/common/be/drift/drift_data.hpp"
#include "cxx/common/be/drift/be_drift.h"
#include "cxx/common/be/drift/be_drift.hpp"
#include "cxx/common/be/drift/track.hpp"

#include "cxx/common/be/multipole/be_multipole_traits.hpp"
#include "cxx/common/be/multipole/be_multipole_data.hpp"
#include "cxx/common/be/multipole/be_multipole.h"
#include "cxx/common/be/multipole/be_multipole.hpp"
#include "cxx/common/be/multipole/track.hpp"

#include "cxx/common/particles/particle_traits.hpp"
#include "cxx/common/particles/track_particle_data.hpp"
#include "cxx/common/particles/track_particle.hpp"
#include "cxx/common/particles/track_particle.h"

#include "cxx/common/track/obj_track_traits.hpp"

#if defined( SIXTRL_EXT_LIBRARY_BOOST ) && SIXTRL_EXT_LIBRARY_BOOST == 1

    #include "cxx/boost_multiprec/definitions.hpp"
    #include "cxx/boost_multiprec/math_constant_traits.hpp"
    #include "cxx/boost_multiprec/phys_constant_traits.hpp"
    #include "cxx/boost_multiprec/track_particle_data.hpp"
    #include "cxx/boost_multiprec/track_particle.hpp"

#endif /* SIXTRL_EXT_LIBRARY_BOOST */

#if defined( SIXTRL_EXT_LIBRARY_XSIMD ) && SIXTRL_EXT_LIBRARY_XSIMD == 1

    #include "cxx/xsimd/track_particle_data.hpp"
    #include "cxx/xsimd/track_particle.hpp"

#endif /* SIXTRL_EXT_LIBRARY_XSIMD */


#endif /* SIXTRACKLIB_CXX_SIXTRACKLIB_CXX_HPP__ */

/* end: cxx/sixtracklib.hpp */
