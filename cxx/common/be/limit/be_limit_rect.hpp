#ifndef SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/limit/be_limit_traits.hpp"
#include "cxx/common/be/limit/be_limit_rect_data.hpp"
#include "cxx/common/be/limit/be_limit_rect.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeLimitRectBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef sixtrack_cxx::BeLimitRectTraits< BeObjData > limit_traits_t;
        typedef typename limit_traits_t::real_t real_t;
        typedef ::NS(BeLimitRect) c_api_t;

        static SIXTRL_FN constexpr bool SupportsCObjectsStorage()
        {
            return sixtrack_cxx::ObjData_can_be_stored_on_cobjects_buffer<
                BeObjData >();
        }

        template< typename T >
        using can_store_cobj_t = std::enable_if<
            BeLimitRectBase< BeObjData >::SupportsCObjectsStorage(), T >;

        static SIXTRL_FN constexpr bool HasCApiMemoryLayout()
        {
            return sixtrack_cxx::ObjDataStoreTraits< BeObjData >::HasCApiLayout();
        }

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeLimitRectBase() : BeObjData()
        {
            this->min_x = real_t{ -1.0 };   this->max_x = real_t{  1.0 };
            this->min_y = real_t{ -1.0 };   this->max_y = real_t{  1.0 };
        }

        SIXTRL_FN BeLimitRectBase(
            real_t const& SIXTRL_RESTRICT_REF min_coord,
            real_t const& SIXTRL_RESTRICT_REF max_coord ) : BeObjData()
        {
            this->min_x = min_coord;    this->max_x = max_coord;
            this->min_y = min_coord;    this->max_y = max_coord;
        }

        SIXTRL_FN BeLimitRectBase(
            real_t const& SIXTRL_RESTRICT_REF min_x,
            real_t const& SIXTRL_RESTRICT_REF max_x,
            real_t const& SIXTRL_RESTRICT_REF min_y,
            real_t const& SIXTRL_RESTRICT_REF max_y ) : BeObjData()
        {
            this->min_x = min_x;   this->max_x = max_x;
            this->min_y = min_y;   this->max_y = max_y;
        }

        SIXTRL_FN BeLimitRectBase(
            BeLimitRectBase< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitRectBase(
            BeLimitRectBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeLimitRectBase< BeObjData >& operator=(
            BeLimitRectBase< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitRectBase< BeObjData >& operator=(
            BeLimitRectBase< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeLimitRectBase() = default;

        SIXTRL_FN void init()
        {
            this->min_x = real_t{ -1.0 };  this->max_x = real_t{  1.0 };
            this->min_y = real_t{ -1.0 };  this->max_y = real_t{  1.0 };
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
            typedef sixtrack_cxx::BeLimitRectBase< BeObjData > _this_t;
            _this_t temp;

            return sixtrack_cxx::Obj_can_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT, sizeof( _this_t ),
                    nullptr, nullptr, requ_num_objects, requ_num_slots,
                        requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitRectBase< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeLimitRectBase< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitRectBase< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeLimitRectBase< BeObjData >;
            _this_t temp;
            temp.init( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeLimitRectBase< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeLimitRectBase< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, this->beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitRectBase< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeLimitRectBase< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitRectBase< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeLimitRectBase< BeObjData >;
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

    template< class BeLimitRect >
    bool BeLimitRect_can_store_on_buffer(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_objects = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_slots = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_dataptrs = nullptr )
    {
        return BeLimitRect::CanStoreOnBuffer( buffer,
            required_num_objects, required_num_slots, required_num_dataptrs );
    }

    template< class BeLimitRect >
    BeLimitRect* BeLimitRect_new( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
    {
        return BeLimitRect::CreateNewObject( buffer );
    }

    template< class BeLimitRect, typename... Args >
    BeLimitRect* BeLimitRect_add(
        ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
    {
        return BeLimitRect::AddObject( buffer, std::forward< Args >( args )... );
    }

    template< class BeLimitRect >
    BeLimitRect const* BeLimitRect_get_const(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return BeLimitRect::GetConstObj( buffer, index );
    }

    template< class BeLimitRect >
    BeLimitRect* BeLimitRect_get( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return BeLimitRect::GetObj( buffer, index );
    }
    /* --------------------------------------------------------------------- */

    typedef BeLimitRectBase< ::NS(BeLimitRect) >            CBeLimitRect;
    typedef BeLimitRectBase< BeLimitRectData< double > >    BeLimitRect;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeLimitRect = BeLimitRectBase< BeLimitRectData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_LIMIT_RECT_BE_LIMIT_RECT_CXX_HPP__ */
/* end: */
