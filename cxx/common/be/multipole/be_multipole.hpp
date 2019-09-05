#ifndef SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/multipole/be_multipole_traits.hpp"
#include "cxx/common/be/multipole/be_multipole_data.hpp"
#include "cxx/common/be/multipole/be_multipole.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeMultipoleBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef sixtrack_cxx::BeMultipoleTraits< BeObjData > mp_traits_t;
        typedef typename mp_traits_t::real_t real_t;
        typedef typename mp_traits_t::order_t order_t;
        typedef ::NS(BeMultipole) c_api_t;

        static SIXTRL_FN constexpr bool SupportsCObjectsStorage()
        {
            return sixtrack_cxx::ObjData_can_be_stored_on_cobjects_buffer<
                BeObjData >();
        }

        template< typename T >
        using can_store_cobj_t = std::enable_if<
            BeMultipoleBase< BeObjData >::SupportsCObjectsStorage(), T >;

        static SIXTRL_FN constexpr bool HasCApiMemoryLayout()
        {
            return sixtrack_cxx::ObjDataStoreTraits<
                BeObjData >::HasCApiLayout();
        }

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeMultipoleBase() : BeObjData()
        {
            this->order  = order_t{ 0 };
            this->length = real_t{ 0.0 };
            this->hxl    = real_t{ 0.0 };
            this->hyl    = real_t{ 0.0 };
            this->bal    = nullptr;
        }

        SIXTRL_FN explicit BeMultipoleBase( order_t const _order,
            real_t* SIXTRL_RESTRICT ptr_to_ext_bal = nullptr ) : BeObjData()
        {
            this->order  = _order;
            this->length = real_t{ 0.0 };
            this->hxl    = real_t{ 0.0 };
            this->hyl    = real_t{ 0.0 };
            this->bal    = ptr_to_ext_bal;
        }

        SIXTRL_FN BeMultipoleBase( order_t const _order,
            real_t const& SIXTRL_RESTRICT_REF _length,
            real_t const& SIXTRL_RESTRICT_REF _hxl,
            real_t const& SIXTRL_RESTRICT_REF _hyl,
            real_t* SIXTRL_RESTRICT ptr_to_ext_bal = nullptr ) : BeObjData()
        {
            this->order  = _order;
            this->length = _length;
            this->hxl    = _hxl;
            this->hyl    = _hyl;
            this->bal    = ptr_to_ext_bal;
        }

        SIXTRL_FN BeMultipoleBase(
            BeMultipoleBase< BeObjData > const& other) = default;

        SIXTRL_FN BeMultipoleBase(
            BeMultipoleBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeMultipoleBase< BeObjData >& operator=(
            BeMultipoleBase< BeObjData > const& other) = default;

        SIXTRL_FN BeMultipoleBase< BeObjData >& operator=(
            BeMultipoleBase< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeMultipoleBase() = default;

        SIXTRL_FN void init()
        {
            this->order  = order_t{ 0 };
            this->length = real_t{ 0.0 };
            this->hxl    = real_t{ 0.0 };
            this->hyl    = real_t{ 0.0 };
            this->bal    = nullptr;
        }

        SIXTRL_FN void init( order_t const _order,
            real_t* SIXTRL_RESTRICT ptr_to_ext_bal = nullptr )
        {
            this->order = _order;
            this->length = real_t{ 0.0 };
            this->hxl    = real_t{ 0.0 };
            this->hyl    = real_t{ 0.0 };
            this->bal    = ptr_to_ext_bal;
        }

        SIXTRL_FN void init( order_t const _order,
            real_t const& SIXTRL_RESTRICT_REF _length,
            real_t const& SIXTRL_RESTRICT_REF _hxl,
            real_t const& SIXTRL_RESTRICT_REF _hyl,
            real_t* SIXTRL_RESTRICT ptr_to_ext_bal = nullptr )
        {
            this->order  = _order;
            this->length = _length;
            this->hxl    = _hxl;
            this->hyl    = _hyl;
            this->bal    = ptr_to_ext_bal;
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
                std::advance( in_end, this->getNumParameters() );

                status = ::NS(ARCH_STATUS_SUCCESS);

                for( ; in_it != in_end ; ++in_it, ++out_it )
                {
                    *out_it = real_t( *in_it );
                }
            }

            return status;
        }

        /* ----------------------------------------------------------------- */

        real_t const& operator[]( order_t const index ) const SIXTRL_NOEXCEPT
        {
            SIXTRL_ASSERT( this->getNumParameters() > index );
            SIXTRL_ASSERT( this->bal != nullptr );

            return this->bal[ index ];
        }

        real_t& operator[]( order_t const index ) SIXTRL_NOEXCEPT
        {
            SIXTRL_ASSERT( this->getNumParameters() > index );
            SIXTRL_ASSERT( this->bal != nullptr );

            return this->bal[ index ];
        }

        real_t const& getBal( order_t const index ) const SIXTRL_NOEXCEPT
        {
            SIXTRL_ASSERT( this->getNumParameters() > index );
            SIXTRL_ASSERT( this->bal != nullptr );

            return this->bal[ index ];
        }

        real_t& getBal( order_t const index ) SIXTRL_NOEXCEPT
        {
            SIXTRL_ASSERT( this->getNumParameters() > index );
            SIXTRL_ASSERT( this->bal != nullptr );

            return this->bal[ index ];
        }

        /* TODO: Add missing calculation of inverse factorial factors ->
         * this is an interesting test for the generic type! */

        /*
        real_t const& knl( order_t const index ) const SIXTRL_NOEXCEPT
        {
            namespace stcxx = sixtrack_cxx;
            order_t const knl_index = static_cast< order_t >( 2u ) * index;
            return stcxx::BeMultipoleData_get_const_bal( *this, knl_index );
        }

        real_t const& ksl( order_t const index ) const SIXTRL_NOEXCEPT
        {
            namespace stcxx = sixtrack_cxx;
            order_t const ksl_index = static_cast< order_t >( 2u ) * index +
                static_cast< order_t >( 1u );
            return stcxx::BeMultipoleData_get_const_bal( *this, ksl_index );
        }

        real_t& knl( order_t const index ) SIXTRL_NOEXCEPT
        {
            order_t const knl_index = static_cast< order_t >( 2u ) * index;
            return sixtrack_cxx::BeMultipoleData_get_bal( *this, knl_index );
        }

        real_t& ksl( order_t const index ) SIXTRL_NOEXCEPT
        {
            order_t const ksl_index = static_cast< order_t >( 2u ) * index +
                static_cast< order_t >( 1u );
            return sixtrack_cxx::BeMultipoleData_get_bal( *this, ksl_index );
        }
        */

        order_t getOrder() const SIXTRL_NOEXCEPT
        {
            return this->order;
        }

        order_t getNumParameters() const SIXTRL_NOEXCEPT
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
            using  size_t = ::NS(buffer_size_t);
            using _data_t = BeObjData;
            using _this_t = sixtrack_cxx::BeMultipoleBase< _data_t >;
            using _traits_t = sixtrack_cxx::ObjDataStoreLayoutTraits< _data_t >;

            constexpr size_t NUM_DATAPTRS = _traits_t::GetNumDataPtrs();
            size_t COUNTS[ NUM_DATAPTRS ];
            std::fill( &COUNTS[ 0 ], &COUNTS[ NUM_DATAPTRS ], size_t{ 0 } );

            _this_t temp( order, nullptr );

            return sixtrack_cxx::Obj_can_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE, sizeof( _this_t ),
                &COUNTS[ 0 ], &COUNTS[ NUM_DATAPTRS ], requ_num_objects,
                    requ_num_slots, requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeMultipoleBase< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
            order_t const order )
        {
            using  size_t = ::NS(buffer_size_t);
            using _data_t = BeObjData;
            using _this_t = sixtrack_cxx::BeMultipoleBase< _data_t >;
            using _traits_t = sixtrack_cxx::ObjDataStoreLayoutTraits< _data_t >;

            constexpr size_t NUM_DATAPTRS = _traits_t::GetNumDataPtrs();
            size_t COUNTS[ NUM_DATAPTRS ];
            std::fill( &COUNTS[ 0 ], &COUNTS[ NUM_DATAPTRS ], size_t{ 0 } );

            _this_t temp( order, nullptr );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE,
                sizeof( _this_t ), &COUNTS[ 0 ], &COUNTS[ NUM_DATAPTRS ] ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args > static SIXTRL_FN
        typename can_store_cobj_t< BeMultipoleBase< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using  size_t = ::NS(buffer_size_t);
            using _data_t = BeObjData;
            using _this_t = sixtrack_cxx::BeMultipoleBase< _data_t >;
            using _traits_t = sixtrack_cxx::ObjDataStoreLayoutTraits< _data_t >;

            constexpr size_t NUM_DATAPTRS = _traits_t::GetNumDataPtrs();
            size_t COUNTS[ NUM_DATAPTRS ];
            std::fill( &COUNTS[ 0 ], &COUNTS[ NUM_DATAPTRS ], size_t{ 0 } );

            _this_t temp( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                    SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE,
                    sizeof( _this_t ), &COUNTS[ 0 ], &COUNTS[ NUM_DATAPTRS ] ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeMultipoleBase< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using  size_t = ::NS(buffer_size_t);
            using _data_t = BeObjData;
            using _this_t = sixtrack_cxx::BeMultipoleBase< _data_t >;
            using _traits_t = sixtrack_cxx::ObjDataStoreLayoutTraits< _data_t >;

            constexpr size_t NUM_DATAPTRS = _traits_t::GetNumDataPtrs();
            size_t COUNTS[ NUM_DATAPTRS ];
            std::fill( &COUNTS[ 0 ], &COUNTS[ NUM_DATAPTRS ], size_t{ 0 } );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, this->beData(),
                    SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE,
                    sizeof( _this_t ), &COUNTS[ 0 ], &COUNTS[ NUM_DATAPTRS ] ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeMultipoleBase< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeMultipoleBase< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeMultipoleBase< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeMultipoleBase< BeObjData >;
            return ObjStore_get_ptr_obj_from_info< _this_t >(
                ::NS(Buffer_get_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* ----------------------------------------------------------------- */

        SIXTRL_FN be_data_t* ptrBeData() SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t* >( this );
        }

        SIXTRL_FN be_data_t const* ptrBeData() const SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t const* >( this );
        }

        SIXTRL_FN be_data_t& beData() SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t& >( *this );
        }

        SIXTRL_FN be_data_t const& beData() const SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t const& >( *this );
        }
    };

    template< class MultiPoleType >
    bool MultiPole_can_store_on_buffer(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_objects = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_slots = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_dataptrs = nullptr )
    {
        return MultiPoleType::CanStoreOnBuffer( buffer,
            required_num_objects, required_num_slots, required_num_dataptrs );
    }

    template< class MultiPoleType >
    MultiPoleType* MultiPole_new( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
    {
        return MultiPoleType::CreateNewObject( buffer );
    }

    template< class MultiPoleType, typename... Args >
    MultiPoleType* MultiPole_add( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
    {
        return MultiPoleType::AddObject( buffer, std::forward< Args >( args )... );
    }

    template< class MultiPoleType >
    MultiPoleType const* MultiPole_get_const(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return MultiPoleType::GetConstObj( buffer, index );
    }

    template< class MultiPoleType >
    MultiPoleType* MultiPole_get( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return MultiPoleType::GetObj( buffer, index );
    }

    /* --------------------------------------------------------------------- */

    template< class BeObjData >
    typename BeMultipoleBase< BeObjData >::order_t Multipole_get_order(
        BeMultipoleBase< BeObjData > const& SIXTRL_RESTRICT_REF mp )
    {
        return mp.getOrder();
    }

    template< class BeObjData >
    typename BeMultipoleBase< BeObjData >::order_t
    Multipole_get_num_bal_parameters(
        BeMultipoleBase< BeObjData > const& SIXTRL_RESTRICT_REF mp )
    {
        return mp.getNumParameters();
    }

    template< class BeObjData >
    typename BeMultipoleBase< BeObjData >::real_t const&
    Multipole_get_const_bal(
        BeMultipoleBase< BeObjData > const& SIXTRL_RESTRICT_REF mp,
        typename BeMultipoleBase< BeObjData >::order_t const bal_index )
    {
        return mp[ bal_index ];
    }

    template< class BeObjData >
    typename BeMultipoleBase< BeObjData >::real_t& Multipole_get_bal(
        BeMultipoleBase< BeObjData >& SIXTRL_RESTRICT_REF mp,
        typename BeMultipoleBase< BeObjData >::order_t const bal_index )
    {
        return mp[ bal_index ];
    }

    /* --------------------------------------------------------------------- */

    typedef BeMultipoleBase< ::NS(BeMultipole) >            CBeMultipole;
    typedef BeMultipoleBase< BeMultipoleData< double > >    BeMultipole;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign(),
        std::size_t OAlign = sixtrack_cxx::TypeStoreTraits<
            ::NS(be_multipole_order_t) >::StorageAlign() >
    using TBeMultipole = BeMultipoleBase< BeMultipoleData< R, RAlign, OAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_CXX_HPP__ */
/* end: */
