#ifndef SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_C99_H__
#define SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_C99_H__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#if defined( __cplusplus )

#include "cxx/common/be/limit/be_limit_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

extern "C" {
#endif /* defined( __cplusplus ) */

typedef double NS(be_limit_ellipse_real_t);

typedef struct NS(BeLimitEllipse)
{
    NS(be_limit_ellipse_real_t) a_squ   SIXTRL_ALIGN( 8 );
    NS(be_limit_ellipse_real_t) b_squ   SIXTRL_ALIGN( 8 );
    NS(be_limit_ellipse_real_t) a_b_squ SIXTRL_ALIGN( 8 );
}
NS(BeLimitEllipse);

#if defined( __cplusplus )
}

namespace sixtrack_cxx
{
    template<> struct ObjDataStoreTraits< ::NS(BeLimitEllipse) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return true; }
    };

    template<> struct ObjDataTrackTraits< ::NS(BeLimitEllipse) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE;
        }
    };

    template<> struct BeLimitEllipseTraits< ::NS(BeLimitEllipse) >
    {
        typedef ::NS(be_limit_ellipse_real_t) real_t;
    };
}

#endif /* c++ */

#endif /* SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_C99_H__ */
/* end: */
