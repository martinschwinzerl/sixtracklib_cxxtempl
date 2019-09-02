#ifndef SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/drift/drift_data.hpp"
#include "cxx/common/be/drift/be_drift.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeDriftBase : public BeObjData
    {
        public:

        typedef BeObjData                                       be_data_t;
        typedef typename BeDriftTraits< BeObjData >::real_t     real_t;

        SIXTRL_FN BeDriftBase() = default;

        SIXTRL_FN BeDriftBase( BeDriftBase< BeObjData > const& other) = default;
        SIXTRL_FN BeDriftBase( BeDriftBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeDriftBase< BeObjData >& operator=(
            BeDriftBase< BeObjData > const& other) = default;

        SIXTRL_FN BeDriftBase< BeObjData >& operator=(
            BeDriftBase< BeObjData >&& other ) = default;

        SIXTRL_FN virtual ~BeDriftBase() = default;

        protected:

        SIXTRL_FN be_data_t* ptrBeData() SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t* >( this );
        }

        SIXTRL_FN be_data_t const* ptrBeData() const SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t const* >( this );
        }

        SIXTRL_FN be_data_t& beData() SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t& >( *this );
        }

        SIXTRL_FN be_data_t const& beData() const SIXTRL_NOEXCEPT
        {
            return static_cast< be_data_t const& >( *this );
        }
    };

    /* --------------------------------------------------------------------- */

    typedef BeDriftBase< ::NS(BeDrift) >                CBeDrift;
    typedef BeDriftBase< ::NS(BeDriftExact) >           CBeDriftExact;

    typedef BeDriftBase< DriftData< double > >          BeDrift;
    typedef BeDriftBase< DriftExactData< double > >     BeDriftExact;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeDrift = BeDriftBase< DriftData< R, RAlign > >;

    template< class R, std::size_t RAlign =
        sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeDriftExact = BeDriftBase< DriftExactData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_DRIFT_BE_DRIFT_CXX_HPP__ */
/* end: */
