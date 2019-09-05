#ifndef SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/limit/be_limit_traits.hpp"
#include "cxx/common/be/limit/be_limit_ellipse_data.hpp"
#include "cxx/common/be/limit/be_limit_ellipse.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeLimitEllipseBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef ::NS(BeLimitEllipse) c_api_t;
        typedef typename BeLimitEllipseTraits< BeObjData >::real_t real_t;

        static SIXTRL_FN constexpr bool SupportsCObjectsStorage()
        {
            return sixtrack_cxx::ObjData_can_be_stored_on_cobjects_buffer<
                BeObjData >();
        }

        template< typename T >
        using can_store_cobj_t = std::enable_if<
            BeLimitEllipseBase< BeObjData >::SupportsCObjectsStorage(), T >;

        static SIXTRL_FN constexpr bool HasCApiMemoryLayout()
        {
            return sixtrack_cxx::ObjDataStoreTraits<
                BeObjData >::HasCApiLayout();
        }

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeLimitEllipseBase() : BeObjData()
        {
            this->a_squ   = real_t{ 1.0 };
            this->b_squ   = real_t{ 1.0 };
            this->a_b_squ = real_t{ 1.0 };
        }

        SIXTRL_FN BeLimitEllipseBase(
            real_t const& SIXTRL_RESTRICT_REF a_squ,
            real_t const& SIXTRL_RESTRICT_REF b_squ ) : BeObjData()
        {
            this->a_squ   = a_squ;
            this->b_squ   = b_squ;
            this->a_b_squ = a_squ * b_squ;
        }

        SIXTRL_FN BeLimitEllipseBase(
            BeLimitEllipseBase< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitEllipseBase(
            BeLimitEllipseBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeLimitEllipseBase< BeObjData >& operator=(
            BeLimitEllipseBase< BeObjData > const& other) = default;

        SIXTRL_FN BeLimitEllipseBase< BeObjData >& operator=(
            BeLimitEllipseBase< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeLimitEllipseBase() = default;

        SIXTRL_FN void init()
        {
            this->a_squ   = real_t{ 1.0 };
            this->b_squ   = real_t{ 1.0 };
            this->a_b_squ = real_t{ 1.0 };
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
            typedef sixtrack_cxx::BeLimitEllipseBase< BeObjData > _this_t;
            _this_t temp;

            return sixtrack_cxx::Obj_can_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE,
                    sizeof( _this_t ), nullptr, nullptr, requ_num_objects,
                        requ_num_slots, requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitEllipseBase< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeLimitEllipseBase< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE,
                    sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitEllipseBase< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeLimitEllipseBase< BeObjData >;
            _this_t temp;
            temp.init( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE,
                    sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeLimitEllipseBase< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeLimitEllipseBase< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, this->beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE,
                    sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitEllipseBase< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeLimitEllipseBase< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeLimitEllipseBase< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeLimitEllipseBase< BeObjData >;
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

    template< class LimitEllipseType >
    bool LimitEllipse_can_store_on_buffer(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_objects = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_slots = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_dataptrs = nullptr )
    {
        return LimitEllipseType::CanStoreOnBuffer( buffer,
            required_num_objects, required_num_slots, required_num_dataptrs );
    }

    template< class LimitEllipseType >
    LimitEllipseType* LimitEllipse_new( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
    {
        return LimitEllipseType::CreateNewObject( buffer );
    }

    template< class LimitEllipseType, typename... Args >
    LimitEllipseType* LimitEllipse_add(
        ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
    {
        return LimitEllipseType::AddObject(
            buffer, std::forward< Args >( args )... );
    }

    template< class LimitEllipseType >
    LimitEllipseType const* LimitEllipse_get_const(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return LimitEllipseType::GetConstObj( buffer, index );
    }

    template< class LimitEllipseType >
    LimitEllipseType* LimitEllipse_get(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return LimitEllipseType::GetObj( buffer, index );
    }

    /* --------------------------------------------------------------------- */

    typedef BeLimitEllipseBase< ::NS(BeLimitEllipse) >          CBeLimitEllipse;
    typedef BeLimitEllipseBase< BeLimitEllipseData< double > >  BeLimitEllipse;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeLimitEllipse = BeLimitEllipseBase< BeLimitEllipseData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_CXX_HPP__ */
/* end: */
