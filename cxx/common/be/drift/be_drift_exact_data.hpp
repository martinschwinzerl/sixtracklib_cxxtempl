#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_DRIFT_EXACT_DATA_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DRIFT_DRIFT_EXACT_DATA_CXX_HPP__

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
    struct BeDriftExactData
    {
        typedef R real_t;

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return RAlign; }

        real_t length SIXTRL_ALIGN( RAlign );
    };

    template< class R, std::size_t RAlign >
    void BeDriftExactData_init(
        BeDriftExactData< R, RAlign >& SIXTRL_RESTRICT_REF drift )
    {
        drift.length = typename BeDriftExactData< R, RAlign >::real_t{ 0 };
    }

    template< class R, std::size_t RAlign >
    void BeDriftExactData_init(
        BeDriftExactData< R, RAlign >& SIXTRL_RESTRICT_REF drift,
        typename BeDriftExactData< R, RAlign >::real_t const& length )
    {
        drift.length = length;
    }

    /* --------------------------------------------------------------------- */

    template<> struct ObjDataStoreTraits< BeDriftExactData< double > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return true; }
    };

    template< class R, std::size_t RealAlign >
    struct ObjDataTrackTraits< BeDriftExactData< R, RealAlign > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT;
        }
    };
}

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_DRIFT_EXACT_DATA_CXX_HPP__ */
/* end: */
