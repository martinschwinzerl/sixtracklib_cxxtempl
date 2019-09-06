#ifndef SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_CXX_HPP__

#include "sixtracklib/common/definitions.h"

#include "cxx/common/be/beam_elements_base.hpp"
#include "cxx/common/be/xyshift/be_xyshift_traits.hpp"
#include "cxx/common/be/xyshift/be_xyshift_data.hpp"
#include "cxx/common/be/xyshift/be_xyshift.h"

namespace sixtrack_cxx
{
    template< class BeObjData > class BeXYShiftInterface :
        public sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeXYShift) >
    {
        public:

        typedef sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeXYShift) >
                _base_t;

        typedef typename _base_t::c_api_t c_api_t;

        template< typename T > using can_store_cobj_t =
            std::enable_if< _base_t::SupportsCObjectsStorage(), T >;

        typedef sixtrack_cxx::BeXYShiftTraits< BeObjData > be_traits_t;
        typedef typename be_traits_t::real_t real_t;

        static_assert( !sixtrack_cxx::ObjData_has_data_ptrs< BeObjData >(),
            "BeXYShift* implementations are not supposed to have dataptrs" );

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeXYShiftInterface() { this->init(); }

        SIXTRL_FN explicit BeXYShiftInterface( const c_api_t *const
            SIXTRL_RESTRICT xyshift ) { this->init( xyshift ); }

        SIXTRL_FN BeXYShiftInterface( real_t const& SIXTRL_RESTRICT_REF dx,
            real_t const& SIXTRL_RESTRICT_REF dy ) { this->init( dx, dy ); }

        SIXTRL_FN BeXYShiftInterface(
            BeXYShiftInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeXYShiftInterface(
            BeXYShiftInterface< BeObjData >&& other ) = default;

        SIXTRL_FN BeXYShiftInterface< BeObjData >& operator=(
            BeXYShiftInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeXYShiftInterface< BeObjData >& operator=(
            BeXYShiftInterface< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeXYShiftInterface() = default;

        SIXTRL_FN void init()
        {
            this->dx = real_t{ 0.0 };   this->dy = real_t{ 0.0 };
        }

        SIXTRL_FN void init( const c_api_t *const SIXTRL_RESTRICT xyshift )
        {
            if( xyshift != nullptr )
            {
                this->dx = real_t( xyshift->dx );
                this->dy = real_t( xyshift->dy );
            }
            else this->init();
        }

        SIXTRL_FN void init( real_t const& SIXTRL_RESTRICT_REF dx,
            real_t const& SIXTRL_RESTRICT_REF dy )
        {
            this->dx = dx;   this->dy = dy;
        }

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN typename can_store_cobj_t< bool >::type
        CanStoreObjectOnBuffer( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
        {
            typedef sixtrack_cxx::BeXYShiftInterface< BeObjData > _this_t;
            return sixtrack_cxx::Obj_can_store_on_buffer< BeObjData >( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_XYSHIFT, nullptr,
                    sizeof( _this_t ), requ_num_objects, requ_num_slots,
                        requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeXYShiftInterface< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            namespace  st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeXYShiftInterface< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                    st::OBJECT_TYPE_XYSHIFT, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args > static SIXTRL_FN
        typename can_store_cobj_t< BeXYShiftInterface< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            namespace  st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeXYShiftInterface< BeObjData >;
            _this_t temp( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                    st::OBJECT_TYPE_XYSHIFT, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeXYShiftInterface< BeObjData >*
            >::type storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            namespace  st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeXYShiftInterface< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                    st::OBJECT_TYPE_XYSHIFT, this->ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeXYShiftInterface< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeXYShiftInterface< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeXYShiftInterface< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeXYShiftInterface< BeObjData >;
            return ObjStore_get_ptr_obj_from_info< _this_t >(
                ::NS(Buffer_get_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }
    };

    typedef BeXYShiftInterface< ::NS(BeXYShift) >            CBeXYShift;
    typedef BeXYShiftInterface< BeXYShiftData< double > >    BeXYShift;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeXYShift = BeXYShiftInterface< BeXYShiftData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_CXX_HPP__ */
/* end: */
