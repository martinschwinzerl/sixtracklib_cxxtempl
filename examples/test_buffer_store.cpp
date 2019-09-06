#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/track/definitions.h"
#include "sixtracklib/common/buffer.h"

#include <iostream>
#include <iomanip>

#include "cxx/boost_multiprec/definitions.hpp"
#include "cxx/boost_multiprec/beam_elements.hpp"
#include "cxx/common/be/cavity/be_cavity.hpp"

int main()
{
    namespace st    = SIXTRL_CXX_NAMESPACE;
    namespace stcxx = sixtrack_cxx;
    using size_t    = ::NS(buffer_size_t);

    using cxx_cavity_t = sixtrack_cxx::BeCavity;
    using c99_cavity_t = sixtrack_cxx::CBeCavity;

    ::NS(Buffer)* buffer = ::NS(Buffer_new)( size_t{ 0 } );

    SIXTRL_ASSERT( cxx_cavity_t::SupportsCObjectsStorage() );
    SIXTRL_ASSERT( c99_cavity_t::SupportsCObjectsStorage() );

    cxx_cavity_t cavity_a;
    cavity_a.init();

    std::cout << "cavity_a : "
              << "voltage   = " << cavity_a.voltage << "\r\n"
              << "frequency = " << cavity_a.frequency  << "\r\n"
              << "lag       = " << cavity_a.lag << std::endl;

    cxx_cavity_t cavity_b( 1e6, 400e6, 0.5 );

    std::cout << "cavity_b : "
              << "voltage   = " << cavity_b.voltage << "\r\n"
              << "frequency = " << cavity_b.frequency  << "\r\n"
              << "lag       = " << cavity_b.lag << std::endl;

    /* Store C++ Cavities on the buffer */

    cxx_cavity_t* ptr_cxx_cavity_0 =
        cxx_cavity_t::CreateNewObject( buffer );

    SIXTRL_ASSERT( ptr_cxx_cavity_0 != nullptr );

    std::cout << "cavity_0 : "
              << "voltage   = " << ptr_cxx_cavity_0->voltage << "\r\n"
              << "frequency = " << ptr_cxx_cavity_0->frequency  << "\r\n"
              << "lag       = " << ptr_cxx_cavity_0->lag << std::endl;

    cxx_cavity_t* ptr_cxx_cavity_1 =
        cxx_cavity_t::AddObject( buffer, 137e3, 55e3, 42.0 );

    SIXTRL_ASSERT( ptr_cxx_cavity_1 != nullptr );

    std::cout << "cavity_1 : "
              << "voltage   = " << ptr_cxx_cavity_1->voltage << "\r\n"
              << "frequency = " << ptr_cxx_cavity_1->frequency  << "\r\n"
              << "lag       = " << ptr_cxx_cavity_1->lag << std::endl;

    cxx_cavity_t* ptr_cxx_cavity_2 = cavity_a.storeCopy( buffer );

    SIXTRL_ASSERT( ptr_cxx_cavity_2 != nullptr );
    SIXTRL_ASSERT( ptr_cxx_cavity_2 != &cavity_a );

    ptr_cxx_cavity_2->voltage = 260e6;
    ptr_cxx_cavity_2->lag = 0.25 * sixtrack_cxx::MathConstants< double >::Pi();

    std::cout << "cavity_2 : "
              << "voltage   = " << ptr_cxx_cavity_2->voltage << "\r\n"
              << "frequency = " << ptr_cxx_cavity_2->frequency  << "\r\n"
              << "lag       = " << ptr_cxx_cavity_2->lag << std::endl;

    c99_cavity_t* ptr_c99_cavity_3 = c99_cavity_t::CreateNewObject( buffer );

    SIXTRL_ASSERT( ptr_c99_cavity_3 != nullptr );
    ptr_c99_cavity_3->voltage   = cavity_b.voltage;
    ptr_c99_cavity_3->frequency = cavity_b.frequency;
    ptr_c99_cavity_3->lag       = cavity_b.lag;

    std::cout << "cavity_3 : "
              << "voltage   = " << ptr_c99_cavity_3->voltage << "\r\n"
              << "frequency = " << ptr_c99_cavity_3->frequency  << "\r\n"
              << "lag       = " << ptr_c99_cavity_3->lag << std::endl;

    c99_cavity_t* ptr_c99_cavity_4 = c99_cavity_t::AddObject(
        buffer, 10e3, 256.0, 2 * sixtrack_cxx::MathConstants< double >::Pi() );

    SIXTRL_ASSERT( ptr_c99_cavity_4 != nullptr );
    std::cout << "cavity_4 : "
              << "voltage   = " << ptr_c99_cavity_4->voltage << "\r\n"
              << "frequency = " << ptr_c99_cavity_4->frequency  << "\r\n"
              << "lag       = " << ptr_c99_cavity_4->lag << std::endl;

    /* Access the C++ cavities 0, 1, and 2 as C99 Cavities;
     * Access the C99 cavities 3 and 4 as C++ Cavities: */

    SIXTRL_ASSERT( cxx_cavity_t::HasCApiMemoryLayout() );
    SIXTRL_ASSERT( c99_cavity_t::HasCApiMemoryLayout() );

    /* Note: Buffer has grown, so we have to get the already inserted cavities
     * as well (with the exception of the last one); Then, even the addresses
     * should be identical */

    ptr_cxx_cavity_0 = cxx_cavity_t::GetObj( buffer, 0 );
    ptr_cxx_cavity_1 = cxx_cavity_t::GetObj( buffer, 1 );
    ptr_cxx_cavity_2 = cxx_cavity_t::GetObj( buffer, 2 );

    c99_cavity_t const* ptr_c99_cavity_0 = c99_cavity_t::GetConstObj( buffer, 0 );
    SIXTRL_ASSERT( ptr_c99_cavity_0 != nullptr );
    SIXTRL_ASSERT( reinterpret_cast< std::uintptr_t >( ptr_cxx_cavity_0 ) ==
                   reinterpret_cast< std::uintptr_t >( ptr_c99_cavity_0 ) );

    std::cout << "cavity_0 : \r\n"
              << "C++:voltage   = "
              << std::setw( 12 ) << ptr_cxx_cavity_0->voltage
              << " | C99: voltage   = "
              << std::setw( 12 ) << ptr_c99_cavity_0->voltage
              << "\r\n"
              << "C++:frequency = "
              << std::setw( 12 ) << ptr_cxx_cavity_0->frequency
              << " | C99:frequency = "
              << std::setw( 12 ) << ptr_c99_cavity_0->frequency
              << "\r\n"
              << "C++:lag       = "
              << std::setw( 12 ) << ptr_cxx_cavity_0->lag
              << " | C99:lag       = "
              << std::setw( 12 ) << ptr_c99_cavity_0->lag
              << "\r\n" << std::endl;

    c99_cavity_t const* ptr_c99_cavity_1 = c99_cavity_t::GetConstObj( buffer, 1 );
    SIXTRL_ASSERT( ptr_c99_cavity_1 != nullptr );
    SIXTRL_ASSERT( reinterpret_cast< std::uintptr_t >( ptr_cxx_cavity_1 ) ==
                   reinterpret_cast< std::uintptr_t >( ptr_c99_cavity_1 ) );

    std::cout << "cavity_1 : \r\n"
              << "C++:voltage   = "
              << std::setw( 12 ) << ptr_cxx_cavity_1->voltage
              << " | C99: voltage   = "
              << std::setw( 12 ) << ptr_c99_cavity_1->voltage
              << "\r\n"
              << "C++:frequency = "
              << std::setw( 12 ) << ptr_cxx_cavity_1->frequency
              << " | C99:frequency = "
              << std::setw( 12 ) << ptr_c99_cavity_1->frequency
              << "\r\n"
              << "C++:lag       = "
              << std::setw( 12 ) << ptr_cxx_cavity_1->lag
              << " | C99:lag       = "
              << std::setw( 12 ) << ptr_c99_cavity_1->lag
              << "\r\n" << std::endl;

    c99_cavity_t const* ptr_c99_cavity_2 = c99_cavity_t::GetConstObj( buffer, 2 );
    SIXTRL_ASSERT( ptr_c99_cavity_2 != nullptr );
    SIXTRL_ASSERT( reinterpret_cast< std::uintptr_t >( ptr_cxx_cavity_2 ) ==
                   reinterpret_cast< std::uintptr_t >( ptr_c99_cavity_2 ) );

    std::cout << "cavity_2 : \r\n"
              << "C++:voltage   = "
              << std::setw( 12 ) << ptr_cxx_cavity_2->voltage
              << " | C99: voltage   = "
              << std::setw( 12 ) << ptr_c99_cavity_2->voltage
              << "\r\n"
              << "C++:frequency = "
              << std::setw( 12 ) << ptr_cxx_cavity_2->frequency
              << " | C99:frequency = "
              << std::setw( 12 ) << ptr_c99_cavity_2->frequency
              << "\r\n"
              << "C++:lag       = "
              << std::setw( 12 ) << ptr_cxx_cavity_2->lag
              << " | C99:lag       = "
              << std::setw( 12 ) << ptr_c99_cavity_2->lag
              << "\r\n" << std::endl;

    using mp_cavity_100_t = sixtrack_cxx::BeCavityInterface<
        sixtrack_cxx::BMPBeCavityData< 100 > >;

    mp_cavity_100_t mp_cavity_a;
    mp_cavity_a.init();

    using mp_cavity_200_t = sixtrack_cxx::BeCavityInterface<
        sixtrack_cxx::BMPBeCavityData< 200 > >;

    mp_cavity_200_t mp_cavity_b( 1e6, 400e6, 0.5 );

    std::cout << "mp_cavity_a : "
              << "voltage   = " << mp_cavity_a.voltage << "\r\n"
              << "frequency = " << mp_cavity_a.frequency  << "\r\n"
              << "lag       = " << mp_cavity_a.lag << std::endl;

    std::cout << "mp_cavity_b : "
              << "voltage   = " << mp_cavity_b.voltage << "\r\n"
              << "frequency = " << mp_cavity_b.frequency  << "\r\n"
              << "lag       = " << mp_cavity_b.lag << std::endl;

    SIXTRL_ASSERT( ::NS(Buffer_get_num_of_objects)( buffer ) == std::size_t{ 5 } );

    mp_cavity_100_t* ptr_mp_cavity_5 = mp_cavity_100_t::CreateNewObject( buffer );
    SIXTRL_ASSERT( ptr_mp_cavity_5 != nullptr );

    SIXTRL_ASSERT( ::NS(Buffer_get_const_object)( buffer, 5 ) != nullptr );
    SIXTRL_ASSERT( ::NS(Buffer_get_const_object)( buffer, 5 )->begin_addr != 0u );

    std::cout << "object_id->type_id : " << std::hex
              << ::NS(Buffer_get_const_object)( buffer, 5 )->type_id
              << std::endl;

    SIXTRL_ASSERT( ::NS(Buffer_get_const_object)( buffer, 5 )->type_id !=
                   st::OBJECT_TYPE_CAVITY );
    SIXTRL_ASSERT( ::NS(Buffer_get_const_object)( buffer, 5 )->type_id ==
                   ( sixtrack_cxx::BMPObjIdVariant< 100 >::GetVariantFlag() |
                     SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY ) );

    SIXTRL_ASSERT( ::NS(Buffer_get_const_object)( buffer, 5 )->type_id !=
                   ( sixtrack_cxx::BMPObjIdVariant< 200 >::GetVariantFlag() |
                     SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY ) );

    std::cout << "ptr_mp_cavity_5 : "
              << "voltage   = " << ptr_mp_cavity_5->voltage << "\r\n"
              << "frequency = " << ptr_mp_cavity_5->frequency  << "\r\n"
              << "lag       = " << ptr_mp_cavity_5->lag << std::endl;

    ptr_mp_cavity_5->init( 512e6, 100.0e6, 0.12345 );

    std::cout << "ptr_mp_cavity_5 : "
              << "voltage   = " << ptr_mp_cavity_5->voltage << "\r\n"
              << "frequency = " << ptr_mp_cavity_5->frequency  << "\r\n"
              << "lag       = " << ptr_mp_cavity_5->lag << std::endl;




    ::NS(Buffer_delete)( buffer );

    return 0;
}

/* end: */
