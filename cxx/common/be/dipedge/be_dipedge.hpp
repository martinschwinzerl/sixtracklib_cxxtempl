#ifndef SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/dipedge/be_dipedge_traits.hpp"
#include "cxx/common/be/dipedge/be_dipedge_data.hpp"
#include "cxx/common/be/dipedge/be_dipedge.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeDipoleEdgeBase : public BeObjData
    {
        public:

        typedef BeObjData be_data_t;
        typedef ::NS(BeDipoleEdge) c_api_t;
        typedef typename BeDipoleEdgeTraits< BeObjData >::real_t real_t;

        /* ----------------------------------------------------------------- */

        static SIXTRL_FN constexpr bool SupportsCObjectsStorage()
        {
            return sixtrack_cxx::ObjData_can_be_stored_on_cobjects_buffer<
                BeObjData >();
        }

        template< typename T >
        using can_store_cobj_t = std::enable_if<
            BeDipoleEdgeBase< BeObjData >::SupportsCObjectsStorage(), T >;

        static SIXTRL_FN constexpr bool HasCApiMemoryLayout()
        {
            return sixtrack_cxx::ObjDataStoreTraits< BeObjData >::HasCApiLayout();
        }

        /* ----------------------------------------------------------------- */

        SIXTRL_FN BeDipoleEdgeBase() : BeObjData()
        {
            this->r21 = real_t{ 0.0 };
            this->r43 = real_t{ 0.0 };
        }

        SIXTRL_FN BeDipoleEdgeBase(
            real_t const& SIXTRL_RESTRICT_REF _r21,
            real_t const& SIXTRL_RESTRICT_REF _r43 ) : BeObjData()
        {
            this->r21 = _r21;
            this->r43 = _r43;
        }

        SIXTRL_FN BeDipoleEdgeBase(
            BeDipoleEdgeBase< BeObjData > const& other) = default;

        SIXTRL_FN BeDipoleEdgeBase(
            BeDipoleEdgeBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeDipoleEdgeBase< BeObjData >& operator=(
            BeDipoleEdgeBase< BeObjData > const& other) = default;

        SIXTRL_FN BeDipoleEdgeBase< BeObjData >& operator=(
            BeDipoleEdgeBase< BeObjData >&& other ) = default;

        SIXTRL_FN ~BeDipoleEdgeBase() = default;

        SIXTRL_FN void init()
        {
            this->r21 = real_t{ 0.0 };
            this->r43 = real_t{ 0.0 };
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
            using _this_t = sixtrack_cxx::BeDipoleEdgeBase< BeObjData >;

            _this_t temp;
            return sixtrack_cxx::Obj_can_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE, sizeof( _this_t ),
                    nullptr, nullptr, requ_num_objects, requ_num_slots,
                        requ_num_dataptrs );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDipoleEdgeBase< BeObjData >* >::type
        CreateNewObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDipoleEdgeBase< BeObjData >;
            _this_t temp;

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        template< typename... Args >
        static SIXTRL_FN
        typename can_store_cobj_t< BeDipoleEdgeBase< BeObjData >* >::type
        AddObject( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
        {
            using _this_t = sixtrack_cxx::BeDipoleEdgeBase< BeObjData >;
            _this_t temp;
            temp.init( std::forward< Args >( args )... );

            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, temp.beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        SIXTRL_FN
        typename can_store_cobj_t< BeDipoleEdgeBase< BeObjData >* >::type
        storeCopy( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
        {
            using _this_t = sixtrack_cxx::BeDipoleEdgeBase< BeObjData >;
            return sixtrack_cxx::ObjStore_get_ptr_obj_from_info< _this_t >(
                sixtrack_cxx::Obj_store_on_buffer( buffer, this->beData(),
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE, sizeof( _this_t ) ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        /* -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- */

        static SIXTRL_FN
        typename can_store_cobj_t< BeDipoleEdgeBase< BeObjData > const* >::type
        GetConstObj( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDipoleEdgeBase< BeObjData >;
            return ObjStore_get_ptr_const_obj_from_info< _this_t >(
                ::NS(Buffer_get_const_object)( buffer, index ),
                sixtrack_cxx::ObjDataStoreTraits< BeObjData >::ObjTypeId() );
        }

        static SIXTRL_FN
        typename can_store_cobj_t< BeDipoleEdgeBase< BeObjData >* >::type
        GetObj( ::NS(Buffer)* SIXTRL_RESTRICT buffer,
                ::NS(buffer_size_t) const index )
        {
            using _this_t = sixtrack_cxx::BeDipoleEdgeBase< BeObjData >;
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

    template< class DipEdgeType >
    bool BeDipoleEdge_can_store_on_buffer(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_objects = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_slots = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_dataptrs = nullptr )
    {
        return DipEdgeType::CanStoreOnBuffer( buffer,
            required_num_objects, required_num_slots, required_num_dataptrs );
    }

    template< class DipEdgeType >
    DipEdgeType* DipoleEdge_new( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
    {
        return DipEdgeType::CreateNewObject( buffer );
    }

    template< class DipEdgeType, typename... Args >
    DipEdgeType* DipoleEdge_add( ::NS(Buffer)* SIXTRL_RESTRICT buffer, Args&&... args )
    {
        return DipEdgeType::AddObject( buffer, std::forward< Args >( args )... );
    }

    template< class DipEdgeType >
    DipEdgeType const* DipoleEdge_get_const(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return DipEdgeType::GetConstObj( buffer, index );
    }

    template< class DipEdgeType >
    DipEdgeType* DipoleEdge_get( const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t) const index )
    {
        return DipEdgeType::GetObj( buffer, index );
    }

    /* --------------------------------------------------------------------- */

    typedef BeDipoleEdgeBase< ::NS(BeDipoleEdge) >            CBeDipoleEdge;
    typedef BeDipoleEdgeBase< BeDipoleEdgeData< double > >    BeDipoleEdge;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeDipoleEdge = BeDipoleEdgeBase< BeDipoleEdgeData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_CXX_HPP__ */
/* end: */
