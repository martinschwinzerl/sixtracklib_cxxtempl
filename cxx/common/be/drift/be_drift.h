#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_DATA_C99_H__
#define SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_DATA_C99_H__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#if defined( __cplusplus )

#include "cxx/common/be/drift/be_drift_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

extern "C" {
#endif /* defined( __cplusplus ) */

typedef double NS(be_drift_real_t);

typedef struct NS(BeDrift)
{
    NS(be_drift_real_t) length SIXTRL_ALIGN( 8 ); /* [m] */
}
NS(BeDrift);

typedef struct NS(BeDriftExact)
{
    NS(be_drift_real_t) length SIXTRL_ALIGN( 8 ); /* [m] */
}
NS(BeDriftExact);

#if defined( __cplusplus )
}

/* ------------------------------------------------------------------------- */

namespace sixtrack_cxx
{
    template<> struct ObjDataStoreTraits< ::NS(BeDrift) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template<> struct ObjDataTrackTraits< ::NS(BeDrift) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT;
        }
    };

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template<> struct ObjDataStoreTraits< ::NS(BeDriftExact) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template<> struct ObjDataTrackTraits< ::NS(BeDriftExact) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT;
        }
    };
}

#endif /* defined( __cplusplus ) */

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_DATA_C99_H__ */

/* end: cxx/common/particles/track_particle.h */
