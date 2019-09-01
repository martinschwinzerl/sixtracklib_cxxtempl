#ifndef SIXTRACKLIB_COMMON_PARTICLES_TRACK_PARTICLE_C99_H__
#define SIXTRACKLIB_COMMON_PARTICLES_TRACK_PARTICLE_C99_H__

#include "sixtracklib/sixtracklib.h"

#if defined( __cplusplus )
extern "C" {
#endif /* defined( __cplusplus ) */

typedef struct NS(TrackParticle)
{
    NS(particle_real_t)  q0             SIXTRL_ALIGN( 8 ); /* C */
    NS(particle_real_t)  mass0          SIXTRL_ALIGN( 8 ); /* eV */
    NS(particle_real_t)  beta0          SIXTRL_ALIGN( 8 ); /* nounit */
    NS(particle_real_t)  gamma0         SIXTRL_ALIGN( 8 ); /* nounit */
    NS(particle_real_t)  p0c            SIXTRL_ALIGN( 8 ); /* eV */

    NS(particle_real_t)  s              SIXTRL_ALIGN( 8 ); /* [m] */
    NS(particle_real_t)  x              SIXTRL_ALIGN( 8 ); /* [m] */
    NS(particle_real_t)  y              SIXTRL_ALIGN( 8 ); /* [m] */
    NS(particle_real_t)  px             SIXTRL_ALIGN( 8 ); /* Px/P0 */
    NS(particle_real_t)  py             SIXTRL_ALIGN( 8 ); /* Py/P0 */
    NS(particle_real_t)  zeta           SIXTRL_ALIGN( 8 ); /* */

    NS(particle_real_t)  psigma         SIXTRL_ALIGN( 8 ); /* (E-E0)/(beta0 P0c) */
    NS(particle_real_t)  delta          SIXTRL_ALIGN( 8 ); /* P/P0-1 = 1/rpp-1 */
    NS(particle_real_t)  rpp            SIXTRL_ALIGN( 8 ); /* ratio P0 /P */
    NS(particle_real_t)  rvv            SIXTRL_ALIGN( 8 ); /* ratio beta / beta0 */
    NS(particle_real_t)  chi            SIXTRL_ALIGN( 8 ); /* q/q0 * m/m0 */
    NS(particle_real_t)  charge_ratio   SIXTRL_ALIGN( 8 ); /* ratio q/q0 */

    NS(particle_index_t) particle_id    SIXTRL_ALIGN( 8 );
    NS(particle_index_t) at_element_id  SIXTRL_ALIGN( 8 );
    NS(particle_index_t) at_turn        SIXTRL_ALIGN( 8 );
    NS(particle_index_t) state          SIXTRL_ALIGN( 8 );
}
NS(TrackParticle);

#if defined( __cplusplus )
}
#endif /* defined( __cplusplus ) */

#endif /* SIXTRACKLIB_COMMON_PARTICLES_TRACK_PARTICLE_C99_H__ */

/* end: cxx/common/particles/track_particle.h */
