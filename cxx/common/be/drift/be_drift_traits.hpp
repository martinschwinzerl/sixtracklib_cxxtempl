#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_TRAITS_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_TRAITS_CXX_HPP__

#include <type_traits>
#include <utility>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< class ParticleObjData, class BeObjData >
    SIXTRL_FN constexpr bool CanTrackAsDrift()
    {
        return ( ( ObjDataTrackTraits< ParticleObjData >::ObjTypeId() ==
                   SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_PARTICLE ) &&
                 ( ObjDataTrackTraits< BeObjData >::ObjTypeId() ==
                   SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT ) );
    }

    template< class ParticleObjData, class BeObjData >
    using track_as_drift_t = std::enable_if<
        sixtrack_cxx::CanTrackAsDrift< ParticleObjData, BeObjData >, int >;

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< class ParticleObjData, class BeObjData >
    SIXTRL_FN constexpr bool CanTrackAsDriftExact()
    {
        return ( ( ObjDataTrackTraits< ParticleObjData >::ObjTypeId() ==
                   SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_PARTICLE ) &&
                 ( ObjDataTrackTraits< BeObjData >::ObjTypeId() ==
                   SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT ) );
    }

    template< class ParticleObjData, class BeObjData >
    using track_as_drift_exact_t = std::enable_if<
        sixtrack_cxx::CanTrackAsDriftExact< ParticleObjData, BeObjData >, int >;

    /* --------------------------------------------------------------------- */

    template< class BeObjData >
    struct BeDriftTraits
    {
        typedef typename BeObjData::real_t  real_t;
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_TRAITS_CXX_HPP__ */
