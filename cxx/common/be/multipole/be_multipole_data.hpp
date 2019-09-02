#ifndef SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_DATA_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_DATA_CXX_HPP__

#include <cstddef>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/be/multipole/be_multipole_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< typename R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign(),
        std::size_t OAlign = sixtrack_cxx::TypeStoreTraits<
            ::NS(multipole_order_t) >::StorageAlign() >
    struct BeMultipoleData
    {
        typedef R                       real_t;
        typedef ::NS(multipole_order_t) order_t;

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return RAlign; }

        static SIXTRL_FN constexpr std::size_t
        OrderAlignment() { return OAlign; }

        static SIXTRL_FN constexpr std::size_t
        BalParamAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t* >::StorageAlign();
        }

        order_t order       SIXTRL_ALIGN( OAlign );
        real_t  length      SIXTRL_ALIGN( RAlign );
        real_t  hxl         SIXTRL_ALIGN( RAlign );
        real_t  hyl         SIXTRL_ALIGN( RAlign );
        real_t* bal         SIXTRL_ALIGN(
            ( BeMultipoleData< R, RAlign, OAlign >::BalParamAlignment() ) );
    };

    template< typename R, std::size_t RAlign, std::size_t OAlign >
    typename BeMultipoleData< R, RAlign, OAlign >::order_t
    BeMultipoleData_get_order( BeMultipoleData< R, RAlign, OAlign >
        const& SIXTRL_RESTRICT_REF mp ) SIXTRL_NOEXCEPT
    {
        return mp.order;
    }

    template< typename R, std::size_t RAlign, std::size_t OAlign >
    typename BeMultipoleData< R, RAlign, OAlign >::real_t const&
    BeMultipoleData_get_const_bal(
        BeMultipoleData< R, RAlign, OAlign > const& SIXTRL_RESTRICT_REF mp,
        ::NS(multipole_order_t) const order_index ) SIXTRL_NOEXCEPT
    {
        SIXTRL_ASSERT( mp.bal != nullptr );
        SIXTRL_ASSERT( mp.order > order_index );

        return mp.bal[ order_index ];
    }

    template< typename R, std::size_t RAlign, std::size_t OAlign >
    typename BeMultipoleData< R, RAlign, OAlign >::real_t&
    BeMultipoleData_get_bal(
        BeMultipoleData< R, RAlign, OAlign >& SIXTRL_RESTRICT_REF mp,
        ::NS(multipole_order_t) const order_index ) SIXTRL_NOEXCEPT
    {
        SIXTRL_ASSERT( mp.bal != nullptr );
        SIXTRL_ASSERT( mp.order > order_index );

        return mp.bal[ order_index ];
    }

    /* --------------------------------------------------------------------- */

    template<>
    struct ObjDataStoreTraits< BeMultipoleData< double, 8u, 8u > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template< class R, std::size_t RealAlign, std::size_t OrderAlign >
    struct ObjDataTrackTraits< BeMultipoleData< R, RealAlign, OrderAlign > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE;
        }
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_MULTIPOLE_BE_MULTIPOLE_DATA_CXX_HPP__ */
/* end: */
