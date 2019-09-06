#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_CXX_HPP__

#include "sixtracklib/common/definitions.h"

#include "cxx/common/be/beam_elements_base.hpp"
#include "cxx/common/be/drift/be_drift_traits.hpp"
#include "cxx/common/be/drift/be_drift_data.hpp"
#include "cxx/common/be/drift/be_drift.h"

namespace sixtrack_cxx
{
    template< class BeObjData > class BeDriftInterface :
        public sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeDrift) >
    {
        public:

        typedef sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeDrift) > _base_t;
        typedef typename _base_t::c_api_t c_api_t;

        template< typename T > using can_store_cobj_t =
            std::enable_if< _base_t::SupportsCObjectsStorage(), T >;

        typedef sixtrack_cxx::BeDriftTraits< BeObjData > be_traits_t;
        typedef typename be_traits_t::real_t real_t;

        static_assert( !sixtrack_cxx::ObjData_has_data_ptrs< BeObjData >(),
            "BeDrift* implementations are not supposed to have dataptrs" );

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeDriftInterface() { this->init(); }

        SIXTRL_FN BeDriftInterface( const c_api_t *const
            SIXTRL_RESTRICT drift ) { this->init( drift ); }

        SIXTRL_FN BeDriftInterface( real_t const& SIXTRL_RESTRICT_REF length )
        { this->init( length ); }

        SIXTRL_FN BeDriftInterface(
            BeDriftInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeDriftInterface(
            BeDriftInterface< BeObjData >&& other ) = default;

        SIXTRL_FN BeDriftInterface< BeObjData >& operator=(
            BeDriftInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeDriftInterface< BeObjData >& operator=(
            BeDriftInterface< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeDriftInterface() = default;

        SIXTRL_FN void init() { this->length = real_t{ 0.0 }; }

        SIXTRL_FN void init( real_t const& SIXTRL_RESTRICT_REF length )
        {
            this->length = length;
        }

        SIXTRL_FN void init( const c_api_t *const SIXTRL_RESTRICT drift )
        {
            if( drift != nullptr )
            {
                this->init( real_t( drift->length ) );
            }
            else this->init();
        }

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN typename can_store_cobj_t< bool >::type
        CanStoreObjectOnBuffer( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
        {
            using _this_t = sixtrack_cxx::BeDriftInterface< BeObjData >;
            return sixtrack_cxx::Obj_can_store_on_buffer< BeObjData >( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT, nullptr,
                    sizeof( _this_t ), requ_num_objects, requ_num_slots,
                        requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftInterface< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDriftInterface< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args > static SIXTRL_FN
        typename can_store_cobj_t< BeDriftInterface< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeDriftInterface< BeObjData >;
            _this_t temp( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeDriftInterface< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDriftInterface< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT, this->ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftInterface< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDriftInterface< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDriftInterface< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDriftInterface< BeObjData >;
            return ObjStore_get_ptr_obj_from_info< _this_t >(
                ::NS(Buffer_get_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }
    };

    typedef BeDriftInterface< ::NS(BeDrift) > CBeDrift;
    typedef BeDriftInterface< BeDriftData< double > > BeDrift;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeDrift = BeDriftInterface< BeDriftData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_CXX_HPP__ */
/* end: */
