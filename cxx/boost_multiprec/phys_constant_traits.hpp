#ifndef SIXTRACKLIB_BOOST_MULTIPREC_PHYS_CONSTANT_TRAITS_CXX_HPP__
#define SIXTRACKLIB_BOOST_MULTIPREC_PHYS_CONSTANT_TRAITS_CXX_HPP__

#include "cxx/boost_multiprec/definitions.hpp"
#include "cxx/common/internal/phys_constant_traits.hpp"

namespace sixtrack_cxx
{
    template< unsigned Digits10 >
    struct PhysConstants< sixtrack_cxx::mp_float_n_t< Digits10 > >
    {
        using real_t = sixtrack_cxx::mp_float_n_t< Digits10 >;

        /* Source: https://physics.nist.gov/cuu/Constants/index.html
         *         If not noted otherwise, these values correspond to the
         *         CODATA 2018 recommended values */

        static SIXTRL_FN real_t C0() SIXTRL_NOEXCEPT
        {
            return real_t{ 299792458.0 };
        }

        static SIXTRL_FN real_t Mu0() SIXTRL_NOEXCEPT
        {
            /* Check whether using 4*pi*1e-7 would be better here */
            return real_t{ 1.25663706212e-6 };
        }

        static SIXTRL_FN real_t Epsilon0() SIXTRL_NOEXCEPT
        {
            /* Check whether using 1 / ( c0*c0*mu0) would be better here */
            return real_t{ 8.8541878128e-12 };
        }

        static SIXTRL_FN real_t Q0() SIXTRL_NOEXCEPT
        {
            return real_t{ 1.602176634e-19 };
        }
    };
}

#endif /* SIXTRACKLIB_COMMON_INTERNAL_PHYS_CONSTANT_TRAITS_CXX_HPP__ */
/* end: */
