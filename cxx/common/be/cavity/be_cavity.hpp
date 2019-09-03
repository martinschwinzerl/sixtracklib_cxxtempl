#ifndef SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/buffer.h"

#include "cxx/common/be/cavity/be_cavity_traits.hpp"
#include "cxx/common/be/cavity/be_cavity_data.hpp"
#include "cxx/common/be/cavity/be_cavity.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeCavityBase : public BeObjData
    {
        public:

        typedef BeObjData       be_data_t;
        typedef ::NS(BeCavity)  c_api_t;

        typedef typename BeCavityTraits< BeObjData >::real_t  real_t;

        /* ----------------------------------------------------------------- */

        template< typename... Args >
        SIXTRL_FN explicit BeCavityBase( Args&&... args )
        {
            sixtrack_cxx::BeCavityData_init(
                this->beData(), std::forward< Args >( args )... );
        }

        SIXTRL_FN BeCavityBase(
            BeCavityBase< BeObjData > const& other) = default;

        SIXTRL_FN BeCavityBase(
            BeCavityBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeCavityBase< BeObjData >& operator=(
            BeCavityBase< BeObjData > const& other) = default;

        SIXTRL_FN BeCavityBase< BeObjData >& operator=(
            BeCavityBase< BeObjData >&& other ) = default;

        SIXTRL_FN virtual ~BeCavityBase() = default;

        SIXTRL_FN be_data_t& beData() SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t& >( *this );
        }

        SIXTRL_FN be_data_t const& beData() const SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t const& >( *this );
        }

        SIXTRL_FN be_data_t* ptrBeData() SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t* >( this );
        }

        SIXTRL_FN be_data_t const* ptrBeData() const SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t const* >( this );
        }
    };

    template< class BeObjData >
    bool Cavity_can_store_on_buffer(
        const ::NS(Buffer) *const SIXTRL_RESTRICT buffer,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_objects = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_slots = nullptr,
        ::NS(buffer_size_t)* SIXTRL_RESTRICT required_num_dataptrs = nullptr )
    {
        return sixtrack_cxx::Obj_can_store_on_buffer( buffer,
            BeCavityBase< BeObjData >{},
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY, required_num_objects,
                required_num_slots, required_num_dataptrs );
    }

    template< class BeObjData >
    BeCavityBase< BeObjData >* Cavity_new( ::NS(Buffer)* SIXTRL_RESTRICT buffer )
    {
        std::uintptr_t return_addr = std::uintptr_t{ 0 };

        ::NS(Object) obj_info = sixtrack_cxx::Obj_store_on_buffer(
            buffer, BeCavityBase< BeObjData >{},
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY );

        if( ::NS(Object_get_type_id)( &obj_info ) ==
                SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY )
        {
            return_addr = ::NS(Object_get_begin_addr)( &obj_info );
        }

        return reinterpret_cast< BeCavityBase< BeObjData >* >( return_addr );
    }

    /* --------------------------------------------------------------------- */

    typedef BeCavityBase< ::NS(BeCavity) >              CBeCavity;
    typedef BeCavityBase< BeCavityData< double, 8u > >  BeCavity;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeCavity = BeCavityBase< BeCavityData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_CXX_HPP__ */
/* end: */
