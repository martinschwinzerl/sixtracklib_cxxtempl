#ifndef SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_DATA_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_DATA_CXX_HPP__

#include <cstddef>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/be/limit/be_limit_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< typename R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign()>
    struct BeLimitEllipseData
    {
        typedef R real_t;

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return RAlign; }

        real_t a_squ   SIXTRL_ALIGN( RAlign );
        real_t b_squ   SIXTRL_ALIGN( RAlign );
        real_t a_b_squ SIXTRL_ALIGN( RAlign );
    };

    /* --------------------------------------------------------------------- */

    template<> struct ObjDataStoreTraits< BeLimitEllipseData< double, 8u > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template< class R, std::size_t RealAlign >
    struct ObjDataTrackTraits< BeLimitEllipseData< R, RealAlign > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE;
        }
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_LIMIT_ELLIPSE_BE_LIMIT_ELLIPSE_DATA_CXX_HPP__ */
/* end: */
