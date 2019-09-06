#ifndef SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/beam_elements_base.hpp"
#include "cxx/common/be/srotation/be_srotation_traits.hpp"
#include "cxx/common/be/srotation/be_srotation_data.hpp"
#include "cxx/common/be/srotation/be_srotation.h"

namespace sixtrack_cxx
{
    template< class BeObjData > class BeSRotationInterface :
        public sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeSRotation) >
    {
        public:

        typedef sixtrack_cxx::BeamElementBase< BeObjData,
            ::NS(BeSRotation) > _base_t;
        typedef typename _base_t::c_api_t c_api_t;

        template< typename T > using can_store_cobj_t =
            std::enable_if< _base_t::SupportsCObjectsStorage(), T >;

        typedef sixtrack_cxx::BeSRotationTraits< BeObjData > be_traits_t;
        typedef typename be_traits_t::real_t real_t;

        static_assert( !sixtrack_cxx::ObjData_has_data_ptrs< BeObjData >(),
            "BeSRotation* implementations aren't supposed to have dataptrs" );

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeSRotationInterface() { this->init(); }

        SIXTRL_FN explicit BeSRotationInterface(
            const c_api_t *const SIXTRL_RESTRICT srot ) { this->init( srot ); }

        SIXTRL_FN explicit BeSRotationInterface(
            real_t const& SIXTRL_RESTRICT_REF angle ) { this->init( angle ); }

        SIXTRL_FN BeSRotationInterface(
            real_t const& SIXTRL_RESTRICT_REF _cos_z,
            real_t const& SIXTRL_RESTRICT_REF _sin_z )
        {
            this->init( _cos_z, _sin_z );
        }

        SIXTRL_FN BeSRotationInterface(
            BeSRotationInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeSRotationInterface(
            BeSRotationInterface< BeObjData >&& other ) = default;

        SIXTRL_FN BeSRotationInterface< BeObjData >& operator=(
            BeSRotationInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeSRotationInterface< BeObjData >& operator=(
            BeSRotationInterface< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeSRotationInterface() = default;

        SIXTRL_FN void init()
        {
            this->cos_z = real_t{ 1.0 };    this->sin_z = real_t{ 0.0 };
        }

        SIXTRL_FN void init( real_t const& SIXTRL_RESTRICT_REF angle )
        {
            using std::cos;
            using std::sin;

            this->cos_z = cos( angle );
            this->sin_z = sin( angle );
        }

        SIXTRL_FN void init( const c_api_t *const SIXTRL_RESTRICT srot )
        {
            if( srot != nullptr )
            {
                this->cos_z = real_t( srot->cos_z );
                this->sin_z = real_t( srot->sin_z );
            }
            else this->init();
        }

        SIXTRL_FN void init( real_t const& SIXTRL_RESTRICT_REF _cos_z,
            real_t const& SIXTRL_RESTRICT_REF _sin_z )
        {
            this->cos_z = _cos_z;
            this->sin_z = _sin_z;
        }

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN typename can_store_cobj_t< bool >::type
        CanStoreObjectOnBuffer(
            const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
        {
            using _this_t = sixtrack_cxx::BeSRotationInterface< BeObjData >;
            return sixtrack_cxx::Obj_can_store_on_buffer< BeObjData >( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION, sizeof( _this_t ),
                    requ_num_objects, requ_num_slots, requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeSRotationInterface< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeSRotationInterface< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args > static SIXTRL_FN
        typename can_store_cobj_t< BeSRotationInterface< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            namespace st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeSRotationInterface< BeObjData >;
            _this_t temp( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                    st::OBJECT_TYPE_SROTATION, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t<
            BeSRotationInterface< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            namespace st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeSRotationInterface< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, this->ptrBeData(),
                    st::OBJECT_TYPE_SROTATION, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN typename can_store_cobj_t<
            BeSRotationInterface< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeSRotationInterface< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN typename can_store_cobj_t<
            BeSRotationInterface< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeSRotationInterface< BeObjData >;
            return ObjStore_get_ptr_obj_from_info< _this_t >(
                ::NS(Buffer_get_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }
    };

    typedef BeSRotationInterface< ::NS(BeSRotation) >            CBeSRotation;
    typedef BeSRotationInterface< BeSRotationData< double > >    BeSRotation;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeSRotation = BeSRotationInterface< BeSRotationData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_CXX_HPP__ */
/* end: */
