#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_CXX_HPP__

#include "sixtracklib/common/definitions.h"

#include "cxx/common/be/drift/be_drift_traits.hpp"
#include "cxx/common/be/drift/be_drift_data.hpp"
#include "cxx/common/be/drift/be_drift.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeDriftBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef ::NS(BeDrift) c_api_t;

        typedef sixtrack_cxx::BeDriftTraits< BeObjData > be_traits_t;
        typedef typename be_traits_t::real_t real_t;

        static SIXTRL_FN constexpr bool SupportsCObjectsStorage()
        {
            return sixtrack_cxx::ObjData_can_be_stored_on_cobjects_buffer<
                BeObjData >();
        }

        template< typename T >
        using can_store_cobj_t = std::enable_if<
            BeDriftBase< BeObjData >::SupportsCObjectsStorage(), T >;

        static SIXTRL_FN constexpr bool HasCApiMemoryLayout()
        {
            return sixtrack_cxx::ObjDataStoreTraits<
                BeObjData >::HasCApiLayout();
        }

        /* ----------------------------------------------------------------- */

        template< typename... Args >
        SIXTRL_FN BeDriftBase( Args&&... args ) : BeObjData()
        {
            sixtrack_cxx::BeDriftData_init(
                this->beData(), std::forward< Args >( args )... );
        }

        SIXTRL_FN BeDriftBase( BeDriftBase< BeObjData > const& other) = default;
        SIXTRL_FN BeDriftBase( BeDriftBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeDriftBase< BeObjData >& operator=(
            BeDriftBase< BeObjData > const& other) = default;

        SIXTRL_FN BeDriftBase< BeObjData >& operator=(
            BeDriftBase< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeDriftBase() = default;

        template< typename... Args >
        SIXTRL_FN void init( Args&&... args )
        {
            sixtrack_cxx::BeDriftData_init(
                this->beData(), std::forward< Args >( args )... );
        }

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN typename can_store_cobj_t< bool >::type
        CanStoreObjectOnBuffer(
            const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
        {
            BeDriftBase< BeObjData > temp;
            return sixtrack_cxx::Obj_can_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT, requ_num_objects,
                    requ_num_slots, requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftBase< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDriftBase< BeObjData >;

            _this_t temp;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftBase< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeDriftBase< BeObjData >;
            _this_t temp( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                    SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeDriftBase< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDriftBase< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, this->beData(),
                    SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftBase< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDriftBase< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftBase< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDriftBase< BeObjData >;
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

    /* --------------------------------------------------------------------- */

    typedef BeDriftBase< ::NS(BeDrift) > CBeDrift;
    typedef BeDriftBase< BeDriftData< double > > BeDrift;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeDrift = BeDriftBase< BeDriftData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_CXX_HPP__ */
/* end: */
