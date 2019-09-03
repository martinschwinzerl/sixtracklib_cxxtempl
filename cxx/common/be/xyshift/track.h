#ifndef SIXTRACKLIB_COMMON_BE_XYSHIFT_TRACK_C99_H__
#define SIXTRACKLIB_COMMON_BE_XYSHIFT_TRACK_C99_H__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/track/definitions.h"

#include "cxx/common/particles/track_particle.h"
#include "cxx/common/be/xyshift/be_xyshift.h"

#if defined( __cplusplus )
extern "C" {
#endif /* C++ */

SIXTRL_STATIC SIXTRL_FN NS(track_status_t) NS(XYShift_track)(
    NS(TrackParticle)* SIXTRL_RESTRICT particle,
    const NS(BeXYShift) *const SIXTRL_RESTRICT_REF xy_shift )
{
    SIXTRL_ASSERT( particle != NULL );
    SIXTRL_ASSERT( xy_shift != NULL );

    particle->x -= xy_shift->dx;
    particle->y -= xy_shift->dy;

    return NS(TRACK_SUCCESS);
}

#if defined( __cplusplus )
}
#endif /* C++ */

#endif /* SIXTRACKLIB_COMMON_BE_XYSHIFT_TRACK_C99_H__ */

/* end: */
