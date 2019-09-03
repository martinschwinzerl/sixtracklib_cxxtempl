#ifndef SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_TRACK_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_TRACK_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/dipedge/be_dipedge.hpp"
#include "cxx/common/be/dipedge/be_dipedge_traits.hpp"
#include "cxx/common/particles/track_particle_base.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< class PData, class BeData >
    typename track_result_t< PData, BeData, SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE >::type
    DipoleEdge_track( TrackParticleBase< PData >& SIXTRL_RESTRICT_REF particle,
        BeDipoleEdgeBase< BeData > const& SIXTRL_RESTRICT_REF dipedge )
    {
        particle.px += particle.x * dipedge.r21;
        particle.py += particle.y * dipedge.r43;

        return SIXTRL_CXX_NAMESPACE::TRACK_SUCCESS;
    }
}

#endif /* SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_TRACK_CXX_HPP__ */

/* end: */
