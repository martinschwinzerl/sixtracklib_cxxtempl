#ifndef SIXTRACKLIB_COMMON_INTERNAL_OBJ_STORE_TRAITS_CXX_HPP__
#define SIXTRACKLIB_COMMON_INTERNAL_OBJ_STORE_TRAITS_CXX_HPP__

#include <cstdlib>

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/control/definitions.h"
#include "sixtracklib/common/buffer.h"
#include "sixtracklib/common/internal/objects_type_id.h"

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
    SIXTRL_FN bool ObjData_can_be_stored(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer )
    {
        typedef ::NS(buffer_size_t) size_type;

        size_type const slot_size = ::NS(Buffer_get_slot_size)( buffer );

        return ( ( sixtrack_cxx::ObjData_can_be_stored< ObjData >() ) &&
                 ( buffer != nullptr ) && ( slot_size > size_type{ 0 } ) &&
                 ( ( slot_size == size_type { 1 } ) ||
                   ( ( slot_size <= alignof( ObjData ) ) &&
                     ( alignof( ObjData ) % slot_size == size_type{ 0 } ) ) ||
                   ( slot_size > alignof( ObjData ) ) ) );
    }

    template< class ObjData >
    SIXTRL_FN constexpr bool ObjData_has_same_layout_as_c_api() SIXTRL_NOEXCEPT
    {
        return ObjDataStoreTraits< ObjData >::HasCApiLayout();
    }

    /* --------------------------------------------------------------------- */

    SIXTRL_FN SIXTRL_CXX_NAMESPACE::object_type_id_t
    ObjectTypeId_add_special_variant(
        SIXTRL_FN SIXTRL_CXX_NAMESPACE::object_type_id_t const obj_type_id,
        SIXTRL_FN SIXTRL_CXX_NAMESPACE::object_type_id_t const variant_flag )
    {
        using obj_type_id_t = SIXTRL_CXX_NAMESPACE::object_type_id_t;
        obj_type_id_t const VARIANT_FLAG_MASK = ( obj_type_id_t )0x0000ffff;

        return ( obj_type_id & VARIANT_FLAG_MASK ) |
            ( ( variant_flag & VARIANT_FLAG_MASK ) << 4u );
    }

    SIXTRL_FN bool ObjectTypeId_is_special_type_id(
        SIXTRL_CXX_NAMESPACE::object_type_id_t const obj_type_id )
    {
        using obj_type_id_t = SIXTRL_CXX_NAMESPACE::object_type_id_t;
        obj_type_id_t const SPECIAL_VARIANT = ( obj_type_id_t )0x0000ffff;

        return ( obj_type_id > SPECIAL_VARIANT );
    }

    SIXTRL_FN SIXTRL_CXX_NAMESPACE::object_type_id_t
    ObjectTypeId_get_base_type_id(
        SIXTRL_FN SIXTRL_CXX_NAMESPACE::object_type_id_t const obj_type_id )
    {
        using obj_type_id_t = SIXTRL_CXX_NAMESPACE::object_type_id_t;
        obj_type_id_t const MASK = ( obj_type_id_t )0x0000ffff;

        return obj_type_id & MASK;
    }

    SIXTRL_FN SIXTRL_CXX_NAMESPACE::object_type_id_t
    ObjectTypeId_get_variant_flag(
        SIXTRL_FN SIXTRL_CXX_NAMESPACE::object_type_id_t const obj_type_id )
    {
        using obj_type_id_t = SIXTRL_CXX_NAMESPACE::object_type_id_t;
        obj_type_id_t const MASK = ( obj_type_id_t )0x0000ffff;

        return ( obj_type_id >> 4u ) & MASK;
    }

    /* --------------------------------------------------------------------- */

    template< class ObjData >
    struct ObjDataStoreLayoutTraits
    {
        typedef ::NS(buffer_size_t) size_type;

        static SIXTRL_FN constexpr size_type GetNumDataPtrs()
        {
            return ::NS(buffer_size_t){ 0 };
        }

        static SIXTRL_FN size_type const* GetPtrSizesBegin()
        {
            return nullptr;
        }

        static SIXTRL_FN size_type const* GetPtrOffsetsBegin()
        {
            return nullptr;
        }

        static SIXTRL_FN SIXTRL_CXX_NAMESPACE::arch_status_t GetDataPtrsCounts(
            ObjData const& SIXTRL_RESTRICT_REF obj_data,
            size_type* SIXTRL_RESTRICT counts_begin,
            size_type* SIXTRL_RESTRICT counts_end )
        {
            ( void )obj_data;

            if( ( counts_begin != nullptr ) && ( counts_end != nullptr ) &&
                ( std::distance( counts_begin, counts_end ) >
                    std::ptrdiff_t{ 0 } ) )
            {
                std::fill( counts_begin, counts_end, size_type{ 0 } );
            }

            return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_SUCCESS;
        }
    };

    template< class ObjData > static SIXTRL_FN ::NS(buffer_size_t)
    ObjDataStore_get_num_required_data_ptrs(
        ObjData const& SIXTRL_RESTRICT_REF obj_data )
    {
        ( void )obj_data;
        return ObjDataStoreLayoutTraits< ObjData >::GetNumDataPtrs();
    }

    template< class ObjData > static SIXTRL_FN ::NS(buffer_size_t) const*
    ObjDataStore_get_dataptr_type_sizes_begin(
        ObjData const& SIXTRL_RESTRICT_REF obj_data )
    {
        ( void )obj_data;
        return ObjDataStoreLayoutTraits< ObjData >::GetPtrSizesBegin();
    }

    template< class ObjData > static SIXTRL_FN ::NS(buffer_size_t) const*
    ObjDataStore_get_dataptr_type_offsets_begin(
        ObjData const& SIXTRL_RESTRICT_REF obj_data )
    {
        ( void )obj_data;
        return ObjDataStoreLayoutTraits< ObjData >::GetPtrOffsetsBegin();
    }

    template< class ObjData > static SIXTRL_FN ::NS(arch_status_t)
    ObjDataStore_get_dataptr_counts(
        ObjData const& SIXTRL_RESTRICT_REF obj_data,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT counts_begin,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT counts_end )
    {
        ::NS(arch_status_t) status = ::NS(ARCH_STATUS_GENERAL_FAILURE);

        ::NS(buffer_size_t) const num_datptrs =
            ObjDataStore_get_num_required_data_ptrs( obj_data );

        if( ( num_datptrs == ::NS(buffer_size_t){ 0 } ) ||
            ( ( counts_begin != counts_end ) &&
              ( std::distance( counts_begin, counts_end ) >= static_cast<
                    std::ptrdiff_t >( num_datptrs ) ) ) )
        {
            status = ObjDataStoreLayoutTraits< ObjData >::GetDataPtrsCounts(
                obj_data, counts_begin, counts_end );
        }

        return status;
    }

    template< class ObjData >
    static SIXTRL_FN bool Obj_can_store_on_buffer(
        const ::NS(Buffer) *const SIXTRL_RESTRICT_REF buffer,
        ObjData const& SIXTRL_RESTRICT_REF obj_data,
        ::NS(object_type_id_t) const expected_base_object_type_id
            = SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_INVALID,
        ::NS(buffer_size_t) native_size = ::NS(buffer_size_t){ 0 },
        ::NS(buffer_size_t)* SIXTRL_RESTRICT dataptrs_counts_begin = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT dataptrs_counts_end   = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects  = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots    = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
    {
        namespace st = SIXTRL_CXX_NAMESPACE;

        bool can_be_stored = false;

        typedef ::NS(buffer_size_t)     size_t;
        typedef ::NS(arch_status_t)     status_t;
        typedef ::NS(object_type_id_t)  obj_type_id_t;
        typedef sixtrack_cxx::ObjDataStoreLayoutTraits< ObjData > obj_traits_t;

        status_t status = st::ARCH_STATUS_GENERAL_FAILURE;
        obj_type_id_t obj_type_id = st::OBJECT_TYPE_INVALID;

        if( sixtrack_cxx::ObjData_can_be_stored< ObjData >( buffer ) )
        {
            status = sixtrack_cxx::ObjDataStore_get_dataptr_counts(
                obj_data, dataptrs_counts_begin, dataptrs_counts_end );

            obj_type_id = sixtrack_cxx::ObjDataStoreTraits<
                ObjData >::ObjTypeId();
        }

        if( ( status == st::ARCH_STATUS_SUCCESS ) &&
            ( obj_type_id != st::OBJECT_TYPE_INVALID ) &&
            ( ( expected_base_object_type_id == st::OBJECT_TYPE_INVALID ) ||
              ( expected_base_object_type_id ==
                sixtrack_cxx::ObjectTypeId_get_base_type_id( obj_type_id ) ) ) )
        {
            if( native_size == size_t{ 0 } ) native_size = sizeof( obj_data );
            can_be_stored = ::NS(Buffer_can_add_object)( buffer, native_size,
                obj_traits_t::GetNumDataPtrs(), obj_traits_t::GetPtrSizesBegin(),
                    dataptrs_counts_begin, requ_num_objects, requ_num_slots,
                        requ_num_dataptrs );
        }

        return can_be_stored;
    }

    template< class ObjData >
    static SIXTRL_FN ::NS(Object) Obj_store_on_buffer(
        ::NS(Buffer)* SIXTRL_RESTRICT buffer,
        ObjData const& SIXTRL_RESTRICT_REF obj_data,
        ::NS(object_type_id_t) const expected_base_object_type_id
            = SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_INVALID,
        ::NS(buffer_size_t) native_size = ::NS(buffer_size_t){ 0 },
        ::NS(buffer_size_t)* SIXTRL_RESTRICT dataptrs_counts_begin = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT dataptrs_counts_end = nullptr )
    {
        namespace st = SIXTRL_CXX_NAMESPACE;

        ::NS(Object) obj_info;
        ::NS(Object_preset)( &obj_info );

        typedef ::NS(buffer_size_t) size_t;
        typedef ::NS(arch_status_t) status_t;
        typedef sixtrack_cxx::ObjDataStoreLayoutTraits< ObjData > obj_traits_t;
        typedef ::NS(object_type_id_t) obj_type_id_t;

        status_t status = st::ARCH_STATUS_GENERAL_FAILURE;
        obj_type_id_t obj_type_id = st::OBJECT_TYPE_INVALID;

        if( sixtrack_cxx::ObjData_can_be_stored< ObjData >( buffer ) )
        {
            status = sixtrack_cxx::ObjDataStore_get_dataptr_counts(
                obj_data, dataptrs_counts_begin, dataptrs_counts_end );

            obj_type_id = sixtrack_cxx::ObjDataStoreTraits<
                ObjData >::ObjTypeId();
        }

        if( ( status == st::ARCH_STATUS_SUCCESS ) &&
            ( obj_type_id != st::OBJECT_TYPE_INVALID ) &&
            ( ( expected_base_object_type_id == st::OBJECT_TYPE_INVALID ) ||
              ( expected_base_object_type_id ==
                sixtrack_cxx::ObjectTypeId_get_base_type_id( obj_type_id ) ) ) )
        {
            if( native_size == size_t{ 0 } ) native_size = sizeof( obj_data );
            obj_info = ::NS(Buffer_add_object)( buffer, &obj_data, native_size,
                obj_type_id, obj_traits_t::GetNumDataPtrs(),
                    obj_traits_t::GetPtrOffsetsBegin(),
                        obj_traits_t::GetPtrSizesBegin(),
                            dataptrs_counts_begin );
        }

        return obj_info;
    }

}

#endif /* SIXTRACKLIB_COMMON_INTERNAL_OBJ_STORE_TRAITS_CXX_HPP__ */
/* end: cxx/common/internal/obj_store_traits.hpp */
