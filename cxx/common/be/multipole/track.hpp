#ifndef SIXTRACKLIB_COMMON_BE_MULTIPOLE_TRACK_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_MULTIPOLE_TRACK_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/internal/math_constant_traits.hpp"
#include "cxx/common/be/multipole/multipole.hpp"
#include "cxx/common/be/multipole/be_multipole_traits.hpp"
#include "cxx/common/particles/track_particle_base.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< class PData, class BeData >
    typename track_result_t< PData, BeData, SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE >::type
    Multipole_track( TrackParticleBase< PData >& SIXTRL_RESTRICT_REF particle,
        BeMultipoleBase< BeData > const& SIXTRL_RESTRICT_REF mp )
    {
        namespace st = SIXTRL_CXX_NAMESPACE;
        namespace stcxx = sixtrack_cxx;

        typedef BeMultipoleBase< BeData >           be_multipole_t;
        typedef typename be_multipole_t::real_t     mp_real_t;
        typedef typename be_multipole_t::order_t    mp_order_t;

        typedef TrackParticleBase< PData >          particle_t;
        typedef typename particle_t::real_t         real_t;

        mp_order_t index_x = mp.getOrder() * ( mp_order_t )2u;
        mp_order_t index_y = index_x + ( mp_order_t )1u;

        real_t dpx = mp[ index_x ];
        real_t dpy = mp[ index_y ];

        while( index_x >= ( mp_order_t )2 )
        {
            real_t const zre = dpx * particle.x - dpy * particle.y;
            real_t const zim = dpx * particle.y + dpy * particle.x;

            index_x -= 2;
            index_y -= 2;

            dpx = mp[ index_x ] + zre;
            dpy = mp[ index_y ] + zim;
        }

        dpx = -particle.chi * dpx;
        dpy =  particle.chi * dpy;

        if( ( mp.hxl != sixtrack_cxx::MathConstants< real_t >::Zero() ) ||
            ( mp.hyl != sixtrack_cxx::MathConstants< real_t >::Zero() ) )
        {
            real_t const hxlx = particle.x * mp.hxl;
            real_t const hyly = particle.y * mp.hyl;

            particle.zeta += particle.chi * ( hyly - hxlx );

            real_t const delta_plus_1 = particle.delta +
                sixtrack_cxx::MathConstants< real_t >::One();

            dpx += delta_plus_1 * hxlx;
            dpy -= delta_plus_1 * hyly;

            if( mp.length > sixtrack_cxx::MathConstants< mp_real_t >::Zero() )
            {
                dpx -= particle.chi * mp[ 0 ] * hxlx / mp.length;
                dpy += particle.chi * mp[ 1 ] * hyly / mp.length;
            }
        }

        particle.px += dpx;
        particle.py += dpy;

        return st::TRACK_SUCCESS;
    }
}

#endif /* SIXTRACKLIB_COMMON_BE_MULTIPOLE_TRACK_CXX_HPP__ */

/* end: */
