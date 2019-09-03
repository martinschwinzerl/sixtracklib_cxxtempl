#ifndef SIXTRACKLIB_COMMMON_PARTICLES_TRACK_PARTICLE_BASE_CXX_HPP__
#define SIXTRACKLIB_COMMMON_PARTICLES_TRACK_PARTICLE_BASE_CXX_HPP__

#include <cstddef>

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#include "cxx/common/particles/particle_traits.hpp"
#include "cxx/common/particles/track_particle.h"
#include "cxx/common/particles/track_particle_data.hpp"

namespace sixtrack_cxx
{
    template< class ParticleData >
    class TrackParticleBase : public ParticleData
    {
        public:

        typedef ParticleData particle_data_t;

        typedef typename TrackParticleDataTraits< ParticleData >::real_t real_t;
        typedef typename TrackParticleDataTraits< ParticleData >::int_t  int_t;

        TrackParticleBase() = default;

        TrackParticleBase(
            TrackParticleBase< ParticleData > const& other ) = default;

        TrackParticleBase(
            TrackParticleBase< ParticleData >&& other ) = default;

        TrackParticleBase< ParticleData >& operator=(
            TrackParticleBase< ParticleData > const& other ) = default;

        TrackParticleBase< ParticleData >& operator=(
            TrackParticleBase< ParticleData >&& other ) = default;

        virtual ~TrackParticleBase() = default;

        real_t getEnergy() const
        {
            return sixtrack_cxx::TrackParticleData_get_energy( *this );
        }

        void setEnergy( real_t const& SIXTRL_RESTRICT_REF new_energy )
        {
            sixtrack_cxx::TrackParticleData_set_energy( *this, new_energy );
        }

        void addEnergy( real_t const& SIXTRL_RESTRICT_REF delta_energy )
        {
            sixtrack_cxx::TrackParticleData_set_energy( *this,
                sixtrack_cxx::TrackParticleData_get_energy( *this ) +
                    delta_energy );
        }

        protected:

        particle_data_t* ptrParticleData() SIXTRL_NOEXCEPT
        {
            return static_cast< particle_data_t* >( this );
        }

        particle_data_t& particleData() SIXTRL_NOEXCEPT
        {
            return static_cast< particle_data_t& >( *this );
        }

        particle_data_t const* ptrParticleData() const SIXTRL_NOEXCEPT
        {
            return static_cast< particle_data_t const* >( this );
        }

        particle_data_t const& particleData() const SIXTRL_NOEXCEPT
        {
            return static_cast< particle_data_t const& >( *this );
        }
    };
}

#endif /* SIXTRACKLIB_COMMMON_PARTICLES_TRACK_PARTICLE_BASE_CXX_HPP__ */
/* end: cxx/common/particles/track_particle_base.hpp */
