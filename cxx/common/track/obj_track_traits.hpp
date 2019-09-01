#ifndef SIXTRACKLIB_COMMON_TRACK_OBJ_TRACK_TRAITS_CXX_HPP__
#define SIXTRACKLIB_COMMON_TRACK_OBJ_TRACK_TRAITS_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

namespace sixtrack_cxx
{
    template< class ObjData > struct ObjDataTrackTraits
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_INVALID;
        }
    };

    template< class ObjData >
    SIXTRL_FN constexpr bool ObjData_can_be_tracked() SIXTRL_NOEXCEPT
    {
        return ( sixtrack_cxx::ObjDataTrackTraits< ObjData >::ObjTypeId() !=
                 SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_INVALID );
    }
}

#endif /* SIXTRACKLIB_COMMON_TRACK_OBJ_TRACK_TRAITS_CXX_HPP__ */
/* end: cxx/common/track/obj_track_traits.hpp */
