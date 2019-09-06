#include <cstdint>
#include <iostream>
#include <iomanip>

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/track/definitions.h"

#include "cxx/boost_multiprec/definitions.hpp"
#include "cxx/boost_multiprec/beam_elements.hpp"
#include "cxx/sixtracklib.hpp"

int main()
{
    sixtrack_cxx::BeDrift                   cxx_drift_1;
    sixtrack_cxx::TBeDrift< double >        cxx_drift_2;
    sixtrack_cxx::CBeDrift                  c99_drift;

    sixtrack_cxx::BeDriftExact              cxx_drift_exact_1;
    sixtrack_cxx::TBeDriftExact< double >   cxx_drift_exact_2;
    sixtrack_cxx::CBeDriftExact             c99_drift_exact;

    #if defined( SIXTRL_EXT_LIBRARY_BOOST ) && ( SIXTRL_EXT_LIBRARY_BOOST == 1 )

    using mp_drift_100_t = sixtrack_cxx::BeDriftInterface<
        sixtrack_cxx::BMPBeDriftData< 100 > >;

    using mp_drift_exact_100_t = sixtrack_cxx::BeDriftExactInterface<
        sixtrack_cxx::BMPBeDriftExactData< 100 > >;

    using mp_particle_100_t = sixtrack_cxx::MultPrecTrackParticle< 100 >;

    mp_drift_100_t       mp_drift;
    mp_drift_exact_100_t mp_drift_exact;
    mp_particle_100_t    mp_particle;

    #endif /* Boost Multiprecision available */

    sixtrack_cxx::TrackParticle             cxx_particle_1;
    sixtrack_cxx::CTrackParticle            c99_particle;

    std::cout << "track: cxx_particle_1, cxx_drift_1 : \r\n";
    sixtrack_cxx::Drift_track( cxx_particle_1, cxx_drift_1 );

    std::cout << "track: cxx_particle_1, cxx_drift_2 : \r\n";
    sixtrack_cxx::Drift_track( cxx_particle_1, cxx_drift_2 );

    std::cout << "track: cxx_particle_1, c99_drift : \r\n";
    sixtrack_cxx::Drift_track( cxx_particle_1, c99_drift );

    std::cout << "track: c99_particle, cxx_drift_1 : \r\n";
    sixtrack_cxx::Drift_track( c99_particle, cxx_drift_1 );

    std::cout << "track: c99_particle, cxx_drift_2 : \r\n";
    sixtrack_cxx::Drift_track( c99_particle, cxx_drift_2 );

    std::cout << "track: c99_particle, c99_drift : \r\n";
    sixtrack_cxx::Drift_track( c99_particle, c99_drift );

    #if defined( SIXTRL_EXT_LIBRARY_BOOST ) && ( SIXTRL_EXT_LIBRARY_BOOST == 1 )

    std::cout << "track: mp_particle, mp_drift : \r\n";
    sixtrack_cxx::Drift_track( mp_particle, mp_drift );

    #endif /* Boost multiprecision available */

    std::cout << "\r\n\r\n";

    std::cout << "track: cxx_particle_1, cxx_drift_exact_1 : \r\n";
    sixtrack_cxx::DriftExact_track( cxx_particle_1, cxx_drift_exact_1 );

    std::cout << "track: cxx_particle_1, cxx_drift_exact_2 : \r\n";
    sixtrack_cxx::DriftExact_track( cxx_particle_1, cxx_drift_exact_2 );

    std::cout << "track: cxx_particle_1, c99_drift_exact : \r\n";
    sixtrack_cxx::DriftExact_track( cxx_particle_1, c99_drift_exact );

    std::cout << "track: c99_particle, cxx_drift_exact_1 : \r\n";
    sixtrack_cxx::DriftExact_track( c99_particle, cxx_drift_exact_1 );

    std::cout << "track: c99_particle, cxx_drift_exact_2 : \r\n";
    sixtrack_cxx::DriftExact_track( c99_particle, cxx_drift_exact_2 );

    std::cout << "track: c99_particle, c99_drift_exact : \r\n";
    sixtrack_cxx::DriftExact_track( c99_particle, c99_drift_exact );

    #if defined( SIXTRL_EXT_LIBRARY_BOOST ) && ( SIXTRL_EXT_LIBRARY_BOOST == 1 )

    std::cout << "track: mp_particle, mp_drift_exact : \r\n";
    sixtrack_cxx::DriftExact_track( mp_particle, mp_drift_exact );

    #endif /* Boost multiprecision available */
}

/* end: */
