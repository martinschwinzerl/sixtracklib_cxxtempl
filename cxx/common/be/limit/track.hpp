#ifndef SIXTRACKLIB_COMMON_BE_LIMIT_TRACK_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_LIMIT_TRACK_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/limit/be_limit_traits.hpp"
#include "cxx/common/be/limit/be_limit_rect.hpp"
#include "cxx/common/be/limit/be_limit_ellipse.hpp"
#include "cxx/common/particles/track_particle_base.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< class PData, class BeData >
    typename track_result_t< PData, BeData, SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT >::type
    LimitRect_track( TrackParticleBase< PData >& SIXTRL_RESTRICT_REF particle,
        BeLimitRectBase< BeData > const& SIXTRL_RESTRICT_REF limit )
    {
        typedef sixtrack_cxx::TrackParticleBase< PData >    particle_t;
        typedef typename particle_t::real_t                 real_t;
        typedef typename particle_t::int_t                  state_t;

        state_t state = particle.state;
        if( state == ( state_t )0 ) return SIXTRL_CXX_NAMESPACE::TRACK_SUCCESS;

        state &= ( particle.x >= ( real_t )limit.min_x );
        state &= ( particle.x <= ( real_t )limit.max_x );
        state &= ( particle.y >= ( real_t )limit.min_y );
        state &= ( particle.y <= ( real_t )limit.max_y );

        particle.state = state;
        return SIXTRL_CXX_NAMESPACE::TRACK_SUCCESS;
    }

    template< class PData, class BeData >
    typename track_result_t< PData, BeData, SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE >::type
    LimitEllipse_track( TrackParticleBase< PData >& SIXTRL_RESTRICT_REF particle,
        BeLimitEllipseBase< BeData > const& SIXTRL_RESTRICT_REF limit )
    {
        typedef sixtrack_cxx::TrackParticleBase< PData >    particle_t;
        typedef typename particle_t::real_t                 real_t;
        typedef typename particle_t::int_t                  state_t;

        if( particle.state == ( state_t )0 )
                return SIXTRL_CXX_NAMESPACE::TRACK_SUCCESS;

        real_t temp = particle.x * particle.x * limit.b_squ;
        temp += particle.y * particle.y * limit.a_squ;

        particle.state &= ( temp <= ( real_t )limit.a_b_squ );
        return SIXTRL_CXX_NAMESPACE::TRACK_SUCCESS;
    }
}

#endif /* SIXTRACKLIB_COMMON_BE_LIMIT_TRACK_CXX_HPP__ */

/* end: */
