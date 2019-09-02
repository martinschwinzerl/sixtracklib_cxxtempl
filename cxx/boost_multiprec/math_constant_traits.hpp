#ifndef SIXTRACKLIB_BOOST_MULTIPRECISION_MATH_CONSTANT_TRAITS_CXX_HPP__
#define SIXTRACKLIB_BOOST_MULTIPRECISION_MATH_CONSTANT_TRAITS_CXX_HPP__

#include "cxx/boost_multiprec/definitions.hpp"
#include "cxx/common/internal/math_constant_traits.hpp"

namespace sixtrack_cxx
{
    template< unsigned N >
    struct MathConstants< sixtrack_cxx::mp_float_n_t< N > >
    {
        using real_t = sixtrack_cxx::mp_float_n_t< N >;

        static SIXTRL_FN real_t Zero() SIXTRL_NOEXCEPT
        {
            return real_t{ 0 };
        }

        static SIXTRL_FN real_t One() SIXTRL_NOEXCEPT
        {
            return real_t{ 1 };
        }

        static SIXTRL_FN real_t Two() SIXTRL_NOEXCEPT
        {
            return real_t{ 2 };
        }

        static SIXTRL_FN real_t OneHalf() SIXTRL_NOEXCEPT
        {
            return real_t{ 1 } / real_t{ 2 };
        }

        static SIXTRL_FN real_t Pi() SIXTRL_NOEXCEPT
        {
            namespace bmp = boost::multiprecision;
            return bmp::atan( real_t{ 1.0 } ) * real_t{ 4.0 };
        }

        static SIXTRL_FN real_t SqrtPi() SIXTRL_NOEXCEPT
        {
            return boost::multiprecision::sqrt( MathConstants< real_t >::Pi() );
        }

        static SIXTRL_FN real_t Deg2Rad() SIXTRL_NOEXCEPT
        {
            return MathConstants< real_t >::Pi() / real_t{ 180.0 };
        }

        static SIXTRL_FN real_t Rad2Deg() SIXTRL_NOEXCEPT
        {
            return real_t{ 180.0 } / MathConstants< real_t >::Pi();
        }
    };
}

#endif /* SIXTRACKLIB_BOOST_MULTIPRECISION_MATH_CONSTANT_TRAITS_CXX_HPP__ */
