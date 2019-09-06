#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_EXACT_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_EXACT_CXX_HPP__

#include "sixtracklib/common/definitions.h"

#include "cxx/common/be/beam_elements_base.hpp"
#include "cxx/common/be/drift/be_drift_traits.hpp"
#include "cxx/common/be/drift/be_drift_exact_data.hpp"
#include "cxx/common/be/drift/be_drift_exact.h"

namespace sixtrack_cxx
{
    template< class BeObjData > class BeDriftExactInterface :
        public sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeDriftExact) >
    {
        public:

        typedef sixtrack_cxx::BeamElementBase< BeObjData,
            ::NS(BeDriftExact) > _base_t;
        typedef typename _base_t::c_api_t c_api_t;

        template< typename T > using can_store_cobj_t =
            std::enable_if< _base_t::SupportsCObjectsStorage(), T >;

        typedef sixtrack_cxx::BeDriftExactTraits< BeObjData > be_traits_t;
        typedef typename be_traits_t::real_t real_t;

        static_assert( !sixtrack_cxx::ObjData_has_data_ptrs< BeObjData >(),
            "BeDriftExact* implementations are not supposed to have dataptrs" );

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeDriftExactInterface() { this->init(); }

        SIXTRL_FN explicit BeDriftExactInterface(
            const c_api_t *const SIXTRL_RESTRICT drift ) { this->init( drift ); }

        SIXTRL_FN explicit BeDriftExactInterface(
            real_t const& SIXTRL_RESTRICT_REF length ) { this->init( length ); }

        SIXTRL_FN BeDriftExactInterface(
            BeDriftExactInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeDriftExactInterface(
            BeDriftExactInterface< BeObjData >&& other ) = default;

        SIXTRL_FN BeDriftExactInterface< BeObjData >& operator=(
            BeDriftExactInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeDriftExactInterface< BeObjData >& operator=(
            BeDriftExactInterface< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeDriftExactInterface() = default;

        SIXTRL_FN void init() { this->length = real_t{ 0.0 }; }

        SIXTRL_FN void init( const c_api_t *const SIXTRL_RESTRICT drift )
        {
            if( drift != nullptr )
            {
                this->length = real_t( drift->length );
            }
            else this->init();
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
            using _this_t = sixtrack_cxx::BeDriftExactInterface< BeObjData >;
            return sixtrack_cxx::Obj_can_store_on_buffer< BeObjData >( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT, nullptr,
                    sizeof( _this_t ), requ_num_objects, requ_num_slots,
                        requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftExactInterface< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDriftExactInterface< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftExactInterface< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeDriftExactInterface< BeObjData >;
            _this_t temp( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeDriftExactInterface< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDriftExactInterface< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT, this->ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftExactInterface< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDriftExactInterface< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftExactInterface< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDriftExactInterface< BeObjData >;
            return ObjStore_get_ptr_obj_from_info< _this_t >(
                ::NS(Buffer_get_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }
    };

    typedef BeDriftExactInterface< ::NS(BeDriftExact) > CBeDriftExact;
    typedef BeDriftExactInterface< BeDriftExactData< double > > BeDriftExact;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeDriftExact = BeDriftExactInterface< BeDriftExactData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_EXACT_CXX_HPP__ */
/* end: */
