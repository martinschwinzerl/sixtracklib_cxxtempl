#ifndef SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_DATA_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_DATA_CXX_HPP__

#include <cstddef>

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#include "cxx/common/be/xyshift/be_xyshift_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< typename R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign()>
    struct BeXYShiftData
    {
        typedef R real_t;

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return RAlign; }

        real_t  dx          SIXTRL_ALIGN( RAlign );
        real_t  dy          SIXTRL_ALIGN( RAlign );
    };

    /* --------------------------------------------------------------------- */

    template<> struct ObjDataStoreTraits< BeXYShiftData< double, 8u > >
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

    template< class R, std::size_t RealAlign >
    struct ObjDataTrackTraits< BeXYShiftData< R, RealAlign > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_XYSHIFT;
        }
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_DATA_CXX_HPP__ */
/* end: */
