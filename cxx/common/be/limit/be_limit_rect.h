#ifndef SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_C99_H__
#define SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_C99_H__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#if defined( __cplusplus )

#include "cxx/common/be/limit/be_limit_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

extern "C" {
#endif /* defined( __cplusplus ) */

typedef double  NS(be_limit_rect_real_t);

typedef struct NS(BeLimitRect)
{
    NS(be_limit_rect_real_t) min_x SIXTRL_ALIGN( 8 );
    NS(be_limit_rect_real_t) max_x SIXTRL_ALIGN( 8 );

    NS(be_limit_rect_real_t) min_y SIXTRL_ALIGN( 8 );
    NS(be_limit_rect_real_t) max_y SIXTRL_ALIGN( 8 );
}
NS(BeLimitRect);

#if defined( __cplusplus )
}

/* ------------------------------------------------------------------------- */

namespace sixtrack_cxx
{
    template<> struct ObjDataStoreTraits< ::NS(BeLimitRect) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template<> struct ObjDataTrackTraits< ::NS(BeLimitRect) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT;
        }
    };

    template<> struct BeLimitRectTraits< ::NS(BeLimitRect) >
    {
        typedef ::NS(be_limit_rect_real_t)   real_t;
    };
}

#endif /* c++ */

#endif /* SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_C99_H__ */
/* end: */
