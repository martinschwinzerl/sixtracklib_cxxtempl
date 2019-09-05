#ifndef SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_C99_H__
#define SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_C99_H__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#if defined( __cplusplus )

#include "cxx/common/be/multipole/definitions.h"
#include "cxx/common/be/multipole/be_multipole_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

extern "C" {
#endif /* defined( __cplusplus ) */

typedef struct NS(BeMultipole)
{
    NS(be_multipole_order_t) order  SIXTRL_ALIGN( 8 );
    NS(be_multipole_real_t)  length SIXTRL_ALIGN( 8 );
    NS(be_multipole_real_t)  hxl    SIXTRL_ALIGN( 8 );
    NS(be_multipole_real_t)  hyl    SIXTRL_ALIGN( 8 );
    NS(be_multipole_real_t)* bal    SIXTRL_ALIGN( 8 );
}
NS(BeMultipole);

#if defined( __cplusplus )
}

/* ------------------------------------------------------------------------- */

namespace sixtrack_cxx
{
    void BeMultipoleData_init( ::NS(BeMultipole)& SIXTRL_RESTRICT_REF mp )
    {
        mp.order  = ::NS(be_multipole_order_t){ 0 };
        mp.length = ::NS(be_multipole_real_t){ 0 };
        mp.hxl    = ::NS(be_multipole_real_t){ 0 };
        mp.hyl    = ::NS(be_multipole_real_t){ 0 };
        mp.bal    = nullptr;
    }

    void BeMultipoleData_init( ::NS(BeMultipole)& SIXTRL_RESTRICT_REF mp,
        ::NS(be_multipole_order_t) const order,
        ::NS(be_multipole_real_t)* SIXTRL_RESTRICT ptr_to_bal = nullptr )
    {
        mp.order  = order;
        mp.length = ::NS(be_multipole_real_t){ 0 };
        mp.hxl    = ::NS(be_multipole_real_t){ 0 };
        mp.hyl    = ::NS(be_multipole_real_t){ 0 };
        mp.bal    = ptr_to_bal;
    }

    void BeMultipoleData_init( ::NS(BeMultipole)& SIXTRL_RESTRICT_REF mp,
        ::NS(be_multipole_order_t) const order,
        ::NS(be_multipole_real_t) const length,
        ::NS(be_multipole_real_t) const hxl,
        ::NS(be_multipole_real_t) const hyl,
        ::NS(be_multipole_real_t)* SIXTRL_RESTRICT ptr_to_bal = nullptr )
    {
        mp.order  = order;
        mp.length = length;
        mp.hxl    = hxl;
        mp.hyl    = hyl;
        mp.bal    = ptr_to_bal;
    }

    /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --  */

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

    template<> struct ObjDataStoreLayoutTraits< ::NS(BeMultipole) >
    {
        typedef sixtrack_cxx::ObjDataStoreLayoutTraits< ::NS(BeMultipole) >
                _obj_data_store_layout_traits_t;

        typedef ::NS(buffer_size_t) size_type;

        static constexpr size_type DataPtrSizes[ 1 ]   =
        {
            sizeof( ::NS(be_multipole_real_t ) )
        };

        static constexpr size_type DataPtrOffsets[ 1 ] =
        {
            offsetof( ::NS(BeMultipole), bal )
        };

        static SIXTRL_FN constexpr size_type GetNumDataPtrs()
        {
            return ::NS(buffer_size_t){ 1 };
        }

        static SIXTRL_FN size_type const* GetPtrSizesBegin()
        {
            return &_obj_data_store_layout_traits_t::DataPtrSizes[ 0 ];
        }

        static SIXTRL_FN size_type const* GetPtrOffsetsBegin()
        {
            return &_obj_data_store_layout_traits_t::DataPtrOffsets[ 0 ];
        }

        static SIXTRL_FN SIXTRL_CXX_NAMESPACE::arch_status_t GetDataPtrsCounts(
            ::NS(BeMultipole) const& SIXTRL_RESTRICT_REF obj,
            size_type* SIXTRL_RESTRICT counts_begin,
            size_type* SIXTRL_RESTRICT counts_end )
        {
            typedef ::NS(be_multipole_order_t) order_t;
            typedef std::ptrdiff_t diff_t;
            namespace st = SIXTRL_CXX_NAMESPACE;

            st::arch_status_t status = st::ARCH_STATUS_GENERAL_FAILURE;
            diff_t in_length = diff_t{ 0 };

            if( ( counts_begin != nullptr ) && ( counts_end != nullptr ) )
            {
                in_length = std::distance( counts_begin, counts_end );
            }

            if( ( in_length > diff_t{ 0 } ) && ( obj.order >= order_t{ 0 } ) )
            {
                *counts_begin = static_cast< size_type >(
                    order_t{ 2 } * ( obj.order + order_t{ 1 } ) );

                status = st::ARCH_STATUS_SUCCESS;
            }

            return status;
        }
    };
}

#endif /* c++ */

#endif /* SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_C99_H__ */
/* end: */
