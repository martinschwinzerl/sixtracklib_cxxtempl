#ifndef SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_C99_H__
#define SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_C99_H__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#if defined( __cplusplus )

#include "cxx/common/be/cavity/be_cavity_traits.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

extern "C" {
#endif /* defined( __cplusplus ) */

typedef double  NS(be_cavity_real_t);

typedef struct NS(BeCavity)
{
    NS(be_cavity_real_t) voltage   SIXTRL_ALIGN( 8 );
    NS(be_cavity_real_t) frequency SIXTRL_ALIGN( 8 );
    NS(be_cavity_real_t) lag       SIXTRL_ALIGN( 8 );
}
NS(BeCavity);

#if defined( __cplusplus )
}

/* ------------------------------------------------------------------------- */

namespace sixtrack_cxx
{
    void BeCavityData_init(
        ::NS(BeCavity)& SIXTRL_RESTRICT_REF cavity,
        ::NS(be_cavity_real_t) const voltage = ::NS(be_cavity_real_t){ 0 },
        ::NS(be_cavity_real_t) const frequency = ::NS(be_cavity_real_t){ 0 },
        ::NS(be_cavity_real_t) const lag = ::NS(be_cavity_real_t){ 0 } )
    {
        cavity.voltage   = voltage;
        cavity.frequency = frequency;
        cavity.lag       = lag;
    }

    template<> struct ObjDataStoreTraits< ::NS(BeCavity) >
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

    template<> struct ObjDataTrackTraits< ::NS(BeCavity) >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY;
        }
    };

    template<> struct BeCavityTraits< ::NS(BeCavity) >
    {
        typedef ::NS(be_cavity_real_t) real_t;
    };
}

#endif /* C++ */

#endif /* SIXTRACKLIB_COMMON_BE_CAVITY_BE_CAVITY_C99_H__ */
/* end: */
