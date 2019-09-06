#ifndef SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/beam_elements_base.hpp"
#include "cxx/common/be/limit/be_limit_traits.hpp"
#include "cxx/common/be/limit/be_limit_ellipse_data.hpp"
#include "cxx/common/be/limit/be_limit_ellipse.h"

namespace sixtrack_cxx
{
    template< class BeObjData > class BeLimitEllipseInterface :
        public sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeLimitEllipse) >
    {
        public:

        typedef sixtrack_cxx::BeamElementBase< BeObjData, ::NS(BeLimitEllipse) >
                _base_t;
        typedef typename _base_t::c_api_t c_api_t;

        template< typename T > using can_store_cobj_t =
            std::enable_if< _base_t::SupportsCObjectsStorage(), T >;

        typedef sixtrack_cxx::BeLimitEllipseTraits< BeObjData > be_traits_t;
        typedef typename be_traits_t::real_t real_t;

        static_assert( !sixtrack_cxx::ObjData_has_data_ptrs< BeObjData >(),
            "BeLimitEllipse* implementations aren't "
            "supposed to have dataptrs" );

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeLimitEllipseInterface() { this->init(); }

        SIXTRL_FN explicit BeLimitEllipseInterface(
            const c_api_t *const SIXTRL_RESTRICT ell ) { this->init( ell ); }

        SIXTRL_FN BeLimitEllipseInterface(
            real_t const& SIXTRL_RESTRICT_REF a_squ,
            real_t const& SIXTRL_RESTRICT_REF b_squ )
        {
            this->init( a_squ, b_squ );
        }

        SIXTRL_FN BeLimitEllipseInterface(
            BeLimitEllipseInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitEllipseInterface(
            BeLimitEllipseInterface< BeObjData >&& other ) = default;

        SIXTRL_FN BeLimitEllipseInterface< BeObjData >& operator=(
            BeLimitEllipseInterface< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitEllipseInterface< BeObjData >& operator=(
            BeLimitEllipseInterface< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeLimitEllipseInterface() = default;

        SIXTRL_FN void init()
        {
            this->a_squ   = real_t{ 1.0 };
            this->b_squ   = real_t{ 1.0 };
            this->a_b_squ = real_t{ 1.0 };
        }

        SIXTRL_FN void init( const c_api_t *const SIXTRL_RESTRICT ell )
        {
            if( ell != nullptr )
            {
                this->init( real_t( ell->a_squ ), real_t( ell->b_squ ) );
            }
            else this->init();
        }

        SIXTRL_FN void init( real_t const& SIXTRL_RESTRICT_REF a_squ,
            real_t const& SIXTRL_RESTRICT_REF b_squ )
        {
            this->a_squ   = a_squ;
            this->b_squ   = b_squ;
            this->a_b_squ = a_squ * b_squ;
        }

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN typename can_store_cobj_t< bool >::type
        CanStoreObjectOnBuffer(
            const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_objects = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_slots = nullptr,
            ::NS(buffer_size_t)* SIXTRL_RESTRICT requ_num_dataptrs = nullptr )
        {
            typedef sixtrack_cxx::BeLimitEllipseInterface< BeObjData > _this_t;
            return sixtrack_cxx::Obj_can_store_on_buffer< BeObjData >( buffer,
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE, nullptr,
                    sizeof( _this_t ), requ_num_objects, requ_num_slots,
                        requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitEllipseInterface< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            namespace st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeLimitEllipseInterface< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                    st::OBJECT_TYPE_LIMIT_ELLIPSE, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args > static SIXTRL_FN
        typename can_store_cobj_t< BeLimitEllipseInterface< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            namespace st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeLimitEllipseInterface< BeObjData >;
            _this_t temp;
            temp.init( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                    st::OBJECT_TYPE_LIMIT_ELLIPSE, temp.ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t<
            BeLimitEllipseInterface< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            namespace st = SIXTRL_CXX_NAMESPACE;
            using _this_t = sixtrack_cxx::BeLimitEllipseInterface< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer,
                    st::OBJECT_TYPE_LIMIT_ELLIPSE, this->ptrBeData() ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN typename can_store_cobj_t< BeLimitEllipseInterface<
            BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeLimitEllipseInterface< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitEllipseInterface< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeLimitEllipseInterface< BeObjData >;
            return ObjStore_get_ptr_obj_from_info< _this_t >(
                ::NS(Buffer_get_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }
    };

    typedef BeLimitEllipseInterface< ::NS(BeLimitEllipse) > CBeLimitEllipse;
    typedef BeLimitEllipseInterface<
        BeLimitEllipseData< double > > BeLimitEllipse;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeLimitEllipse = BeLimitEllipseInterface<
        BeLimitEllipseData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_CXX_HPP__ */
/* end: */
