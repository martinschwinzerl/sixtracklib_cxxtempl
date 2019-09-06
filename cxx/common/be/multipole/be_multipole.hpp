#ifndef SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/beam_elements_base.hpp"
#include "cxx/common/be/multipole/be_multipole_traits.hpp"
#include "cxx/common/be/multipole/be_multipole_data.hpp"
#include "cxx/common/be/multipole/be_multipole.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeMultipoleInterface :
        public sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeMultipole) >
    {
        public:

        typedef sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeMultipole) >
                _base_t;
        typedef typename _base_t::c_api_t c_api_t;

        template< typename T > using can_store_cobj_t =
            std::enable_if< _base_t::SupportsCObjectsStorage(), T >;

        typedef sixtrack_cxx::BeMultipoleTraits< BeObjData > be_traits_t;
        typedef typename be_traits_t::real_t  real_t;
        typedef typename be_traits_t::order_t order_t;

        static_assert( sixtrack_cxx::ObjData_get_num_data_ptrs< BeObjData >() ==
            ::NS(buffer_size_t){ 1 },
            "BeMultipole* implementations are required to have one dataptr" );

        static_assert( sixtrack_cxx::ObjData_dataptr_type_count_can_vary<
            BeObjData >(), "BeMultipole* implementations are expected to "
            "have a storage size dependent on the order parameter" );

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeMultipoleInterface()
        {
            this->order = order_t{ 0 };
            this->bal = nullptr;
            this->init();
        }

        SIXTRL_FN explicit BeMultipoleInterface(
            const c_api_t *const SIXTRL_RESTRICT mp )
        {
            this->order = order_t( 0 );
            this->bal = nullptr;

            if( mp != nullptr )
            {
                this->init( mp );
            }
            else
            {
                this->init();
            }
        }

        SIXTRL_FN explicit BeMultipoleInterface( order_t const _order,
            real_t* SIXTRL_RESTRICT ptr_to_ext_bal = nullptr )
        {
            this->order = order_t{ 0 };
            this->bal = nullptr;
            this->init( _order, ptr_to_ext_bal );
        }

        SIXTRL_FN BeMultipoleInterface( order_t const _order,
            real_t const& SIXTRL_RESTRICT_REF _length,
            real_t const& SIXTRL_RESTRICT_REF _hxl,
            real_t const& SIXTRL_RESTRICT_REF _hyl,
            real_t* SIXTRL_RESTRICT ptr_to_ext_bal = nullptr )
        {
            this->init( _order, _length, _hxl, _hyl, ptr_to_ext_bal );
        }

        SIXTRL_FN BeMultipoleInterface(
            BeMultipoleInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeMultipoleInterface(
            BeMultipoleInterface< BeObjData >&& other ) = default;

        SIXTRL_FN BeMultipoleInterface< BeObjData >& operator=(
            BeMultipoleInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeMultipoleInterface< BeObjData >& operator=(
            BeMultipoleInterface< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeMultipoleInterface() = default;

        SIXTRL_FN void init()
        {
            if( ( this->order == order_t{ 0 } ) && ( this->bal == nullptr ) )
            {
                this->length = real_t{ 0.0 };
                this->hxl    = real_t{ 0.0 };
                this->hyl    = real_t{ 0.0 };
            }
        }

        SIXTRL_FN void init( const c_api_t *const SIXTRL_RESTRICT mp )
        {
            if( ( mp != nullptr ) && ( this->bal == nullptr ) &&
                ( this->order != order_t{ 0 } ) )
            {
                this->order  = mp->order;
                this->length = real_t( mp->length );
                this->hxl    = real_t( mp->hxl );
                this->hyl    = real_t( mp->hyl );
            }
        }

        SIXTRL_FN void init( order_t const _order,
            real_t* SIXTRL_RESTRICT ptr_to_ext_bal = nullptr )
        {
            if( ( this->order == order_t{ 0 } ) && ( this->bal == nullptr ) )
            {
                this->order  = _order;
                this->length = real_t{ 0.0 };
                this->hxl    = real_t{ 0.0 };
                this->hyl    = real_t{ 0.0 };
                this->bal    = ptr_to_ext_bal;
            }
        }

        SIXTRL_FN void init( order_t const _order,
            real_t const& SIXTRL_RESTRICT_REF _length,
            real_t const& SIXTRL_RESTRICT_REF _hxl,
            real_t const& SIXTRL_RESTRICT_REF _hyl,
            real_t* SIXTRL_RESTRICT ptr_to_ext_bal = nullptr )
        {
            if( ( this->order == order_t{ 0 } ) && ( this->bal == nullptr ) )
            {
                this->order  = _order;
                this->length = _length;
                this->hxl    = _hxl;
                this->hyl    = _hyl;
                this->bal    = ptr_to_ext_bal;
            }
        }

        /* ----------------------------------------------------------------- */

        template< typename Iter >
        SIXTRL_FN ::NS(arch_status_t) copyBalValues(
            order_t const other_order, Iter other_begin )
        {
            ::NS(arch_status_t) status = ::NS(ARCH_STATUS_GENERAL_FAILURE);

            if( ( this->order == other_order ) &&
                ( this->bal != nullptr ) )
            {
                real_t* out_it = this->bal;

                Iter in_it  = other_begin;
                Iter in_end = other_begin;
                std::advance( in_end, this->getNumBalParameters() );

                status = ::NS(ARCH_STATUS_SUCCESS);

                for( ; in_it != in_end ; ++in_it, ++out_it )
                {
                    *out_it = real_t( *in_it );
                }
            }

            return status;
        }

        /* ----------------------------------------------------------------- */

        SIXTRL_FN real_t const& operator[](
            order_t const index ) const SIXTRL_NOEXCEPT
        {
            SIXTRL_ASSERT( this->getNumBalParameters() > index );
            SIXTRL_ASSERT( this->bal != nullptr );
            return this->bal[ index ];
        }

        SIXTRL_FN real_t& operator[]( order_t const index ) SIXTRL_NOEXCEPT
        {
            SIXTRL_ASSERT( this->getNumBalParameters() > index );
            SIXTRL_ASSERT( this->bal != nullptr );
            return this->bal[ index ];
        }

        SIXTRL_FN real_t const& getConstBal(
            order_t const index ) const SIXTRL_NOEXCEPT
        {
            SIXTRL_ASSERT( this->getNumBalParameters() > index );
            SIXTRL_ASSERT( this->bal != nullptr );
            return this->bal[ index ];
        }

        SIXTRL_FN real_t& getBal( order_t const index ) SIXTRL_NOEXCEPT
        {
            SIXTRL_ASSERT( this->getNumBalParameters() > index );
            SIXTRL_ASSERT( this->bal != nullptr );
            return this->bal[ index ];
        }

        SIXTRL_FN order_t getOrder() const SIXTRL_NOEXCEPT
        { return this->order; }

        SIXTRL_FN order_t getNumBalParameters() const SIXTRL_NOEXCEPT
        {
            return order_t{ 2 } * ( this->order + order_t{ 1 } );
        }

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN typename can_store_cobj_t< bool >::type
        CanStoreObjectOnBuffer(
            const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
            order_t const order,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
        {
            namespace  st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeMultipoleInterface< BeObjData >;
            _this_t temp( order, nullptr );

            return sixtrack_cxx::Obj_can_store_on_buffer< BeObjData >( buffer,
                st::OBJECT_TYPE_MULTIPOLE, temp.ptrBeData(), sizeof( _this_t ),
                    requ_num_objects, requ_num_slots, requ_num_dataptrs );
        }

        static SIXTRL_FN typename can_store_cobj_t< BeMultipoleInterface<
            BeObjData >* >::type CreateNewObject(
                ::NS(Buffer)* SIXTRL_RESTRICT buffer, order_t const order )
        {
            namespace  st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeMultipoleInterface< BeObjData >;
            _this_t temp( order, nullptr );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                    st::OBJECT_TYPE_MULTIPOLE, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args > static SIXTRL_FN
        typename can_store_cobj_t< BeMultipoleInterface< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            namespace  st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeMultipoleInterface< BeObjData >;
            _this_t temp( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                    st::OBJECT_TYPE_MULTIPOLE, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeMultipoleInterface< BeObjData
            >* >::type storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            namespace  st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeMultipoleInterface< BeObjData >;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                    st::OBJECT_TYPE_MULTIPOLE, this->ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN typename can_store_cobj_t< BeMultipoleInterface<
            BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeMultipoleInterface< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeMultipoleInterface< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeMultipoleInterface< BeObjData >;
            return ObjStore_get_ptr_obj_from_info< _this_t >(
                ::NS(Buffer_get_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }
    };

    template< class BeObjData >
    typename BeMultipoleInterface< BeObjData >::order_t Multipole_get_order(
        BeMultipoleInterface< BeObjData > const& SIXTRL_RESTRICT_REF mp )
    {
        return mp.getOrder();
    }

    template< class BeObjData >
    typename BeMultipoleInterface< BeObjData >::order_t
    Multipole_get_num_bal_parameters(
        BeMultipoleInterface< BeObjData > const& SIXTRL_RESTRICT_REF mp )
    {
        return mp.getNumBalParameters();
    }

    template< class BeObjData >
    typename BeMultipoleInterface< BeObjData >::real_t const&
    Multipole_get_const_bal(
        BeMultipoleInterface< BeObjData > const& SIXTRL_RESTRICT_REF mp,
        typename BeMultipoleInterface< BeObjData >::order_t const bal_index )
    {
        return mp[ bal_index ];
    }

    template< class BeObjData >
    typename BeMultipoleInterface< BeObjData >::real_t& Multipole_get_bal(
        BeMultipoleInterface< BeObjData >& SIXTRL_RESTRICT_REF mp,
        typename BeMultipoleInterface< BeObjData >::order_t const bal_index )
    {
        return mp[ bal_index ];
    }

    /* --------------------------------------------------------------------- */

    typedef BeMultipoleInterface< ::NS(BeMultipole) > CBeMultipole;
    typedef BeMultipoleInterface< BeMultipoleData< double > > BeMultipole;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign(),
        std::size_t OAlign = sixtrack_cxx::TypeStoreTraits<
            ::NS(be_multipole_order_t) >::StorageAlign() >
    using TBeMultipole = BeMultipoleInterface< BeMultipoleData<
        R, RAlign, OAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_CXX_HPP__ */
/* end: */
