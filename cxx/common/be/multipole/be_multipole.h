#ifndef SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_C99_H__
#define SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_C99_H__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#if defined( __cplusplus )

#include "cxx/common/be/multipole/be_multipole_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

extern "C" {
#endif /* defined( __cplusplus ) */

typedef double  NS(be_multipole_real_t);
typedef int64_t NS(be_multipole_order_t);

typedef struct NS(BeMultipole)
{
    NS(be_multipole_order_t) order       SIXTRL_ALIGN( 8 );
    NS(be_multipole_real_t)  length      SIXTRL_ALIGN( 8 );
    NS(be_multipole_real_t)  hxl         SIXTRL_ALIGN( 8 );
    NS(be_multipole_real_t)  hyl         SIXTRL_ALIGN( 8 );
    NS(be_multipole_real_t)* bal         SIXTRL_ALIGN( 8 );
}
NS(BeMultipole);

#if defined( __cplusplus )
}

/* ------------------------------------------------------------------------- */

namespace sixtrack_cxx
{
    ::NS(be_multipole_order_t) BeMultipoleData_get_order(
        ::NS(BeMultipole) const& SIXTRL_RESTRICT_REF mp ) SIXTRL_NOEXCEPT
    {
        return mp.order;
    }

    ::NS(be_multipole_real_t) BeMultipoleData_get_const_bal(
        ::NS(BeMultipole) const& SIXTRL_RESTRICT_REF mp,
        ::NS(be_multipole_order_t) const order_index ) SIXTRL_NOEXCEPT
    {
        SIXTRL_ASSERT( mp.bal != nullptr );
        SIXTRL_ASSERT( mp.order > order_index );

        return mp.bal[ order_index ];
    }

    ::NS(be_multipole_real_t)& BeMultipoleData_get_const_bal(
        ::NS(BeMultipole)& SIXTRL_RESTRICT_REF mp,
        ::NS(be_multipole_order_t) const order_index ) SIXTRL_NOEXCEPT
    {
        SIXTRL_ASSERT( mp.bal != nullptr );
        SIXTRL_ASSERT( mp.order > order_index );

        return mp.bal[ order_index ];
    }

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template<> struct ObjDataStoreTraits< ::NS(BeMultipole) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template<> struct ObjDataTrackTraits< ::NS(BeMultipole) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE;
        }
    };

    template<> struct BeMultipoleTraits< ::NS(BeMultipole) >
    {
        typedef ::NS(be_multipole_real_t)   real_t;
        typedef ::NS(be_multipole_order_t)  order_t;
    };
}

#endif /* c++ */

#endif /* SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_C99_H__ */
/* end: */
