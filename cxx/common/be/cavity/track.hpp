#ifndef SIXTRACKLIB_COMMON_BE_CAVITY_TRACK_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_CAVITY_TRACK_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/cavity/cavity.hpp"
#include "cxx/common/be/cavity/be_cavity_traits.hpp"
#include "cxx/common/internal/math_constant_traits.hpp"
#include "cxx/common/internal/phys_constant_traits.hpp"
#include "cxx/common/particles/track_particle_base.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< class PData, class BeData >
    typename track_result_t< PData, BeData,
            SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY >::type
    Cavity_track( TrackParticleBase< PData >& SIXTRL_RESTRICT_REF particle,
        BeCavityBase< BeData > const& SIXTRL_RESTRICT_REF cavity )
    {
        typedef TrackParticleBase< PData >  particle_t;
        typedef typename particle_t::real_t real_t;

        real_t const K_FACTOR = ( MathConstants< real_t >::Two() *
            MathConstants< real_t >::Pi() ) / PhysConstants< real_t >::C0();

        real_t const tau   = particle.zeta / ( particle.beta0 * particle.rvv );
        real_t const phase = MathConstants< real_t >::Deg2Rad() * cavity.lag -
                             K_FACTOR * tau * cavity.frequency;

        particle.addEnergy( particle.q0  * particle.charge_ratio *
                sin( phase ) * cavity.voltage );

        return SIXTRL_CXX_NAMESPACE::TRACK_SUCCESS;
    }
}

#endif /* SIXTRACKLIB_COMMON_BE_CAVITY_TRACK_CXX_HPP__ */

/* end: */
