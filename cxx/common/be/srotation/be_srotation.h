#ifndef SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_C99_H__
#define SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_C99_H__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/track/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#if defined( __cplusplus )

#include "cxx/common/be/srotation/be_srotation_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

extern "C" {
#endif /* defined( __cplusplus ) */

typedef double  NS(be_srotation_real_t);

typedef struct NS(BeSRotation)
{
    NS(be_srotation_real_t) cos_z SIXTRL_ALIGN( 8 );
    NS(be_srotation_real_t) sin_z SIXTRL_ALIGN( 8 );
}
NS(BeSRotation);

#if defined( __cplusplus )
}

namespace sixtrack_cxx
{
    template<> struct ObjDataStoreTraits< ::NS(BeSRotation) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template<> struct ObjDataTrackTraits< ::NS(BeSRotation) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION;
        }
    };

    template<> struct BeSRotationTraits< ::NS(BeSRotation) >
    {
        typedef ::NS(be_srotation_real_t) real_t;
    };
}

#endif /* c++ */

#endif /* SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_C99_H__ */
/* end: */
