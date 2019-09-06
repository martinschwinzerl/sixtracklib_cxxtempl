#ifndef SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_DATA_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_DATA_CXX_HPP__

#include <cstddef>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/be/multipole/be_multipole_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< typename R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign(),
        std::size_t OAlign = sixtrack_cxx::TypeStoreTraits<
            ::NS(multipole_order_t) >::StorageAlign() >
    struct BeMultipoleData
    {
        typedef R                       real_t;
        typedef ::NS(multipole_order_t) order_t;

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return RAlign; }

        static SIXTRL_FN constexpr std::size_t
        OrderAlignment() { return OAlign; }

        static SIXTRL_FN constexpr std::size_t
        BalParamAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t* >::StorageAlign();
        }

        order_t order       SIXTRL_ALIGN( OAlign );
        real_t  length      SIXTRL_ALIGN( RAlign );
        real_t  hxl         SIXTRL_ALIGN( RAlign );
        real_t  hyl         SIXTRL_ALIGN( RAlign );
        real_t* bal         SIXTRL_ALIGN(
            ( BeMultipoleData< R, RAlign, OAlign >::BalParamAlignment() ) );
    };

    /* --------------------------------------------------------------------- */

    template<>
    struct ObjDataStoreTraits< BeMultipoleData< double, 8u, 8u > >
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

    template< class R, std::size_t RealAlign, std::size_t OrderAlign >
    struct ObjDataTrackTraits< BeMultipoleData< R, RealAlign, OrderAlign > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE;
        }
    };

    template< class R, std::size_t RAlign, std::size_t OAlign >
    struct ObjDataStoreLayoutTraits<
        sixtrack_cxx::BeMultipoleData< R, RAlign, OAlign > >
    {
        typedef sixtrack_cxx::BeMultipoleData< R, RAlign, OAlign > _obj_data_t;
        typedef sixtrack_cxx::ObjDataStoreLayoutTraits< _obj_data_t >
                _obj_data_store_layout_traits_t;

        typedef ::NS(buffer_size_t) size_type;
        typedef ::NS(arch_status_t) status_t;

        static SIXTRL_FN constexpr size_type NumDataPtrs()
        {
            return size_type{ 1 };
        }

        static SIXTRL_FN constexpr bool VarNumDataPtrCounts()
        {
            return true;
        }

        static SIXTRL_FN status_t GetDataPtrTypeOffsets(
            size_type* SIXTRL_RESTRICT offsets_begin )
        {
            if( offsets_begin != nullptr )
            {
                *offsets_begin = offsetof( _obj_data_t, bal );
                return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_SUCCESS;
            }

            return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_GENERAL_FAILURE;
        }

        static SIXTRL_FN status_t GetDataPtrTypeSizes(
            size_type* SIXTRL_RESTRICT sizes_begin )
        {
            if( sizes_begin != nullptr )
            {
                *sizes_begin = sizeof( typename _obj_data_t::real_t );
                return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_SUCCESS;
            }

            return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_GENERAL_FAILURE;
        }

        static SIXTRL_FN status_t GetDataPtrTypeCounts(
            const _obj_data_t *const SIXTRL_RESTRICT mp_data,
            size_type* SIXTRL_RESTRICT counts_begin )
        {
            typedef typename _obj_data_t::order_t order_t;

            if( counts_begin != nullptr )
            {
                if( ( mp_data != nullptr ) && ( mp_data->order >= order_t{ 0 } ) )
                {
                    *counts_begin = static_cast< size_type >( 2 ) * (
                        mp_data->order + order_t{ 1 } );
                }
                else
                {
                    *counts_begin = size_type{ 0 };
                }

                return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_SUCCESS;
            }

            return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_GENERAL_FAILURE;
        }
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_DATA_CXX_HPP__ */
/* end: */
