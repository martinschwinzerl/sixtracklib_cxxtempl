#ifndef SIXTRACKLIB_COMMON_BE_XYSHIFT_TRACK_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_XYSHIFT_TRACK_CXX_HPP__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"
#include "sixtracklib/common/track/definitions.h"

#include "cxx/common/be/xyshift/be_xyshift.hpp"
#include "cxx/common/be/xyshift/be_xyshift_traits.hpp"
#include "cxx/common/particles/track_particle_base.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< class PData, class BeData >
    typename track_result_t< PData, BeData, SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_XYSHIFT >::type
    XYShift_track( TrackParticleBase< PData >& SIXTRL_RESTRICT_REF particle,
        BeXYShiftBase< BeData > const& SIXTRL_RESTRICT_REF xyshift )
    {
        particle.x -= xyshift.dx;
        particle.y -= xyshift.dy;

        return SIXTRL_CXX_NAMESPACE::TRACK_SUCCESS;
    }
}

#endif /* SIXTRACKLIB_COMMON_BE_XYSHIFT_TRACK_CXX_HPP__ */

/* end: */
