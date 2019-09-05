#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_EXACT_DATA_C99_H__
#define SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_EXACT_DATA_C99_H__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"
#include "cxx/common/be/drift/definitions.h"

#if defined( __cplusplus )

#include "cxx/common/be/drift/be_drift_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

extern "C" {
#endif /* defined( __cplusplus ) */

typedef struct NS(BeDriftExact)
{
    NS(be_drift_real_t) length SIXTRL_ALIGN( 8 ); /* [m] */
}
NS(BeDriftExact);

#if defined( __cplusplus )
}

namespace sixtrack_cxx
{
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

    template<> struct BeDriftExactTraits< ::NS(BeDriftExact) >
    {
        typedef ::NS(be_drift_real_t) real_t;
    };
}

#endif /* defined( __cplusplus ) */

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_EXACT_DATA_C99_H__ */

/* end: cxx/common/be/drift/be_drift_exact.h */
