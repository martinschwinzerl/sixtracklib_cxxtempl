#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/buffer.h"

#include <iostream>
#include <iomanip>

#include "cxx/sixtracklib.hpp"

int main()
{
    namespace st    = SIXTRL_CXX_NAMESPACE;
    namespace stcxx = sixtrack_cxx;
    using size_t    = ::NS(buffer_size_t);

    ::NS(Buffer)* buffer = ::NS(Buffer_new)( size_t{ 0 } );

    sixtrack_cxx::BeCavity cavity_1;

    std::cout << "cavity_1 : "
              << "voltage    = " << cavity_1.voltage << "\r\n"
              << " frequency = " << cavity_1.frequency  << "\r\n"
              << " lag       = " << cavity_1.lag << std::endl;

    sixtrack_cxx::BeCavity cavity_2( 1e6, 400e6, 0.5 );

    std::cout << "cavity_1 : "
              << "voltage    = " << cavity_2.voltage << "\r\n"
              << " frequency = " << cavity_2.frequency  << "\r\n"
              << " lag       = " << cavity_2.lag << std::endl;

    #if defined( SIXTRL_EXT_LIBRARY_BOOST ) && ( SIXTRL_EXT_LIBRARY_BOOST == 1 )

//     typedef sixtrack_cxx::TBeCavity< sixtrack_cxx::mp_float_n_t< 100 > >
//             mp_cavity_100_t;

    #endif /* Boost Multiprecision available */

    ::NS(Buffer_delete)( buffer );

    return 0;
}

/* end: */
