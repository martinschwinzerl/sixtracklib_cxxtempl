#ifndef SIXTRACKLIB_COMMON_PARTICLES_TRACK_PARTICLE_DATA_CXX_HPP__
#define SIXTRACKLIB_COMMON_PARTICLES_TRACK_PARTICLE_DATA_CXX_HPP__

#include <cstdlib>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"

namespace sixtrack_cxx
{
    template< typename R, typename I,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign(),
        std::size_t IAlign = sixtrack_cxx::TypeStoreTraits< I >::StorageAlign() >
    struct TrackParticleData
    {
        typedef R             real_t;
        typedef I             int_t;

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return RAlign; }

        static SIXTRL_FN constexpr std::size_t
        IntegerAlignment() { return IAlign; }

        real_t q0             SIXTRL_ALIGN( RAlign );
        real_t mass0          SIXTRL_ALIGN( RAlign );
        real_t beta0          SIXTRL_ALIGN( RAlign );
        real_t gamma0         SIXTRL_ALIGN( RAlign );
        real_t p0c            SIXTRL_ALIGN( RAlign );

        real_t s              SIXTRL_ALIGN( RAlign );
        real_t x              SIXTRL_ALIGN( RAlign );
        real_t y              SIXTRL_ALIGN( RAlign );
        real_t px             SIXTRL_ALIGN( RAlign );
        real_t py             SIXTRL_ALIGN( RAlign );
        real_t zeta           SIXTRL_ALIGN( RAlign );

        real_t psigma         SIXTRL_ALIGN( RAlign );
        real_t delta          SIXTRL_ALIGN( RAlign );
        real_t rpp            SIXTRL_ALIGN( RAlign );
        real_t rvv            SIXTRL_ALIGN( RAlign );
        real_t chi            SIXTRL_ALIGN( RAlign );
        real_t charge_ratio   SIXTRL_ALIGN( RAlign );

        int_t  particle_id    SIXTRL_ALIGN( IAlign );
        int_t  at_element_id  SIXTRL_ALIGN( IAlign );
        int_t  at_turn        SIXTRL_ALIGN( IAlign );
        int_t  state          SIXTRL_ALIGN( IAlign );
    };
}

#endif /* SIXTRACKLIB_COMMON_PARTICLES_TRACK_PARTICLE_DATA_CXX_HPP__ */

/* end: cxx/common/particles/track_particle_data.hpp */
