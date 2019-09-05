#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_DRIFT_DATA_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DRIFT_DRIFT_DATA_CXX_HPP__

#include <cstdlib>

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"
#include "cxx/common/be/drift/definitions.h"

#include "cxx/common/be/drift/be_drift_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< class R, std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    struct BeDriftData
    {
        typedef R real_t;

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return RAlign; }

        real_t length SIXTRL_ALIGN( RAlign );
    };

    template<> struct ObjDataStoreTraits< BeDriftData< double > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return true; }
    };

    template< class R, std::size_t RealAlign >
    struct ObjDataTrackTraits< BeDriftData< R, RealAlign > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT;
        }
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_DRIFT_DATA_CXX_HPP__ */
/* end: */
