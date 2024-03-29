#ifndef SIXTRACKLIB_MULTIPREC_TRACK_PARTICLE_DATA_CXX_HPP__
#define SIXTRACKLIB_MULTIPREC_TRACK_PARTICLE_DATA_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"
#include "cxx/common/particles/track_particle_data.hpp"
#include "cxx/common/particles/track_particle_base.hpp"
#include "cxx/boost_multiprec/definitions.hpp"

namespace sixtrack_cxx
{
    template< unsigned Digits10 >
    using MultiPrecTrackParticleData =
    sixtrack_cxx::TrackParticleData< mp_float_n_t< Digits10 >, int64_t >;

    template< unsigned Digits10 > struct ObjDataTrackTraits<
        sixtrack_cxx::MultiPrecTrackParticleData< Digits10 > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_PARTICLE;
        }
    };
}

#endif /* SIXTRACKLIB_MULTIPREC_TRACK_PARTICLE_DATA_CXX_HPP__ */
/* end: cxx/boost_multiprec/track_particle_data.hpp */
