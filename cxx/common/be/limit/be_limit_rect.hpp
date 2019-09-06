#ifndef SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/beam_elements_base.hpp"
#include "cxx/common/be/limit/be_limit_traits.hpp"
#include "cxx/common/be/limit/be_limit_rect_data.hpp"
#include "cxx/common/be/limit/be_limit_rect.h"

namespace sixtrack_cxx
{
    template< class BeObjData > class BeLimitRectInterface :
        public sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeLimitRect) >
    {
        public:

        typedef sixtrack_cxx::BeamElementBase< BeObjData,
            ::NS(BeLimitRect) > _base_t;
        typedef typename _base_t::c_api_t c_api_t;

        template< typename T > using can_store_cobj_t =
            std::enable_if< _base_t::SupportsCObjectsStorage(), T >;

        typedef sixtrack_cxx::BeLimitRectTraits< BeObjData > be_traits_t;
        typedef typename be_traits_t::real_t real_t;

        static_assert( !sixtrack_cxx::ObjData_has_data_ptrs< BeObjData >(),
            "BeLimitRect* implementations aren't supposed to have dataptrs" );

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeLimitRectInterface() { this->init(); }

        SIXTRL_FN explicit BeLimitRectInterface( const c_api_t *const
            SIXTRL_RESTRICT limit ) { this->init( limit ); }

        SIXTRL_FN BeLimitRectInterface(
            real_t const& SIXTRL_RESTRICT_REF min_coord,
            real_t const& SIXTRL_RESTRICT_REF max_coord )
        {
            this->init( min_coord, max_coord );
        }

        SIXTRL_FN BeLimitRectInterface(
            real_t const& SIXTRL_RESTRICT_REF min_x,
            real_t const& SIXTRL_RESTRICT_REF max_x,
            real_t const& SIXTRL_RESTRICT_REF min_y,
            real_t const& SIXTRL_RESTRICT_REF max_y )
        {
            this->init( min_x, max_x, min_y, max_y );
        }

        SIXTRL_FN BeLimitRectInterface(
            BeLimitRectInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitRectInterface(
            BeLimitRectInterface< BeObjData >&& other ) = default;

        SIXTRL_FN BeLimitRectInterface< BeObjData >& operator=(
            BeLimitRectInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitRectInterface< BeObjData >& operator=(
            BeLimitRectInterface< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeLimitRectInterface() = default;

        SIXTRL_FN void init()
        {
            this->min_x = real_t{ -1.0 };  this->max_x = real_t{  1.0 };
            this->min_y = real_t{ -1.0 };  this->max_y = real_t{  1.0 };
        }

        SIXTRL_FN void init( const c_api_t *const SIXTRL_RESTRICT limit )
        {
            if( limit != nullptr )
            {
                this->min_x = real_t( limit->min_x );
                this->max_x = real_t( limit->max_x );
                this->min_y = real_t( limit->min_y );
                this->max_y = real_t( limit->max_y );
            }
            else this->init();
        }

        SIXTRL_FN void init( real_t const& SIXTRL_RESTRICT_REF min_coord,
            real_t const& SIXTRL_RESTRICT_REF max_coord )
        {
            this->min_x = min_coord;   this->max_x = max_coord;
            this->min_y = min_coord;   this->max_y = max_coord;
        }

        SIXTRL_FN void init( real_t const& SIXTRL_RESTRICT_REF min_x,
            real_t const& SIXTRL_RESTRICT_REF max_x,
            real_t const& SIXTRL_RESTRICT_REF min_y,
            real_t const& SIXTRL_RESTRICT_REF max_y )
        {
            this->min_x = min_x;   this->max_x = max_x;
            this->min_y = min_y;   this->max_y = max_y;
        }

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN typename can_store_cobj_t< bool >::type
        CanStoreObjectOnBuffer(
            const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
        {
            typedef sixtrack_cxx::BeLimitRectInterface< BeObjData > _this_t;
            return sixtrack_cxx::Obj_can_store_on_buffer< BeObjData >( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT, sizeof( _this_t ),
                    requ_num_objects, requ_num_slots, requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitRectInterface< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeLimitRectInterface< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitRectInterface< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeLimitRectInterface< BeObjData >;
            _this_t temp( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeLimitRectInterface< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeLimitRectInterface< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT, this->ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitRectInterface< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeLimitRectInterface< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitRectInterface< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeLimitRectInterface< BeObjData >;
            return ObjStore_get_ptr_obj_from_info< _this_t >(
                ::NS(Buffer_get_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }
    };

    typedef BeLimitRectInterface< ::NS(BeLimitRect) > CBeLimitRect;
    typedef BeLimitRectInterface< BeLimitRectData< double > > BeLimitRect;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeLimitRect = BeLimitRectInterface< BeLimitRectData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_CXX_HPP__ */
/* end: */
