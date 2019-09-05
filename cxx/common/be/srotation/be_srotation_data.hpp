#ifndef SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_DATA_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_DATA_CXX_HPP__

#include <cstddef>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/be/srotation/be_srotation_traits.hpp"
#include "cxx/common/internal/math_constant_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< typename R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign()>
    struct BeSRotationData
    {
        typedef R real_t;

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return RAlign; }

        real_t  cos_z SIXTRL_ALIGN( RAlign );
        real_t  sin_z SIXTRL_ALIGN( RAlign );
    };

    template<> struct ObjDataStoreTraits< BeSRotationData< double, 8u > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template< class R, std::size_t RealAlign >
    struct ObjDataTrackTraits< BeSRotationData< R, RealAlign > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION;
        }
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_SROTATION_BE_SROTATION_DATA_CXX_HPP__ */
/* end: */
