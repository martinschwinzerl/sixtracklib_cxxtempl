#ifndef SIXTRACKLIB_COMMON_INTERNAL_OBJ_STORE_TRAITS_CXX_HPP__
#define SIXTRACKLIB_COMMON_INTERNAL_OBJ_STORE_TRAITS_CXX_HPP__

#include <cstdlib>

#include "sixtracklib/sixtracklib.hpp"

namespace sixtrack_cxx
{
    template< typename T >
    struct TypeStoreTraits
    {
        static SIXTRL_FN constexpr std::size_t StorageAlign()
        {
            return alignof( T ) > static_cast< std::size_t >( 8u )
                 ? alignof( T ) : static_cast< std::size_t >( 8u );
        }

        static SIXTRL_FN constexpr bool Scalar()
        {
            return true;
        }
    };

    /* --------------------------------------------------------------------- */

    template< class ObjData >
    struct ObjDataStoreTraits
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_INVALID;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return false;
        }
    };

    template< class ObjData >
    SIXTRL_FN constexpr bool ObjData_can_be_stored() SIXTRL_NOEXCEPT
    {
        return ( sixtrack_cxx::ObjDataStoreTraits< ObjData >::ObjTypeId() !=
                 SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_INVALID );
    }

    template< class ObjData >
    SIXTRL_FN constexpr bool ObjData_has_same_layout_as_c_api() SIXTRL_NOEXCEPT
    {
        return ObjDataStoreTraits< ObjData >::HasCApiLayout();
    }
}

#endif /* SIXTRACKLIB_COMMON_INTERNAL_OBJ_STORE_TRAITS_CXX_HPP__ */
/* end: cxx/common/internal/obj_store_traits.hpp */
