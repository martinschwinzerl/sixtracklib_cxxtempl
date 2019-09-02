#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_DRIFT_DATA_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DRIFT_DRIFT_DATA_CXX_HPP__

#include <cstdlib>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/be/drift/be_drift_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    struct DriftData
    {
        typedef R   real_t;

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return RAlign; }

        real_t length SIXTRL_ALIGN( RAlign );
    };

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    struct DriftExactData
    {
        typedef R   real_t;

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return RAlign; }

        real_t length SIXTRL_ALIGN( RAlign );
    };

    /* --------------------------------------------------------------------- */

    template<>
    struct ObjDataStoreTraits< DriftData< double > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template< class R, std::size_t RealAlign >
    struct ObjDataTrackTraits< DriftData< R, RealAlign > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT;
        }
    };

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    template<>
    struct ObjDataStoreTraits< DriftExactData< double > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout()
        {
            return true;
        }
    };

    template< class R, std::size_t RealAlign >
    struct ObjDataTrackTraits< DriftExactData< R, RealAlign > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT;
        }
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_DRIFT_DATA_CXX_HPP__ */
/* end: */
