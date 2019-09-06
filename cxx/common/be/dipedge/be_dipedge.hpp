#ifndef SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/beam_elements_base.hpp"
#include "cxx/common/be/dipedge/be_dipedge_traits.hpp"
#include "cxx/common/be/dipedge/be_dipedge_data.hpp"
#include "cxx/common/be/dipedge/be_dipedge.h"

namespace sixtrack_cxx
{
    template< class BeObjData > class BeDipoleEdgeInterface :
        public sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeDipoleEdge) >
    {
        public:

        typedef sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeDipoleEdge) >
                _base_t;

        typedef typename _base_t::c_api_t c_api_t;

        template< typename T > using can_store_cobj_t =
            std::enable_if< _base_t::SupportsCObjectsStorage(), T >;

        typedef sixtrack_cxx::BeDipoleEdgeTraits< BeObjData > be_traits_t;
        typedef typename be_traits_t::real_t real_t;

        static_assert( !sixtrack_cxx::ObjData_has_data_ptrs< BeObjData >(),
            "BeDipoleEdge* implementations are not supposed to have dataptrs" );

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeDipoleEdgeInterface() { this->init(); }

        SIXTRL_FN explicit BeDipoleEdgeInterface( const c_api_t *const
            SIXTRL_RESTRICT ptr_dipedge ) { this->init( ptr_dipedge ); }

        SIXTRL_FN BeDipoleEdgeInterface( real_t const& SIXTRL_RESTRICT_REF _r21,
            real_t const& SIXTRL_RESTRICT_REF _r43 )
        {
            this->init( _r21, _r43 );
        }

        SIXTRL_FN BeDipoleEdgeInterface(
            BeDipoleEdgeInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeDipoleEdgeInterface(
            BeDipoleEdgeInterface< BeObjData >&& other ) = default;

        SIXTRL_FN BeDipoleEdgeInterface< BeObjData >& operator=(
            BeDipoleEdgeInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeDipoleEdgeInterface< BeObjData >& operator=(
            BeDipoleEdgeInterface< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeDipoleEdgeInterface() = default;

        SIXTRL_FN void init()
        {
            this->r21 = real_t{ 0.0 };
            this->r43 = real_t{ 0.0 };
        }

        SIXTRL_FN void init( const c_api_t *const SIXTRL_RESTRICT dipedge )
        {
            if( dipedge != nullptr )
            {
                this->init( real_t( dipedge->r21 ), real_t( dipedge->r43 ) );
            }
            else this->init();
        }

        SIXTRL_FN void init( real_t const& SIXTRL_RESTRICT_REF _r21,
                             real_t const& SIXTRL_RESTRICT_REF _r43 )
        {
            this->r21 = _r21;
            this->r43 = _r43;
        }

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN typename can_store_cobj_t< bool >::type
        CanStoreObjectOnBuffer(
            const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
        {
            using _this_t = sixtrack_cxx::BeDipoleEdgeInterface< BeObjData >;
            return sixtrack_cxx::Obj_can_store_on_buffer< BeObjData >( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE, nullptr,
                    sizeof( _this_t ), requ_num_objects, requ_num_slots,
                        requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDipoleEdgeInterface< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDipoleEdgeInterface< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeDipoleEdgeInterface< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeDipoleEdgeInterface< BeObjData >;
            _this_t temp;
            temp.init( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN
        typename can_store_cobj_t< BeDipoleEdgeInterface< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDipoleEdgeInterface< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE, this->ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeDipoleEdgeInterface< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDipoleEdgeInterface< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDipoleEdgeInterface< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDipoleEdgeInterface< BeObjData >;
            return ObjStore_get_ptr_obj_from_info< _this_t >(
                ::NS(Buffer_get_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }
    };

    typedef BeDipoleEdgeInterface< ::NS(BeDipoleEdge) > CBeDipoleEdge;
    typedef BeDipoleEdgeInterface< BeDipoleEdgeData< double > > BeDipoleEdge;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeDipoleEdge = BeDipoleEdgeInterface< BeDipoleEdgeData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_CXX_HPP__ */
/* end: */
