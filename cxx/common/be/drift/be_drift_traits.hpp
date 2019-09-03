#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_TRAITS_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_TRAITS_CXX_HPP__

#include <type_traits>
#include <utility>

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#include "cxx/common/be/drift/be_drift.h"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< class BeObjData >
    SIXTRL_FN constexpr bool ObjIsDrift()
    {
        return ( ObjDataTrackTraits< BeObjData >::ObjTypeId() ==
                   SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT );
    }

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

    template< class BeObjData >
    SIXTRL_FN constexpr bool ObjIsDriftExact()
    {
        return ( ObjDataTrackTraits< BeObjData >::ObjTypeId() ==
                   SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT );
    }

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
    SIXTRL_FN constexpr bool ObjIsDriftOrDriftExact()
    {
        return ( ( ObjDataTrackTraits< BeObjData >::ObjTypeId() ==
                        SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT ) ||
                 ( ObjDataTrackTraits< BeObjData >::ObjTypeId() ==
                        SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT ) );
    }

    /* --------------------------------------------------------------------- */

    template< class BeObjData >
    struct BeDriftTraits
    {
        typedef typename std::conditional<
            sixtrack_cxx::ObjIsDrift< BeObjData >(),
            ::NS(BeDrift), typename std::conditional<
                sixtrack_cxx::ObjIsDriftExact< BeObjData >(),
                    ::NS(DriftExact), void > >::type c_api_t;

        typedef typename BeObjData::real_t real_t;
    };

    template<> struct BeDriftTraits< ::NS(BeDrift) >
    {
        typedef ::NS(BeDrift)      c_api_t;
        typedef ::NS(be_drift_real_t)   real_t;
    };

    template<> struct BeDriftTraits< ::NS(BeDriftExact) >
    {
        typedef ::NS(BeDriftExact)      c_api_t;
        typedef ::NS(be_drift_real_t)   real_t;
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_TRAITS_CXX_HPP__ */
