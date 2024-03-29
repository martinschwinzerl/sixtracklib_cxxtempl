#ifndef SIXTRACKLIB_BOOST_MULTIPREC_BEAM_ELEMENTS_CXX_HPP_42__
#define SIXTRACKLIB_BOOST_MULTIPREC_BEAM_ELEMENTS_CXX_HPP_42__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"
#include "sixtracklib/common/control/definitions.h"
#include "sixtracklib/common/buffer.h"

#include "cxx/ext_libs.h"
#include "cxx/boost_multiprec/definitions.hpp"
#include "cxx/common/be/multipole/definitions.h"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

namespace sixtrack_cxx
{
    template< unsigned N > struct BMPObjIdVariant
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) GetVariantFlag()
        {
            return ::NS(object_type_id_t){ 0x10000 } |
                ( static_cast< ::NS(object_type_id_t) >( N ) &
                  ::NS(object_type_id_t){ 0xff } ) << 24;
        }
    };

    /* ********************************************************************* */

    template< unsigned N > struct BMPBeCavityData
    {
        using real_t = sixtrack_cxx::mp_float_n_t< N >;
        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        real_t  voltage   SIXTRL_ALIGN( 8 );
        real_t  frequency SIXTRL_ALIGN( 8 );
        real_t  lag       SIXTRL_ALIGN( 8 );
    };

    template< unsigned N > struct ObjDataStoreTraits<
        sixtrack_cxx::BMPBeCavityData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits<
        sixtrack_cxx::BMPBeCavityData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY;
        }
    };

    template< unsigned N > struct ObjDataStoreConstructionTraits<
        sixtrack_cxx::BMPBeCavityData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };

    /* --------------------------------------------------------------------- */

    template< unsigned N > struct BMPBeDipoleEdgeData
    {
        using real_t = sixtrack_cxx::mp_float_n_t< N >;
        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        real_t r21 SIXTRL_ALIGN( 8 );
        real_t r43 SIXTRL_ALIGN( 8 );
    };

    template< unsigned N > struct ObjDataStoreTraits<
        sixtrack_cxx::BMPBeDipoleEdgeData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits<
        sixtrack_cxx::BMPBeDipoleEdgeData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DIPEDGE;
        }
    };

    template< unsigned N > struct ObjDataStoreConstructionTraits<
        sixtrack_cxx::BMPBeDipoleEdgeData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };

    /* --------------------------------------------------------------------- */

    template< unsigned N > struct BMPBeDriftData
    {
        using real_t = sixtrack_cxx::mp_float_n_t< N >;
        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        real_t length SIXTRL_ALIGN( 8 );
    };

    template< unsigned N > struct ObjDataStoreTraits<
        sixtrack_cxx::BMPBeDriftData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits<
        sixtrack_cxx::BMPBeDriftData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT;
        }
    };

    template< unsigned N > struct ObjDataStoreConstructionTraits<
        sixtrack_cxx::BMPBeDriftData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };

    /* --------------------------------------------------------------------- */

    template< unsigned N > struct BMPBeDriftExactData
    {
        using real_t = sixtrack_cxx::mp_float_n_t< N >;
        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        real_t length SIXTRL_ALIGN( 8 );
    };

    template< unsigned N > struct ObjDataStoreTraits<
        sixtrack_cxx::BMPBeDriftExactData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits<
        sixtrack_cxx::BMPBeDriftExactData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT;
        }
    };

    template< unsigned N > struct ObjDataStoreConstructionTraits<
        sixtrack_cxx::BMPBeDriftExactData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };

    /* --------------------------------------------------------------------- */

    template< unsigned N > struct BMPBeLimitRectData
    {
        using real_t = sixtrack_cxx::mp_float_n_t< N >;
        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        real_t min_x SIXTRL_ALIGN( 8 );
        real_t max_x SIXTRL_ALIGN( 8 );

        real_t min_y SIXTRL_ALIGN( 8 );
        real_t max_y SIXTRL_ALIGN( 8 );
    };

    template< unsigned N > struct ObjDataStoreTraits<
        sixtrack_cxx::BMPBeLimitRectData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits<
        sixtrack_cxx::BMPBeLimitRectData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_RECT;
        }
    };

    template< unsigned N > struct ObjDataStoreConstructionTraits<
        sixtrack_cxx::BMPBeLimitRectData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };

    /* --------------------------------------------------------------------- */

    template< unsigned N > struct BMPBeLimitEllipseData
    {
        using real_t = sixtrack_cxx::mp_float_n_t< N >;
        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        real_t a_squ   SIXTRL_ALIGN( 8 );
        real_t b_squ   SIXTRL_ALIGN( 8 );
        real_t a_b_squ SIXTRL_ALIGN( 8 );
    };

    template< unsigned N > struct ObjDataStoreTraits<
        sixtrack_cxx::BMPBeLimitEllipseData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits<
        sixtrack_cxx::BMPBeLimitEllipseData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_LIMIT_ELLIPSE;
        }
    };

    template< unsigned N > struct ObjDataStoreConstructionTraits<
        sixtrack_cxx::BMPBeLimitEllipseData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };

    /* --------------------------------------------------------------------- */

    template< unsigned N > struct BMPBeMultipoleData
    {
        using real_t  = sixtrack_cxx::mp_float_n_t< N >;
        using order_t = ::NS(be_multipole_order_t);
        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        order_t order SIXTRL_ALIGN(
            sixtrack_cxx::TypeStoreTraits< order_t* >::StorageAlign() );

        real_t  length SIXTRL_ALIGN( 8 );
        real_t  hxl    SIXTRL_ALIGN( 8 );
        real_t  hyl    SIXTRL_ALIGN( 8 );
        real_t* bal    SIXTRL_ALIGN( 8 );
    };

    template< unsigned N > struct ObjDataStoreTraits< BMPBeMultipoleData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits< BMPBeMultipoleData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_MULTIPOLE;
        }
    };

    template< unsigned N >
    struct ObjDataStoreConstructionTraits< BMPBeMultipoleData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };

    template< unsigned N >
    struct ObjDataStoreLayoutTraits< BMPBeMultipoleData< N > >
    {
        typedef sixtrack_cxx::BMPBeMultipoleData< N > _obj_data_t;
        typedef sixtrack_cxx::ObjDataStoreLayoutTraits< _obj_data_t >
                _obj_data_store_layout_traits_t;

        typedef ::NS(buffer_size_t) size_type;
        typedef ::NS(arch_status_t) status_t;

        static SIXTRL_FN constexpr size_type NumDataPtrs() { return size_type{ 1 }; }
        static SIXTRL_FN constexpr bool VarNumDataPtrCounts() { return true; }

        static SIXTRL_FN status_t GetDataPtrTypeOffsets(
            size_type* SIXTRL_RESTRICT offsets_begin )
        {
            if( offsets_begin != nullptr )
            {
                *offsets_begin = offsetof( _obj_data_t, bal );
                return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_SUCCESS;
            }

            return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_GENERAL_FAILURE;
        }

        static SIXTRL_FN status_t GetDataPtrTypeSizes(
            size_type* SIXTRL_RESTRICT sizes_begin )
        {
            if( sizes_begin != nullptr )
            {
                *sizes_begin = sizeof( typename _obj_data_t::real_t );
                return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_SUCCESS;
            }

            return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_GENERAL_FAILURE;
        }

        static SIXTRL_FN status_t GetDataPtrTypeCounts(
            const _obj_data_t *const SIXTRL_RESTRICT mp_data,
            size_type* SIXTRL_RESTRICT counts_begin )
        {
            typedef typename _obj_data_t::order_t order_t;

            if( counts_begin != nullptr )
            {
                if( ( mp_data != nullptr ) && ( mp_data->order >= order_t{ 0 } ) )
                {
                    *counts_begin = static_cast< size_type >( 2 ) * (
                        mp_data->order + order_t{ 1 } );
                }
                else
                {
                    *counts_begin = size_type{ 0 };
                }

                return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_SUCCESS;
            }

            return SIXTRL_CXX_NAMESPACE::ARCH_STATUS_GENERAL_FAILURE;
        }
    };

    /* --------------------------------------------------------------------- */

    template< unsigned N > struct BMPBeSRotationData
    {
        using real_t = sixtrack_cxx::mp_float_n_t< N >;
        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        real_t cos_z SIXTRL_ALIGN( 8 );
        real_t sin_z SIXTRL_ALIGN( 8 );
    };

    template< unsigned N >
    struct ObjDataStoreTraits< sixtrack_cxx::BMPBeSRotationData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits<
        sixtrack_cxx::BMPBeSRotationData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_SROTATION;
        }
    };

    template< unsigned N > struct ObjDataStoreConstructionTraits<
        sixtrack_cxx::BMPBeSRotationData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };

    /* --------------------------------------------------------------------- */

    template< unsigned N > struct BMPBeXYShiftData
    {
        using real_t = sixtrack_cxx::mp_float_n_t< N >;
        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        real_t dx SIXTRL_ALIGN( 8 );
        real_t dy SIXTRL_ALIGN( 8 );
    };

    template< unsigned N >
    struct ObjDataStoreTraits< sixtrack_cxx::BMPBeXYShiftData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_XYSHIFT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits<
        sixtrack_cxx::BMPBeXYShiftData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_XYSHIFT;
        }
    };

    template< unsigned N > struct ObjDataStoreConstructionTraits<
        sixtrack_cxx::BMPBeXYShiftData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };
}

/* ************************************************************************* */

#include "cxx/common/be/beam_elements.h"
#include "cxx/common/be/beam_elements.hpp"

namespace sixtrack_cxx
{
    template< unsigned N >
    ::NS(arch_status_t) BeamElements_convert_buffer_to_bmp(
        const ::NS(Buffer) *const SIXTRL_RESTRICT input_buffer,
        ::NS(Buffer)* SIXTRL_RESTRICT output_buffer )
    {
        using real_t = sixtrack_cxx::mp_float_n_t< N >;
        using mp_cavity_n_t = sixtrack_cxx::BeCavityInterface<
            sixtrack_cxx::BMPBeCavityData< N > >;

        using mp_drift_n_t = sixtrack_cxx::BeDriftInterface<
            sixtrack_cxx::BMPBeDriftData< N > >;

        using mp_drift_exact_n_t = sixtrack_cxx::BeDriftExactInterface<
            sixtrack_cxx::BMPBeDriftExactData< N > >;

        using mp_dipedge_n_t = sixtrack_cxx::BeDipoleEdgeInterface<
            sixtrack_cxx::BMPBeDipoleEdgeData< N > >;

        using mp_limit_rect_n_t = sixtrack_cxx::BeLimitRectInterface<
            sixtrack_cxx::BMPBeLimitRectData< N > >;

        using mp_limit_ellipse_n_t = sixtrack_cxx::BeLimitEllipseInterface<
            sixtrack_cxx::BMPBeLimitEllipseData< N > >;

        using mp_multipole_n_t = sixtrack_cxx::BeMultipoleInterface<
            sixtrack_cxx::BMPBeMultipoleData< N > >;

        using mp_srotation_n_t = sixtrack_cxx::BeSRotationInterface<
            sixtrack_cxx::BMPBeSRotationData< N > >;

        using mp_xyshift_n_t = sixtrack_cxx::BeXYShiftInterface<
            sixtrack_cxx::BMPBeXYShiftData< N > >;

        ::NS(Object) const* obj_it  =
            ::NS(Buffer_get_const_objects_begin)( input_buffer );

        ::NS(Object) const* obj_end =
            ::NS(Buffer_get_const_objects_end)( input_buffer );

        ::NS(arch_status_t) status = ::NS(ARCH_STATUS_GENERAL_FAILURE);

        if( ( obj_it == nullptr ) || ( obj_end == nullptr ) )
        {
            return status;
        }

        status = ::NS(ARCH_STATUS_SUCCESS);

        for( ; obj_it != obj_end ; ++obj_it )
        {
            ::NS(object_type_id_t) const type_id =
                ::NS(Object_get_type_id)( obj_it );

            auto const base_addr = ::NS(Object_get_begin_addr)( obj_it );

            if( base_addr == 0u )
            {
                status = ::NS(ARCH_STATUS_GENERAL_FAILURE);
                break;
            }

            switch( type_id )
            {
                case ::NS(OBJECT_TYPE_DRIFT):
                {
                    auto in_ptr = reinterpret_cast< ::NS(BeDrift) const* >(
                        static_cast< std::uintptr_t >( base_addr ) );

                    auto ptr = mp_drift_n_t::AddObject( output_buffer, in_ptr );
                    if( ptr == nullptr ) status = ::NS(ARCH_STATUS_GENERAL_FAILURE);
                    break;
                }

                case ::NS(OBJECT_TYPE_DRIFT_EXACT):
                {
                    auto in_ptr = reinterpret_cast< ::NS(BeDriftExact) const* >(
                        static_cast< std::uintptr_t >( base_addr ) );

                    auto ptr = mp_drift_exact_n_t::AddObject( output_buffer, in_ptr );
                    if( ptr == nullptr ) status = ::NS(ARCH_STATUS_GENERAL_FAILURE);
                    break;
                }

                case ::NS(OBJECT_TYPE_CAVITY):
                {
                    auto in_ptr = reinterpret_cast< ::NS(BeCavity) const* >(
                        static_cast< std::uintptr_t >( base_addr ) );

                    auto ptr = mp_cavity_n_t::AddObject( output_buffer, in_ptr );
                    if( ptr == nullptr ) status = ::NS(ARCH_STATUS_GENERAL_FAILURE);
                    break;
                }

                case ::NS(OBJECT_TYPE_DIPEDGE):
                {
                    auto in_ptr = reinterpret_cast< ::NS(BeDipoleEdge) const* >(
                        static_cast< std::uintptr_t >( base_addr ) );

                    auto ptr = mp_dipedge_n_t::AddObject( output_buffer, in_ptr );
                    if( ptr == nullptr ) status = ::NS(ARCH_STATUS_GENERAL_FAILURE);
                    break;
                }

                case ::NS(OBJECT_TYPE_MULTIPOLE):
                {
                    auto in_ptr = reinterpret_cast< ::NS(BeMultipole) const* >(
                        static_cast< std::uintptr_t >( base_addr ) );

                    auto ptr = mp_multipole_n_t::AddObject( output_buffer,
                        in_ptr->order, real_t( in_ptr->length ),
                        real_t( in_ptr->hxl ), real_t( in_ptr->hyl ),
                        nullptr );

                    if( ptr != nullptr )
                    {
                        status = ptr->copyBalValues( in_ptr->order, in_ptr->bal );
                    }
                    else status = ::NS(ARCH_STATUS_GENERAL_FAILURE);
                    break;
                }

                case ::NS(OBJECT_TYPE_LIMIT_RECT):
                {
                    auto in_ptr = reinterpret_cast< ::NS(BeLimitRect) const* >(
                        static_cast< std::uintptr_t >( base_addr ) );

                    auto ptr = mp_limit_rect_n_t::AddObject( output_buffer, in_ptr );
                    if( ptr == nullptr ) status = ::NS(ARCH_STATUS_GENERAL_FAILURE);
                    break;
                }

                case ::NS(OBJECT_TYPE_LIMIT_ELLIPSE):
                {
                    auto in_ptr = reinterpret_cast< ::NS(BeLimitEllipse) const* >(
                        static_cast< std::uintptr_t >( base_addr ) );

                    auto ptr = mp_limit_ellipse_n_t::AddObject( output_buffer, in_ptr );
                    if( ptr == nullptr ) status = ::NS(ARCH_STATUS_GENERAL_FAILURE);
                    break;
                }

                case ::NS(OBJECT_TYPE_SROTATION):
                {
                    auto in_ptr = reinterpret_cast< ::NS(BeSRotation) const* >(
                        static_cast< std::uintptr_t >( base_addr ) );

                    auto ptr = mp_srotation_n_t::AddObject( output_buffer, in_ptr );
                    if( ptr == nullptr ) status = ::NS(ARCH_STATUS_GENERAL_FAILURE);
                    break;
                }

                case ::NS(OBJECT_TYPE_XYSHIFT):
                {
                    auto in_ptr = reinterpret_cast< ::NS(BeXYShift) const* >(
                        static_cast< std::uintptr_t >( base_addr ) );

                    auto ptr = mp_xyshift_n_t::AddObject( output_buffer, in_ptr );
                    if( ptr == nullptr ) status = ::NS(ARCH_STATUS_GENERAL_FAILURE);
                    break;
                }

                default:
                {
                    status = ::NS(ARCH_STATUS_GENERAL_FAILURE);
                }
            };

            if( status != ::NS(ARCH_STATUS_SUCCESS) ) break;
        }

        return status;
    }
}

#endif /* SIXTRACKLIB_BOOST_MULTIPREC_BEAM_ELEMENTS_CXX_HPP_42__ */
/* end: */
