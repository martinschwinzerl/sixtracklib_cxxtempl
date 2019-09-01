#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>

#include "xsimd/xsimd.hpp"

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/sixtracklib.hpp"

int main()
{
    namespace st = sixtrack;

    using sse_track_particle_t = sixtrack_cxx::XsimdTrackParticle< 2 >;
    using avx_track_particle_t = sixtrack_cxx::XsimdTrackParticle< 4 >;

    sse_track_particle_t sse_track_particle;
    avx_track_particle_t avx_track_particle;

    return 0;
}

/* end: examples/test_xsimd.cpp */

