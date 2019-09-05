#ifndef SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/srotation/be_srotation_traits.hpp"
#include "cxx/common/be/srotation/be_srotation_data.hpp"
#include "cxx/common/be/srotation/be_srotation.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeSRotationBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef BeSRotationTraits< BeObjData > srotation_traits_t;
        typedef typename srotation_traits_t::real_t real_t;
        typedef ::NS(BeSRotation) c_api_t;

        static SIXTRL_FN constexpr bool SupportsCObjectsStorage()
        {
            return sixtrack_cxx::ObjData_can_be_stored_on_cobjects_buffer<
                BeObjData >();
        }

        template< typename T >
        using can_store_cobj_t = std::enable_if<
            BeSRotationBase< BeObjData >::SupportsCObjectsStorage(), T >;

        static SIXTRL_FN constexpr bool HasCApiMemoryLayout()
        {
            return sixtrack_cxx::ObjDataStoreTraits< BeObjData >::HasCApiLayout();
        }

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeSRotationBase() : BeObjData()
        {
            this->cos_z = real_t{ 0.0 };    this->sin_z = real_t{ 0.0 };
        }

        SIXTRL_FN BeSRotationBase(
            real_t const& SIXTRL_RESTRICT_REF _cos_z,
            real_t const& SIXTRL_RESTRICT_REF _sin_z ) : BeObjData()
        {
            this->cos_z = _cos_z; this->sin_z = _sin_z;
        }

        SIXTRL_FN BeSRotationBase(
            BeSRotationBase< BeObjData > const& other) = default;

        SIXTRL_FN BeSRotationBase(
            BeSRotationBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeSRotationBase< BeObjData >& operator=(
            BeSRotationBase< BeObjData > const& other) = default;

        SIXTRL_FN BeSRotationBase< BeObjData >& operator=(
            BeSRotationBase< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeSRotationBase() = default;

        SIXTRL_FN void init()
        {
            this->cos_z = real_t{ 0.0 };    this->sin_z = real_t{ 0.0 };
        }

        SIXTRL_FN void init( real_t const& SIXTRL_RESTRICT_REF _cos_z,
            real_t const& SIXTRL_RESTRICT_REF _sin_z )
        {
            this->cos_z = _cos_z; this->sin_z = _sin_z;
        }

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN typename can_store_cobj_t< bool >::type
        CanStoreObjectOnBuffer(
            const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
        {
            using _this_t = sixtrack_cxx::BeSRotationBase< BeObjData >;

            _this_t temp;
            return sixtrack_cxx::Obj_can_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION, sizeof( _this_t ),
                    nullptr, nullptr, requ_num_objects, requ_num_slots,
                        requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeSRotationBase< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeSRotationBase< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeSRotationBase< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeSRotationBase< BeObjData >;
            _this_t temp;
            temp.init( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeSRotationBase< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeSRotationBase< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, this->beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeSRotationBase< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeSRotationBase< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeSRotationBase< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeSRotationBase< BeObjData >;
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

    template< class SRotationType >
    bool SRotation_can_store_on_buffer(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_objects = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_slots = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_dataptrs = nullptr )
    {
        return SRotationType::CanStoreOnBuffer( buffer,
            required_num_objects, required_num_slots, required_num_dataptrs );
    }

    template< class SRotationType >
    SRotationType* SRotation_new( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
    {
        return SRotationType::CreateNewObject( buffer );
    }

    template< class SRotationType, typename... Args >
    SRotationType* SRotation_add( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
    {
        return SRotationType::AddObject( buffer, std::forward< Args >( args )... );
    }

    template< class SRotationType >
    SRotationType const* SRotation_get_const(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return SRotationType::GetConstObj( buffer, index );
    }

    template< class SRotationType >
    SRotationType* SRotation_get( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return SRotationType::GetObj( buffer, index );
    }

    /* --------------------------------------------------------------------- */

    typedef BeSRotationBase< ::NS(BeSRotation) >            CBeSRotation;
    typedef BeSRotationBase< BeSRotationData< double > >    BeSRotation;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeSRotation = BeSRotationBase< BeSRotationData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_CXX_HPP__ */
/* end: */
