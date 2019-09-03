#ifndef SIXTRACKLIB_COMMON_PARTICLES_TRACK_PATRICLE_CXX_HPP__
#define SIXTRACKLIB_COMMON_PARTICLES_TRACK_PATRICLE_CXX_HPP__

#include "sixtracklib/common/definitions.h"

#include "cxx/common/particles/track_particle_base.hpp"
#include "cxx/common/particles/track_particle.h"

namespace sixtrack_cxx
{
    typedef TrackParticleBase< ::NS(TrackParticle) > CTrackParticle;
    typedef TrackParticleBase< TrackParticleData< double, int64_t > > TrackParticle;

}

#endif /* SIXTRACKLIB_COMMON_PARTICLES_TRACK_PATRICLE_CXX_HPP__ */
/* end: cxx/common/particles/track_particle.hpp */
