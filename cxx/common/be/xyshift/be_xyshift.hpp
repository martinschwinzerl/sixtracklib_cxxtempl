#ifndef SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_CXX_HPP__

#include "sixtracklib/common/definitions.h"

#include "cxx/common/be/xyshift/be_xyshift_traits.hpp"
#include "cxx/common/be/xyshift/be_xyshift_data.hpp"
#include "cxx/common/be/xyshift/be_xyshift.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeXYShiftBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef sixtrack_cxx::BeXYShiftTraits< BeObjData > xy_shift_traits_t;
        typedef typename xy_shift_traits_t::real_t real_t;
        typedef ::NS(BeXYShift) c_api_t;

        static SIXTRL_FN constexpr bool SupportsCObjectsStorage()
        {
            return sixtrack_cxx::ObjData_can_be_stored_on_cobjects_buffer<
                BeObjData >();
        }

        template< typename T >
        using can_store_cobj_t = std::enable_if<
            BeXYShiftBase< BeObjData >::SupportsCObjectsStorage(), T >;

        static SIXTRL_FN constexpr bool HasCApiMemoryLayout()
        {
            return sixtrack_cxx::ObjDataStoreTraits< BeObjData >::HasCApiLayout();
        }

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeXYShiftBase() : BeObjData()
        {
            this->dx = real_t{ 0.0 };   this->dy = real_t{ 0.0 };
        }

        SIXTRL_FN BeXYShiftBase( real_t const& SIXTRL_RESTRICT_REF dx,
            real_t const& SIXTRL_RESTRICT_REF dy ) : BeObjData()
        {
            this->dx = dx;   this->dy = dy;
        }

        SIXTRL_FN BeXYShiftBase(
            BeXYShiftBase< BeObjData > const& other) = default;

        SIXTRL_FN BeXYShiftBase(
            BeXYShiftBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeXYShiftBase< BeObjData >& operator=(
            BeXYShiftBase< BeObjData > const& other) = default;

        SIXTRL_FN BeXYShiftBase< BeObjData >& operator=(
            BeXYShiftBase< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeXYShiftBase() = default;

        SIXTRL_FN void init()
        {
            this->dx = real_t{ 0.0 };   this->dy = real_t{ 0.0 };
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
            typedef sixtrack_cxx::BeXYShiftBase< BeObjData > _this_t;
            _this_t temp;

            return sixtrack_cxx::Obj_can_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_XYSHIFT, sizeof( _this_t ),
                    nullptr, nullptr, requ_num_objects, requ_num_slots,
                        requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeXYShiftBase< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeXYShiftBase< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_XYSHIFT, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeXYShiftBase< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeXYShiftBase< BeObjData >;
            _this_t temp;
            temp.init( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_XYSHIFT, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN typename can_store_cobj_t< BeXYShiftBase< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeXYShiftBase< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, this->beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_XYSHIFT, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeXYShiftBase< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeXYShiftBase< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeXYShiftBase< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeXYShiftBase< BeObjData >;
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

    template< class XYShiftType >
    bool XYShift_can_store_on_buffer(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_objects = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_slots = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_dataptrs = nullptr )
    {
        return XYShiftType::CanStoreOnBuffer( buffer,
            required_num_objects, required_num_slots, required_num_dataptrs );
    }

    template< class XYShiftType >
    XYShiftType* XYShift_new( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
    {
        return XYShiftType::CreateNewObject( buffer );
    }

    template< class XYShiftType, typename... Args >
    XYShiftType* XYShift_add( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
    {
        return XYShiftType::AddObject( buffer, std::forward< Args >( args )... );
    }

    template< class XYShiftType >
    XYShiftType const* XYShift_get_const(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return XYShiftType::GetConstObj( buffer, index );
    }

    template< class XYShiftType >
    XYShiftType* XYShift_get( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return XYShiftType::GetObj( buffer, index );
    }

    /* --------------------------------------------------------------------- */

    typedef BeXYShiftBase< ::NS(BeXYShift) >            CBeXYShift;
    typedef BeXYShiftBase< BeXYShiftData< double > >    BeXYShift;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeXYShift = BeXYShiftBase< BeXYShiftData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_XYSHIFT_BE_XYSHIFT_CXX_HPP__ */
/* end: */
