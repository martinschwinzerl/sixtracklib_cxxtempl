#ifndef SIXTRACKLIB_BOOST_MULTIPREC_DEFINITIONS_CXX_HPP__
#define SIXTRACKLIB_BOOST_MULTIPREC_DEFINITIONS_CXX_HPP__

#include "cxx/ext_libs.h"

#if defined( SIXTRL_EXT_LIBRARY_BOOST ) && ( SIXTRL_EXT_LIBRARY_BOOST == 1 )
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace sixtrack_cxx
{
    template< unsigned Digits10 >
    using mp_float_n_t = boost::multiprecision::number<
        boost::multiprecision::cpp_dec_float< Digits10 > >;

    typedef mp_float_n_t< 50  > mp_float_50_t;
    typedef mp_float_n_t< 100 > mp_float_100_t;
}

#endif /* Boost Multiprecision available */

#endif /* SIXTRACKLIB_BOOST_MULTIPREC_DEFINITIONS_CXX_HPP__ */
/* end: */
