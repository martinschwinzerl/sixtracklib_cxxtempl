#ifndef SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_CXX_HPP__
#define SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_CXX_HPP__

#include "sixtracklib/sixtracklib.hpp"

#include "cxx/common/be/dipedge/be_dipedge_traits.hpp"
#include "cxx/common/be/dipedge/be_dipedge_data.hpp"
#include "cxx/common/be/dipedge/be_dipedge.h"

namespace sixtrack_cxx
{
    template< class BeObjData >
    class BeDipoleEdgeBase : public BeObjData
    {
        public:

        typedef BeObjData           be_data_t;
        typedef ::NS(BeDipoleEdge)  c_api_t;
        typedef typename BeDipoleEdgeTraits< BeObjData >::real_t  real_t;

        SIXTRL_FN BeDipoleEdgeBase() = default;

        SIXTRL_FN BeDipoleEdgeBase(
            BeDipoleEdgeBase< BeObjData > const& other) = default;

        SIXTRL_FN BeDipoleEdgeBase(
            BeDipoleEdgeBase< BeObjData >&& other ) = default;

        SIXTRL_FN BeDipoleEdgeBase< BeObjData >& operator=(
            BeDipoleEdgeBase< BeObjData > const& other) = default;

        SIXTRL_FN BeDipoleEdgeBase< BeObjData >& operator=(
            BeDipoleEdgeBase< BeObjData >&& other ) = default;

        SIXTRL_FN virtual ~BeDipoleEdgeBase() = default;

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

    typedef BeDipoleEdgeBase< ::NS(BeDipoleEdge) >            CBeDipoleEdge;
    typedef BeDipoleEdgeBase< BeDipoleEdgeData< double > >    BeDipoleEdge;

    template< class R,
        std::size_t RAlign = sixtrack_cxx::TypeStoreTraits< R >::StorageAlign() >
    using TBeDipoleEdge = BeDipoleEdgeBase< BeDipoleEdgeData< R, RAlign > >;
}

#endif /* SIXTRACKLIB_COMMON_BE_DIPOLE_EDGE_BE_DIPOLE_EDGE_CXX_HPP__ */
/* end: */
