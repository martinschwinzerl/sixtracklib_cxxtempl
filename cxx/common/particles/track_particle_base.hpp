#ifndef SIXTRACKLIB_COMMMON_PARTICLES_TRACK_PARTICLE_BASE_CXX_HPP__
#define SIXTRACKLIB_COMMMON_PARTICLES_TRACK_PARTICLE_BASE_CXX_HPP__

#include <cstddef>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"

#include "cxx/common/particles/track_particle.h"
#include "cxx/common/particles/track_particle_data.hpp"

#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template<> struct ObjDataTrackTraits< ::NS(TrackParticle) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_PARTICLE;
        }
    };

    template< typename R, typename I, std::size_t RAlign, std::size_t IAlign >
    struct ObjDataTrackTraits<
        sixtrack_cxx::TrackParticleData< R, I, RAlign, IAlign > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_PARTICLE;
        }
    };

    /* ********************************************************************* */

    template< class ParticleData >
    class TrackParticleBase : public ParticleData
    {
        public:

        typedef ParticleData particle_data_t;

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
