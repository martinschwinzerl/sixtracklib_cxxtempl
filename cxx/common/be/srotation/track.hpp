#ifndef SIXTRACKLIB_COMMON_BE_SROTATION_TRACK_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_SROTATION_TRACK_CXX_HPP__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/track/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#include "cxx/common/internal/math_constant_traits.hpp"
#include "cxx/common/be/srotation/be_srotation.hpp"
#include "cxx/common/be/srotation/be_srotation_traits.hpp"
#include "cxx/common/particles/track_particle_base.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< class PData, class BeData >
    typename track_result_t< PData, BeData,
        SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION >::type
    SRotation_track( TrackParticleBase< PData >& SIXTRL_RESTRICT_REF particle,
        BeSRotationInterface< BeData > const& SIXTRL_RESTRICT_REF rot )
    {
        typedef sixtrack_cxx::TrackParticleBase< PData >     particle_t;
        typedef typename particle_t::real_t                  real_t;

        typedef sixtrack_cxx::BeSRotationInterface< BeData > srotation_t;
        typedef typename srotation_t::real_t                 be_real_t;

        be_real_t const minus_sin_z = -( rot.sin_z );
        real_t temp_x = particle.x  * rot.cos_z   + particle.y  * rot.sin_z;
        particle.y    = particle.x  * minus_sin_z + particle.y  * rot.cos_z;
        particle.x    = temp_x;

        temp_x        = particle.px * rot.cos_z   + particle.py * rot.sin_z;
        particle.py   = particle.px * minus_sin_z + particle.py * rot.cos_z;
        particle.px   = temp_x;

        return SIXTRL_CXX_NAMESPACE::TRACK_SUCCESS;
    }
}

#endif /* SIXTRACKLIB_COMMON_BE_SROTATION_TRACK_CXX_HPP__ */

/* end: */
