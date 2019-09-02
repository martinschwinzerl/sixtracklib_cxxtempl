#ifndef SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_DATA_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_DATA_CXX_HPP__

#include <cstddef>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/be/cavity/be_cavity_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< typename R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    struct BeCavityData
    {
        typedef R real_t;

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return RAlign; }

        real_t  voltage     SIXTRL_ALIGN( RAlign );
        real_t  frequency   SIXTRL_ALIGN( RAlign );
        real_t  lag         SIXTRL_ALIGN( RAlign );
    };

    /* --------------------------------------------------------------------- */

    template<>
    struct ObjDataStoreTraits< BeCavityData< double, 8u  > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template< class R, std::size_t RealAlign >
    struct ObjDataTrackTraits< BeCavityData< R, RealAlign > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY;
        }
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_DATA_CXX_HPP__ */
/* end: */
