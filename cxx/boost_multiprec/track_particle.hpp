#ifndef SIXTRACKLIB_MULTIPREC_TRACK_PARTICLE_CXX_HPP__
#define SIXTRACKLIB_MULTIPREC_TRACK_PARTICLE_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"
#include "cxx/common/particles/track_particle_data.hpp"
#include "cxx/common/particles/track_particle_base.hpp"
#include "cxx/boost_multiprec/track_particle_data.hpp"

namespace sixtrack_cxx
{
    template< unsigned Digits10 >
    using MultPrecTrackParticle =
    sixtrack_cxx::TrackParticleBase<
        sixtrack_cxx::MultiPrecTrackParticleData< Digits10 > >;
}

#endif /* SIXTRACKLIB_MULTIPREC_TRACK_PARTICLE_CXX_HPP__ */
/* end: cxx/boost_multiprec/track_particle.hpp */
