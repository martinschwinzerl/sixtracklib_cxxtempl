#ifndef SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__

#include <type_traits>

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/buffer.h"

#include "cxx/common/be/cavity/be_cavity_traits.hpp"
#include "cxx/common/be/cavity/be_cavity_data.hpp"
#include "cxx/common/be/cavity/be_cavity.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeCavityBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef ::NS(BeCavity) c_api_t;
        typedef sixtrack_cxx::BeCavityTraits< BeObjData >   cavity_traits_t;
        typedef typename cavity_traits_t::real_t real_t;

        static SIXTRL_FN constexpr bool SupportsCObjectsStorage()
        {
            return sixtrack_cxx::ObjData_can_be_stored_on_cobjects_buffer<
                BeObjData >();
        }

        template< typename T >
        using can_store_cobj_t = std::enable_if<
            BeCavityBase< BeObjData >::SupportsCObjectsStorage(), T >;

        static SIXTRL_FN constexpr bool HasCApiMemoryLayout()
        {
            return sixtrack_cxx::ObjDataStoreTraits< BeObjData >::HasCApiLayout();
        }

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeCavityBase() : BeObjData()
        {
            this->voltage   = real_t{ 0.0 };
            this->frequency = real_t{ 0.0 };
            this->lag       = real_t{ 0.0 };
        }

        SIXTRL_FN BeCavityBase( real_t const& SIXTRL_RESTRICT_REF _voltage,
            real_t const& SIXTRL_RESTRICT_REF _frequency,
            real_t const& SIXTRL_RESTRICT_REF _lag ) : BeObjData()
        {
            this->voltage   = _voltage;
            this->frequency = _frequency;
            this->lag       = _lag;
        }

        SIXTRL_FN BeCavityBase(
            BeCavityBase< BeObjData > const& other) = default;

        SIXTRL_FN BeCavityBase(
            BeCavityBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeCavityBase< BeObjData >& operator=(
            BeCavityBase< BeObjData > const& other) = default;

        SIXTRL_FN BeCavityBase< BeObjData >& operator=(
            BeCavityBase< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeCavityBase() = default;

        SIXTRL_FN void init()
        {
            this->voltage   = real_t{ 0.0 };
            this->frequency = real_t{ 0.0 };
            this->lag       = real_t{ 0.0 };
        }

        SIXTRL_FN void init(
            real_t const& SIXTRL_RESTRICT_REF _voltage,
            real_t const& SIXTRL_RESTRICT_REF _frequency,
            real_t const& SIXTRL_RESTRICT_REF _lag )
        {
            this->voltage   = _voltage;
            this->frequency = _frequency;
            this->lag       = _lag;
        }

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN typename can_store_cobj_t< bool >::type
        CanStoreObjectOnBuffer(
            const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
        {
            using _this_t = sixtrack_cxx::BeCavityBase< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::Obj_can_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY, sizeof( _this_t ),
                    nullptr, nullptr, requ_num_objects, requ_num_slots,
                        requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeCavityBase< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeCavityBase< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeCavityBase< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeCavityBase< BeObjData >;
            _this_t temp;
            temp.init( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeCavityBase< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeCavityBase< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, this->beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeCavityBase< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeCavityBase< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeCavityBase< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeCavityBase< BeObjData >;
            return ObjStore_get_ptr_obj_from_info< _this_t >(
                ::NS(Buffer_get_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* ----------------------------------------------------------------- */

        SIXTRL_FN be_data_t& beData() SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t& >( *this );
        }

        SIXTRL_FN be_data_t const& beData() const SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t const& >( *this );
        }

        SIXTRL_FN be_data_t* ptrBeData() SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t* >( this );
        }

        SIXTRL_FN be_data_t const* ptrBeData() const SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t const* >( this );
        }
    };

    template< class CavityType >
    bool Cavity_can_store_on_buffer(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_objects = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_slots = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_dataptrs = nullptr )
    {
        return CavityType::CanStoreOnBuffer( buffer,
            required_num_objects, required_num_slots, required_num_dataptrs );
    }

    template< class CavityType >
    CavityType* Cavity_new( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
    {
        return CavityType::CreateNewObject( buffer );
    }

    template< class CavityType, typename... Args >
    CavityType* Cavity_add( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
    {
        return CavityType::AddObject( buffer, std::forward< Args >( args )... );
    }

    template< class CavityType >
    CavityType const* Cavity_get_const(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return CavityType::GetConstObj( buffer, index );
    }

    template< class CavityType >
    CavityType* Cavity_get( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return CavityType::GetObj( buffer, index );
    }

    /* --------------------------------------------------------------------- */

    typedef BeCavityBase< ::NS(BeCavity) >          CBeCavity;
    typedef BeCavityBase< BeCavityData< double > >  BeCavity;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeCavity = BeCavityBase< BeCavityData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__ */
/* end: */
