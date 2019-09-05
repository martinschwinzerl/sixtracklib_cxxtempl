#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/buffer.h"
#include "sixtracklib/common/track/definitions.h"

#include "cxx/common/be/beam_elements.hpp"
#include "cxx/boost_multiprec/definitions.hpp"
#include "cxx/boost_multiprec/beam_elements.hpp"

#include <iomanip>
#include <iostream>
#include <type_traits>

int main()
{
    ::NS(Buffer)* original_lattice =
        ::NS(Buffer_new_from_file)( "./beam_elements.bin" );

    ::NS(Buffer)* mp_lattice = ::NS(Buffer_new)( 0u );


    ::NS(arch_status_t) status =
        sixtrack_cxx::BeamElements_convert_buffer_to_bmp< 100 >(
            original_lattice, mp_lattice );

    SIXTRL_ASSERT( status == ::NS(ARCH_STATUS_SUCCESS) );

    ::NS(Buffer_delete)( mp_lattice );
    ::NS(Buffer_delete)( original_lattice );

    return 0;
}

/* end: */
