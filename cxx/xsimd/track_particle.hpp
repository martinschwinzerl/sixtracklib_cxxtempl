#ifndef SIXTRACKLIB_XSIMD_PARTICLES_TRACK_PARTICLE_CXX_HPP__
#define SIXTRACKLIB_XSIMD_PARTICLES_TRACK_PARTICLE_CXX_HPP__

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

#include <xsimd/xsimd.hpp>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"

#include "cxx/common/particles/track_particle.h"
#include "cxx/common/particles/track_particle_data.hpp"

#include "cxx/common/track/obj_track_traits.hpp"
#include "cxx/xsimd/track_particle_base.hpp"

namespace sixtrack_cxx
{
    template< unsigned N >
    using XsimdTrackParticle = sixtrack_cxx::TrackParticleBase<
        sixtrack_cxx::XsimdTrackParticleData< N > >;
}

#endif /* SIXTRACKLIB_XSIMD_PARTICLES_TRACK_PARTICLE_CXX_HPP__ */

/* end: cxx/xsimd/track_particle.hpp */
