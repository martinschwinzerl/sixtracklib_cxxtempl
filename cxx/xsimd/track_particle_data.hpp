#ifndef SIXTRACKLIB_XSIMD_PARTICLES_TRACK_PARTICLE_DATA_CXX_HPP__
#define SIXTRACKLIB_XSIMD_PARTICLES_TRACK_PARTICLE_DATA_CXX_HPP__

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

#include <xsimd/xsimd.hpp>

#include "sixtracklib/sixtracklib.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"

#include "cxx/common/particles/track_particle.h"
#include "cxx/common/particles/track_particle_data.hpp"

#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< unsigned N > using XsimdReal = xsimd::batch< double,  N >;
    template< unsigned N > using XsimdInt  = xsimd::batch< int64_t, N >;

    template< unsigned N > struct TypeStoreTraits< XsimdReal< N > >
    {
        static SIXTRL_FN constexpr std::size_t StorageAlign()
        {
            return sizeof( double ) * N;
        }

        static SIXTRL_FN constexpr bool Scalar()
        {
            return false;
        }
    };

    template< unsigned N > struct TypeStoreTraits< XsimdInt< N > >
    {
        static SIXTRL_FN constexpr std::size_t StorageAlign()
        {
            return sizeof( int64_t ) * N;
        }

        static SIXTRL_FN constexpr bool Scalar()
        {
            return false;
        }
    };

    /* --------------------------------------------------------------------- */

    template< unsigned N >
    struct XsimdTrackParticleData
    {
        typedef XsimdReal< N >                          real_t;
        typedef XsimdInt< N >                           int_t;

        typedef typename real_t::value_type             raw_real_t;
        typedef typename int_t::value_type              raw_int_t;

        typedef raw_real_t*                             ptr_raw_real_t;
        typedef raw_int_t*                              ptr_raw_int_t;

        typedef real_t*                                 ptr_simd_real_t;
        typedef int_t*                                  ptr_simd_int_t;

        typedef SIXTRL_CXX_NAMESPACE::arch_size_t       size_type;
        typedef SIXTRL_CXX_NAMESPACE::arch_status_t     status_t;

        static constexpr size_type Q0_INDEX              = size_type{  0 };
        static constexpr size_type MASS0_INDEX           = size_type{  1 };
        static constexpr size_type BETA0_INDEX           = size_type{  2 };
        static constexpr size_type GAMMA0_INDEX          = size_type{  3 };
        static constexpr size_type P0C_INDEX             = size_type{  4 };

        static constexpr size_type S_INDEX               = size_type{  5 };
        static constexpr size_type X_INDEX               = size_type{  6 };
        static constexpr size_type Y_INDEX               = size_type{  7 };
        static constexpr size_type PX_INDEX              = size_type{  8 };
        static constexpr size_type PY_INDEX              = size_type{  9 };
        static constexpr size_type ZETA_INDEX            = size_type{ 10 };

        static constexpr size_type PSIGMA_INDEX          = size_type{ 11 };
        static constexpr size_type DELTA_INDEX           = size_type{ 12 };
        static constexpr size_type RPP_INDEX             = size_type{ 13 };
        static constexpr size_type RVV_INDEX             = size_type{ 14 };
        static constexpr size_type CHI_INDEX             = size_type{ 15 };
        static constexpr size_type CHARGE_RATIO_INDEX    = size_type{ 16 };

        static constexpr size_type PARTICLE_ID_INDEX     = size_type{  0 };
        static constexpr size_type AT_ELEMENT_ID_INDEX   = size_type{  1 };
        static constexpr size_type AT_TURN_INDEX         = size_type{  2 };
        static constexpr size_type STATE_INDEX           = size_type{  3 };

        static constexpr size_type NUM_REAL_FIELDS       = size_type{ 17 };
        static constexpr size_type NUM_INT_FIELDS        = size_type{  4 };
        static constexpr size_type NUM_FIELDS            = size_type{ 21 };

        static SIXTRL_FN constexpr std::size_t
        RealAlignment() { return TypeStoreTraits< real_t >::StorageAlign(); }

        static SIXTRL_FN constexpr std::size_t
        IntegerAlignment() { return TypeStoreTraits< int_t >::StorageAlign(); }

        SIXTRL_FN XsimdTrackParticleData() :
            q0(), mass0(), beta0(), gamma0(), p0c(), s(), x(), y(), px(), py(),
            zeta(), psigma(), delta(), rpp(), rvv(), chi(), charge_ratio(),
            particle_id(), at_element_id(), at_turn(), state(),
            m_real_remainder_buffer(), m_int_remainder_buffer(),
            m_num_particles( size_type{ 0 } ),
            m_num_chunks( size_type{ 0 } ),
            m_num_remainders( size_type{ 0 } )
        {
            this->doInit();
        }

        SIXTRL_FN explicit XsimdTrackParticleData(
            SIXTRL_CXX_NAMESPACE::Particles& SIXTRL_RESTRICT_REF pset ):
            q0(), mass0(), beta0(), gamma0(), p0c(), s(), x(), y(), px(), py(),
            zeta(), psigma(), delta(), rpp(), rvv(), chi(), charge_ratio(),
            particle_id(), at_element_id(), at_turn(), state(),
            m_real_remainder_buffer(), m_int_remainder_buffer(),
            m_num_particles( size_type{ 0 } ),
            m_num_chunks( size_type{ 0 } ),
            m_num_remainders( size_type{ 0 } )
        {
            this->doInit();
            this->reset( pset );
        }

        SIXTRL_FN explicit XsimdTrackParticleData(
            ::NS(Particles)* SIXTRL_RESTRICT particle_set ) :
            q0(), mass0(), beta0(), gamma0(), p0c(), s(), x(), y(), px(), py(),
            zeta(), psigma(), delta(), rpp(), rvv(), chi(), charge_ratio(),
            particle_id(), at_element_id(), at_turn(), state(),
            m_real_remainder_buffer(), m_int_remainder_buffer(),
            m_num_particles( size_type{ 0 } ),
            m_num_chunks( size_type{ 0 } ),
            m_num_remainders( size_type{ 0 } )
        {
            this->doInit();
            this->reset( particle_set );
        }

        SIXTRL_FN XsimdTrackParticleData(
            XsimdTrackParticleData< N > const& other ) = default;

        SIXTRL_FN XsimdTrackParticleData(
            XsimdTrackParticleData< N >&& other ) = default;

        SIXTRL_FN XsimdTrackParticleData< N >& operator=(
            XsimdTrackParticleData< N > const& rhs ) = default;

        SIXTRL_FN XsimdTrackParticleData< N >& operator=(
            XsimdTrackParticleData< N >&& rhs ) = default;

        SIXTRL_FN virtual ~XsimdTrackParticleData() = default;

        /* ----------------------------------------------------------------- */

        SIXTRL_FN status_t reset(
            SIXTRL_CXX_NAMESPACE::Particles& SIXTRL_RESTRICT_REF pset )
        {
            typedef sixtrack_cxx::XsimdTrackParticleData< N > _this_t;

            this->m_real_field_ptrs[ _this_t::Q0_INDEX     ] = pset.getQ0();
            this->m_real_field_ptrs[ _this_t::MASS0_INDEX  ] = pset.getMass0();
            this->m_real_field_ptrs[ _this_t::BETA0_INDEX  ] = pset.getBeta0();
            this->m_real_field_ptrs[ _this_t::GAMMA0_INDEX ] = pset.getGamma0();
            this->m_real_field_ptrs[ _this_t::P0C_INDEX    ] = pset.getP0c();
            this->m_real_field_ptrs[ _this_t::S_INDEX      ] = pset.getS();
            this->m_real_field_ptrs[ _this_t::X_INDEX      ] = pset.getX();
            this->m_real_field_ptrs[ _this_t::Y_INDEX      ] = pset.getY();
            this->m_real_field_ptrs[ _this_t::PX_INDEX     ] = pset.getPx();
            this->m_real_field_ptrs[ _this_t::PY_INDEX     ] = pset.getPy();
            this->m_real_field_ptrs[ _this_t::ZETA_INDEX   ] = pset.getZeta();
            this->m_real_field_ptrs[ _this_t::PSIGMA_INDEX ] = pset.getPSigma();
            this->m_real_field_ptrs[ _this_t::DELTA_INDEX  ] = pset.getDelta();
            this->m_real_field_ptrs[ _this_t::RPP_INDEX    ] = pset.getRpp();
            this->m_real_field_ptrs[ _this_t::RVV_INDEX    ] = pset.getRvv();
            this->m_real_field_ptrs[ _this_t::CHI_INDEX    ] = pset.getChi();

            this->m_real_field_ptrs[ _this_t::CHARGE_RATIO_INDEX ] =
                pset.getChargeRatio();

            this->m_integer_field_ptrs[ _this_t::PARTICLE_ID_INDEX ] =
                pset.getParticleId();

            this->m_integer_field_ptrs[ _this_t::AT_ELEMENT_ID_INDEX ] =
                pset.getAtElementId();

            this->m_integer_field_ptrs[ _this_t::AT_TURN_INDEX ] =
                pset.getAtTurn();

            this->m_integer_field_ptrs[ _this_t::STATE_INDEX ] =
                pset.getState();

            return this->doReset( pset.getNumParticles() );
        }

        SIXTRL_FN status_t reset(
            ::NS(Particles)* SIXTRL_RESTRICT particle_set )
        {
            typedef sixtrack_cxx::XsimdTrackParticleData< N > _this_t;

            this->m_real_field_ptrs[ _this_t::Q0_INDEX ] =
                ::NS(Particles_get_q0)( particle_set );
            this->m_real_field_ptrs[ _this_t::MASS0_INDEX ] =
                ::NS(Particles_get_mass0)( particle_set );
            this->m_real_field_ptrs[ _this_t::BETA0_INDEX ] =
                ::NS(Particles_get_beta0)( particle_set );
            this->m_real_field_ptrs[ _this_t::GAMMA0_INDEX ] =
                ::NS(Particles_get_gamma0)( particle_set );
            this->m_real_field_ptrs[ _this_t::P0C_INDEX ] =
                ::NS(Particles_get_p0c)( particle_set );

            this->m_real_field_ptrs[ _this_t::S_INDEX ] =
                ::NS(Particles_get_s)( particle_set );
            this->m_real_field_ptrs[ _this_t::X_INDEX ] =
                ::NS(Particles_get_x)( particle_set );
            this->m_real_field_ptrs[ _this_t::Y_INDEX ] =
                ::NS(Particles_get_y)( particle_set );
            this->m_real_field_ptrs[ _this_t::PX_INDEX ] =
                ::NS(Particles_get_px)( particle_set );
            this->m_real_field_ptrs[ _this_t::PY_INDEX ] =
                ::NS(Particles_get_py)( particle_set );
            this->m_real_field_ptrs[ _this_t::ZETA_INDEX ] =
                ::NS(Particles_get_zeta)( particle_set );

            this->m_real_field_ptrs[ _this_t::PSIGMA_INDEX ] =
                ::NS(Particles_get_psigma)( particle_set );
            this->m_real_field_ptrs[ _this_t::DELTA_INDEX ] =
                ::NS(Particles_get_delta)( particle_set );
            this->m_real_field_ptrs[ _this_t::RPP_INDEX ] =
                ::NS(Particles_get_rpp)( particle_set );
            this->m_real_field_ptrs[ _this_t::RVV_INDEX ] =
                ::NS(Particles_get_rvv)( particle_set );
            this->m_real_field_ptrs[ _this_t::CHI_INDEX ] =
                ::NS(Particles_get_chi)( particle_set );
            this->m_real_field_ptrs[ _this_t::CHARGE_RATIO_INDEX ] =
                ::NS(Particles_get_charge_ratio)( particle_set );

            this->m_integer_field_ptrs[ _this_t::PARTICLE_ID_INDEX ] =
                ::NS(Particles_get_particle_id)( particle_set );
            this->m_integer_field_ptrs[ _this_t::AT_ELEMENT_ID_INDEX ] =
                ::NS(Particles_get_at_element_id)( particle_set );
            this->m_integer_field_ptrs[ _this_t::AT_TURN_INDEX ] =
                ::NS(Particles_get_at_turn)( particle_set );
            this->m_integer_field_ptrs[ _this_t::STATE_INDEX ] =
                ::NS(Particles_get_state)( particle_set );

            return this->doReset(
                ::NS(Particles_get_num_of_particles)( particle_set ) );
        }

        status_t reset( size_type const num_particles,
            ptr_raw_real_t ptr_real_data[ NUM_REAL_FIELDS ],
            ptr_raw_int_t  ptr_integer_data[ NUM_INT_FIELDS ] )
        {
            typedef sixtrack_cxx::XsimdTrackParticleData< N > _this_t;

            std::copy( &ptr_real_data[ 0 ],
                       &ptr_real_data[ _this_t::NUM_REAL_FIELDS ],
                       &this->m_real_field_ptrs[ 0 ] );

            std::copy( &ptr_integer_data[ 0 ],
                       &ptr_integer_data[ _this_t::NUM_INT_FIELDS ],
                       &this->m_integer_field_ptrs[ 0 ] );

            return this->doReset( num_particles );
        }

        SIXTRL_FN size_type numOfParticles() const SIXTRL_NOEXCEPT
        {
            return this->m_num_particles;
        }

        SIXTRL_FN size_type numOfChunks() const SIXTRL_NOEXCEPT
        {
            return this->m_num_chunks;
        }

        SIXTRL_FN size_type numRemainders() const SIXTRL_NOEXCEPT
        {
            return this->m_num_remainders;
        }

        SIXTRL_FN status_t load( size_type const particle_idx ) SIXTRL_NOEXCEPT
        {
            namespace st = SIXTRL_CXX_NAMESPACE;
            typedef sixtrack_cxx::XsimdTrackParticleData< N > _this_t;

            status_t status = st::ARCH_STATUS_GENERAL_FAILURE;
            SIXTRL_ASSERT( N > unsigned{ 0 } );
            SIXTRL_ASSERT( N % unsigned{ 2 } == unsigned{ 0 } );

            size_type const chunk_id = particle_idx / N;

            if( this->m_num_chunks > chunk_id )
            {
                status = st::ARCH_STATUS_SUCCESS;
                size_type const begin_offset = chunk_id * N;
                SIXTRL_ASSERT( begin_offset  < this->m_num_particles );
                size_type ii = size_type{ 0 };

                for( ; ii < _this_t::NUM_REAL_FIELDS ; ++ii )
                {
                    SIXTRL_ASSERT( this->m_real_field_ptrs[ ii ] != nullptr );
                    SIXTRL_ASSERT( this->m_ptr_real_simd_fields[ ii ] !=
                                   nullptr );

                    if( this->m_real_fields_aligned[ ii ] )
                    {
                        SIXTRL_ASSERT( std::uintptr_t{ 0 } ==
                            ( reinterpret_cast< std::uintptr_t >(
                                this->m_real_field_ptrs[ ii ] ) %
                                    _this_t::RealAlignment() ) );

                        this->m_ptr_real_simd_fields[ ii ].load_aligned(
                            &this->m_real_field_ptrs[ ii ][ begin_offset ] );
                    }
                    else
                    {
                        this->m_ptr_real_simd_fields[ ii ].load_unaligned(
                            &this->m_real_field_ptrs[ ii ][ begin_offset ] );
                    }
                }

                for( ii = size_type{ 0 } ; ii < _this_t::NUM_INT_FIELDS ; ++ii )
                {
                    SIXTRL_ASSERT( this->m_integer_field_ptrs[ ii ] != nullptr );
                    SIXTRL_ASSERT( this->m_ptr_integer_simd_fields[ ii ] !=
                                   nullptr );

                    if( this->m_integer_fields_aligned[ ii ] )
                    {
                        SIXTRL_ASSERT( std::uintptr_t{ 0 } ==
                            ( reinterpret_cast< std::uintptr_t >(
                                this->m_integer_field_ptrs[ ii ] ) %
                                    _this_t::IntegerAlignment() ) );

                        this->m_ptr_integer_simd_fields[ ii ].load_aligned(
                            &this->m_integer_field_ptrs[ ii ][ begin_offset ] );
                    }
                    else
                    {
                        this->m_ptr_integer_simd_fields[ ii ].load_unaligned(
                            &this->m_integer_field_ptrs[ ii ][ begin_offset ] );
                    }
                }
            }
            else if( ( chunk_id == this->m_num_chunks ) &&
                     ( particle_idx < this->m_num_particles ) )
            {
                status = st::ARCH_STATUS_SUCCESS;
                SIXTRL_ASSERT( ( particle_idx % N ) < this->m_num_remainders );

                size_type const begin_offset = this->m_num_chunks * N;
                size_type const end_offset   = this->m_num_particles;
                size_type ii = size_type{ 0 };

                for( ; ii < _this_t::NUM_REAL_FIELDS ; ++ii )
                {
                    SIXTRL_ASSERT( this->m_real_remainder_ptrs[ ii ] !=
                                   nullptr );

                    SIXTRL_ASSERT( this->m_ptr_real_simd_fields[ ii ] !=
                                   nullptr );

                    SIXTRL_ASSERT( std::uintptr_t{ 0 } == ( reinterpret_cast<
                        std::uintptr_t >( this->m_real_field_ptrs[ ii ] ) %
                            _this_t::RealAlignment() ) );

                    std::copy( &this->m_real_field_ptrs[ ii ][ begin_offset ],
                               &this->m_real_field_ptrs[ ii ][ end_offset ],
                               &this->m_real_remainder_buffer[ ii ][ 0 ] );

                    this->m_ptr_real_simd_fields[ ii ].load_aligned(
                        &this->m_real_remainder_ptrs[ ii ][ 0u ] );
                }

                for( ii = size_type{ 0 } ; ii < _this_t::NUM_INT_FIELDS ; ++ii )
                {
                    SIXTRL_ASSERT( this->m_integer_remainder_ptrs[ ii ] !=
                                   nullptr );

                    SIXTRL_ASSERT( this->m_ptr_integer_simd_fields[ ii ] !=
                                   nullptr );

                    SIXTRL_ASSERT( std::uintptr_t{ 0 } == ( reinterpret_cast<
                        std::uintptr_t >( this->m_integer_field_ptrs[ ii ] ) %
                            _this_t::IntegerAlignment() ) );

                    std::copy(
                        &this->m_integer_remainder_ptrs[ ii ][ begin_offset ],
                        &this->m_integer_remainder_ptrs[ ii ][ end_offset ],
                        &this->m_integer_remainder_ptrs[ ii ][ 0 ] );

                    this->m_ptr_integer_simd_fields[ ii ].load_aligned(
                            &this->m_integer_remainder_ptrs[ ii ][ 0 ] );
                }
            }

            return status;
        }

        SIXTRL_FN status_t store( size_type const particle_idx ) SIXTRL_NOEXCEPT
        {
            namespace st = SIXTRL_CXX_NAMESPACE;
            typedef sixtrack_cxx::XsimdTrackParticleData< N > _this_t;

            status_t status = st::ARCH_STATUS_GENERAL_FAILURE;
            SIXTRL_ASSERT( N > unsigned{ 0 } );
            SIXTRL_ASSERT( N % unsigned{ 2 } == unsigned{ 0 } );

            size_type const chunk_id = particle_idx / N;

            if( this->m_num_chunks > chunk_id )
            {
                status = st::ARCH_STATUS_SUCCESS;
                size_type const begin_offset = chunk_id * N;
                SIXTRL_ASSERT( begin_offset  < this->m_num_particles );
                size_type ii = size_type{ 0 };

                for( ; ii < _this_t::NUM_REAL_FIELDS ; ++ii )
                {
                    SIXTRL_ASSERT( this->m_real_field_ptrs[ ii ] != nullptr );
                    SIXTRL_ASSERT( this->m_ptr_real_simd_fields[ ii ] !=
                                   nullptr );

                    if( this->m_real_fields_aligned[ ii ] )
                    {
                        SIXTRL_ASSERT( std::uintptr_t{ 0 } ==
                            ( reinterpret_cast< std::uintptr_t >(
                                this->m_real_field_ptrs[ ii ] ) %
                                    _this_t::RealAlignment() ) );

                        this->m_ptr_real_simd_fields[ ii ].store_aligned(
                            &this->m_real_field_ptrs[ ii ][ begin_offset ] );
                    }
                    else
                    {
                        this->m_ptr_real_simd_fields[ ii ].store_unaligned(
                            &this->m_real_field_ptrs[ ii ][ begin_offset ] );
                    }
                }

                for( ii = size_type{ 0 } ; ii < _this_t::NUM_INT_FIELDS ; ++ii )
                {
                    SIXTRL_ASSERT( this->m_integer_field_ptrs[ ii ] != nullptr );
                    SIXTRL_ASSERT( this->m_ptr_integer_simd_fields[ ii ] !=
                                   nullptr );

                    if( this->m_integer_fields_aligned[ ii ] )
                    {
                        SIXTRL_ASSERT( std::uintptr_t{ 0 } ==
                            ( reinterpret_cast< std::uintptr_t >(
                                this->m_integer_field_ptrs[ ii ] ) %
                                    _this_t::IntegerAlignment() ) );

                        this->m_ptr_integer_simd_fields[ ii ].store_aligned(
                            &this->m_integer_field_ptrs[ ii ][ begin_offset ] );
                    }
                    else
                    {
                        this->m_ptr_integer_simd_fields[ ii ].store_unaligned(
                            &this->m_integer_field_ptrs[ ii ][ begin_offset ] );
                    }
                }
            }
            else if( ( chunk_id == this->m_num_chunks ) &&
                     ( particle_idx < this->m_num_particles ) )
            {
                status = st::ARCH_STATUS_SUCCESS;
                SIXTRL_ASSERT( ( particle_idx % N ) < this->m_num_remainders );

                size_type const begin_offset = this->m_num_chunks * N;
                size_type ii = size_type{ 0 };

                for( ; ii < _this_t::NUM_REAL_FIELDS ; ++ii )
                {
                    SIXTRL_ASSERT( this->m_real_remainder_ptrs[ ii ] !=
                                   nullptr );

                    SIXTRL_ASSERT( this->m_ptr_real_simd_fields[ ii ] !=
                                   nullptr );

                    SIXTRL_ASSERT( std::uintptr_t{ 0 } == ( reinterpret_cast<
                        std::uintptr_t >( this->m_real_field_ptrs[ ii ] ) %
                            _this_t::RealAlignment() ) );

                    this->m_ptr_real_simd_fields[ ii ].store_aligned(
                        &this->m_real_remainder_ptrs[ ii ][ 0u ] );

                    std::copy( &this->m_real_remainder_ptrs[ ii ][ 0u ],
                               &this->m_real_remainder_ptrs[ ii ][
                                this->m_num_remainders ],
                               &this->m_real_field_ptrs[ ii ][ begin_offset ] );
                }

                for( ii = size_type{ 0 } ; ii < _this_t::NUM_INT_FIELDS ; ++ii )
                {
                    SIXTRL_ASSERT( this->m_integer_remainder_ptrs[ ii ] !=
                                   nullptr );

                    SIXTRL_ASSERT( this->m_ptr_integer_simd_fields[ ii ] !=
                                   nullptr );

                    SIXTRL_ASSERT( std::uintptr_t{ 0 } == ( reinterpret_cast<
                        std::uintptr_t >( this->m_integer_field_ptrs[ ii ] ) %
                            _this_t::IntegerAlignment() ) );

                    this->m_ptr_integer_simd_fields[ ii ].store_aligned(
                            &this->m_integer_remainder_ptrs[ ii ][ 0 ] );

                    std::copy( &this->m_integer_remainder_ptrs[ ii ][ 0u ],
                               &this->m_integer_remainder_ptrs[ ii ][
                                this->m_num_remainders ],
                               &this->m_integer_field_ptrs[ ii ][
                                begin_offset ] );
                }
            }

            return status;
        }

        /* ----------------------------------------------------------------- */

        real_t q0;
        real_t mass0;
        real_t beta0;
        real_t gamma0;
        real_t p0c;

        real_t s;
        real_t x;
        real_t y;
        real_t px;
        real_t py;
        real_t zeta;

        real_t psigma;
        real_t delta;
        real_t rpp;
        real_t rvv;
        real_t chi;
        real_t charge_ratio;

        int_t  particle_id;
        int_t  at_element_id;
        int_t  at_turn;
        int_t  state;

        private:

        typedef std::vector< raw_real_t, XSIMD_DEFAULT_ALLOCATOR( raw_real_t ) >
                real_remainder_buffer_t;

        typedef std::vector< raw_int_t, XSIMD_DEFAULT_ALLOCATOR( raw_int_t ) >
                int_remainder_buffer_t;

        SIXTRL_FN status_t doInit() SIXTRL_NOEXCEPT
        {
            namespace st = SIXTRL_CXX_NAMESPACE;
            typedef XsimdTrackParticleData< N > _this_t;

            SIXTRL_ASSERT( N > unsigned{ 0 } );
            SIXTRL_ASSERT( N % unsigned{ 2 } == 0 );

            this->m_ptr_real_simd_fields[ _this_t::Q0_INDEX     ] = &this->q0;
            this->m_ptr_real_simd_fields[ _this_t::MASS0_INDEX  ] = &this->mass0;
            this->m_ptr_real_simd_fields[ _this_t::BETA0_INDEX  ] = &this->beta0;
            this->m_ptr_real_simd_fields[ _this_t::GAMMA0_INDEX ] = &this->gamma0;
            this->m_ptr_real_simd_fields[ _this_t::P0C_INDEX    ] = &this->p0c;

            this->m_ptr_real_simd_fields[ _this_t::S_INDEX      ] = &this->s;
            this->m_ptr_real_simd_fields[ _this_t::X_INDEX      ] = &this->x;
            this->m_ptr_real_simd_fields[ _this_t::Y_INDEX      ] = &this->y;
            this->m_ptr_real_simd_fields[ _this_t::PX_INDEX     ] = &this->px;
            this->m_ptr_real_simd_fields[ _this_t::PY_INDEX     ] = &this->py;
            this->m_ptr_real_simd_fields[ _this_t::ZETA_INDEX   ] = &this->zeta;

            this->m_ptr_real_simd_fields[ _this_t::PSIGMA_INDEX ] = &this->psigma;
            this->m_ptr_real_simd_fields[ _this_t::DELTA_INDEX  ] = &this->delta;
            this->m_ptr_real_simd_fields[ _this_t::RPP_INDEX    ] = &this->rpp;
            this->m_ptr_real_simd_fields[ _this_t::RVV_INDEX    ] = &this->rvv;
            this->m_ptr_real_simd_fields[ _this_t::CHI_INDEX    ] = &this->chi;
            this->m_ptr_real_simd_fields[ _this_t::CHARGE_RATIO_INDEX ] =
                &this->charge_ratio;

            this->m_ptr_integer_simd_fields[ _this_t::PARTICLE_ID_INDEX ] =
                &this->particle_id;

            this->m_ptr_integer_simd_fields[ _this_t::AT_ELEMENT_ID_INDEX ] =
                &this->at_element_id;

            this->m_ptr_integer_simd_fields[ _this_t::AT_TURN_INDEX ] =
                &this->at_turn;

            this->m_ptr_integer_simd_fields[ _this_t::STATE_INDEX ] =
                &this->state;

            /* ------------------------------------------------------------- */

            this->m_real_remainder_buffer.resize(
                N * _this_t::NUM_REAL_FIELDS, _this_t::raw_real_t{ 0 } );

            ptr_raw_real_t ptr_real_rem = this->m_real_remainder_buffer.data();
            size_type ii = size_type{ 0 };

            for( ; ii < _this_t::NUM_REAL_FIELDS ; ++ii )
            {
                SIXTRL_ASSERT( _this_t::RealAlignment() > size_type{ 0 } );
                SIXTRL_ASSERT( ( reinterpret_cast< std::uintptr_t >(
                    ptr_real_rem ) % _this_t::RealAlignment() ) ==
                        std::uintptr_t{ 0 } );

                this->m_real_field_ptrs[ ii ] = nullptr;
                this->m_real_remainder_ptrs[ ii ] = ptr_real_rem;
                std::advance( ptr_real_rem, N );
            }

            this->m_int_remainder_buffer.resize(
                N * _this_t::NUM_INT_FIELDS, _this_t::raw_int_t{ 0 } );

            ptr_raw_int_t  ptr_int_rem  = this->m_int_remainder_buffer.data();

            for( ii = size_type{ 0 } ; ii < _this_t::NUM_INT_FIELDS ; ++ii )
            {
                SIXTRL_ASSERT( ( reinterpret_cast< std::uintptr_t >(
                    ptr_int_rem ) % _this_t::IntegerAlignment() ) ==
                        std::uintptr_t{ 0 } );

                this->m_integer_field_ptrs[ ii ] = nullptr;
                this->m_integer_remainder_ptrs[ ii ] = ptr_int_rem;
                std::advance( ptr_int_rem, N );
            }

            return st::ARCH_STATUS_SUCCESS;
        }

        SIXTRL_FN status_t doReset(
            size_type const num_particles ) SIXTRL_NOEXCEPT
        {
            namespace st = SIXTRL_CXX_NAMESPACE;
            typedef sixtrack_cxx::XsimdTrackParticleData< N > _this_t;

            status_t status = st::ARCH_STATUS_SUCCESS;

            if( ( num_particles > size_type{ 0 } ) && ( N > unsigned{ 0 } ) &&
                ( ( N % unsigned{ 2 } ) == unsigned{ 0 } ) )
            {
                status = st::ARCH_STATUS_SUCCESS;

                size_type ii = size_type{ 0 };
                for( ; ii < _this_t::NUM_REAL_FIELDS ; ++ii )
                {
                    if( ( this->m_real_field_ptrs[ ii ] == nullptr ) ||
                        ( this->m_real_remainder_ptrs[ ii ] == nullptr ) ||
                        ( this->m_ptr_real_simd_fields[ ii ] == nullptr ) )
                    {
                        status = st::ARCH_STATUS_GENERAL_FAILURE;
                        break;
                    }

                    this->m_real_fields_aligned[ ii ] = ( std::uintptr_t{ 0 } ==
                        ( reinterpret_cast< std::uintptr_t >(
                            this->m_real_field_ptrs[ ii ] ) %
                                _this_t::RealAlignment() ) );
                }

                if( status != st::ARCH_STATUS_SUCCESS ) return status;

                ii = size_type{ 0 };
                for( ; ii < _this_t::NUM_INT_FIELDS ; ++ii )
                {
                    if( ( this->m_integer_field_ptrs[ ii ] == nullptr ) ||
                        ( this->m_integer_remainder_ptrs[ ii ] == nullptr ) ||
                        ( this->m_ptr_integer_simd_fields[ ii ] == nullptr ) )
                    {
                        status = st::ARCH_STATUS_GENERAL_FAILURE;
                        break;
                    }

                    this->m_integer_fields_aligned[ ii ] = ( std::uintptr_t{ 0 }
                        == ( reinterpret_cast< std::uintptr_t >(
                            this->m_integer_field_ptrs[ ii ] ) %
                                _this_t::IntegerAlignment() ) );
                }

                if( status == st::ARCH_STATUS_SUCCESS )
                {
                    this->m_num_particles  = num_particles;
                    this->m_num_chunks     = num_particles / N;
                    this->m_num_remainders =
                        num_particles - this->m_num_chunks * N;
                }
            }

            return status;
        }

        ptr_raw_real_t m_real_field_ptrs[ NUM_REAL_FIELDS ];
        ptr_raw_real_t m_real_remainder_ptrs[ NUM_REAL_FIELDS ];
        real_t*        m_ptr_real_simd_fields[ NUM_REAL_FIELDS ];

        ptr_raw_int_t  m_integer_field_ptrs[ NUM_INT_FIELDS ];
        ptr_raw_int_t  m_integer_remainder_ptrs[ NUM_INT_FIELDS ];
        int_t*         m_ptr_integer_simd_fields[ NUM_INT_FIELDS ];

        bool           m_real_fields_aligned[ NUM_REAL_FIELDS ];
        bool           m_integer_fields_aligned[ NUM_INT_FIELDS ];


        real_remainder_buffer_t m_real_remainder_buffer;
        int_remainder_buffer_t  m_int_remainder_buffer;

        size_type               m_num_particles;
        size_type               m_num_chunks;
        size_type               m_num_remainders;
    };
}


#endif /* SIXTRACKLIB_XSIMD_PARTICLES_TRACK_PARTICLE_DATA_CXX_HPP__ */
/* end: cxx/xsimd/track_particle_data.hpp */
