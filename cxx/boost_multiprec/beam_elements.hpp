#ifndef SIXTRACKLIB_BOOST_MULTIPREC_BEAM_ELEMENTS_CXX_HPP_42__
#define SIXTRACKLIB_BOOST_MULTIPREC_BEAM_ELEMENTS_CXX_HPP_42__

#include "sixtracklib/common/definitions.h"
#include "sixtracklib/common/internal/objects_type_id.h"

#include "cxx/boost_multiprec/definitions.hpp"
#include "cxx/common/internal/obj_store_traits.hpp"
#include "cxx/common/track/obj_track_traits.hpp"

#include <boost/multiprecision/cpp_dec_float.hpp>

namespace sixtrack_cxx
{
    template< unsigned N >
    struct BMPObjIdVariant
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) GetVariantFlag()
        {
            return ::NS(object_type_id_t){ 0x10000 } |
                ( static_cast< ::NS(object_type_id_t) >( N ) &
                  ::NS(object_type_id_t){ 0xff } ) << 24;
        }
    };

    template< unsigned N >
    struct BMPBeCavityData
    {
        using real_t = boost::multiprecision::number<
            boost::multiprecision::cpp_dec_float< N > >;

        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        real_t  voltage   SIXTRL_ALIGN( 8 );
        real_t  frequency SIXTRL_ALIGN( 8 );
        real_t  lag       SIXTRL_ALIGN( 8 );
    };

    template< unsigned N >
    void BeCavityData_init(
        sixtrack_cxx::BMPBeCavityData< N >& SIXTRL_RESTRICT_REF cavity )
    {
        using real_t = boost::multiprecision::number<
            boost::multiprecision::cpp_dec_float< N > >;

        cavity.voltage   = real_t{ 0 };
        cavity.frequency = real_t{ 0 };
        cavity.lag       = real_t{ 0 };
    }

    template< unsigned N >
    void BeCavityData_init(
        sixtrack_cxx::BMPBeCavityData< N >& SIXTRL_RESTRICT_REF cavity,
        typename sixtrack_cxx::BMPBeCavityData< N >::real_t const& voltage,
        typename sixtrack_cxx::BMPBeCavityData< N >::real_t const& frequency,
        typename sixtrack_cxx::BMPBeCavityData< N >::real_t const& lag )
    {
        cavity.voltage   = voltage;
        cavity.frequency = frequency;
        cavity.lag       = lag;
    }

    template< unsigned N >
    struct ObjDataStoreTraits< BMPBeCavityData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits< BMPBeCavityData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_CAVITY;
        }
    };

    template< unsigned N >
    struct ObjDataStoreConstructionTraits< BMPBeCavityData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };

    /* --------------------------------------------------------------------- */

    template< unsigned N >
    struct BMPBeDriftData
    {
        using real_t = boost::multiprecision::number<
            boost::multiprecision::cpp_dec_float< N > >;

        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        real_t length SIXTRL_ALIGN( 8 );
    };

    template< unsigned N >
    void BeDriftData_init( sixtrack_cxx::BMPBeDriftData< N >&
        SIXTRL_RESTRICT_REF drift )
    {
        using real_t = boost::multiprecision::number<
            boost::multiprecision::cpp_dec_float< N > >;

        drift.length = real_t{ 0 };
    }

    template< unsigned N >
    void BeDriftData_init( sixtrack_cxx::BMPBeDriftData< N >&
        SIXTRL_RESTRICT_REF drift,
        typename sixtrack_cxx::BMPBeDriftData< N >::real_t const& length )
    {
        drift.length = length;
    }

    template< unsigned N > struct ObjDataStoreTraits< BMPBeDriftData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits< BMPBeDriftData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT;
        }
    };

    template< unsigned N >
    struct ObjDataStoreConstructionTraits< BMPBeDriftData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };

    /* --------------------------------------------------------------------- */

    template< unsigned N >
    struct BMPBeDriftExactData
    {
        using real_t = boost::multiprecision::number<
            boost::multiprecision::cpp_dec_float< N > >;

        static SIXTRL_FN constexpr std::size_t RealAlignment()
        {
            return sixtrack_cxx::TypeStoreTraits< real_t >::StorageAlign();
        }

        real_t length SIXTRL_ALIGN( 8 );
    };

    template< unsigned N > void BeDriftExactData_init(
        sixtrack_cxx::BMPBeDriftExactData< N >& SIXTRL_RESTRICT_REF drift )
    {
        using real_t = boost::multiprecision::number<
            boost::multiprecision::cpp_dec_float< N > >;

        drift.length = real_t{ 0 };
    }

    template< unsigned N > void BeDriftExactData_init(
            sixtrack_cxx::BMPBeDriftExactData< N >& SIXTRL_RESTRICT_REF drift,
            typename sixtrack_cxx::BMPBeDriftExactData< N >::real_t const& l )
    {
        drift.length = l;
    }

    template< unsigned N > struct ObjDataStoreTraits< BMPBeDriftExactData< N > >
    {
        static SIXTRL_FN constexpr ::NS(object_type_id_t) ObjTypeId()
        {
            return sixtrack_cxx::BMPObjIdVariant< N >::GetVariantFlag()
                | SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT;
        }

        static SIXTRL_FN constexpr bool HasCApiLayout() { return false; }
    };

    template< unsigned N > struct ObjDataTrackTraits< BMPBeDriftExactData< N > >
    {
        static SIXTRL_FN constexpr
        SIXTRL_CXX_NAMESPACE::object_type_id_t ObjTypeId()
        {
            return SIXTRL_CXX_NAMESPACE::OBJECT_TYPE_DRIFT_EXACT;
        }
    };

    template< unsigned N >
    struct ObjDataStoreConstructionTraits< BMPBeDriftExactData< N > >
    {
        static SIXTRL_FN constexpr bool CanBeMemCopied() { return true; }
    };

    /* --------------------------------------------------------------------- */
}

#endif /* SIXTRACKLIB_BOOST_MULTIPREC_BEAM_ELEMENTS_CXX_HPP_42__ */
/* end: */
