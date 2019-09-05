#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_EXACT_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_EXACT_CXX_HPP__

#include "sixtracklib/common/definitions.h"

#include "cxx/common/be/drift/be_drift_traits.hpp"
#include "cxx/common/be/drift/be_drift_exact_data.hpp"
#include "cxx/common/be/drift/be_drift_exact.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeDriftExactBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef ::NS(BeDriftExact) c_api_t;

        typedef sixtrack_cxx::BeDriftExactTraits< BeObjData > be_traits_t;
        typedef typename be_traits_t::real_t real_t;

        static SIXTRL_FN constexpr bool SupportsCObjectsStorage()
        {
            return sixtrack_cxx::ObjData_can_be_stored_on_cobjects_buffer<
                BeObjData >();
        }

        template< typename T >
        using can_store_cobj_t = std::enable_if<
            BeDriftExactBase< BeObjData >::SupportsCObjectsStorage(), T >;

        static SIXTRL_FN constexpr bool HasCApiMemoryLayout()
        {
            return sixtrack_cxx::ObjDataStoreTraits<
                BeObjData >::HasCApiLayout();
        }

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeDriftExactBase() : BeObjData()
        {
            this->length = real_t{ 0.0 };
        }

        SIXTRL_FN explicit BeDriftExactBase(
            real_t const& SIXTRL_RESTRICT_REF length ) : BeObjData()
        {
            this->length = length;
        }

        SIXTRL_FN BeDriftExactBase(
            BeDriftExactBase< BeObjData > const& other) = default;

        SIXTRL_FN BeDriftExactBase(
            BeDriftExactBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeDriftExactBase< BeObjData >& operator=(
            BeDriftExactBase< BeObjData > const& other) = default;

        SIXTRL_FN BeDriftExactBase< BeObjData >& operator=(
            BeDriftExactBase< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeDriftExactBase() = default;

        SIXTRL_FN void init()
        {
            this->length = real_t{ 0.0 };
        }

        SIXTRL_FN void init( real_t const& SIXTRL_RESTRICT_REF length )
        {
            this->length = length;
        }

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN typename can_store_cobj_t< bool >::type
        CanStoreObjectOnBuffer(
            const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
        {
            using _this_t = sixtrack_cxx::BeDriftExactBase< BeObjData >;
            _this_t temp;
            return sixtrack_cxx::Obj_can_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT,
                    sizeof( _this_t ), nullptr, nullptr, requ_num_objects,
                        requ_num_slots, requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftExactBase< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDriftExactBase< BeObjData >;

            _this_t temp;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                    SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT,
                        sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftExactBase< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeDriftExactBase< BeObjData >;
            _this_t temp( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                    SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT,
                        sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeDriftExactBase< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDriftExactBase< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, this->beData(),
                    SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT,
                        sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftExactBase< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDriftExactBase< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftExactBase< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDriftExactBase< BeObjData >;
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

    template< class DriftExactType >
    bool DriftExact_can_store_on_buffer(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_objects = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_slots = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_dataptrs = nullptr )
    {
        return DriftExactType::CanStoreOnBuffer( buffer,
            required_num_objects, required_num_slots, required_num_dataptrs );
    }

    template< class DriftExactType > DriftExactType* DriftExact_new(
        ::NS(Buffer)* SIXTRL_RESTRICT buffer )
    {
        return DriftExactType::CreateNewObject( buffer );
    }

    template< class DriftExactType, typename... Args >
    DriftExactType* DriftExact_add(
        ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
    {
        return DriftExactType::AddObject(
            buffer, std::forward< Args >( args )... );
    }

    template< class DriftExactType > DriftExactType const* DriftExact_get_const(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return DriftExactType::GetConstObj( buffer, index );
    }

    template< class DriftExactType > DriftExactType* DriftExact_get(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return DriftExactType::GetObj( buffer, index );
    }

    /* --------------------------------------------------------------------- */

    typedef BeDriftExactBase< ::NS(BeDriftExact) > CBeDriftExact;
    typedef BeDriftExactBase< BeDriftExactData< double > > BeDriftExact;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeDriftExact = BeDriftExactBase< BeDriftExactData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_EXACT_CXX_HPP__ */
/* end: */
