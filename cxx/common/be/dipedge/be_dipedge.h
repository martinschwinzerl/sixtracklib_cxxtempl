#ifndef SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_C99_H__
#define SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_C99_H__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#if defined( __cplusplus )

#include "cxx/common/be/dipedge/be_dipedge_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

extern "C" {
#endif /* defined( __cplusplus ) */

typedef double  NS(be_dipedge_real_t);

typedef struct NS(BeDipoleEdge)
{
    NS(be_dipedge_real_t) r21 SIXTRL_ALIGN( 8 );
    NS(be_dipedge_real_t) r43 SIXTRL_ALIGN( 8 );
}
NS(BeDipoleEdge);

#if defined( __cplusplus )
}

namespace sixtrack_cxx
{
    template<> struct ObjDataStoreTraits< ::NS(BeDipoleEdge) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template<> struct ObjDataTrackTraits< ::NS(BeDipoleEdge) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE;
        }
    };

    template<> struct BeDipoleEdgeTraits< ::NS(BeDipoleEdge) >
    {
        typedef ::NS(be_dipedge_real_t)   real_t;
    };
}

#endif /* c++ */

#endif /* SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_C99_H__ */
/* end: */
