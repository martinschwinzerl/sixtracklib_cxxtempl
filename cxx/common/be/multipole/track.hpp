#ifndef SIXTRACKLIB_COMMON_BE_MULTIPOLE_TRACK_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_MULTIPOLE_TRACK_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/internal/math_constant_traits.hpp"
#include "cxx/common/be/multipole/be_multipole.hpp"
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
        typedef sixtrack_cxx::TrackParticleBase< PData > particle_t;
        typedef typename particle_t::real_t              real_t;
        typedef sixtrack_cxx::MathConstants< real_t >    real_math_constants_t;

        typedef sixtrack_cxx::BeMultipoleBase< BeData >  be_multipole_t;
        typedef typename be_multipole_t::real_t          mp_real_t;
        typedef typename be_multipole_t::order_t         mp_order_t;
        typedef sixtrack_cxx::MathConstants< mp_real_t > mp_real_math_constants_t;

        mp_order_t index_x =
            sixtrack_cxx::BeMultipoleData_get_order( mp ) * ( mp_order_t )2u;

        mp_order_t index_y = index_x + ( mp_order_t )1u;

        real_t dpx = sixtrack_cxx::BeMultipoleData_get_const_bal( mp, index_x );
        real_t dpy = sixtrack_cxx::BeMultipoleData_get_const_bal( mp, index_y );

        while( index_x >= ( mp_order_t )2 )
        {
            real_t zre = dpx * particle.x - dpy * particle.y;
            real_t zim = dpx * particle.y + dpy * particle.x;

            index_x -= 2;
            index_y -= 2;

            zre += sixtrack_cxx::BeMultipoleData_get_const_bal( mp, index_x );
            zim += sixtrack_cxx::BeMultipoleData_get_const_bal( mp, index_y );

            dpx = zre;
            dpy = zim;
        }

        dpx *= -particle.chi;
        dpy *=  particle.chi;

        if( ( mp.hxl != real_math_constants_t::Zero() ) ||
            ( mp.hyl != real_math_constants_t::Zero() ) )
        {
            real_t const hxlx = particle.x * mp.hxl;
            real_t const hyly = particle.y * mp.hyl;

            particle.zeta += particle.chi * ( hyly - hxlx );

            real_t const delta_plus_1 = particle.delta +
                real_math_constants_t::One();

            dpx += delta_plus_1 * hxlx;
            dpy -= delta_plus_1 * hyly;

            if( mp.length > mp_real_math_constants_t::Zero() )
            {
                real_t delta_p = particle.chi * hxlx;
                delta_p *= sixtrack_cxx::BeMultipoleData_get_const_bal( mp, 0 );
                delta_p /= mp.length;
                dpx -= delta_p;

                delta_p  = particle.chi * hyly;
                delta_p *= sixtrack_cxx::BeMultipoleData_get_const_bal( mp, 1 );
                delta_p /= mp.length;
                dpy += delta_p;
            }
        }

        particle.px += dpx;
        particle.py += dpy;

        return SIXTRL_CXX_NAMESPACE::TRACK_SUCCESS;
    }
}

#endif /* SIXTRACKLIB_COMMON_BE_MULTIPOLE_TRACK_CXX_HPP__ */

/* end: */
