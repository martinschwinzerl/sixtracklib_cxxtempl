#ifndef SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__

#include <type_traits>

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/buffer.h"

#include "cxx/common/be/beam_elements_base.hpp"
#include "cxx/common/be/cavity/be_cavity_traits.hpp"
#include "cxx/common/be/cavity/be_cavity_data.hpp"
#include "cxx/common/be/cavity/be_cavity.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeCavityInterface :
        public sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeCavity) >
    {
        public:

        typedef sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeCavity) > _base_t;
        typedef typename _base_t::c_api_t c_api_t;

        template< typename T > using can_store_cobj_t =
            std::enable_if< _base_t::SupportsCObjectsStorage(), T >;

        typedef sixtrack_cxx::BeCavityTraits< BeObjData > be_traits_t;
        typedef typename be_traits_t::real_t real_t;

        static_assert( !sixtrack_cxx::ObjData_has_data_ptrs< BeObjData >(),
            "BeCavity* implementations are not supposed to have dataptrs" );

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeCavityInterface() { this->init(); }

        SIXTRL_FN explicit BeCavityInterface( const c_api_t *const
            SIXTRL_RESTRICT cavity ) { this->init( cavity ); }

        SIXTRL_FN BeCavityInterface( real_t const& SIXTRL_RESTRICT_REF _voltage,
            real_t const& SIXTRL_RESTRICT_REF _frequency,
            real_t const& SIXTRL_RESTRICT_REF _lag )
        {
            this->init( _voltage, _frequency, _lag );
        }

        SIXTRL_FN BeCavityInterface(
            BeCavityInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeCavityInterface(
            BeCavityInterface< BeObjData >&& other ) = default;

        SIXTRL_FN BeCavityInterface< BeObjData >& operator=(
            BeCavityInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeCavityInterface< BeObjData >& operator=(
            BeCavityInterface< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeCavityInterface() = default;

        SIXTRL_FN void init()
        {
            this->voltage   = real_t{ 0.0 };
            this->frequency = real_t{ 0.0 };
            this->lag       = real_t{ 0.0 };
        }

        SIXTRL_FN void init( const c_api_t *const SIXTRL_RESTRICT cavity )
        {
            if( cavity != nullptr )
            {
                this->voltage   = real_t( cavity->voltage );
                this->frequency = real_t( cavity->frequency );
                this->lag       = real_t( cavity->lag );
            }
            else this->init();
        }

        SIXTRL_FN void init( real_t const& SIXTRL_RESTRICT_REF _voltage,
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
            using _this_t = sixtrack_cxx::BeCavityInterface< BeObjData >;
            return sixtrack_cxx::Obj_can_store_on_buffer< BeObjData >( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY, nullptr,
                sizeof( _this_t ), requ_num_objects, requ_num_slots,
                    requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeCavityInterface< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeCavityInterface< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeCavityInterface< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeCavityInterface< BeObjData >;
            _this_t temp( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeCavityInterface< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeCavityInterface< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY, this->ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeCavityInterface< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeCavityInterface< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeCavityInterface< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeCavityInterface< BeObjData >;
            return ObjStore_get_ptr_obj_from_info< _this_t >(
                ::NS(Buffer_get_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }
    };

    typedef BeCavityInterface< ::NS(BeCavity) > CBeCavity;
    typedef BeCavityInterface< BeCavityData< double > > BeCavity;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeCavity = BeCavityInterface< BeCavityData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__ */
/* end: */
