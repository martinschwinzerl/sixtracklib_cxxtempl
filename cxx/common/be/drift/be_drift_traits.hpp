#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_TRAITS_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_TRAITS_CXX_HPP__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< class BeObjData >
    struct BeDriftExactTraits
    {
        typedef typename BeObjData::real_t real_t;
    };

    template< class BeObjData >
    struct BeDriftTraits
    {
        typedef typename BeObjData::real_t real_t;
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_TRAITS_CXX_HPP__ */
