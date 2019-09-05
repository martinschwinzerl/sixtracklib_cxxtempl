#ifndef SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_C99_H__
#define SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_C99_H__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#if defined( __cplusplus )

#include "cxx/common/be/xyshift/be_xyshift_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

extern "C" {
#endif /* defined( __cplusplus ) */

typedef double NS(be_xyshift_real_t);

typedef struct NS(BeXYShift)
{
    NS(be_xyshift_real_t) dx SIXTRL_ALIGN( 8 );
    NS(be_xyshift_real_t) dy SIXTRL_ALIGN( 8 );
}
NS(BeXYShift);

#if defined( __cplusplus )
}

namespace sixtrack_cxx
{
    template<> struct ObjDataStoreTraits< ::NS(BeXYShift) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_XYSHIFT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template<> struct ObjDataTrackTraits< ::NS(BeXYShift) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_XYSHIFT;
        }
    };

    template<> struct BeXYShiftTraits< ::NS(BeXYShift) >
    {
        typedef ::NS(be_xyshift_real_t) real_t;
    };
}

#endif /* c++ */

#endif /* SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_C99_H__ */
/* end: */
