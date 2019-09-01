#include <cstddef>
#include <cstdint>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/sixtracklib.hpp"
#include "cxx/ext_libs.h"

#include <boost/multiprecision/cpp_dec_float.hpp>

#include <iostream>

namespace sixtrack_cxx
{
    namespace tests
    {
        template< class DataObj >
        void Print( sixtrack_cxx::TrackParticleBase< DataObj > const& particle )
        {
            std::cout << "x             = " << particle.x     << "\r\n"
                      << "px            = " << particle.px    << "\r\n"
                      << "y             = " << particle.y     << "\r\n"
                      << "py            = " << particle.py    << "\r\n"
                      << "delta         = " << particle.delta << "\r\n"
                      << "zeta          = " << particle.zeta  << "\r\n"
                      << "\r\n";
        }
    }
}

namespace boost_mp = boost::multiprecision;

int main()
{
    sixtrack_cxx::TrackParticle  track_particle_1;
    track_particle_1.x = 1.0;
    track_particle_1.px = 0.0;
    std::cout << "track_particle_1: \r\n";
    std::cout << "real-align    = "
              << sixtrack_cxx::TrackParticle::RealAlignment() << "\r\n"
              << "integer-align = "
              << sixtrack_cxx::TrackParticle::IntegerAlignment() << "\r\n";
    sixtrack_cxx::tests::Print( track_particle_1 );

    sixtrack_cxx::CTrackParticle track_particle_2;
    track_particle_2.x = -1.0;
    track_particle_2.px = -0.25;
    std::cout << "track_particle_2: \r\n";
    sixtrack_cxx::tests::Print( track_particle_2 );

    #if defined( SIXTRL_EXT_LIBRARY_BOOST ) && SIXTRL_EXT_LIBRARY_BOOST == 1

    sixtrack_cxx::MultPrecTrackParticle< 100 > track_particle_3;
    track_particle_3.x = 2.0;
    track_particle_3.y = 2.0;
    track_particle_3.px = -0.1;
    track_particle_3.delta = 1e-5;
    std::cout << "track_particle_3: \r\n";
    std::cout << "real-align    = "
              << sixtrack_cxx::MultPrecTrackParticle< 100 >::RealAlignment()
              << "\r\n" << "integer-align = "
              << sixtrack_cxx::MultPrecTrackParticle< 100 >::IntegerAlignment()
              << "\r\n";
    sixtrack_cxx::tests::Print( track_particle_3 );

    #endif /* multiprecision */



    return 0;
}

/* end: examples/test_particles.cpp */
